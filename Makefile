FILES = get_next_line.c get_next_line_utils.c get_next_line.h
PROG = tester.c get_next_line.c get_next_line_utils.c
FLAGS = -Werror -Wall -Wextra
BUFFER = -D BUFFER_SIZE=1000000

all : 
	gcc -g $(FLAGS) $(BUFFER) $(PROG) -o tester
	./tester

%.o : %.c
	gcc $(FLAGS) $?

save :
	git add $(FILES)
	git commit -m autosave
	git push