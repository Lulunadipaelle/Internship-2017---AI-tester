#include "AI.h"

Board::Board(Box tab[6][7], int line, int row){
for(int i = 0;i<6;i++){
	for (int j = 0; j<7;j++){
		array[i][j] = tab[i][j];
		}
	}  
}

int Board::getScoreWinLose(Player P) { 
    //test if we've won
    for (int i=5;i>=3;i--) { //up right
        for (int j=6;j>=3;j--) { 
            if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                if ((array[i][j-1].isEmpty() == false) && (array[i][j-1].whichColor() == P.getPlayer())) {
                    if ((array[i][j-2].isEmpty() == false) && (array[i][j-2].whichColor() == P.getPlayer())) {
                        if ((array[i][j-3].isEmpty() == false) && (array[i][j-3].whichColor() == P.getPlayer())) {
                            return 2; // --
                        }
                    }
                }
            } else if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                if ((array[i-1][j-1].isEmpty() == false) && (array[i-1][j-1].whichColor() == P.getPlayer())) {
                    if ((array[i-2][j-2].isEmpty() == false) && (array[i-2][j-2].whichColor() == P.getPlayer())) {
                        if ((array[i-3][j-3].isEmpty() == false) && (array[i-3][j-3].whichColor() == P.getPlayer())) {
                            return 2; // /
                        }
                    }
                }
            } else if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                if ((array[i-1][j].isEmpty() == false) && (array[i-1][j].whichColor() == P.getPlayer())) {
                    if ((array[i-2][j].isEmpty() == false) && (array[i-2][j].whichColor() == P.getPlayer())) {
                        if ((array[i-3][j].isEmpty() == false) && (array[i-3][j].whichColor() == P.getPlayer())) {
                            return 2; // |
                        }
                    }
                }
            }
            
        }
    }
    
    for (int i=2;i>=0;i--) { //down right
        for (int j=6;j>=3;j--) { 
            if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                if ((array[i][j-1].isEmpty() == false) && (array[i][j-1].whichColor() == P.getPlayer())) {
                    if ((array[i][j-2].isEmpty() == false) && (array[i][j-2].whichColor() == P.getPlayer())) {
                        if ((array[i][j-3].isEmpty() == false) && (array[i][j-3].whichColor() == P.getPlayer())) {
                            return 2; // --
                        }
                    }
                }
            } else if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                if ((array[i+1][j-1].isEmpty() == false) && (array[i+1][j-1].whichColor() == P.getPlayer())) {
                    if ((array[i+2][j-2].isEmpty() == false) && (array[i+2][j-2].whichColor() == P.getPlayer())) {
                        if ((array[i+3][j-3].isEmpty() == false) && (array[i+3][j-3].whichColor() == P.getPlayer())) {
                            return 2; // /
                        }
                    }
                }
            } else if ((array[i+3][j].isEmpty() == false) && (array[i+3][j].whichColor() == P.getPlayer())) {
                if ((array[i+2][j].isEmpty() == false) && (array[i+2][j].whichColor() == P.getPlayer())) {
                    if ((array[i+1][j].isEmpty() == false) && (array[i+1][j].whichColor() == P.getPlayer())) {
                        if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                            return 2; // |
                        }
                    }
                }
            }
            
        }
    }
    
    for (int i=5;i>=3;i--) { //up left
        for (int j=3;j>=0;j--) { 
            if ((array[i][j+3].isEmpty() == false) && (array[i][j+3].whichColor() == P.getPlayer())) {
                if ((array[i][j+2].isEmpty() == false) && (array[i][j+2].whichColor() == P.getPlayer())) {
                    if ((array[i][j+1].isEmpty() == false) && (array[i][j+1].whichColor() == P.getPlayer())) {
                        if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                            return 2; // --
                        }
                    }
                }
            } else if ((array[i-3][j+3].isEmpty() == false) && (array[i-3][j+3].whichColor() == P.getPlayer())) {
                if ((array[i-2][j+2].isEmpty() == false) && (array[i-2][j+2].whichColor() == P.getPlayer())) {
                    if ((array[i-1][j+1].isEmpty() == false) && (array[i-1][j+1].whichColor() == P.getPlayer())) {
                        if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                            return 2; // /
                        }
                    }
                }
            } else if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                if ((array[i-1][j].isEmpty() == false) && (array[i-1][j].whichColor() == P.getPlayer())) {
                    if ((array[i-2][j].isEmpty() == false) && (array[i-2][j].whichColor() == P.getPlayer())) {
                        if ((array[i-3][j].isEmpty() == false) && (array[i-3][j].whichColor() == P.getPlayer())) {
                            return 2; // |
                        }
                    }
                }
            }
            
        }
    }
    
    for (int i=2;i>=0;i--) { //down left
        for (int j=3;j>=0;j--) { 
            if ((array[i][j+3].isEmpty() == false) && (array[i][j+3].whichColor() == P.getPlayer())) {
                if ((array[i][j+2].isEmpty() == false) && (array[i][j+2].whichColor() == P.getPlayer())) {
                    if ((array[i][j+1].isEmpty() == false) && (array[i][j+1].whichColor() == P.getPlayer())) {
                        if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                            return 2; // --
                        }
                    }
                }
            } else if ((array[i+3][j+3].isEmpty() == false) && (array[i+3][j+3].whichColor() == P.getPlayer())) {
                if ((array[i+2][j+2].isEmpty() == false) && (array[i+2][j+2].whichColor() == P.getPlayer())) {
                    if ((array[i+1][j+1].isEmpty() == false) && (array[i+1][j+1].whichColor() == P.getPlayer())) {
                        if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                            return 2; // /
                        }
                    }
                }
            } else if ((array[i+3][j].isEmpty() == false) && (array[i+3][j].whichColor() == P.getPlayer())) {
                if ((array[i+2][j].isEmpty() == false) && (array[i+2][j].whichColor() == P.getPlayer())) {
                    if ((array[i+1][j].isEmpty() == false) && (array[i+1][j].whichColor() == P.getPlayer())) {
                        if ((array[i][j].isEmpty() == false) && (array[i][j].whichColor() == P.getPlayer())) {
                            return 2; // |
                        }
                    }
                }
            }
            
        }
    }
    //Si pas de victoire on renvoie un score neutre
return 1;
    
}

void Board::setToken(int row, Player player) {
    int i=0;
    while ((i<7) && (!array[i][row].isEmpty())) {
        i++;
    }
    if (i == 6) {
        std::cout << "Error : full row (Board::setToken)";
    } else {
        array[i][row].setBox(player, true);
    }
}
 void Board::cancelPlay(int row) {
     Player p1;
    int i=5;
    while ((i>0) && (array[i][row].isEmpty())) {
        i--;
    }
        array[i][row].setBox(p1, false);
    
 }
void Board::setBox(int line, int row, Player player, bool token) {
    array[line][row].setBox(player, token);
}
Box Board::getBox(int line, int row) {
    return this->array[line][row];
}
