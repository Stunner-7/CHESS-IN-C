#ifndef CHESS_H
#define CHESS_H
#include <stdio.h>
#include "board.h"

typedef struct XY {
    int x;
    int y;
}XY; 


void initGameState();
void KingPosition();
void MoveCheck();
void ReadytoCheck();// THESE 2 are yet to be done......  First do checkking and then put ready to check by deleting the chosen piece and use checkking fn inside it to see if it will be in check......
int CheckKing();
int EndGame();

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
            gameState->board[j][i].color = 3;
        }

    }
    gameState->whiteillegal = 0;
    gameState->blackillegal = 0;
    gameState->turn = 0;
};
void KingPosition(GameState* gameState, XY* xy) {
    if (gameState->turn % 2 == 0) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                int type = gameState->board[x][y].type;
                int col = gameState->board[x][y].color;
                if (type == PIECE_KING && col == 1) {
                    xy->x = x;
                    xy->y = y;

                }
            }
        }
        

    }
    else {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                int type = gameState->board[x][y].type;
                int col = gameState->board[x][y].color;
                if (type == PIECE_KING && col == 0) {
                    xy->x = x;
                    xy->y = y;
                    
                }
            }
        }

    }
}
int CheckKing(GameState* gameState, int x1, int y1, int x5,int y5) {
    // Find the position of the king of the specified color
    int piece = gameState->board[x1][y1].type;
    int piececolor = gameState->board[x1][y1].color;
    int piece2 = gameState->board[x5][y5].type;
    int piececolor2 = gameState->board[x5][y5].color;
    gameState->board[x1][y1].type = PIECE_NONE;
    gameState->board[x1][y1].color = 3;
    gameState->board[x5][y5].type = piece;
    gameState->board[x5][y5].color = piececolor;
    XY king;
    KingPosition(gameState, &king);

    // Check if any of the opponent's pieces can attack the king's position
    //check on white king
    if (gameState->turn % 2 == 0) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                int type = gameState->board[x][y].type;
                int col = gameState->board[x][y].color;
                if (type != PIECE_NONE && col == 0) {
                    //PAWN
                    if (type == 1) {
                        // Calculate the distance between the piece's current position and the target position
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);

                        // Determine the direction the pawn is moving based on its color
                        int dir = -1;

                        // Check if the move is a standard one or a capture
                        if (dx == 0 && dy == 1 && gameState->board[king.x][king.y].type == PIECE_NONE) {
                            // The move is a standard one square forward
                            
                        }
                        else if (dx == 1 && dy == 1 && gameState->board[king.x][king.y].type != PIECE_NONE) {
                            // The move is a capture
                            if (gameState->board[king.x][king.y].color != 0) {
                                gameState->board[x1][y1].type = piece;
                                gameState->board[x5][y5].type = piece2;
                                gameState->board[x5][y5].color = piececolor2;
                                gameState->board[x1][y1].color = piececolor;
                                return 1;
                            }
                            else {
                               
                            }
                        }
                        else if (dx == 0 && dy == 2 && y == 6 && gameState->board[king.x][king.y].type == PIECE_NONE) {
                            // The move is a two-square move from the starting position
                            int x2 = x + dir;
                            int y2 = y + dir;
                            if (gameState->board[x2][y2].type == PIECE_NONE) {
                               
                            }
                            else {
                                
                            }
                        }

                        else {
                            
                        }



                    }
                    //knight
                    else if (type == 2) {
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);


                        if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
                            if (!(gameState->board[king.x][king.y].color == 0)) {
                                gameState->board[x1][y1].type = piece;
                                gameState->board[x5][y5].type = piece2;
                                gameState->board[x5][y5].color = piececolor2;
                                gameState->board[x1][y1].color = piececolor;
                                return 1;
                            }
                            else {
                                
                            }
                        }
                        else {
                           
                        }
                    }
                    //BISHOP
                    else if (type == 3) {
                        // Calculate the distance between the piece's current position and the target position
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);

                        // Check if the move is diagonal
                        if (dx == dy) {
                            // Check if there are any pieces blocking the path to the target
                            int xDir = (king.x > x) ? 1 : -1;
                            int yDir = (king.y > y) ? 1 : -1;
                            int x2 = x + xDir;
                            int y2 = y + yDir;
                            int error = 1;
                            while (x2 != king.x && y2 != king.y) {
                                if (gameState->board[x2][y2].type != PIECE_NONE) {
                                   
                                    error = 0;
                                }
                                x2 += xDir;
                                y2 += yDir;
                            }
                            // Check if the target square is empty or occupied by an opponent piece
                            if (error == 1) {
                                if (!(gameState->board[king.x][king.y].color == 0)) {
                                    gameState->board[x1][y1].type = piece;
                                    gameState->board[x5][y5].type = piece2;
                                    gameState->board[x5][y5].color = piececolor2;
                                    gameState->board[x1][y1].color = piececolor;
                                    return 1;
                                }
                                else {
                                   
                                }
                            }
                        }
                        else {
                            
                        }
                    }
                    //ROOK
                    else if (type == 4) {
                        // Calculate the distance between the piece's current position and the target position
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);

                        // Check if the move is horizontal or vertical
                        if ((dx > 0 && dy == 0) || (dx == 0 && dy > 0)) {
                            // Check if the path to the target square is clear
                            int xdir = (king.x > x) ? 1 : ((king.x < x) ? -1 : 0);
                            int ydir = (king.y > y) ? 1 : ((king.y < y) ? -1 : 0);
                            int x2 = x;
                            int y2 = y;
                            x2 += xdir;
                            y2 += ydir;
                            int error = 1;
                            while (x2 != king.x || y2 != king.y) {
                                if (gameState->board[x2][y2].type != PIECE_NONE) {
                                    
                                    error = 0;

                                }
                                x2 += xdir;
                                y2 += ydir;
                            }
                            // Check if the target square is empty or occupied by an opponent piece
                            if (error == 1) {
                                if (!(gameState->board[king.x][king.y].color == 0)) {
                                    gameState->board[x1][y1].type = piece;
                                    gameState->board[x5][y5].type = piece2;
                                    gameState->board[x5][y5].color = piececolor2;
                                    gameState->board[x1][y1].color = piececolor;
                                    return 1;
                                }
                                else {
                                    
                                }
                            }
                        }

                        else {
                           
                        }
                    }
                    //QUEEN
                    else if (type == 5) {
                        // Calculate the distance between the piece's current position and the target position
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);

                        // Check if the move is horizontal or vertical
                        if ((dx > 0 && dy == 0) || (dx == 0 && dy > 0)) {
                            // Check if the path to the target square is clear
                            int xdir = (king.x > x) ? 1 : ((king.x < x) ? -1 : 0);
                            int ydir = (king.y > y) ? 1 : ((king.y < y) ? -1 : 0);
                            int x2 = x;
                            int y2 = y;
                            x2 += xdir;
                            y2 += ydir;
                            int error = 1;
                            while (x2 != king.x || y2 != king.y) {
                                if (gameState->board[x2][y2].type != PIECE_NONE) {
                                    
                                    error = 0;

                                }
                                x2 += xdir;
                                y2 += ydir;
                            }
                            // Check if the target square is empty or occupied by an opponent piece
                            if (error == 1) {
                                if (!(gameState->board[king.x][king.y].color == 0)) {
                                    gameState->board[x1][y1].type = piece;
                                    gameState->board[x5][y5].type = piece2;
                                    gameState->board[x5][y5].color = piececolor2;
                                    gameState->board[x1][y1].color = piececolor;
                                    return 1;
                                }
                                else {
                                    
                                }
                            }
                        }
                        else if (dx == dy) {
                            // Check if there are any pieces blocking the path to the target
                            int xDir = (king.x > x) ? 1 : -1;
                            int yDir = (king.y > y) ? 1 : -1;
                            int x2 = x + xDir;
                            int y2 = y + yDir;
                            int error = 1;
                            while (x2 != king.x && y2 != king.y) {
                                if (gameState->board[x2][y2].type != PIECE_NONE) {
                                    
                                    error = 0;
                                }
                                x2 += xDir;
                                y2 += yDir;
                            }
                            // Check if the target square is empty or occupied by an opponent piece
                            if (error == 1) {
                                if (!(gameState->board[king.x][king.y].color == 0)) {
                                    gameState->board[x1][y1].type = piece;
                                    gameState->board[x5][y5].type = piece2;
                                    gameState->board[x5][y5].color = piececolor2;
                                    gameState->board[x1][y1].color = piececolor;
                                    return 1;
                                }
                                else {
                                    
                                }
                            }
                        }
                        else {
                            
                        }
                    }
                    //KING
                    else if (type == 6) {
                        // Calculate the distance between the piece's current position and the target position
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);

                        // Check if the move is valid for a king (one square in any direction)
                        if (dx <= 1 && dy <= 1) {
                            // Check if the target square is empty or occupied by an opponent piece
                            if (!(gameState->board[king.x][king.y].color == 0)) {
                                gameState->board[x1][y1].type = piece;
                                gameState->board[x5][y5].type = piece2;
                                gameState->board[x5][y5].color = piececolor2;
                                gameState->board[x1][y1].color = piececolor;
                                return 1;
                            }
                            else {
                                
                            }
                        }
                        else {
                           
                        }
                    }
                }
            }
        }
    }

    //Check on black king
    else if (gameState->turn % 2 !=0) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                int type = gameState->board[x][y].type;
                int col = gameState->board[x][y].color;
                if (type != PIECE_NONE && col == 1) {
                    //PAWN
                    if (type == 1) {
                        // Calculate the distance between the piece's current position and the target position
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);

                        // Determine the direction the pawn is moving based on its color
                        int dir = 1;

                        // Check if the move is a standard one or a capture
                        if (dx == 0 && dy == 1 && gameState->board[king.x][king.y].type == PIECE_NONE) {
                            // The move is a standard one square forward
                            
                        }
                        else if (dx == 1 && dy == 1 && gameState->board[king.x][king.y].type != PIECE_NONE) {
                            // The move is a capture
                            if (gameState->board[king.x][king.y].color != 1) {
                                gameState->board[x1][y1].type = piece;
                                gameState->board[x5][y5].type = piece2;
                                gameState->board[x5][y5].color = piececolor2;
                                gameState->board[x1][y1].color = piececolor;
                                return 1;
                            }
                            else {
                                
                            }
                        }
                        else if (dx == 0 && dy == 2 && y == 1 && gameState->board[king.x][king.y].type == PIECE_NONE) {
                            // The move is a two-square move from the starting position
                            int x2 = x + dir;
                            int y2 = y + dir;
                            if (gameState->board[x2][y2].type == PIECE_NONE) {
                                
                            }
                            else {
                                
                            }
                        }

                        else {
                           
                        }



                    }
                    //knight
                    else if (type == 2) {
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);


                        if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
                            if (!(gameState->board[king.x][king.y].color == 1)) {
                                gameState->board[x1][y1].type = piece;
                                gameState->board[x5][y5].type = piece2;
                                gameState->board[x5][y5].color = piececolor2;
                                gameState->board[x1][y1].color = piececolor;
                                return 1;
                            }
                            else {
                                
                            }
                        }
                        else {
                            
                        }
                    }
                    //BISHOP
                    else if (type == 3) {
                        // Calculate the distance between the piece's current position and the target position
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);

                        // Check if the move is diagonal
                        if (dx == dy) {
                            // Check if there are any pieces blocking the path to the target
                            int xDir = (king.x > x) ? 1 : -1;
                            int yDir = (king.y > y) ? 1 : -1;
                            int x2 = x + xDir;
                            int y2 = y + yDir;
                            int error = 1;
                            while (x2 != king.x && y2 != king.y) {
                                if (gameState->board[x2][y2].type != PIECE_NONE) {
                                    
                                    error = 0;
                                }
                                x2 += xDir;
                                y2 += yDir;
                            }
                            // Check if the target square is empty or occupied by an opponent piece
                            if (error == 1) {
                                if (!(gameState->board[king.x][king.y].color == 1)) {
                                    gameState->board[x1][y1].type = piece;
                                    gameState->board[x5][y5].type = piece2;
                                    gameState->board[x5][y5].color = piececolor2;
                                    gameState->board[x1][y1].color = piececolor;
                                    return 1;
                                }
                                else {
                                    
                                }
                            }
                        }
                        else {
                           
                        }
                    }
                    //ROOK
                    else if (type == 4) {
                        // Calculate the distance between the piece's current position and the target position
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);

                        // Check if the move is horizontal or vertical
                        if ((dx > 0 && dy == 0) || (dx == 0 && dy > 0)) {
                            // Check if the path to the target square is clear
                            int xdir = (king.x > x) ? 1 : ((king.x < x) ? -1 : 0);
                            int ydir = (king.y > y) ? 1 : ((king.y < y) ? -1 : 0);
                            int x2 = x;
                            int y2 = y;
                            x2 += xdir;
                            y2 += ydir;
                            int error = 1;
                            while (x2 != king.x || y2 != king.y) {
                                if (gameState->board[x2][y2].type != PIECE_NONE) {
                                    
                                    error = 0;

                                }
                                x2 += xdir;
                                y2 += ydir;
                            }
                            // Check if the target square is empty or occupied by an opponent piece
                            if (error == 1) {
                                if (!(gameState->board[king.x][king.y].color == 1)) {
                                    gameState->board[x1][y1].type = piece;
                                    gameState->board[x5][y5].type = piece2;
                                    gameState->board[x5][y5].color = piececolor2;
                                    gameState->board[x1][y1].color = piececolor;
                                    return 1;
                                }
                                else {
                                   
                                }
                            }
                        }

                        else {
                            
                        }
                    }
                    //QUEEN
                    else if (type == 5) {
                        // Calculate the distance between the piece's current position and the target position
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);

                        // Check if the move is horizontal or vertical
                        if ((dx > 0 && dy == 0) || (dx == 0 && dy > 0)) {
                            // Check if the path to the target square is clear
                            int xdir = (king.x > x) ? 1 : ((king.x < x) ? -1 : 0);
                            int ydir = (king.y > y) ? 1 : ((king.y < y) ? -1 : 0);
                            int x2 = x;
                            int y2 = y;
                            x2 += xdir;
                            y2 += ydir;
                            int error = 1;
                            while (x2 != king.x || y2 != king.y) {
                                if (gameState->board[x2][y2].type != PIECE_NONE) {
                                   
                                    error = 0;

                                }
                                x2 += xdir;
                                y2 += ydir;
                            }
                            // Check if the target square is empty or occupied by an opponent piece
                            if (error == 1) {
                                if (!(gameState->board[king.x][king.y].color == 1)) {
                                    gameState->board[x1][y1].type = piece;
                                    gameState->board[x5][y5].type = piece2;
                                    gameState->board[x5][y5].color = piececolor2;
                                    gameState->board[x1][y1].color = piececolor;
                                    return 1;
                                }
                                else {
                                    
                                    
                                }
                            }
                        }
                        else if (dx == dy) {
                            // Check if there are any pieces blocking the path to the target
                            int xDir = (king.x > x) ? 1 : -1;
                            int yDir = (king.y > y) ? 1 : -1;
                            int x2 = x + xDir;
                            int y2 = y + yDir;
                            int error = 1;
                            while (x2 != king.x && y2 != king.y) {
                                if (gameState->board[x2][y2].type != PIECE_NONE) {
                                   
                                    error = 0;
                                }
                                x2 += xDir;
                                y2 += yDir;
                            }
                            // Check if the target square is empty or occupied by an opponent piece
                            if (error == 1) {
                                if (!(gameState->board[king.x][king.y].color == 1)) {
                                    gameState->board[x1][y1].type = piece;
                                    gameState->board[x5][y5].type = piece2;
                                    gameState->board[x5][y5].color = piececolor2;
                                    gameState->board[x1][y1].color = piececolor;
                                    
                                    return 1;
                                }
                                else {
                                   
                                }
                            }
                        }
                        else {
                            
                        }
                    }
                    //KING
                    else if (type == 6) {
                        // Calculate the distance between the piece's current position and the target position
                        int dx = abs(king.x - x);
                        int dy = abs(king.y - y);

                        // Check if the move is valid for a king (one square in any direction)
                        if (dx <= 1 && dy <= 1) {
                            // Check if the target square is empty or occupied by an opponent piece
                            if (!(gameState->board[king.x][king.y].color == 1)) {
                                gameState->board[x1][y1].type = piece;
                                gameState->board[x5][y5].type = piece2;
                                gameState->board[x5][y5].color = piececolor2;
                                gameState->board[x1][y1].color = piececolor;
                                return 1;
                            }
                            else {
                                
                            }
                        }
                        else {
                           
                        }
                    }
                }
            }
        }
    }
    gameState->board[x1][y1].type = piece;
    gameState->board[x5][y5].type = piece2;
    gameState->board[x5][y5].color = piececolor2;
    gameState->board[x1][y1].color = piececolor;
    return 0;

    

}



