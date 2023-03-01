#include "chessmoves.h"


// Define the main game loop
int main() {
    GameState gameState;
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            gameState.board[i][j].color = NULL;
        }
    }
    initGameState(&gameState);
    while (1) {
        Display(&gameState);
        handleTurn(&gameState);
        printf("\n \n Next Round starts in 2 sec");
        Sleep(2000);
    }
    return 0;
}