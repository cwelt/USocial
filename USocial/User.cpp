#include "User.h"

using namespace std;

#pragma region staticInit
// init user id numerator
unsigned long User::nextUserId = 1L;
#pragma endregion

#pragma region constructors
// default constructor 
User::User()
{
	this->id = nextUserId++;
	this->name = "Anonymous";
	this->us = nullptr;
}

// copy constructor
User::User(const User& user) 
{
	this->id = nextUserId++;
	this->name = user.name;
	this->us = user.us;

	// deep copy the friend list 
	for (auto const& friendId : user.friends)
		this->friends.push_back(friendId);

	// deep copy the posts list 
	for (auto const& post : user.posts)
		this->posts.push_back(new Post(*post));

	// deep copy the received messages list 
	for (auto const& message : user.receivedMsgs)
		this->receivedMsgs.push_back(new Message(*message));
}
#pragma endregion

#pragma region destructor
User::~User()
{
	// release memory of all posts and clear post list
	for (auto const& post : this->posts)
		delete post;
	posts.clear();

	// release memory of all received messages and clear message list
	for (auto const& message : this->receivedMsgs)
		delete message;
	receivedMsgs.clear();

	// clear friend list (every friend would be responsible for releasing his own memory)
	friends.clear();
}
#pragma endregion

#pragma region getters (accessors)
// getId
unsigned long User::getId()
{
	return this->id;
}

// getName
std::string User::getName()
{
	return this->name;
}

// getPosts
std::list<Post*> User::getPosts()
{
	return this->posts;
}
#pragma endregion

#pragma region addfriend & removeFriend

// add friend
void User::addFriend(User* user)
{
	// throw exception if friend already exists on this user's friend list
	if (this->isFriend(user))
	{
		cerr << "Error: " << *user << "already exists on friend list of " << *this << endl;
		throw std::invalid_argument("Friend already exists!");
	}

	else
	{
		// add given user to this user's friend list 
		this->friends.push_back(user->id);

		// add this user to given user's friend list 
		user->friends.push_back(this->id);
	}
}


// removeFriend
void User::removeFriend(User* user)
{
	if (this->isFriend(user))
	{
		// remove given from this user's friend list
		this->friends.remove(user->id);

		// remove this user from the given user's friend list 
		user->friends.remove(this->id);
	}
	else
	{
		cerr << "Error: Can't remove " << *user << ": from friend list." << endl;
		throw std::invalid_argument("Given user is not on this user's friend list!");
	}
}
#pragma endregion

#pragma region post

// post with only text
void User::post(std::string text)
{
	this->posts.push_back(new Post(text));
}

// post with text and media
void User::post(std::string text, Media* media)
{
	this->posts.push_back(new Post(text, media));
}
#pragma endregion

#pragma region viewFriendsPosts
// viewFriendsPosts 
void User::viewFriendsPosts()
{
	// if user has no registered friends, print appropriate message and abort
	if (this->friends.empty())
	{
		cout << *this << " has no registerd users on USocial";
		cout << endl;
		return;
	}

	// user has friends, print all their posts 
	cout << *this << " friends' posts:\n";
	for (auto const& friendId : this->friends)
	{
		User* usersFriend = (User*)(this->us->getUserById(friendId));
		cout << "\t" << *usersFriend << ":";
		for (auto const& post : usersFriend->posts)
			cout << "\n\t\t" << *post;
		cout << endl;
	}
}
#pragma endregion

#pragma region receive and send messages

// receiveMessage
void User::receiveMessage(Message* message)
{
	this->receivedMsgs.push_back(message);
}

// sendMessage
void User::sendMessage(User* user, Message* message)
{
	// validate given user is a registered user of this friend
	if (this->isFriend(user))
	{
		user->receiveMessage(message);
	}

	// only business accounts could message strangers
	else
	{
		cout << *this << " cannot send message to " << *user << ":" << endl;
		cout << "Only business account users could message users out of their friend list." << endl;
	}
}

// print all received messages 
void User::viewReceivedMessages()
{
	if (this->receivedMsgs.empty())
	{
		cout << *this << " has no received messages." << endl;
		return;
	}

	cout << "Received message for " << *this << ":" << endl;
	for (auto const& message : this->receivedMsgs)
	{
		cout << "\t" << message->getText() << endl;
	}
	cout << endl;
}

#pragma endregion

#pragma region utills
// returns true if the given user exists in this user's friend list, false otherwise;
bool User::isFriend(User* user)
{
	for (auto const& friendId : this->friends)
	{
		if (friendId == user->id)
			return true; // user found in friend list
	}
	return false; // user does not exist in friend list
}

// check if two given users are identical by their id's
bool User::operator==(const User& user) const
{
	return this->id == user.id;
}

// define a "ToString" style override << operator for user printout 
std::ostream& operator<<(std::ostream& stream, const User& user)
{
	return stream << "User " << user.id << " (" << user.name << ")";
}

#pragma endregion

#pragma region assignmentOperatorOverload

// assignment = operator overload 
User& User::operator=(const User& user) 
{
	if (this != &user)
	{
		// set id
		this->id = ++nextUserId;
		
		// deep copy the friend list 
		this->friends.clear();
		for (auto const& friendId : user.friends)
			this->friends.push_back(friendId);

		// deep copy the posts list 
		this->posts.clear();
		for (auto const& post : user.posts)
			this->posts.push_back(new Post(*post));

		// deep copy the received messages list 
		this->receivedMsgs.clear();
		for (auto const& message : user.receivedMsgs)
			this->receivedMsgs.push_back(new Message(*message));
	}
	return *this;
}
#pragma endregion

