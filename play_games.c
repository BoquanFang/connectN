#include<stdio.h>
#include"functions_use_2.h"

int main(int argc, char** argv) {
	int rows_num;
	int cols_num;
	int connect_N;
	is_argc_correct(argc-1);
	sscanf(argv[1], " %d", &rows_num);
  sscanf(argv[2], " %d", &cols_num);
  sscanf(argv[3], " %d", &connect_N);
  read_args(argc - 1, rows_num, cols_num, connect_N);
	/* Use Zhou's command lines */
	int drop_time = 0;
	int table_size;
	table_size = (rows_num * cols_num);
	char** board = create_board(rows_num, cols_num);
	while (1) {
		print_board(board, rows_num, cols_num);
		dropPiece(board, cols_num, rows_num, &drop_time, &table_size);
		declearResult(board, cols_num, rows_num, connect_N, &table_size);
	}
}
