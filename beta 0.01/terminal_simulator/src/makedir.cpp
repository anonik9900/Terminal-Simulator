#include <iostream>
#include <direct.h>
#include <string>
#include <windows.h>

using namespace std;


void makedir()
{

string a;






string dirName; //= "C:/Users/Nicholas Impieri/Desktop/";
string usrInput; // This is where the user inputed a string of their choice

cout<<"Seleziona il percorso es (C:/Users/John/Desktop/)"<<endl; //Seleziona il percorso
cout<<endl;
cout<<"Non supporta gli spazi es (C:/Users/John Smith/)"<<endl; // non corretto
cout<<endl;
cin>> dirName;
cin.ignore();
//cin.ignore(VK_SPACE);

cout<<endl;


cout<<"Scegli il nome della tua cartella"<<endl;
cin>> usrInput;

// Combines the user input with directory info
dirName = dirName + usrInput;

mkdir(dirName.c_str());





/*cout <<"Scegli il nome per la tua cartella"<<endl;
cin>> a;


mkdir("C:/Users/Nicholas Impieri/Desktop/%a");*/


}

