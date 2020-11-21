
#include <iostream>
#include "Media.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

    Audio *audio = new Audio();
    Media* p = new Photo();

    Media* video = new Video();

    audio->display();
    p->display();
    video->display();

}
