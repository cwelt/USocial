#ifndef USER_H_
#define USER_H_

#include <string>
#include <list>
#include "Post.h"
#include "USocial.h"
#include "Message.h"

class USocial;

class User
{
private:
	friend class USocial;
	static unsigned long nextUserId;

protected:
	USocial *us;
	unsigned long id;
	std::string name;
	std::list<unsigned long> friends;
	std::list<Post*> posts;
	std::list<Message*> receivedMsgs;

	// constructors
	User();
	User(const User& user); // copy constructor 

	// destructor 
	~User();

	// util methods 
	bool isFriend(User* user);

public:
	unsigned long getId();
	std::string getName();

	void addFriend(User* user);
	void removeFriend(User* user);

	void post(std::string text);
	void post(std::string text, Media* media);
	std::list<Post*> getPosts();
	void viewFriendsPosts();
	void receiveMessage(Message* message);
	virtual void sendMessage(User* user, Message* meesage);
	void viewReceivedMessages();

	// Operators overloads 
	User& operator=(const User& post);
	bool operator==(const User& post) const;
	friend std::ostream& operator<<(std::ostream& stream, const User& user);
};

#endif // USER_H_
