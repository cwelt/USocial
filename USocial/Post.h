#ifndef POST_H_

#include <string>
#include "Media.h"

class Post
{
private:
	std::string _text;
	Media *_media;
public:
	Post(std::string text);
	Post(std::string text, Media *media);
	std::string getText();
	Media* getMedia();
	bool operator == (const Post& post) const;
};

#endif //  POST_H_