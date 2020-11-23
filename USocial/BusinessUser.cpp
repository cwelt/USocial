#include "BusinessUser.h"

using namespace std;

// business user could send message to whom he wants, friend or not
void BusinessUser::sendMessage(User* user, Message* message)
{
	user->receiveMessage(message);
}
