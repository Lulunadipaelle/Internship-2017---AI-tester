#include "../AI/AI.h"
#include "../AI/Functions.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

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
	
    //int depth = atoi(argv[1]);
    bool win = false;
    Player p1, p2, Ap; //p1 = tester, p2 = newcomer, Ap = active player
    p2.setPlayer(false);
    int row = -1;
    Box source[6][7];
    Board playboard(source, 6, 7);
    
    cout << endl;
    //Init board
    BoardToFile(playboard, "F:\\My_Projects\\Internship-2017-AI-tester\\playboard.txt");
    cout << "Board file set." << endl;
    //Set the begining player;
    if ((rand() % 2 + 1) == 1) {
        Ap = p1;
    } else {
        Ap = p2;
    }
    while (win == false) {
        if (Ap.getPlayer() == p1.getPlayer()) { //tester turn
            //system("start cmd.exe /k F:\\My_Projects\\Internship-2017-AI-tester\\AI\\Debug\\AI.exe"); //TODO Set the exe file for the tester
                cout << "Player 1 must send their play" << endl;
        } else { //AI turn
            //system("start cmd.exe /k F:\\My_Projects\\Internship-2017-AI-tester\\UI\\Debug\\UI.exe"); //TODO Set the exe file for the AI to test
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
        playboard.setToken(row, Ap);
        //TODO Changer la méthode setToken pour qu'elle renvoie une erreur si row est invalide
        BoardToFile(playboard, "F:\\My_Projects\\Internship-2017-AI-tester\\playboard.txt");
        //TODO établir conditions de victoire : réutiliser getScoreWinLose ?
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
