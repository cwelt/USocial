#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>

class Message
{
private:
	// data members 
	std::string _text;

public:
	// methods
	std::string getText();

	//constructors
	Message();
	Message(std::string text);
	Message(const Message& message); // copy constructor 
};

#endif // MESSAGE_H_
