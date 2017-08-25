#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

std::pair<int, int> BestPlay(Player P, Board board, int depth);
void BoardToFile(Board board, char const *filename);
Board FileToBoard(char const *filename);


#endif