#include <iostream>
#include "Media.h"
#include "Post.h"
#include "USocial.h"
#include "User.h"

using namespace std;

int main()
{
    // check polymorphism with virtual functions on media entites 
    cout << "Polymorphism testing with virtual functions:" << endl;
    Media* audio = new Audio();
    Media* video = new Video();
    audio->display();
    video->display();

    // set up a social network
    USocial theSocialNetwork;

    // rock n roll players
    User* r1 = theSocialNetwork.registerUser("Brian May");
    User* r2 = theSocialNetwork.registerUser("Jimmy Page");
    User* r3 = theSocialNetwork.registerUser("David Gilmor");
    User* r4 = theSocialNetwork.registerUser("George Harrison");
    User* r5 = theSocialNetwork.registerUser("BB King");

    // jazz musicians
    User* j1 = theSocialNetwork.registerUser("John Coltrane");
    User* j2 = theSocialNetwork.registerUser("Charlie Parker");

    // cllassical amazing composers 
    User* c1 = theSocialNetwork.registerUser("Fredrich Chopin");
    User* c2 = theSocialNetwork.registerUser("Johan Sebastian Bach");

    // business user
    User* b1 = theSocialNetwork.registerUser("Israel Israely ", true);

    // print current status:
    cout << "\nNewotk before making any relationships:\n" << theSocialNetwork;

    // make each individual group friends - rock:
    r1->addFriend(r2);
    r1->addFriend(r3);
    r1->addFriend(r4);
    r1->addFriend(r5);
    r2->addFriend(r3);
    r2->addFriend(r4);
    r2->addFriend(r5);
    r3->addFriend(r4);
    r3->addFriend(r5);
    r4->addFriend(r5);

    // jazz:
    j1->addFriend(j2);

    // classical:
    c1->addFriend(c2);

    // add some posts:
    r1->post("Radio Gaga, Radio Gugu!", audio);
    r2->post("Video Killed the Radio Star!!!", new Video());
    r4->post("Isn't it a pitty?");
    r5->post("That's Why I Sing the Bluuuees!", new Audio());

    // send some messages 
    r3->sendMessage(r4, new Message("How I Wish You Were Here"));
    r4->sendMessage(r3, new Message("My Lord,..., Really wanna see you..."));
    r5->sendMessage(r4, new Message("You're the man!"));
    r2->sendMessage(r4, new Message());

    // view received messages for r4 (geroge harrison)
    r4->viewReceivedMessages();

    // view some posts of friends 
    r3->viewFriendsPosts();

    // after removing one friend
    cout << "After removing friendship with r5 (friend with last post): " << endl;
    r5->removeFriend(r3);
    r3->viewFriendsPosts();

    // try to send message to user who's not a friend from regular account 
    j1->sendMessage(c2, new Message("This would fail because j1 is not a business account..."));
    cout << "Messages after failed attempt to send from non-friend regular account:\n";
    c2->viewReceivedMessages();

    // try to send message from business user to strangers
    b1->sendMessage(j2, new Message("Spam Spam Spam I have premium so i could spam"));
    j2->viewReceivedMessages();

    // attempt to remove friend which does not exist 
    cout << "attempt to remove friend which does not exist: " << endl;
    try
    {
        j2->removeFriend(b1);
    }
    catch (const std::exception& e)
    {
        cout << "Runtime Exception Occoured: " << e.what() << endl;
    }

    // try to add a friend twice
    cout << endl<< "Attempt to add a user as a friend more than once:" << endl;
    try
    {
        c1->addFriend(c2);
    }
    catch (const std::exception& e)
    {
        cout << "Runtime Exception Occoured: " << e.what() << endl;
    }

    // the end
    cout << endl;
    j1->post("Thank You! Don't work too hard!", new Photo());
    j2->viewFriendsPosts();
}
