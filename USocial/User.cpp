
#include "User.h"

using namespace std;

User::User()
{

}

User::User(const User& user)
{
}

User::~User()
{
}

unsigned long User::getId()
{
	return this->id;
}

std::string User::getName()
{
	return this->name;
}

void User::addFriend(User* user)
{
	if (this->isFriend(user))
	{
		cout << "Friend already exists!" << endl;
	}
	else
	{
		this->friends.push_back(user->id);
	}
}


void User::removeFriend(User* user)
{
	if (this->isFriend(user))
	{
		this->friends.remove(user->id);
	}
	else
	{
		cout << "Can't remove user " << user->id << ": User is not on friend list!" << endl;
	}
}

void User::post(std::string text)
{
	this->posts.push_back(new Post(text));
}

void User::post(std::string text, Media* media)
{
	this->posts.push_back(new Post(text, media));
}

std::list<Post*> User::getPosts()
{
	return this->posts;
}

void User::viewFriendsPosts()
{
	cout << "TODO viewFriendsPosts...";
}

void User::receiveMessage(Message* message)
{
	cout << "TODO receiveMessage...";
}

void User::sendMessage(User* user, Message* meesage)
{
	cout << "TODO sendMessage...";
}

void User::viewReceivedMessages()
{
	cout << "TODO viewReceivedMessages...";
}

// returns true if the given user exists in this user's friend list, false otherwise;
bool User::isFriend(User* user)
{
	for (auto const& friendId : this->friends)
	{
		if (friendId == user->id)
		{
			return true; // user found in friend list
		}
	}
	return false; // user does not exist in friend list
}

User& User::operator=(const User& user)
{
	return *this;
}

bool User::operator==(const User& user) const
{
	return false;
}

std::ostream& operator<<(std::ostream& stream, const User& user)
{
	stream << "user id: " << user.id << "user name: " << user.name;
	return stream << std::endl;
}


