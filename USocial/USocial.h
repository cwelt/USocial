#ifndef USOCIAL_H_
#define USOCIAL_H_

#include <map>
#include "User.h"

class User;

class USocial
{
private:
	friend class User;

	// data members 
	std::map<unsigned long, User*> users;
	
public:
	// methods
	User* registerUser(std::string userName, bool isBusinessAccount = false);
	void removeUser(User* user);
	User* getUserById(unsigned long userId);

	// Operators overloads 
	friend std::ostream& operator<<(std::ostream& stream, const USocial& usocial);
	USocial& operator=(const USocial& usocial);

	// Constructors 
	USocial();
	USocial(const USocial& usocial); // copy constructor 

	// destructor 
	~USocial();
};

#endif // USER_H_
