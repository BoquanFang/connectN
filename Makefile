connectn.out: play_games.o functions_use_2.o
	gcc -g -Wall -Werror -o connectn.out play_games.o functions_use_2.o

functions_use_2.o: functions_use_2.c functions_use_2.h
	gcc -g -Wall -Werror -c functions_use_2.c

play_games.o: play_games.c functions_use_2.h
	gcc -g -Wall -Werror -c play_games.c

clean:
	rm -fr *.o *.out
