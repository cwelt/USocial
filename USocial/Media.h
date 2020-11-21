#ifndef MEDIA_H_
#define MEDIA_H_

#include <iostream>

/* Abstract Media Class */
class Media
{	
public:
	void virtual display() = 0;
};


/* Photo Class */
class Photo : public Media
{
public:
	void display() { std::cout << "image\n"; }
};


/* Audio Class */
class Audio : public Media
{
public:
	void display() { std::cout << "audio\n"; }
};


/* Video Class */
class Video : public Media
{
public:
	void display() { std::cout << "video\n"; }
};

#endif  // MEDIA_H_ 