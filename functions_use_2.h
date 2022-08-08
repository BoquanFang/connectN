#ifndef FUNCTIONS_USE_2_H
#define FUNCTIONS_USE_2_H

	void is_argc_correct(int argc);
	void read_args(int numReads, int num_rows, int num_cols, int num_connectN);
	char** create_board (int row_dim, int col_dim);
	void print_board(char** board, int row_dim, int col_dim);
	void destroy_board(char*** matrix, int row_dim, int col_dim);
	void keepTrackOfEmptySize(int* table_size);
	int columnIsFilled(char** board, int drop_col, int* num_rows);
	void dropPiece(char** board, int num_cols , int num_rows, int* drop_time, int* table_size);
	void declearTie(int* table_size, char** board , int num_cols, int num_rows);
	void winWithARow(char** board, int num_cols, int num_rows, int connect_N);
	void winWithAColumn(char** board, int num_cols, int num_rows, int connect_N);
	void winWithDiagonalRight(char** board, int num_cols, int num_rows, int connect_N);
	void winWithDiagonalLeft(char** board, int num_cols, int num_rows, int connect_N);
	void destroy_board(char*** board, int row_dim, int col_dim);
	void declearResult(char** board, int num_cols, int num_rows, int connect_N, int* table_size);

#endif
