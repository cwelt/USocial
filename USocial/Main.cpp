#include <iostream>
#include "Media.h"
#include "Post.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

    Media *audio = new Audio();
    Media* p = new Photo();

    Media* video = new Video();

    audio->display();
    p->display();
    video->display();

    Post post1("post1", audio);
    Post post2("post2", p);

    cout << post1;
    cout << post2;
    
    Post post3(post1);

    cout << post3;

    cout << (post1 == post3) << endl;
    cout << (post1 == post2) << endl;

    audio = video;

    cout << "After change:\n" << endl;
    cout << post1;
    cout << post2;
    cout << post3;


}
