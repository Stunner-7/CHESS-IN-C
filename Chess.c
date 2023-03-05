#include "chessmoves.h"


// Define the main game loop
int main() {
    char random;
    printf("WELCOME TO CHESS IN C \n");
    printf("RULES:\n1.WE FOLLOW ALL THE GENERAL RULES OF OLD CHESS (No En passant)\n 2.PAWN WILL AUTOMATICALLY BE PROMOTED TO QUEEN WHEN IT REACHES OPPOSITE END\n 3.EACH PLAYER IS ALLOWED 3 ILLEGAL MOVES AFTER WHICH THE OPPONENT DIRECTLY WINS! (THIS IS AN EXISTING RULE IN PHYSICAL CHESS)\n4. LOWERCASE REPRESENTS WHITE AND UPPERCASE REPRESENTS BLACK\n 5.THERE IS NO LIMIT ON THE NUMBER OF TURNS \n\n\n ENJOY YOUR GAME  \n \n \n HOPE YOU HAVE READ ALL INSTRUCTIONS..IF NOT PLEASE DO  \n TO CONTINUE TO THE GAME TYPE ANY LETTER AND  CLICK ENTER");
    scanf_s("%c", &random);
    system("cls");
    GameState gameState;
    int endgame = 0;
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            gameState.board[i][j].color = NULL;
        }
    }
    initGameState(&gameState);
    while (1) {
        endgame = EndGame(&gameState);
        if (endgame == 1) {
            break;
        }
        Display(&gameState);
        handleTurn(&gameState);
        printf("\n \n Next Round starts in 2 sec");
        Sleep(2000);
        
        
    }
    return 0;
}