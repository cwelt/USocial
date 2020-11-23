#ifndef BUSINESS_USER_H_
#define BUSINESS_USER_H_
#include "User.h"
class BusinessUser : public User
{
	virtual void sendMessage(User* user, Message* meesage);
};

#endif // BUSINESS_USER_H_

