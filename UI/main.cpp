#include "../AI/AI.h"
#include "../AI/Functions.h"
#include <winsock2.h>

using namespace std;


int main(int argc, char **argv) //Find the best play from a given board in a file
{   

    string msg;
    HANDLE hPipe;
    DWORD dwWritten;
	//Init board here
    Player p1, p2;
    p2.setPlayer(false);
    Box source[6][7];
    Board playboard(source, 6, 7);
    playboard = FileToBoard("..\\playboard.txt");
    
    //Display the board to the user
    cout << "Welcome, Player 2 !" << endl;
    for (int i=5;i>=0;i--) {
        for (int j=0;j<7;j++) {
            if (playboard.getBox(i, j).isEmpty() == true) {
                cout << "0 ";
            } else if (playboard.getBox(i, j).whichColor() == true) {
                cout << "1 ";
            } else {
                cout << "2 ";
            }
        }
            cout << endl;
    }
    
    //Ask for the row to play
    cout << "Enter here the number of the row where you want to play (between 0 and 6)" << endl;
    cin >> msg;
	cout << endl << msg << endl;
	
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