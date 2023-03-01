#ifndef CHESS_H
#define CHESS_H
#include <stdio.h>
#include "board.h"
int ErrorDiag();
int ErrorStr();
void initGameState();
void MoveCheck();
void ReadytoCheck();// THESE 2 are yet to be done......  First do checkking and then put ready to check by deleting the chosen piece and use checkking fn inside it to see if it will be in check......
void CheckKing();
//DIAGNOL ERROR FINDER
int ErrorDiag(int x1, int y1, int x, int y, GameState* gameState) {
    int error = 0;
    if ((x1 - x) > 0) {
        for (int i = 1; i < x1 - x; i++) {
            if (gameState->board[x + i][y + i].type == PIECE_NONE) {
                error = 1;
            }
            else {
                error = 0;
                break;

            }
        }
    }

    else if ((x - x1) > 0) {
        for (int i = 1; i < x - x1; i++) {
            if (gameState->board[x - i][y - i].type == PIECE_NONE) {
                error = 1;
            }
            else {
                error = 0;
                break;

            }
        }
    }

    return error;
}

// Straight line error finder
int ErrorStr(int x1, int y1, int x, int y, GameState* gameState) {
    int error = 0;
    if (y1 == y) {
        if ((x - x1) > 0) {
            for (int i = 1; i < x - x1; i++) {
                if (gameState->board[x - i][y].type == PIECE_NONE) {
                    error = 1;
                }
                else {
                    error = 0;
                    break;

                }
            }
        }
        if ((x1 - x) > 0) {
            for (int i = 1; i < x1 - x; i++) {
                if (gameState->board[x + i][y].type == PIECE_NONE) {
                    error = 1;
                }
                else {
                    error = 0;
                    break;

                }
            }
        }

    }
    else {
        if ((y - y1) > 0) {
            for (int i = 1; i < y - y1; i++) {
                if (gameState->board[x][y - i].type == PIECE_NONE) {
                    error = 1;
                }
                else {
                    error = 0;
                    break;

                }
            }
        }
        if ((y1 - y) > 0) {
            for (int i = 1; i < y1 - y; i++) {
                if (gameState->board[x][y + i].type == PIECE_NONE) {
                    error = 1;
                }
                else {
                    error = 0;
                    break;

                }
            }
        }
    }
    return error;
}

// Define a function to initialize the game state
void initGameState(GameState* gameState) {
    // ROW1
    gameState->board[0][0].type = PIECE_ROOK;
    gameState->board[0][0].color = 1;
    gameState->board[1][0].type = PIECE_KNIGHT;
    gameState->board[1][0].color = 1;
    gameState->board[2][0].type = PIECE_BISHOP;
    gameState->board[2][0].color = 1;
    gameState->board[3][0].type = PIECE_QUEEN;
    gameState->board[3][0].color = 1;
    gameState->board[4][0].type = PIECE_KING;
    gameState->board[4][0].color = 1;
    gameState->board[5][0].type = PIECE_BISHOP;
    gameState->board[5][0].color = 1;
    gameState->board[6][0].type = PIECE_KNIGHT;
    gameState->board[6][0].color = 1;
    gameState->board[7][0].type = PIECE_ROOK;
    gameState->board[7][0].color = 1;

    //ROW 2
    gameState->board[0][1].type = PIECE_PAWN;
    gameState->board[0][1].color = 1;
    gameState->board[1][1].type = PIECE_PAWN;
    gameState->board[1][1].color = 1;
    gameState->board[2][1].type = PIECE_PAWN;
    gameState->board[2][1].color = 1;
    gameState->board[3][1].type = PIECE_PAWN;
    gameState->board[3][1].color = 1;
    gameState->board[4][1].type = PIECE_PAWN;
    gameState->board[4][1].color = 1;
    gameState->board[5][1].type = PIECE_PAWN;
    gameState->board[5][1].color = 1;
    gameState->board[6][1].type = PIECE_PAWN;
    gameState->board[6][1].color = 1;
    gameState->board[7][1].type = PIECE_PAWN;
    gameState->board[7][1].color = 1;

    // ROW 7
    gameState->board[0][6].type = PIECE_PAWN;
    gameState->board[0][6].color = 0;
    gameState->board[1][6].type = PIECE_PAWN;
    gameState->board[1][6].color = 0;
    gameState->board[2][6].type = PIECE_PAWN;
    gameState->board[2][6].color = 0;
    gameState->board[3][6].type = PIECE_PAWN;
    gameState->board[3][6].color = 0;
    gameState->board[4][6].type = PIECE_PAWN;
    gameState->board[4][6].color = 0;
    gameState->board[5][6].type = PIECE_PAWN;
    gameState->board[5][6].color = 0;
    gameState->board[6][6].type = PIECE_PAWN;
    gameState->board[6][6].color = 0;
    gameState->board[7][6].type = PIECE_PAWN;
    gameState->board[7][6].color = 0;

    // ROW 8
    gameState->board[0][7].type = PIECE_ROOK;
    gameState->board[0][7].color = 0;
    gameState->board[1][7].type = PIECE_KNIGHT;
    gameState->board[1][7].color = 0;
    gameState->board[2][7].type = PIECE_BISHOP;
    gameState->board[1][7].color = 0;
    gameState->board[3][7].type = PIECE_QUEEN;
    gameState->board[3][7].color = 0;
    gameState->board[4][7].type = PIECE_KING;
    gameState->board[4][7].color = 0;
    gameState->board[5][7].type = PIECE_BISHOP;
    gameState->board[5][7].color = 0;
    gameState->board[6][7].type = PIECE_KNIGHT;
    gameState->board[6][7].color = 0;
    gameState->board[7][7].type = PIECE_ROOK;
    gameState->board[7][7].color = 0;


    //EMPTY ROWS
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            gameState->board[j][i].type = PIECE_NONE;
        }

    }

    gameState->turn = 0;
};