void WhiteMoveCheck(int piece, int x, int y, int x1, int y1, GameState* gameState) {
    //PAWN
    if (piece == 1) {
        // Calculate the distance between the piece's current position and the target position
        int dx = abs(x1 - x);
        int dy = abs(y1 - y);

        // Determine the direction the pawn is moving based on its color
        int dir = 1;

        // Check if the move is a standard one or a capture
        if (dx == 0 && dy == 1 && gameState->board[x1][y1].type == PIECE_NONE) {
            // The move is a standard one square forward
            if (y1 == 7) {
                // The pawn has reached the end of the board, so it must be promoted
                gameState->board[x][y].type = PIECE_QUEEN;

            }
            gameState->board[x1][y1].type = gameState->board[x][y].type;
            gameState->board[x1][y1].color = 1;
            gameState->board[x][y].type = PIECE_NONE;
            gameState->board[x][y].color = 3;
            gameState->turn++;
        }
        else if (dx == 1 && dy == 1 && gameState->board[x1][y1].type != PIECE_NONE) {
            // The move is a capture
            if (gameState->board[x1][y1].color != 1) {
                if (y1 == 7) {
                    // The pawn has reached the end of the board, so it must be promoted (TO QUEEN PREFERENTIALLY)

                    gameState->board[x][y].type = PIECE_QUEEN;
                }
                gameState->board[x1][y1].type = gameState->board[x][y].type;
                gameState->board[x1][y1].color = 1;
                gameState->board[x][y].type = PIECE_NONE;
                gameState->board[x][y].color = 3;
                gameState->turn++;
            }
            else {
                gameState->whiteillegal++;
                printf("INVALID MOVE:cannot attack piece of same color , try again");
            }
        }
        else if (dx == 0 && dy == 2 && y == 1 && gameState->board[x1][y1].type == PIECE_NONE) {
            // The move is a two-square move from the starting position
            int x2 = x + dir;
            int y2 = y + dir;
            if (gameState->board[x2][y2].type == PIECE_NONE) {
                gameState->board[x1][y1].type = gameState->board[x][y].type;
                gameState->board[x1][y1].color = 1;
                gameState->board[x][y].type = PIECE_NONE;
                gameState->board[x][y].color = 3;
                gameState->turn++;
            }
            else {
                gameState->whiteillegal++;
                printf("INVALID MOVE:path blocked , try again");
            }
        }

        else {
            gameState->whiteillegal++;
            printf("INVALID MOVE:Pawn move Illegal, try again");
        }



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
                gameState->board[x][y].color = 3;
                gameState->turn++;
            }
            else {
                gameState->whiteillegal++;
                printf("INVALID MOVE:Cannot attack piece of same color , try again");
            }
        }
        else {
            gameState->whiteillegal++;
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
            int xDir = (x1 > x) ? 1 : -1;
            int yDir = (y1 > y) ? 1 : -1;
            int x2 = x + xDir;
            int y2 = y + yDir;
            int error = 1;
            while (x2 != x1 && y2 != y1) {
                if (gameState->board[x2][y2].type != PIECE_NONE) {
                    gameState->whiteillegal++;
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
                    gameState->board[x][y].color = 3;
                    gameState->turn++;
                }
                else {
                    gameState->whiteillegal++;
                    printf("INVALID MOVE:Cannot attack piece of same color , try again");
                }
            }
        }
        else {
            gameState->whiteillegal++;
            printf("INVALID MOVE:Bishop move Illegal, try again");
        }
    }
    //ROOK
    else if (piece == 4) {
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
                    gameState->whiteillegal++;
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
                    gameState->board[x][y].color = 3;
                    gameState->turn++;
                }
                else {
                    gameState->whiteillegal++;
                    printf("INVALID MOVE:Cannot attack piece of same color , try again");
                }
            }
        }

        else {
            gameState->whiteillegal++;
            printf("INVALID MOVE:Rook move Illegal , try again");
        }
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
                    gameState->whiteillegal++;
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
                    gameState->board[x][y].color = 3;
                    gameState->turn++;
                }
                else {
                    gameState->whiteillegal++;
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
                    gameState->whiteillegal++;
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
                    gameState->board[x][y].color = 3;
                    gameState->turn++;
                }
                else {
                    gameState->whiteillegal++;
                    printf("INVALID MOVE:Cannot attack piece of same color , try again");
                }
            }
        }
        else {
            gameState->whiteillegal++;
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
                gameState->board[x][y].color = 3;
                gameState->turn++;
            }
            else {
                gameState->whiteillegal++;
                printf("INVALID MOVE:Cannot attack piece of same color , try again");
            }
        }
        else {
            gameState->whiteillegal++;
            printf("INVALID MOVE:King move Illegal, try again");
        }
    }
}
void BlackMoveCheck(int piece, int x, int y, int x1, int y1, GameState* gameState) {
    //PAWN
    if (piece == 1) {
        // Calculate the distance between the piece's current position and the target position
        int dx = abs(x1 - x);
        int dy = abs(y1 - y);

        // Determine the direction the pawn is moving based on its color
        int dir = -1;

        // Check if the move is a standard one or a capture
        if (dx == 0 && dy == 1 && gameState->board[x1][y1].type == PIECE_NONE) {
            // The move is a standard one square forward
            if (y1 == 0) {
                // The pawn has reached the end of the board, so it must be promoted
                gameState->board[x][y].type = PIECE_QUEEN;

            }
            gameState->board[x1][y1].type = gameState->board[x][y].type;
            gameState->board[x1][y1].color = 0;
            gameState->board[x][y].type = PIECE_NONE;
            gameState->board[x][y].color = 3;
            gameState->turn++;
        }
        else if (dx == 1 && dy == 1 && gameState->board[x1][y1].type != PIECE_NONE) {
            // The move is a capture
            if (gameState->board[x1][y1].color != 0) {
                if (y1 == 0) {
                    // The pawn has reached the end of the board, so it must be promoted (TO QUEEN PREFERENTIALLY)

                    gameState->board[x][y].type = PIECE_QUEEN;
                }
                gameState->board[x1][y1].type = gameState->board[x][y].type;
                gameState->board[x1][y1].color = 0;
                gameState->board[x][y].type = PIECE_NONE;
                gameState->board[x][y].color = 3;
                gameState->turn++;
            }
            else {
                gameState->blackillegal++;
                printf("INVALID MOVE:cannot attack piece of same color , try again");
            }
        }
        else if (dx == 0 && dy == 2 && y == 6 && gameState->board[x1][y1].type == PIECE_NONE) {
            // The move is a two-square move from the starting position
            int x2 = x + dir;
            int y2 = y + dir;
            if (gameState->board[x2][y2].type == PIECE_NONE) {
                gameState->board[x1][y1].type = gameState->board[x][y].type;
                gameState->board[x1][y1].color = 0;
                gameState->board[x][y].type = PIECE_NONE;
                gameState->board[x][y].color = 3;
                gameState->turn++;
            }
            else {
                gameState->blackillegal++;
                printf("INVALID MOVE:path blocked , try again");
            }
        }

        else {
            gameState->blackillegal++;
            printf("INVALID MOVE:Pawn move Illegal, try again");
        }



    }
    //knight
    else if (piece == 2) {
        int dx = abs(x1 - x);
        int dy = abs(y1 - y);


        if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
            if (!(gameState->board[x1][y1].color == 0)) {
                gameState->board[x1][y1].type = gameState->board[x][y].type;
                gameState->board[x1][y1].color = 0;
                gameState->board[x][y].type = PIECE_NONE;
                gameState->board[x][y].color = 3;
                gameState->turn++;
            }
            else {
                gameState->blackillegal++;
                printf("INVALID MOVE:Cannot attack piece of same color , try again");
            }
        }
        else {
            gameState->blackillegal++;
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
            int xDir = (x1 > x) ? 1 : -1;
            int yDir = (y1 > y) ? 1 : -1;
            int x2 = x + xDir;
            int y2 = y + yDir;
            int error = 1;
            while (x2 != x1 && y2 != y1) {
                if (gameState->board[x2][y2].type != PIECE_NONE) {
                    gameState->blackillegal++;
                    printf("INVALID MOVE:Path is blocked");
                    error = 0;
                }
                x2 += xDir;
                y2 += yDir;
            }
            // Check if the target square is empty or occupied by an opponent piece
            if (error == 1) {
                if (!(gameState->board[x1][y1].color == 0)) {
                    gameState->board[x1][y1].type = gameState->board[x][y].type;
                    gameState->board[x1][y1].color = 0;
                    gameState->board[x][y].type = PIECE_NONE;
                    gameState->board[x][y].color = 3;
                    gameState->turn++;
                }
                else {
                    gameState->blackillegal++;
                    printf("INVALID MOVE:Cannot attack piece of same color , try again");
                }
            }
        }
        else {
            gameState->blackillegal++;
            printf("INVALID MOVE:Bishop move Illegal, try again");
        }
    }
    //ROOK
    else if (piece == 4) {
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
                    gameState->blackillegal++;
                    printf("INVALID MOVE:path is blocked , try again");
                    error = 0;

                }
                x2 += xdir;
                y2 += ydir;
            }
            // Check if the target square is empty or occupied by an opponent piece
            if (error == 1) {
                if (!(gameState->board[x1][y1].color == 0)) {
                    gameState->board[x1][y1].type = gameState->board[x][y].type;
                    gameState->board[x1][y1].color = 0;
                    gameState->board[x][y].type = PIECE_NONE;
                    gameState->board[x][y].color = 3;
                    gameState->turn++;
                }
                else {
                    gameState->blackillegal++;
                    printf("INVALID MOVE:Cannot attack piece of same color , try again");
                }
            }
        }

        else {
            gameState->blackillegal++;
            printf("INVALID MOVE:Rook move Illegal , try again");
        }
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
                    gameState->blackillegal++;
                    printf("INVALID MOVE:path is blocked , try again");
                    error = 0;

                }
                x2 += xdir;
                y2 += ydir;
            }
            // Check if the target square is empty or occupied by an opponent piece
            if (error == 1) {
                if (!(gameState->board[x1][y1].color == 0)) {
                    gameState->board[x1][y1].type = gameState->board[x][y].type;
                    gameState->board[x1][y1].color = 0;
                    gameState->board[x][y].type = PIECE_NONE;
                    gameState->board[x][y].color = 3;
                    gameState->turn++;
                }
                else {
                    gameState->blackillegal++;
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
                    gameState->blackillegal++;
                    printf("INVALID MOVE:Path is blocked");
                    error = 0;
                }
                x2 += xDir;
                y2 += yDir;
            }
            // Check if the target square is empty or occupied by an opponent piece
            if (error == 1) {
                if (!(gameState->board[x1][y1].color == 0)) {
                    gameState->board[x1][y1].type = gameState->board[x][y].type;
                    gameState->board[x1][y1].color = 0;
                    gameState->board[x][y].type = PIECE_NONE;
                    gameState->board[x][y].color = 3;
                    gameState->turn++;
                }
                else {
                    gameState->blackillegal++;
                    printf("INVALID MOVE:Cannot attack piece of same color , try again");
                }
            }
        }
        else {
            gameState->blackillegal++;
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
            if (!(gameState->board[x1][y1].color == 0)) {
                gameState->board[x1][y1].type = gameState->board[x][y].type;
                gameState->board[x1][y1].color = 0;
                gameState->board[x][y].type = PIECE_NONE;
                gameState->board[x][y].color = 3;
                gameState->turn++;
            }
            else {
                gameState->blackillegal++;
                printf("INVALID MOVE:Cannot attack piece of same color , try again");
            }
        }
        else {
            gameState->blackillegal++;
            printf("INVALID MOVE:King move Illegal, try again");
        }
    }
}

