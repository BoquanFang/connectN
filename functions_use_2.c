/*
  FIle intro:
  This file contains all functions that need to be used to play the game.
  There is no main function.
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"functions_use_2.h"
/*Zhou's functions*/
void is_argc_correct(int argc) {
	if (argc < 3){
    printf("Not enough arguments entered\n");
    printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
  } else if (argc > 3) {
    printf("Too many arguments entered\n");
    printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
  }
}

void read_args(int numReads, int num_rows, int num_cols, int num_connectN) {
  if (numReads == 3) {
    if ((num_rows <= 0) || (num_cols <= 0) || (num_connectN <= 0)) {
      exit(0);
    } /* else if ((num_cols * num_rows) < num_connectN) {
      printf("Tie game!\n");
      exit(0);
    } */
  } else if (numReads > 3) {
    printf("Too many arguments entered\n");
    printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
  } else if (numReads < 3){
    printf("Not enough arguments entered\n");
    printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
  }
}

char** create_board (int row_dim, int col_dim) {
  char** board = (char**) calloc(row_dim, sizeof(char*));

	for (int row = 0; row < row_dim; ++row) {
    board[row] = (char*) calloc(col_dim, sizeof(char));
    for (int col = 0; col < col_dim; ++col) {
      board[row][col] = '*';   
    }
  }
  return board;
}

void print_board(char** board, int row_dim, int col_dim) {
  int row_index = row_dim - 1;

  for (int row = 0; row < row_dim; ++row) {
    printf("%d ", row_index);
    --row_index;
    for (int col = 0; col < col_dim; ++col) {
      printf("%c ", board[row][col]);
    }
    printf("\n");
  }
  printf("  ");
  for (int col = 0; col < col_dim; ++col) {
    printf("%d ", col);
  }
  printf("\n");
}

void destroy_board(char*** board, int row_dim, int col_dim) {
	for (int row = 0; row < row_dim; ++row) {
    free((*board)[row]);
  }
  free(*board);
  *board = NULL;
}
/*Fang's functions*/

/*Set up a integer in main and keep track of drop time*/
/*
void keepTrackOfDropTime(int* drop_time) {
  *drop_time ++;
}

void keepTrackOfEmptySize(int* table_size) {
  *table_size --;
}
*/

/*columnIsFilled and dropPiece are a combo of functions*/
int columnIsFilled(char** board, int drop_col, int* num_rows) {
  for (int i = 0; i < *num_rows; i++) {
    if (board[i][drop_col] == '*') {
      return 1;
    }
  }
  return 0;
}

void dropPiece(char** board, int num_cols , int num_rows, int* drop_time, int* table_size) {
  int drop_col;
  do {
    printf("Enter a column between %d and %d to play in: ", 0, num_cols - 1);
    scanf("%d", &drop_col);
  } while (drop_col< 0 || columnIsFilled(board, drop_col, &num_rows) != 1 || drop_col > num_cols - 1);
  for (int i = num_rows - 1; i >= 0; i--) {
    if (board[i][drop_col] == '*' && (*drop_time %2 == 0)) {
      board[i][drop_col] = 'X';
			*drop_time += 1;
			*table_size -= 1;
			break;
    } else if (board[i][drop_col] == '*' && (*drop_time %2 != 0)) {
      board[i][drop_col] = 'O';
			*drop_time += 1;
			*table_size -= 1;
			break;
    }
  }
	// keepTrackOfDropTime(drop_time);
}

/*The following are a declear win or tie combo*/
void declearTie(int* table_size, char** board , int num_cols, int num_rows) {
  if (*table_size == 0) {
		print_board(board, num_rows, num_cols);
		printf("Tie game!\n");
		destroy_board(&board, num_rows, num_cols);
		exit(0);
  }
}

