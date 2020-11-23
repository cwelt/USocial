#ifndef MEDIA_H_
#define MEDIA_H_

#include <iostream>

/* Abstract Media Class */
class Media
{	
public:
	void virtual display() = 0;
	std::string virtual getDescription() = 0 { return "media"; }
};


/* Photo Class */
class Photo : public Media
{
public:
	void display() { std::cout << "image\n"; }
	std::string getDescription() { return "image"; }
};


/* Audio Class */
class Audio : public Media
{
public:
	void display() { std::cout << "audio\n"; }
	std::string getDescription() { return "audio"; }
};


/* Video Class */
class Video : public Media
{
public:
	void display() { std::cout << "video\n"; }
	std::string getDescription() { return "video"; }
};

#endif  // MEDIA_H_ 