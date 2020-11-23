#include "Post.h"

using namespace std;

#pragma region Constructors
// text based constructor 
Post::Post(string text) 
{
	this->_text = text;
	this->_media = NULL;
}

// text and media based constructor 
Post::Post(string text, Media *media)
{
	this->_text = text;
	this->_media = media;
}

// Copy Constructor 
Post::Post(const Post &post)
{
	this->_text = post._text;
	this->_media = post._media; 
}
#pragma endregion

// getters 
string Post::getText()
{
	return this->_text;
}

Media* Post::getMedia()
{
	return this->_media;
}

// assignment operation overload 
Post & Post::operator=(const Post &post)
{
	if (this != &post)
	{
		this->_text = post._text;
		this->_media = post._media; 
	}
	return *this;
}

// equality overload 
bool Post::operator==(const Post &post) const
{
	return this->_text == post._text && this->_media == post._media;
}

// destructor 
Post::~Post() { }

// ToString printout override style with stream operator overload 
std::ostream& operator<<(std::ostream& stream, const Post& post)
{
	stream << "Post={\"Text\": \'" << post._text << "\'; ";
	if (post._media != NULL)
	{
		stream << "\"Media\": " << post._media->getDescription();
	}
	stream << "}";
	return stream << std::endl;
}