// Define a function to handle a player's turn 
void handleTurn(GameState* gameState) {
    int x = 0, y = 0, piece = 0;

    if ((gameState->turn) % (2) == 0) {
        printf("WHITE's TURN !\n");
        printf("Which piece do you want to move? Enter position in x and y coordinate respectively");
        scanf_s("%d  %d", &x, &y);

        if (x > -1 && x<8 && y >-1 && y < 8 && gameState->board[x][y].color == 1) {//Checked if the given piece is inside board and if its for white coin 
            piece = gameState->board[x][y].type;
            int x1, y1;
            printf("Where do you want to move it to ? ");
            scanf_s("%d %d", &x1, &y1);
            int a = CheckKing(gameState, x, y,x1,y1);
 
            if (a == 0) {
                WhiteMoveCheck(piece, x, y, x1, y1, gameState);
            }
            else {
                gameState->whiteillegal++;
                printf("INVALID MOVE:Your King is in danger , try again");
            }
        }
        else
            printf("INVALID INPUT:no such square exists ,try again");


    }
    else {
        printf("BLACK's TURN ! \n");
        printf("Which piece do you want to move? Enter position in x and y coordinate respectively");
        scanf_s("%d  %d", &x, &y);

        if (x > -1 && x<8 && y >-1 && y < 8 && gameState->board[x][y].color == 0) {//Checked if the given piece is inside board and if its for black coin 
            piece = gameState->board[x][y].type;
            int x1, y1;
            printf("Where do you want to move it to ? ");
            scanf_s("%d %d", &x1, &y1);
            int a = CheckKing(gameState, x,y,x1,y1);
            if (a == 0) {
                BlackMoveCheck(piece, x, y, x1, y1, gameState);
            }
            else {
                gameState->blackillegal++;
                printf("INVALID MOVE:King is in danger , try again");
            }
        }
        else
            printf("INVALID INPUT:no such square exists ,try again");
    }

}

int EndGame(GameState *gameState) {
    if (gameState->blackillegal == 4) {
        printf("\n \n \n GAME OVER!! Black Loses White Wins !! CONGRATULATIONS WHITE PLAYER");
        return 1;
    }
    else if (gameState->whiteillegal == 4) {
        printf("\n \n \n GAME OVER!! White Loses Black Wins !! CONGRATULATIONS BLACK PLAYER");
        return 1;
    }

}
#endif // !CHESS_H;