OBJS    = shell.o
SOURCE    = shell.c
HEADER    = 
OUT    = shell
CC     = gcc
FLAGS     = -g -c -Wall
LFLAGS     = -lreadline

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

shell.o: shell.c
	$(CC) $(FLAGS) shell.c 


clean:
	rm -f $(OBJS) $(OUT)
 
