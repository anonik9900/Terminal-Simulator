#include <iostream>
#include <stdlib.h>
#include<windows.h>
#include "main.h"
using namespace std;
void help()
{
        HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
if(hStdOut==NULL)


    cout<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------"<<endl;
       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); //stringa che cambia il colore in verde
    cout<<"List Of Commands"<<endl;
    cout<<endl;
    cout<<"mkdir (make directory)"<<endl;
    cout<<endl;
    cout<<"play_sound (sound player)"<<endl;
    cout<<endl;
    cout<<"file_manager (open file manager application)"<<endl;
    cout<<endl;


system("pause");
    mainc();
}