void WhiteMoveCheck(int piece, int x, int y,int x1, int y1, GameState* gameState) {
    //PAWN
    if (piece == 1) {


    }
    //knight
    else if (piece == 2) {
        int dx = abs(x1 - x);
        int dy = abs(y1 - y);

        
        if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
            if (!(gameState->board[x1][y1].color == 1)) {
                gameState->board[x1][y1].type = gameState->board[x][y].type;
                gameState->board[x1][y1].color = 1;
                gameState->board[x][y].type = PIECE_NONE;
                gameState->board[x][y].color = NULL;
                gameState->turn++;
            }
            else {
                printf("INVALID MOVE:Cannot attack piece of same color , try again");
            }
        }
        else {
            printf("INVALID MOVE:Knight move illegal, try again");
        }
    }
    //BISHOP
    else if (piece == 3) {
        // Calculate the distance between the piece's current position and the target position
        int dx = abs(x1 - x);
        int dy = abs(y1 - y);

        // Check if the move is diagonal
        if (dx == dy) {
            // Check if there are any pieces blocking the path to the target
            int xDir = (x1> x) ? 1 : -1;
            int yDir = (y1 > y) ? 1 : -1;
            int x2 = x + xDir;
            int y2 = y + yDir;
            int error = 1;
            while (x2 != x1 && y2 != y1) {
                if (gameState->board[x2][y2].type != PIECE_NONE) {
                    printf("INVALID MOVE:Path is blocked");
                    error = 0;
                }
                x2 += xDir;
                y2 += yDir;
            }
            // Check if the target square is empty or occupied by an opponent piece
            if (error == 1) {
                if (!(gameState->board[x1][y1].color == 1)) {
                    gameState->board[x1][y1].type = gameState->board[x][y].type;
                    gameState->board[x1][y1].color = 1;
                    gameState->board[x][y].type = PIECE_NONE;
                    gameState->board[x][y].color = NULL;
                    gameState->turn++;
                }
                else {
                    printf("INVALID MOVE:Cannot attack piece of same color , try again");
                }
            }
        }
        else {
            printf("INVALID MOVE:Bishop move Illegal, try again");
        }
    }
    //ROOK
    else if (piece == 4) {
        // Calculate the distance between the piece's current position and the target position
        int dx = abs(x1 - x);
        int dy = abs(y1- y);

        // Check if the move is horizontal or vertical
        if ((dx > 0 && dy == 0) || (dx == 0 && dy > 0)) {
            // Check if the path to the target square is clear
            int xdir = (x1 > x) ? 1 : ((x1 < x) ? -1 : 0);
            int ydir = (y1 > y) ? 1 : ((y1 < y) ? -1 : 0);
            int x2 = x;
            int y2 = y;
            x2 += xdir;
            y2 += ydir;
            int error = 1;
            while (x2 != x1 || y2 != y1) {
                if (gameState->board[x2][y2].type != PIECE_NONE) {
                    printf("INVALID MOVE:path is blocked , try again");
                    error = 0;

                }
                x2 += xdir;
                y2 += ydir;
            }
            // Check if the target square is empty or occupied by an opponent piece
            if (error == 1) {
                if (!(gameState->board[x1][y1].color == 1)) {
                    gameState->board[x1][y1].type = gameState->board[x][y].type;
                    gameState->board[x1][y1].color = 1;
                    gameState->board[x][y].type = PIECE_NONE;
                    gameState->board[x][y].color = NULL;
                    gameState->turn++;
                }
                else {
                    printf("INVALID MOVE:Cannot attack piece of same color , try again");
                }
            }
        }

        else
            printf("INVALID MOVE:Rook move Illegal , try again");
    }
    //QUEEN
    else if (piece == 5) {
        // Calculate the distance between the piece's current position and the target position
        int dx = abs(x1 - x);
        int dy = abs(y1 - y);

        // Check if the move is horizontal or vertical
        if ((dx > 0 && dy == 0) || (dx == 0 && dy > 0)) {
            // Check if the path to the target square is clear
            int xdir = (x1 > x) ? 1 : ((x1 < x) ? -1 : 0);
            int ydir = (y1 > y) ? 1 : ((y1 < y) ? -1 : 0);
            int x2 = x;
            int y2 = y;
            x2 += xdir;
            y2 += ydir;
            int error = 1;
            while (x2 != x1 || y2 != y1) {
                if (gameState->board[x2][y2].type != PIECE_NONE) {
                    printf("INVALID MOVE:path is blocked , try again");
                    error = 0;

                }
                x2 += xdir;
                y2 += ydir;
            }
            // Check if the target square is empty or occupied by an opponent piece
            if (error == 1) {
                if (!(gameState->board[x1][y1].color == 1)) {
                    gameState->board[x1][y1].type = gameState->board[x][y].type;
                    gameState->board[x1][y1].color = 1;
                    gameState->board[x][y].type = PIECE_NONE;
                    gameState->board[x][y].color = NULL;
                    gameState->turn++;
                }
                else {
                    printf("INVALID MOVE:Cannot attack piece of same color , try again");
                }
            }
        }
        else if (dx == dy) {
            // Check if there are any pieces blocking the path to the target
            int xDir = (x1 > x) ? 1 : -1;
            int yDir = (y1 > y) ? 1 : -1;
            int x2 = x + xDir;
            int y2 = y + yDir;
            int error = 1;
            while (x2 != x1 && y2 != y1) {
                if (gameState->board[x2][y2].type != PIECE_NONE) {
                    printf("INVALID MOVE:Path is blocked");
                    error = 0;
                }
                x2 += xDir;
                y2 += yDir;
            }
            // Check if the target square is empty or occupied by an opponent piece
            if (error == 1) {
                if (!(gameState->board[x1][y1].color == 1)) {
                    gameState->board[x1][y1].type = gameState->board[x][y].type;
                    gameState->board[x1][y1].color = 1;
                    gameState->board[x][y].type = PIECE_NONE;
                    gameState->board[x][y].color = NULL;
                    gameState->turn++;
                }
                else {
                    printf("INVALID MOVE:Cannot attack piece of same color , try again");
                }
            }
        }
        else {
            printf("INVALID MOVE:Queen move Illegal, try again");
        }
    }
    //KING
    else if (piece == 6) {
    // Calculate the distance between the piece's current position and the target position
    int dx = abs(x1 - x);
    int dy = abs(y1 - y);

    // Check if the move is valid for a king (one square in any direction)
    if (dx <= 1 && dy <= 1) {
        // Check if the target square is empty or occupied by an opponent piece
        if (!(gameState->board[x1][y1].color == 1)) {
            gameState->board[x1][y1].type = gameState->board[x][y].type;
            gameState->board[x1][y1].color = 1;
            gameState->board[x][y].type = PIECE_NONE;
            gameState->board[x][y].color = NULL;
            gameState->turn++;
        }
        else {
            printf("INVALID MOVE:Cannot attack piece of same color , try again");
        }
    }
    else
        printf("INVALID MOVE:King move Illegal, try again");
    }
}

// Define a function to handle a player's turn 
void handleTurn(GameState* gameState) {
    int x = 0, y = 0, piece = 0;

    if ((gameState->turn) % (2) == 0) {
        printf("Hey there White player ! \n");
        printf("Which piece do you want to move? Enter position in x and y coordinate respectively");
        scanf_s("%d  %d", &x, &y);

        if (x > -1 && x<8 && y >-1 && y < 8 && gameState->board[x][y].color == 1) {//Checked if the given piece is inside board and if its for white coin 
            piece = gameState->board[x][y].type;
           
        }
        else
            printf("INVALID INPUT:no such square exists ,try again");

        int x1, y1;
        printf("Where do you want to move it to ? ");
        scanf_s("%d %d", &x1, &y1);
        WhiteMoveCheck(piece, x, y, x1, y1, gameState);
    }
    else {
        printf("BLACK TURN");
        gameState->turn++;
    }
    
}


#endif // !CHESS_H;
