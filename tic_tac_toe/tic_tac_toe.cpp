// TIC TAC TOE GAME IN CONSOLE 
// USING C++ 
// DATE :- 22/04/21

#include <iostream>
using namespace std;

char board[3][3] ={{'1','2','3'},{'4','5','6'},{'7','8','9'}}; // board 

char currentMarker;
int currentPlayer;

// drawing a board in a console 
void drawABoard()
{
	cout << "        " <<     board[0][0] << "     |      " << board[0][1] << "      |     " <<board[0][2] << endl;
	cout << "       -----------------------------" <<endl;
	cout << "        " <<     board[1][0] << "     |      " << board[1][1] << "      |     " <<board[1][2] << endl;
	cout << "       -----------------------------" <<endl;
	cout << "        " <<     board[2][0] << "     |      " << board[2][1] << "      |     " <<board[2][2] << endl;
}


// to place a marker on a perticular place 
bool placeMarker(int slot)
{
	int row = slot/3;
	int col;

	if(slot % 3 == 0)
		{
			row = row - 1;
			col = 2;
		}
	else
	{
		col = (slot % 3)-1;
	}

		if(board[row][col] != 'x' && board[row][col] != 'o')
		{
			board[row][col] = currentMarker;
			return true;
		}
		else
			return false;
}


//logic for declare a winner 
int winner()
{
	for(int i=0;i<3;i++)
	{
		// for rows
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return currentPlayer;

		// for coloums
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return currentPlayer;
	}
		// for a diagonal 1
		if(board[0][0] == board[1][1] && board[1][1] == board[2][2] )
			return currentPlayer;
		// for a diagonal 2
		if(board[0][2] == board[1][1] && board[1][1] == board[2][0] )
			return currentPlayer;

	return 0;	
}

// for swapping marker to player 1 to player 2 and vice verca
void swap_PlayerAndMarker()
{
	if(currentMarker == 'x') 
		currentMarker = 'o';
	else
		currentMarker = 'x';

	if(currentPlayer == 1) 
		currentPlayer = 2;
	else
		currentPlayer = 1;

}

void gameOfTicTacToe()
{
	// taking symbol for player 1
	char markerForP1;
	cout << "Want you want O or X  :  ";
	cin >> markerForP1;

	currentPlayer = 1;
	currentMarker = markerForP1;

	int playerWon;

	drawABoard();

		for(int i=0;i<9;i++)
		{
			cout << "It's Player " << currentPlayer << "'s turn, Enter a slot : ";
			int slot;
			cin >> slot;

				// to check weather enter slot is valid or not
				if(slot < 1 || slot > 9)
				{
					cout << "********** PLEASE ENTER VALID SLOT *********" << endl;
					i--;
					continue;
				}
				
				// to check slot is occupied or not
				if(!placeMarker(slot))
				{
					cout << "********** This slot is occupied!,TRY ANOTHER SLOT *********" << endl;
					i--;
					continue;
				}
				drawABoard();

				playerWon = winner();
				// for output the winner
					if(playerWon == 1)
					{
						cout << "********** Player 1 won ,Congratulations! **********" << endl;
						break;
					}

					if(playerWon == 2)
					{
						cout << "********** Player 2 won ,Congratulations! **********" << endl;
						break;
					}
					
				swap_PlayerAndMarker();
		}
		// for tie 
		if(playerWon == 0)
		{
			cout << "********** It's Tie! ***********" << endl;
		}


}


int main()
{
	gameOfTicTacToe();
	return 0;
}