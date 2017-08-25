#include "AI.h"
#include "Functions.h"
#include <windows.h>
//#include <winsock2.h>
#pragma comment(lib,"ws_32.lib")

using namespace std;

int main(int argc, char **argv)
{
    WSADATA WSAData;
    SOCKET sock;
    SOCKET csock;
    SOCKADDR_IN sin;
    SOCKADDR_IN csin;
    char buffer[255];
    int depth = atoi(argv[1]);
    bool win = false;
    Player p1, p2, Ap; //p1 = tester, p2 = newcomer, Ap = active player
    p2.setPlayer(false);
    int row = -1;
    Box source[6][7];
    Board playboard(source, 6, 7);
    
    //Create socket
    if (WSAStartup(MAKEWORD(2,0), &WSAData) != NO_ERROR) {
        cerr << "Socket init error (WSASTartup in Referee)" << endl;
        WSACleanup();
        exit(10);
    }
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cerr << "Socket init error (creating socket in Referee)" << endl;
        WSACleanup();
        exit(11);
    }
    
    //Bind socket
    sin.sin_addr.s_addr	= inet_addr("127.0.0.1");
    sin.sin_family		= AF_INET;
    sin.sin_port		= htons(2000);
    
    if (bind(mySocket, (SOCKADDR*) &sin, sizeof(sin)) == SOCKET_ERROR) {
        cerr << "Server socket : Failed to connect (bind)" << endl;
        WSACleanup();
        exit(12);
    }
    cout << endl;
    //Init board
    BoardToFile(playboard, "playboard.txt");
    cout << "Board file set." << endl;
    //Set the begining player;
    if ((r  and() % 2 + 1) == 1) {
        Ap = p1;
    else {
        Ap = p2;
    }
    listen(sock,0);
    while (win == false) {
        if (Ap.getPlayer() == p1.getPlayer()) { //tester turn
            system(".exe"); //TODO Set the exe file for the tester
                
        } else { //AI turn
            system(".exe"); //TODO Set the exe file for the AI to test

        }
        //Wait for the player program to send its play
        if (accept(mySocket, (SOCKADDR *)&))
        int sinsize = sizeof(csin);
        if (csock = accept(sock, (SOCKADDR *)&csin, &sinsize) == INVALID_SOCKET) {
            cerr << "Server socket : Invalid socket received (socket accept Ap = 1)" << endl;
            WSACleanup();
            exit(13);
        }
        recv(sock, buffer, sizeof(buffer), 0);
        row = atoi(buffer);
        playboard.setToken(row, Ap);
        //TODO Changer la méthode setToken pour qu'elle renvoie une erreur si row est invalide
        BoardToFile(playboard, "playboard.txt");
        //TODO établir conditions de victoire : réutiliser getScoreWinLose ?
        if (playboard.getScoreWinLose(Ap) == 2) {
            win = true;
        }
        //Close player sock
        closesocket(csock);
        Ap.setPlayer(!Ap.getPlayer()); //Change turns
    }
    closesocket(sock);
    WSACleanup();
    if (Ap.getPlayer() == true) {
        cout << "The winner is the tested AI, congratulations !" << endl;
    } else {
        cout << "The winner is the tester, better luck next time !" << endl;
    }
	return 0;
}
