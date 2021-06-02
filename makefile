CC = gcc

LIBS=-L/usr/local/lib -I/user/local/include -lreadline 

CFLAGS = $(COMPILER_WARNINGS) $(GDB_FLAGS)


make:	shell
	$(CC) $(CFLAGS) shell.c $@ $^ $(LIBS) -o shell

clean:	
	rm shell
