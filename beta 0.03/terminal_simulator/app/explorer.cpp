/* Windows File Manager V1 By Uranium-239 */
/* Delete, Open, MD5 */

#include <windows.h>
#include <strings.h>
#include <fstream>
#include <wincrypt.h>

using namespace std;

#define ListB 100
#define OPEN_OBJECT 0x01
#define SHIFT_BACK  0x02
#define MD5         0x03
#define DEL         0x04




static HWND filelist = 0;

char directory[500]="C:\\";

void DeleteMyFile(char buffer[]){
     char file[600];
     strcpy(file,directory);
     strcat(file,buffer);
     if(MessageBox(0,file,"Delete this file?",MB_YESNO)==IDYES){
        DeleteFile(file);
     }
}

void MD5Hash(BYTE hash[],int sz,char sec[]){
    HCRYPTPROV hProv = 0,hHash = 0;
    BYTE rgbHash[16];
    DWORD cbHash = 0;
    char file[MAX_PATH],dig[] = "0123456789abcdef";
    int l=0;
    
    CryptAcquireContext(&hProv,NULL,NULL,PROV_RSA_FULL,CRYPT_VERIFYCONTEXT);
    CryptCreateHash(hProv,CALG_MD5,0,0,&hHash);
    CryptHashData(hHash,hash,sz,0);
    cbHash = 16;
    CryptGetHashParam(hHash, HP_HASHVAL, rgbHash, &cbHash, 0);
    
    for(DWORD i=0;i<cbHash;i++){
        sec[l]=dig[rgbHash[i]>>4];
        l++;
        sec[l]=dig[rgbHash[i] & 0xf];
        l++;
    }
    for(l=32;l<strlen(sec);l++)sec[l]=0;
    
    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);
}

int MessageBoxFileHashSum(char buffer[]){
    char file[600];
    strcpy(file,directory);
    strcat(file,buffer);
    ifstream read(file,ios::binary);
    read.seekg(0,ios::end);
    int l = read.tellg();
    read.seekg(0,ios::beg);
    char * buf = 0;
    if((buf = (char*)malloc(l)) == NULL){
            MessageBox(0,"Directorys cannot be summed",0,0);
            return 0;
    }
    read.read(buf,l);
    if(read.fail()){
       free(buf);
       MessageBox(NULL,"Error Opening File","Uranium-239",MB_OK);
       return 0;
    }
    read.close();
    
    char hash[32];
    MD5Hash((BYTE*)buf,l,hash);
    free(buf);
    
    MessageBox(NULL,hash,"File Checksum:",MB_OK);
}

void UpdateList(){
    char path[500];
    strcpy(path,directory);
    strcat(path,"*.*");
    
    WIN32_FIND_DATA data;
    HANDLE hFile = FindFirstFileA(path, &data);
    SendMessage(filelist, LB_RESETCONTENT, 0, 0);
    while(FindNextFile(hFile,&data)!=0)
    {
            SendMessage(filelist, LB_INSERTSTRING, (WPARAM) -1, (LPARAM)data.cFileName);
    }
    FindClose(hFile);
}

