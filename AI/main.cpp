#include "AI.h"
#include "Functions.h"
#include "main.h"
#include <winsock2.h>

using namespace std;


int main(int argc, char **argv) //Find the best play from a given board in a file
{   
    WSADATA WSAData;
    SOCKET sock;
    SOCKADDR_IN sin;
    char* msg = "";
    int depth = atoi(argv[1]);
    WSAStartup(MAKEWORD(2,0), &WSAData);
	//Initialiser le board ici
    Player p1, p2;
    p2.setPlayer(false);
    Box source[6][7];
    Board playboard(source, 6, 7);
    playboard = FileToBoard("playboard.txt");
    
    //Init and bind socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(2000);
    connect(sock, (SOCKADDR *)&sin, sizeof(sin));    
    std::pair<int, int> play = BestPlay(p1, playboard, depth);
    itoa(play.second, msg, 10);
    send(sock, msg, 1,0);
    
    closesocket(sock);
    WSACleanup();
    return 0;
}