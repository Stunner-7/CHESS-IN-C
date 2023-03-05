#ifndef BOARD_H
#define BOARD_H
#include <windows.h>


#include <stdio.h>
#include<stdlib.h>
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

#define PIECE_NONE 0
#define PIECE_PAWN 1
#define PIECE_KNIGHT 2
#define PIECE_BISHOP 3
#define PIECE_ROOK 4
#define PIECE_QUEEN 5
#define PIECE_KING 6

typedef struct {
    int color;
    int type;
} Piece;


typedef struct {
    Piece board[BOARD_WIDTH][BOARD_HEIGHT];
    int turn;
    int whiteillegal;
    int blackillegal;
} GameState;

void Display();




void Display(GameState* gameState) {
    
    system("cls");
    printf("--------------------------------------\n");
    for (int i = 7; i > -1; i--) {
        printf("| %d ", i);
        for (int j = 0; j < 8; j++) {
            int k, col;
            k = gameState->board[j][i].type;
            col = gameState->board[j][i].color;
            if (col == 1) {
                if (k == 0) {
                    printf("|   ");
                }
                else if (k == 1) {
                    printf("| p ");
                }
                else if (k == 2) {
                    printf("| n ");
                }
                else if (k == 3) {
                    printf("| b ");
                }
                else if (k == 4) {
                    printf("| r ");
                }
                else if (k == 5) {
                    printf("| q ");
                }
                else if (k == 6) {
                    printf("| k ");
                }
            }
            else {
                if (k == 0) {
                    printf("|   ");
                }
                else if (k == 1) {
                    printf("| P ");
                }
                else if (k == 2) {
                    printf("| N ");
                }
                else if (k == 3) {
                    printf("| B ");
                }
                else if (k == 4) {
                    printf("| R ");
                }
                else if (k == 5) {
                    printf("| Q ");
                }
                else if (k == 6) {
                    printf("| K ");
                }
            }


        }
        printf("|\n");
        printf("--------------------------------------\n");
    }

    printf("    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
    printf("--------------------------------------\n");
}


#endif // !BOARD_H;