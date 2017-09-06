#include "main.h"
#include "AI.h"
#include "Functions.h"
#include <winsock2.h>
using namespace std;


int main(int argc, char **argv) //Find the best play from a given board in a file
{   
    int depth = 8;
    string msg;
    HANDLE hPipe;
    DWORD dwWritten;
	//Init board here
    Player p1, p2;
    p2.setPlayer(false);
    Box source[6][7];
    Board playboard(source, 6, 7);
    playboard = FileToBoard("..\\playboard.txt");
    
    //Ask for the row to play
    std::pair<int, int> play = BestPlay(p1, playboard, depth);
    //msg << play.second;
    msg = to_string(play.second);
	
	    hPipe = CreateFile(TEXT("\\\\.\\pipe\\Pipe"), 
                       GENERIC_READ | GENERIC_WRITE, 
                       0,
                       NULL,
                       OPEN_EXISTING,
                       0,
                       NULL);
    if (hPipe != INVALID_HANDLE_VALUE) {
        WriteFile(hPipe,
                  msg.c_str(),
                  12,   // = length of string + terminating '\0' !!!
                  &dwWritten,
                  NULL);

        CloseHandle(hPipe);
    }
    system("exit");
    return 0;
}