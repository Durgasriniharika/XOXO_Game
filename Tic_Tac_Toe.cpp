#include<bits/stdc++.h>
using namespace std;
vector<char>board(9,' ');
void show_board() {
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[0] << "  |   " << board[1] << "  |   " << board[2] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[3] << "  |   " << board[4] << "  |   " << board[5] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[6] << "  |   " << board[7] << "  |   " << board[8] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
}
bool check_win(char symbol)
{
	for(int i=0;i<3;i++)
	{
		if(board[i*3]==symbol && board[i*3+1]==symbol && board[i*3+2]==symbol)
		{
			return true;
		}
	}
	for(int i=0;i<3;i++)
	{
		if(board[i]==symbol && board[i+3]==symbol && board[i+6]==symbol)
		{
			return true;
		}
	}
	if((board[0]==symbol && board[4]==symbol && board[8]==symbol) || 
	(board[2]==symbol && board[4]==symbol && board[6]==symbol))
	{
		return true;
	}
	return false;
}
bool check_draw()
{
   for(char cell:board)
   {
      if(cell==' ')
	  {
	  	 return false;
	  }	
   }	
   return true;
}
int main()
{
	char currentPlayer='X';
	cout<<"Welcome to Tic Tac Toe"<<endl;
	show_board();
	while(true)
	{
		
		int position;
		cout<<"Player "<<currentPlayer<<", enter your choice(1-9): ";
		cin>>position;
		position--;
		if(position<0 || position>=9 || board[position]!=' ')
		{
			cout<<"Invalid move! Try again."<<endl;
			continue;
		}
		
		board[position]=currentPlayer;
        show_board();
		if(check_win(currentPlayer))
		{
			cout<<"Player "<<currentPlayer<<" wins!"<<endl;
			break;
		}
		if(check_draw())
		{
			cout<<"Game is Draw!"<<endl;
			break;
		}
		currentPlayer=(currentPlayer=='X')?'0':'X';
	}
	return 0;
}
