#include <iostream>
#include <string>
#include "makedir.h"
#include "help.h"
#include "soundplayer.h"

using namespace std;

string scelta;

int main()
{

    //Menu Yeeeeee
    cout<<"||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"***Terminal Simulator***"<<endl;
    cout<<endl;
    cout<<"Devolved By Nicholas Impieri Aka Anonik"<<endl;
    cout<<endl;
    cout<<"||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<endl;
    //Fine Menu Noooo

    cout<<"Digita un comando... ";
    cin>>scelta;
    cout<<endl;

    //scelta di mkdir
    if(scelta == "mkdir"){
        makedir();

    }

    //scelta di help
    else if(scelta == "help"){
        help();

    }

    else if(scelta == "play_sound"){
        soundplayer();
    }





    return 0;
}






