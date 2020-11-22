#include "Post.h"

using namespace std;

#pragma region Constructors

Post::Post(string text) 
{
	this->_text = text;
}

Post::Post(string text, Media *media)
{
	this->_text = text;
	this->_media = media;
}

// Copy Constructor 
Post::Post(const Post &post)
{
	cout << "Copy Constructor called!\n";

	this->_text = post._text;
	this->_media = post._media; // shuld we use new ?
}

#pragma endregion

string Post::getText()
{
	return this->_text;
}

Media* Post::getMedia()
{
	return this->_media;
}

Post & Post::operator=(const Post &post)
{
	cout << "overloaded = operater called!\n";
	if (this != &post)
	{
		this->_text = post._text;
		this->_media = post._media; // shuld we use new ? 
	}
	return *this;
}

bool Post::operator==(const Post &post) const
{
	return this->_text == post._text && this->_media == post._media;
}

Post::~Post()
{
	cout << "Post Destructor called!\n";
	delete _media;
}

std::ostream& operator<<(std::ostream& stream, const Post& post)
{
	stream	 << "Post : Text: " << post._text << ", Media: " << post._media;
	post._media->display();
	return stream << std::endl;
}
