#include "Post.h"

using namespace std;

Post::Post(string text) 
{
	this->_text = text;
}

Post::Post(string text, Media *media)
{
	this->_text = text;
	this->_media = media;
}

string Post::getText()
{
	return this->_text;
}

Media* Post::getMedia()
{
	return this->_media;
}

bool Post::operator == (const Post& post) const
{
	return this->_text == post._text && this->_media == post._media;
}