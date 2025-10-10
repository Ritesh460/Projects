#include <iostream>
#include <cstring>
using namespace std;
char move[50];
char board[3][3];
int x_wins = 0;
int o_wins = 0;
int ties = 0;

// reset Board after finishing a round
void resetBoard() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      board[i][j] = ' ';
}
//reprints baord after every turn
void printBoard() {
  cout << "\n  1   2  3\n"; // Column headers to help players
  for (int i = 0; i < 3; i++) {
    // Row label: a, b, c to help players
    cout << (char)('a' + i) << " ";
    for (int j = 0; j < 3; j++) {
      // Print cell content (X, O, or space)
      cout << " " << board[i][j];
      if (j < 2) cout << " |"; // Add vertical separator for boxes
    }
    cout << "\n";
  
    // Print horizontal separator after rows a and b
    if (i < 2) {
      cout << "----------- \n";
    }
  }
}


//check if player won
bool check_win (char player) {
  for (int i = 0; i < 3; i++) {
    //check vertical
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
    //check horizontal
    else if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }
  //check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  else if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
    return true;
  }
  else {
    return false;
  }
}

//check if player ties
bool check_tie () {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ')
        return false;
    }
  }
  return true;
}
// main function where all of the other functions are ran
int main() {
  // variables for move, row, columns, turn, and playing again
  char move[3];
  int row;
  int col;
  int player_turn = 1;
  char playAgain = 'y';
    
  while (playAgain == 'y') {
    resetBoard();
    printBoard();
    //states score
    cout << "Score: X wins: " << x_wins << " and O wins: " << o_wins << " and Ties: " << ties << endl;

    bool finish_game = false;
    player_turn = 1;
    // initially false until a round is finished
    while (finish_game == false) {
      //player icon used depending on player turn
      char playerChar;
      if (player_turn == 1) {
        playerChar = 'X';
      }
      else {
        playerChar = 'O';
      }
      //move input
      cout << "Player " << player_turn << " (" << playerChar << "), enter your move (E:a1): ";
      cin >> move;
      
      //checks valid move
      bool validMove = false;
      if (strcmp(move, "a1") == 0) { 
        row = 0; 
	col = 0; 
	validMove = true; 
      }
      else if (strcmp(move, "a2") == 0) {
        row = 0;
        col = 1;
        validMove = true;
      }
      else if (strcmp(move, "a3") == 0) {
        row = 0;
        col = 2;
        validMove = true;
      }
      else if (strcmp(move, "b1") == 0) {
        row = 1;
        col = 0;
        validMove = true;
      }
      else if (strcmp(move, "b2") == 0) {
        row = 1;
        col = 1;
        validMove = true;
      }
      else if (strcmp(move, "b3") == 0) {
        row = 1;
        col = 2;
        validMove = true;
      }
      else if (strcmp(move, "c1") == 0) {
        row = 2;
        col = 0;
        validMove = true;
      }
      else if (strcmp(move, "c2") == 0) {
        row = 2;
        col = 1;
        validMove = true;
      }
      else if (strcmp(move, "c3") == 0) {
        row = 2;
        col = 2;
        validMove = true;
      }
      
      if (validMove) {
	// sees if their is room for this input      
        if (board[row][col] == ' ') {
          board[row][col] = playerChar;
          printBoard(); 
	  // uses win function if true
	  if (check_win(playerChar)) {
	    printBoard();
            cout << "Player " << player_turn << " (" << playerChar << ") wins!" << endl; 
	    if (player_turn == 1) {
	      x_wins++;
	    }
	    else {
	      o_wins++;
	    }
	    finish_game = true;
	  }
	  // uses tie function if true
	  else if (check_tie()) {
	    printBoard();
	    cout << "It's a tie!" << endl;
	    ties++;
	    finish_game = true;
	  }
          //when finished player turn reverts back to original
	  if (finish_game) {
	    player_turn = 1; 
	  } 
	  // if not finished, swaps turns
	  else {
	    if (player_turn == 1) {
	      player_turn = 2;
	    } 
	    else {
	      player_turn = 1;
	    }
	  }
	}
	// if spot is taken state this
	else {
	  cout << "That spot is taken. Try again." << endl;
	}
      }
      
    }
    // if round is over check if they want to play again
    cout << "Play again? (y/n): ";
    cin >> playAgain;
    
  }
  // if no, end program
  return 0;   
}    
