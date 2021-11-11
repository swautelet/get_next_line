FILES = get_next_line.c get_next_line_utils.c get_next_line.h
PROG = tester.c get_next_line.c get_next_line_utils.c
FLAGS = -Werror -Wall -Wextra
BUFFER = -D BUFFER_SIZE=42
BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
all : 
	gcc -g $(FLAGS) $(BUFFER) $(PROG) -o tester
	./tester

%.o : %.c
	gcc $(FLAGS) $?

save :
	git add $(FILES) $(BONUS)
	git commit -m autosave
	git push