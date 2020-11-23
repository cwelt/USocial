#include "Message.h"

using namespace std;

// get message content 
std::string Message::getText()
{
	return _text;
}

// default constructor 
Message::Message()
{
	// set default message context to a smiley if no text is specified
	this->_text = "[^_^]"; 
}

// constructor based on text message 
Message::Message(string messageText)
{
	this->_text = messageText;
}

// copy constructor 
Message::Message(const Message& message)
{
	this->_text = message._text;
}