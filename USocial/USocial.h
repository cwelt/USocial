#ifndef USOCIAL_H_
#define USOCIAL_H_

#include <map>
#include "User.h"

class USocial
{
private:
	friend class User;
	static unsigned int userId;

	// data members 
	std::map<unsigned long, User* > users;
	
public:
	// methods
	User* registerUser(std::string userName, bool isBusinessAccount);
	void removeUser(User* user);
	User* getUserById(unsigned long uderId);
};

#endif // USER_H_
