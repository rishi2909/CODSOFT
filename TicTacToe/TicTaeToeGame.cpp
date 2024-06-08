#include <iostream>
using namespace std;

char arr[3][3];  //Creating a 3x3 grid as the game board.
int row;
int col;
char token = 'X';  //Char to track the current player ('X' or 'O').
bool tie = false;  //Boolean flag to indicate if the game is a tie.
string n1 = "";    //Strings to store the names of the two players.
string n2 = "";

// Function to initialize the game board with numbers 1 to 9
void initializeBoard() {
    char initial = '1';
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            arr[i][j] = initial++;
        }
    }
}

// Function to display the game board
void functionGameboard() {
    cout << "   |     |    \n";
    cout << " " << arr[0][0] << " | " << arr[0][1] << "   | " << arr[0][2] << "  \n";
    cout << "___|_____|___ \n";
    cout << "   |     |    \n";
    cout << " " << arr[1][0] << " | " << arr[1][1] << "   | " << arr[1][2] << "  \n";
    cout << "___|_____|___ \n";
    cout << "   |     |    \n";
    cout << " " << arr[2][0] << " | " << arr[2][1] << "   | " << arr[2][2] << "  \n";
    cout << "   |     |    \n";
}

// Function to prompt the current player to enter their move and update the board
void functionMove() {
    int digit;

    if(token == 'X') {                             
        cout << n1 << " please enter: ";
        cin >> digit;
    } else if(token == 'O') {
        cout << n2 << " please enter: ";
        cin >> digit;
    }

    if(digit < 1 || digit > 9) {
        cout << "Invalid input!" << endl;
        exit(0);
    }

    row = (digit - 1) / 3;
    col = (digit - 1) % 3;

    if(arr[row][col] != 'X' && arr[row][col] != 'O') {
        arr[row][col] = token;
        token = (token == 'X') ? 'O' : 'X';
    } else {
        cout << "The cell is already occupied!" << endl;
        functionMove();
    }
    functionGameboard();
}

// Function to check for a win or a draw
bool checkwon() {
    for(int i = 0; i < 3; i++) {
        //Checking rows and columns for a winning condition.
        if((arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) || 
           (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])) {
            return true;
        }
    }
    //Checking the two diagonals for a winning condition.
    if((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || 
       (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])) {
        return true;
    }
    //Checks if the board is full. If all cells are filled and no winner, sets tie to true and returns false.
    //Returns true if a winning condition is met.
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(arr[i][j] != 'X' && arr[i][j] != 'O') {
                return false;
            }
        }
    } 
    tie = true;
    return false;
}

int main() {
    char playAgain;  //character variable pl to store the user's response to whether they want to play another game.

    do {
        tie = false;
        token = 'X';
        initializeBoard();
        cout << "Enter the name of first player: ";
        getline(cin, n1);
        cout << "Enter the name of second player: ";
        getline(cin, n2);
        cout << n1 << " is player1 so he/she will play first" << endl;
        cout << n2 << " is player2 so he/she will play second" << endl;
        
        //loop which is running until the game not win or draw by any user
        while(!checkwon() && !tie) {
            functionGameboard();
            functionMove();
        }

        if(!tie && checkwon()) {
            if(token == 'O') {
                cout << "Game Over! " << n1 << " Wins!!" << endl;
            } else if(token == 'X') {
                cout << "Game Over! " << n2 << " Wins!!" << endl;
            }
        } else if(tie) {
            cout << "There is no empty space. It's a draw!" << endl;
        }

        cout << "Want to play another game (y/n) for y mean Yes and n means No? : ";
        cin >> playAgain;
        cin.ignore();  //To ignore the newline character.
    } while(playAgain == 'y');

    if (playAgain == 'n')  //if the user don't want to play another game then terminate the program.
    {
        exit(0);
    }
    

    return 0;
}
