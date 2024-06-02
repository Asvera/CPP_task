/**
*
* @Name : Tick_Tac_Toe
* @Version : 1.0
* @Date : 2024-05-28
* 
**/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>

void drawboard(const std::vector<std::vector<char>>& board){
    std::cout << "--------------" << std::endl;
    for(int i=0; i< 3; i++){
        std::cout << "| ";
        for(int j=0; j<3 ; j++){
            std::cout << board[i][j] << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << "--------------" << std::endl;
}

void getPlayerMove(std::vector<std::vector<char>> & board,char currentPlayer){
    int row , col;
    bool isValidMove = false;
    while(!isValidMove){
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        if (!(std::cin >> row >> col) || row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '-') {
            std::cout << "Invalid move! Try again." << std::endl;
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        } else {
            isValidMove = true;
        }
    }
    board[row -1][col - 1] = currentPlayer;
}

char checkWinner(std::vector<std::vector<char>> & board){
    // check row
    for(int i=0; i< 3; i++){
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return board[i][0];
        }
    }

    // check col
    for(int j=0; j< 3; j++){
        if(board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]){
            return board[0][j];
        }
    }

    //check diagonal
    if( board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2] ){
        return board[0][0];
    }
    if( board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0] ){
        return board[0][2];
    }
    
    return '-'; // No winner yet
}

bool isBoardfull(std::vector<std::vector<char>> & board){
    for(int i=0; i< 3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == '-') return false;
        }
    }
    return true;
}

// range based itetations
// bool isBoardfull(const std::vector<std::vector<char>>& board) {
//     for (const auto& row : board) {
//         for (char cell : row) {
//             if (cell == '-') {
//                 return false; // Board is not full
//             }
//         }
//     }
//     return true; // Board is full
// }


void Play(){
    bool isTie = false;
    std::vector<std::vector<char>> board (3,std::vector<char>(3,'-'));
    char currentPlayer = 'X';
    int row, col;
    char winner = '-' ;
    

    while(winner == '-'){
        drawboard(board);
        getPlayerMove(board,currentPlayer);
        winner = checkWinner(board);
        if(winner == '-'){
            currentPlayer = (currentPlayer == 'X')? 'O' : 'X';
        }
        if(isBoardfull(board) && winner == '-'){
            std::cout << "It's a Tie" << std::endl;
            return;
        }
    }
    
    std::cout << "Player " << winner << " wins!" << std::endl;
}

int main(){
    system("clear");
    std::cout << "Welcome To 3T(Tic-Tac-Toe)" << std::endl;
    bool isvalid = true;
    char choice;

    while(isvalid){
        std::cout << "Enter Choice:  Play[P],     Quit[Q]: ";
        std::cin >> choice;
        if(choice == 'q' || choice == 'Q'){
            std::cout << "Bye! Thanks For Playing" << std::endl;
            isvalid = false;
        }else if(choice == 'p' || choice == 'P'){
            Play();
        }else{
            std::cout << "Ivalid! Choice. Try Again" << std::endl;
            continue;
        }
    }    

    return 0;
}