#include "../AI/AI.h"
#include "../AI/Functions.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
    srand (time(NULL));
	HANDLE hPipe;
    DWORD dwRead;
	
	
    hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\Pipe"),
                            PIPE_ACCESS_DUPLEX | PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,   // FILE_FLAG_FIRST_PIPE_INSTANCE is not needed but forces CreateNamedPipe(..) to fail if the pipe already exists...
                            PIPE_WAIT,
                            1,
                            1024 * 16,
                            1024 * 16,
                            NMPWAIT_USE_DEFAULT_WAIT,
                            NULL);
	
    int depth = atoi(argv[1]);
    /*const char* pgrm = argv[1];
    const char* file = argv[2];*/
    bool win = false;
    Player p1, p2, Ap; //p1 = tester, p2 = newcomer, Ap = active player
    p2.setPlayer(false);
    int row = -1;
    Box source[6][7];
    Board playboard(source, 6, 7);
    ostringstream oss;
    oss << "start cmd.exe /k ";
    oss << argv[2];
    string AIstr = oss.str();
    cout << endl;
    //Init board
    BoardToFile(playboard, "playboard.txt");
    //BoardToFile(playboard, file);
    cout << "Board file set." << endl;
    //Set the begining player;
    if ((rand() % 2 + 1) == 1) {
        Ap = p1;
    } else {
        Ap = p2;
    }
    while (win == false) {
        if (Ap.getPlayer() == p1.getPlayer()) { //tester turn
            system("start "" cmd.exe /k AI\\AI.exe"); //Set the exe file for the tester
                cout << "Player 1 must send their play" << endl;
        } else { //AI turn
            system(AIstr.c_str()); //Set the exe file for the AI to test
            cout << "Player 2 must send their play" << endl;
        }
        //Wait for the player program to send its play
        cout << "Waiting for connection..." << endl;
		    char buffer[1024];
			bool test = true;
        while (test == true && hPipe != INVALID_HANDLE_VALUE) {
            if (ConnectNamedPipe(hPipe, NULL) != FALSE) {   // wait for someone to connect to the pipe
                while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE) {
                    /* add terminating zero */
                    buffer[dwRead] = '\0';

                    /* do something with data in buffer */
                
                    test = false;
                }
            }
            DisconnectNamedPipe(hPipe);
        }
		
		
		
		cout << endl << "Row received : " << buffer << endl;
        row = atoi(buffer);
        cout << "Playing on row " << row << endl;
        if (playboard.setToken(row, Ap) == false) {
            cout << "INVALID PLAY, PLAYER " << Ap.getPlayer() << " DISQUALIFED" << endl;
            win = true;
            Ap.setPlayer(!Ap.getPlayer());
        }
        BoardToFile(playboard, "playboard.txt");
        if (playboard.getScoreWinLose(Ap) == 2) {
            win = true;
        }
        //win = true;
        Ap.setPlayer(!Ap.getPlayer()); //Change turns
    }

    if (Ap.getPlayer() == true) {
        cout << "The winner is the tested AI, congratulations !" << endl;
    } else {
        cout << "The winner is the tester, better luck next time !" << endl;
    }

	return 0;
}