void winWithARow(char** board, int num_cols, int num_rows, int connect_N) {
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j <= num_cols - connect_N; j ++) {
      int num_of_X = 0;
      int num_of_O = 0;
      for (int k = j; k < j + connect_N; k ++) {
        if (board[i][k] == 'X') {
          num_of_X += 1;
        } else if (board[i][k] == 'O') {
          num_of_O += 1;
        }
        if (num_of_X == connect_N) {
					print_board(board, num_rows, num_cols);
					printf("Player 1 Won!\n");
					destroy_board(&board, num_rows, num_cols);
          exit(0);
        } else if (num_of_O == connect_N) {
					print_board(board, num_rows, num_cols);
					printf("Player 2 Won!\n");
					destroy_board(&board, num_rows, num_cols);
          exit(0);
        }
      }
    }
  }
}

void winWithAColumn(char** board, int num_cols, int num_rows, int connect_N) {
  for (int j = 0; j < num_cols; j ++) {
    for (int i = 0; i <= num_rows - connect_N; i ++) {
      int num_of_X = 0;
      int num_of_O = 0;
      for (int k = i; k < i + connect_N; k ++) {
        if (board[k][j] == 'X') {
          num_of_X += 1;
        } else if (board[k][j] == 'O') {
          num_of_O += 1;
        }
      }
      if (num_of_X == connect_N) {
				print_board(board, num_rows, num_cols);
				printf("Player 1 Won!\n");
				destroy_board(&board, num_rows, num_cols);
        exit(0);
      } else if (num_of_O == connect_N) {
				print_board(board, num_rows, num_cols);
				printf("Player 2 Won!\n");
				destroy_board(&board, num_rows, num_cols);
        exit(0);
      }
    }
  }
}


void winWithDiagonalRight(char** board, int num_cols, int num_rows, int connect_N) {
  for (int i = 0; i <= num_rows - connect_N; i ++) {
    for (int j = 0; j <= num_cols - connect_N; j ++) {
			int num_of_X = 0;
			int num_of_O = 0;
			for (int k = 0; k < connect_N; k ++) {
				if (board[i+k][j+k] == 'X') {
					num_of_X += 1;
				} else if (board[i+k][j+k] == 'O') {
					num_of_O += 1;
				}
			}
			if (num_of_X == connect_N) {
				print_board(board, num_rows, num_cols);
				printf("Player 1 Won!\n");
				destroy_board(&board, num_rows, num_cols);
        exit(0);
      } else if (num_of_O == connect_N) {
				print_board(board, num_rows, num_cols);
				printf("Player 2 Won!\n");
				destroy_board(&board, num_rows, num_cols);
        exit(0);
      }
    }
  }
}


void winWithDiagonalLeft(char** board, int num_cols, int num_rows, int connect_N) {
	for (int i = 0; i <= num_rows - connect_N; i ++) {
		for (int j = num_cols - 1; j >= num_cols - connect_N; j --) {
			int num_of_X = 0;
			int num_of_O = 0;
			for (int k = 0; k < connect_N; k ++) {
				if (board[i+k][j-k] == 'X') {
					num_of_X += 1;
				} else if (board[i+k][j-k] == 'O') {
					num_of_O += 1;
				}
			}
			if (num_of_X == connect_N) {
				print_board(board, num_rows, num_cols);
				printf("Player 1 Won!\n");
				destroy_board(&board, num_rows, num_cols);
        exit(0);
      } else if (num_of_O == connect_N) {
				print_board(board, num_rows, num_cols);
				printf("Player 2 Won!\n");
				destroy_board(&board, num_rows, num_cols);
        exit(0);
      }
		}
	}
}

/* Combo summary function*/
void declearResult(char** board, int num_cols, int num_rows, int connect_N, int* table_size) {
	winWithARow(board, num_cols, num_rows, connect_N);
	winWithAColumn(board, num_cols, num_rows, connect_N);
	winWithDiagonalRight(board, num_cols, num_rows, connect_N);
	winWithDiagonalLeft(board, num_cols, num_rows, connect_N);
	declearTie(table_size, board, num_cols, num_rows);
}