void RemoveLastDirectory(){
     int i[3];
     i[3]=strlen(directory);
     for(i[0]=0;i[0]<i[3];i[0]++){
         if(directory[i[0]]=='\\'){
            i[2]=i[1];
            i[1]=i[0];
         }
     }
     for(i[2]++;i[2]<i[3];i[2]++)directory[i[2]]=0;
} 

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "FileViewer";

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadCursor (NULL, IDC_ARROW);
    wincl.hIconSm = LoadCursor (NULL, IDC_ARROW);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(1,1,1));

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "File Manager",       /* Title Text */
           WS_SYSMENU | WS_MINIMIZEBOX,
           100,       /* Windows decides the position */
           50,       /* where the window ends up on the screen */
           412,                 /* The programs width */
           460,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND open = 0;
    static HWND back = 0;
    static HWND md5 = 0;
    static HWND del = 0;
    
    char buffer[500];
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        case WM_CREATE:
             filelist=CreateWindow(
             "ListBox",
             0,
             WS_CHILD | LBS_MULTICOLUMN | WS_VISIBLE | WS_BORDER | WS_VSCROLL | WS_HSCROLL | LBS_DISABLENOSCROLL | LBS_NOTIFY,
             2,2,400,400,
             hwnd,
             (HMENU)ListB,
             ((LPCREATESTRUCT) lParam)->hInstance,
             NULL
             ); 
             SendMessage(filelist,LB_SETCOLUMNWIDTH,(WPARAM)200,0);
             open = CreateWindow(
             "BUTTON",
             "Open",
             WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
             2,390,100,30,
             hwnd,
             (HMENU)OPEN_OBJECT,
             ((LPCREATESTRUCT) lParam)->hInstance,
             NULL
             ); 
             back = CreateWindow(
             "BUTTON",
             "Back",
             WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
             100,390,100,30,
             hwnd,
             (HMENU)SHIFT_BACK,
             ((LPCREATESTRUCT) lParam)->hInstance,
             NULL
             ); 
             md5 = CreateWindow(
             "BUTTON",
             "MD5 Sum",
             WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
             200,390,100,30,
             hwnd,
             (HMENU)MD5,
             ((LPCREATESTRUCT) lParam)->hInstance,
             NULL
             ); 
             del = CreateWindow(
             "BUTTON",
             "Delete",
             WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
             300,390,100,30,
             hwnd,
             (HMENU)DEL,
             ((LPCREATESTRUCT) lParam)->hInstance,
             NULL
             ); 
             UpdateList();

        case WM_COMMAND:

                   int c;

                   switch(LOWORD(wParam))
                   {
                          
                          case ListB:

                          if(HIWORD(wParam) == LBN_DBLCLK)
                          {
                             BOOL file;
                             c = SendMessage(filelist, LB_GETCURSEL, 0, 0);
                             SendMessage(filelist,LB_GETTEXT,(WPARAM)c,(LPARAM)buffer);
                             if(strcmp(buffer,"..")==0)
                             {
                                RemoveLastDirectory();
                             }
                             
                             else
                             {
                                if(strstr(buffer,".")!=NULL)file=TRUE;
                                
                                else file=FALSE;
                                
                                if(file==FALSE)
                                {
                                   strcat(buffer,"\\");
                                   strcat(directory,buffer);
                                }
                                
                                else
                                {
                                   char p_b[500];
                                   strcpy(p_b,directory);
                                   strcat(p_b,buffer);
                                   ShellExecute(0,"open",p_b,0,0,SW_SHOW);
                                }
                               }
                               UpdateList();
                               }
                               break;
                               
             if (HIWORD(wParam) == BN_CLICKED)
             {
                                                                         
                          case DEL:
                               c = SendMessage(filelist, LB_GETCURSEL, 0, 0);
                               SendMessage(filelist,LB_GETTEXT,(WPARAM)c,(LPARAM)buffer);
                               DeleteMyFile(buffer);
                               UpdateList();
                               break;
                          case MD5:
                               c = SendMessage(filelist, LB_GETCURSEL, 0, 0);
                               SendMessage(filelist,LB_GETTEXT,(WPARAM)c,(LPARAM)buffer);
                               MessageBoxFileHashSum(buffer);
                               break;
                          case SHIFT_BACK:
                               RemoveLastDirectory();
                               UpdateList();
                               break;
                          case OPEN_OBJECT:
                               BOOL file;
                               c = SendMessage(filelist, LB_GETCURSEL, 0, 0);
                               SendMessage(filelist,LB_GETTEXT,(WPARAM)c,(LPARAM)buffer);
                               if(strcmp(buffer,"..")==0){
                               RemoveLastDirectory();
                               }else{
                                   if(strstr(buffer,".")!=NULL)file=TRUE;
                                   else file=FALSE;
                                   if(file==FALSE){
                                      strcat(buffer,"\\");
                                      strcat(directory,buffer);
                                   }else{
                                   char p_b[500];
                                   strcpy(p_b,directory);
                                   strcat(p_b,buffer);
                                   ShellExecute(0,"open",p_b,0,0,SW_SHOW);
                                   }
                               }
                               UpdateList();
                               break;
                   }
             }                
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

