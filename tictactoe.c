//TicTacToe Game against a computer in C
//Practice with functions


#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define size 3

void clear_table(char board[size][size]);
void display_table(char board[size][size]);
bool check_table_full(char board[size][size]);
void update_table(char board[size][size],int row,int col,char token);
bool check_legal_option(char board[size][size],int row, int col);
void generate_player2_move(char board[size][size],int row, int col);
int check_three_in_a_row(char board[size][size]);
bool check_end_of_game(char board[size][size]);
void get_player1_move(char board[size][size],int row,int col);
void print_winner(char board[size][size]);


int main(void)
{
	char board[size][size];
	int row,col;

	clear_table(board);

	display_table(board);

	do{
		get_player1_move(board,row,col);

		generate_player2_move(board,row,col);
	}while(check_end_of_game(board) == false);
	
	print_winner(board);

	return 0;
}

void clear_table(char board[size][size]){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			board[i][j] = '_';
		}
	}
}

void display_table(char board[size][size]){
	printf("The current state of the game is:\n");
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
}

bool check_table_full(char board[size][size]){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(board[i][j] == '_'){
				return false;
			}
		}
	}
	return true;
}

void update_table(char board[size][size],int row,int col,char token){
	board[row-1][col-1] = token;
}

bool check_legal_option(char board[size][size],int row, int col){
	if(row>0 && row<4 && col>0 && col<4 && (board[row-1][col-1] != 'O' && board[row-1][col-1] != 'X')){
		return true;
	}else{
		return false;
	}
}

void generate_player2_move(char board[size][size],int row, int col){
	if(!check_end_of_game(board)){
		srand(time(NULL));
		do{
			row = rand()%3+1;
			col = rand()%3+1;
		}while(!check_legal_option(board,row,col));
		update_table(board,row,col,'X');
		printf("Player 2 has entered [row, col]: %d,%d\n",row,col);
		display_table(board);
	}
}

int check_three_in_a_row(char board[size][size]){
	for(int i=0;i<=size;i++){
		if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'){
			return 1;
		}else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
			return 1;
		}else if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
			return 1;
		}else if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'){
			return 2;
		}else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){
			return 2;
		}else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){
			return 2;
		}else if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){
			return 1;
		}else if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
			return 1;
		}else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
			return 1;
		}else if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){
			return 2;
		}else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){
			return 2;
		}else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){
			return 2;
		}else if(board[i][i] == 'O' && board[i+1][i+1] == 'O' && board[i+2][i+2] == 'O'){
			return 1;
		}else if(board[i][i+2] == 'O' && board[i+1][i+1] == 'O' && board[i+2][i] == 'O'){
			return 1;
		}else if(board[i][i] == 'X' && board[i+1][i+1] == 'X' && board[i+2][i+2] == 'X'){
			return 2;
		}else if(board[i][i+2] == 'X' && board[i+1][i+1] == 'X' && board[i+2][i] == 'X'){
			return 2;
		}else{
			return 0;
		}
	}
}

bool check_end_of_game(char board[size][size]){
	if(check_table_full(board) || check_three_in_a_row(board) == 1 || check_three_in_a_row(board) == 2){
		return true;
	}else{
		return false;
	}
}

void get_player1_move(char board[size][size],int row,int col){
	if(!check_end_of_game(board)){
		do{
			printf("Player 1 enter your selection [row, col]: ");
			scanf("%d,%d",&row,&col);
		}while(!check_legal_option(board,row,col));
		update_table(board,row,col,'O');
		display_table(board);
	}
}

void print_winner(char board[size][size]){
	if(check_three_in_a_row(board) != 0){
		printf("Congratulations, Player %d wins!\n",check_three_in_a_row(board));
	}else{
		printf("Game over, no player wins.\n");
	}
}