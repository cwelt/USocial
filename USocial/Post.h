#ifndef POST_H_
#define POST_H_

#include <string>
#include "Media.h"

class Post
{

private:
	// instance variables
	std::string _text;
	Media *_media;

public:
	// Constructors 
	Post(std::string text);
	Post(std::string text, Media *media);
	Post(const Post &post); // copy constructor 

	// Getters 
	std::string getText();
	Media* getMedia();

	// Operators overloads 
	Post & operator=(const Post &post);
	bool operator==(const Post &post) const;
	friend std::ostream & operator<<(std::ostream &stream, const Post &post);
	 
	// Desstructor 
	~Post();
};

#endif //  POST_H_