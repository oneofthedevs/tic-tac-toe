#include <iostream>

using namespace std;

const int SIZE = 3;
const char EMPTY = ' ';
void start(char grid[][SIZE]);
void displayBoard(char grid[][SIZE]);
bool isGameOver(char grid[][SIZE]);
int makeMove(char grid[][SIZE], char symbol);

int main()
{
   char ch ='y';
   while(ch == 'y'|| ch == 'Y')
   {
		char grid[SIZE][SIZE];
		start(grid);
		displayBoard(grid);
		int player = 1;
		int winner=4;

			while (!isGameOver(grid) && winner>2)
			{
			if (player == 1)
			{
				winner = makeMove(grid, 'O');
				player = 2;
				if(winner<=2)
					break;
			}
			else
			{
				winner = makeMove(grid, 'X');
				player = 1;
				if(winner<=2)
					break;
			}
				if(winner>2)
					displayBoard(grid);
	}
	cout<<"GAME OVER";
	cout<<"Do you want to play again (y/n)?";
	cin>>ch;
   }
   return 0;
}

void start(char grid[][SIZE])
{
   for (int row = 0; row < SIZE; row++)
	   for (int col = 0; col < SIZE; col++)
		   grid[row][col] = EMPTY;
}

void displayBoard(char grid[][SIZE])
{
   for (int row = 0; row < SIZE; row++)
   {
	   for (int col = 0; col < SIZE; col++)
	   {
		   cout << " " << grid[row][col] << " ";
		   if (col < SIZE - 1)
			   cout << " | ";
	   }
	   cout << endl;
	   if(row < SIZE - 1)
		   cout << "---------------" << endl;
   }
}

bool isGameOver(char grid[][SIZE])
{
   bool isOver = false;
   for (int row = 0; row < SIZE; row++)
	   for (int col = 0; col < SIZE; col++)
	   {
			if(grid[row][col] == EMPTY)
			   return false;
	   }
   return true;
}

int makeMove(char grid[][SIZE], char symbol)
{       
	int x=0,y;
		
	if(grid[0][0]=='O'&&grid[1][1]=='O'&&grid[2][2]=='O'|| grid[0][0]=='O'&&grid[0][1]=='O'&&grid[0][2]=='O'||
		grid[1][0]=='O'&&grid[1][1]=='O'&&grid[1][2]=='O'|| grid[2][0]=='O'&&grid[2][1]=='O'&&grid[2][2]=='O'||
		grid[0][0]=='O'&&grid[1][0]=='O'&&grid[2][0]=='O'|| grid[0][1]=='O'&&grid[1][1]=='O'&&grid[2][1]=='O'||
		grid[0][2]=='O'&&grid[1][2]=='O'&&grid[2][2]=='O'|| grid[0][2]=='0'&&grid[1][1]=='0'&&grid[2][0]=='0')
	{
		cout<<"Player one wins:O Congrats\n";
		x=1;
		return 1;
	}
	else if(grid[0][0]=='X'&&grid[1][1]=='X'&&grid[2][2]=='X'|| grid[0][0]=='X'&&grid[0][1]=='X'&&grid[0][2]=='X'||
			grid[1][0]=='X'&&grid[1][1]=='X'&&grid[1][2]=='X'|| grid[2][0]=='X'&&grid[2][1]=='X'&&grid[2][2]=='X'||
			grid[0][0]=='X'&&grid[1][0]=='X'&&grid[2][0]=='X'|| grid[0][1]=='X'&&grid[1][1]=='X'&&grid[2][1]=='X'||
			grid[0][2]=='X'&&grid[1][2]=='X'&&grid[2][2]=='X'|| grid[0][2]=='X'&&grid[1][1]=='X'&&grid[2][0]=='X')
	{
		cout<<"Player two wins: X Congrats\n";
		x=1;
		return 2;
	}
		
	if(x==0)
	{
		cout << "Where would you like to place your " << symbol << "(x,y): ";
		int row, col;
		char comma;
		cin >> row >> comma >> col;
		
		if(grid[row][col] == ' ')
		{
			grid[row][col] = symbol; 
		}
		else
		{
			cout<<"Input is invalid."<<endl;
			exit(0);
		}
	return 4;
	}
	else
	{       
		cout<<"GAME OVER";
		return 0;
	} 
}