/*
Terminal Simulator Devolved By Nicholas Impieri Aka Anonik - (C) 2017 - 2018
  Free for modification and personal use, written in C,C++
  Website made By Nicholas Impieri Aka Anonik, written in HTML5 and CSS3

                                MIT License

Copyright (c) 2018 DeVeL_AnOnIk

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include "makedir.h"
#include "help.h"
#include "soundplayer.h"
#include "main.h"

using namespace std;

string scelta;


void mainc(){
    system("cls");
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
if(hStdOut==NULL)
    cout<<endl;
    SetConsoleTextAttribute(hStdOut,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN); //Per avere il colore del testo bianco

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



else{
    cout<<"Syntax error, type help to see all commands syntax"<<endl;
    system("pause");
    mainc();
}



}

int main(){



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

else{
    cout<<"Syntax error, type help to see all commands syntax"<<endl;
    system("pause");
    mainc();
}



    return 0;

}







