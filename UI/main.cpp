#include "../AI/AI.h"
#include "../AI/Functions.h"
#include <winsock2.h>

using namespace std;


int main(int argc, char **argv) //Find the best play from a given board in a file
{   
    WSADATA WSAData;
    SOCKET sock;
    SOCKADDR_IN sin;
    char* msg = "";
    WSAStartup(MAKEWORD(2,0), &WSAData);
	//Initialiser le board ici
    Player p1, p2;
    p2.setPlayer(false);
    Box source[6][7];
    Board playboard(source, 6, 7);
    playboard = FileToBoard("F:\\My_Projects\\Internship-2017-AI-tester\\playboard.txt");
    
    //Init and bind socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cerr << "Socket init error (creating socket in UI)" << endl;
        WSACleanup();
        exit(11);
    }
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(2000);
    if (connect(sock, (SOCKADDR *)&sin, sizeof(sin)) == SOCKET_ERROR) {
        cerr << "Socket connect error (connecting to socket in UI)" << endl;
        WSACleanup();
        exit(12);
    }
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
    send(sock, msg, 1,0);
    
    closesocket(sock);
    WSACleanup();
    return 0;
}