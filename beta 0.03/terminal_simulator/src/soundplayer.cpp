#include <iostream>
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include <fstream>
#include "main.h"

using namespace std;

string help1;
string songlist;


void soundplayer()
{
inizio:
cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
cout<<"                     Audio Player"<<endl;
cout<<endl;
cout<<"                   Devolved By Anonik"<<endl;
cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;


cout<<endl;
cout<<"Type 'help' to see how to put the song Or Type 'start' to listen "<<endl;
cout<<endl;
cin>>help1;
cout<<endl;

if(help1 == "help"){
    cout<<"* Open the terminal_simulator folder"<<endl;
    cout<<endl;
    cout<<"* Open the src folder"<<endl;
    cout<<endl;
    cout<<"* Open the Song folder"<<endl;
    cout<<endl;
    cout<<"* Put inside this folder your song (called: song1.wav, song2.wav exc)"<<endl;
    cout<<endl;
    cout<<"* Only .wav file supported"<<endl;
    cout<<endl;
    system("pause");
    system("cls");
    goto inizio;
    cout<<endl;
}

else if(help1 == "start"){

     //Domanda
     cout<<"How many songs are present in the Song folder"<<endl;
     cout<<endl;
     cin>>songlist;
     cout<<endl;


     //1 loop
     if(songlist == "1"){

    ifstream ifile("Song/song1.wav");
    if (ifile) {
  // The file exists, and is open for input
    cout<<"Track N°1"<<endl;
    PlaySound(TEXT("Song/song1.wav"),NULL,SND_SYNC);
    }
     }


    //2 loop
    else if(songlist == "2"){
        //prima
    ifstream ifile("Song/song1.wav");
    if (ifile) {
  // The file exists, and is open for input
    cout<<"Track N°1"<<endl;
    PlaySound(TEXT("Song/song1.wav"),NULL,SND_SYNC);

    //seconda
    //prima
    ifstream ifile2("Song/song2.wav");
    if (ifile2) {
  // The file exists, and is open for input
    cout<<"Track N°2"<<endl;
    PlaySound(TEXT("Song/song2.wav"),NULL,SND_SYNC);
    }
    else if(ifile2){
    cout<<"nothing found"<<endl;
    }

    }//Fine ciclo principale
    else if(ifile){
    cout<<"nothing found"<<endl;
    }

    }




    //3 loop
    else if(songlist =="3"){
            ifstream ifile("Song/song1.wav");
    if (ifile) {
  // The file exists, and is open for input
    cout<<"Track N°1"<<endl;
    PlaySound(TEXT("Song/song1.wav"),NULL,SND_SYNC);

    //seconda
    ifstream ifile2("Song/song2.wav");
    if (ifile2) {
  // The file exists, and is open for input
    cout<<"Track N°2"<<endl;
    PlaySound(TEXT("Song/song2.wav"),NULL,SND_SYNC);
    }//fine seconda

    //terza
    ifstream ifile3("Song/song3.wav");
    if (ifile3) {
  // The file exists, and is open for input
    cout<<"Track N°3"<<endl;
    PlaySound(TEXT("Song/song3.wav"),NULL,SND_SYNC);
    }
                }
    }//Fine 3 loop




    //4 loop
    else if(songlist =="4"){
            ifstream ifile("Song/song1.wav");
    if (ifile) {
  // The file exists, and is open for input
    cout<<"Track N°1"<<endl;
    PlaySound(TEXT("Song/song1.wav"),NULL,SND_SYNC);

    //seconda
    ifstream ifile2("Song/song2.wav");
    if (ifile2) {
  // The file exists, and is open for input
    cout<<"Track N°2"<<endl;
    PlaySound(TEXT("Song/song2.wav"),NULL,SND_SYNC);
    }//fine seconda

    //terza
    ifstream ifile3("Song/song3.wav");
    if (ifile3) {
  // The file exists, and is open for input
    cout<<"Track N°3"<<endl;
    PlaySound(TEXT("Song/song3.wav"),NULL,SND_SYNC);
    }

    //quarta
    ifstream ifile4("Song/song4.wav");
    if (ifile4) {
  // The file exists, and is open for input
    cout<<"Track N°4"<<endl;
    PlaySound(TEXT("Song/song4.wav"),NULL,SND_SYNC);
    }
                }
    }//Fine 4 loop


    //5 loop
    else if(songlist =="5"){
            ifstream ifile("Song/song1.wav");
    if (ifile) {
  // The file exists, and is open for input
    cout<<"Track N°1"<<endl;
    PlaySound(TEXT("Song/song1.wav"),NULL,SND_SYNC);

    //seconda
    ifstream ifile2("Song/song2.wav");
    if (ifile2) {
  // The file exists, and is open for input
    cout<<"Track N°2"<<endl;
    PlaySound(TEXT("Song/song2.wav"),NULL,SND_SYNC);
    }//fine seconda

    //terza
    ifstream ifile3("Song/song3.wav");
    if (ifile3) {
  // The file exists, and is open for input
    cout<<"Track N°3"<<endl;
    PlaySound(TEXT("Song/song3.wav"),NULL,SND_SYNC);
    }

    //quarta
    ifstream ifile4("Song/song4.wav");
    if (ifile4) {
  // The file exists, and is open for input
    cout<<"Track N°4"<<endl;
    PlaySound(TEXT("Song/song4.wav"),NULL,SND_SYNC);
    }

    //quinta
    ifstream ifile5("Song/song5.wav");
    if (ifile4) {
  // The file exists, and is open for input
    cout<<"Track N°5"<<endl;
    PlaySound(TEXT("Song/song5.wav"),NULL,SND_SYNC);
    }
                }
    }








/*
 //esempio
    //prima
    ifstream ifile("Song/test.wav");
    if (ifile) {
  // The file exists, and is open for input
    cout<<"Track N°1"<<endl;
    PlaySound(TEXT("Song/test.wav"),NULL,SND_SYNC);

    //seconda song
        ifstream ifile2("Song/test2.wav");
    if (ifile2) {
  // The file exists, and is open for input
    cout<<"Track N°2"<<endl;
    PlaySound(TEXT("Song/test2.wav"),NULL,SND_SYNC);
            }


            //fine di tutto
            }
*/

//Se non ci sono



}















    system("pause");
    mainc();
}
