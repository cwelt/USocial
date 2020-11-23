#include "USocial.h"
#include "User.h"
#include "BusinessUser.h"

using namespace std;


User* USocial::registerUser(std::string userName, bool isBusinessAccount)
{
    // create a new user 
    User* user = isBusinessAccount ? new BusinessUser() : new  User();

    // set user's name
    user->name = userName;

    // set user's us to reference current us
    user->us = this;

    // add user to registerd users map
    this->users.insert(std::make_pair(user->id, user));

    // return the new created user to caller
    return user;
}


// removeUser
void USocial::removeUser(User* user)
{
    // throw exception if attempt is made to remove unexisting user
    if (users.find(user->id) == users.end())
    {
        cerr << *user << " does not exist!!" << endl;
        throw std::invalid_argument("User does not exist!");
    }
    else
    {
        // remove user from map 
        users.erase(user->id);
    }
}

// Retreive user
User* USocial::getUserById(unsigned long userId)
{
    return users.at(userId);
}

// stream operator overload for "ToString" style printout 
std::ostream& operator<<(std::ostream& stream, const USocial& usocial)
{
    for (auto const& user : usocial.users)
        stream << *user.second << endl;
    return stream << std::endl;
}

// default constructor 
USocial::USocial() {}

// copy constructor
USocial::USocial(const USocial& usocial)
{
    // clear existing map
    this->users.clear();

    // deep copy the users from given usocial
    for (auto const& user : usocial.users)
        this->users.insert(std::make_pair(user.first, user.second));
}

// overload assignment operator
USocial& USocial::operator=(const USocial& usocial)
{
    if (this != &usocial)
    {
        // clear existing map
        this->users.clear();

        // deep copy the users from given usocial
        for (auto const& user : usocial.users)
            this->users.insert(std::make_pair(user.first, user.second));
    }
    return *this;
}

// destructor 
USocial::~USocial()
{
    // release memory of all users in map 
    for (auto const& user : this->users)
        delete user.second;
}