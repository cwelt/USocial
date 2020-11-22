#include "USocial.h"

unsigned int USocial::userId = 0;

User* USocial::registerUser(std::string userName, bool isBusinessAccount)
{
    // create a new user 
    User* user = new User();

    // assign the user a new id
    user->id = ++userId;

    // set user name
    user->name = userName;

    return user;
}

void USocial::removeUser(User*)
{
}

User* USocial::getUserById(unsigned long)
{
    return nullptr;
}
