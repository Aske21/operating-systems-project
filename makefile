CC = gcc
clean: 
	rm shell
make:	shell
	@echo "Compiling..."
	sudo apt-get install libreadline6 libreadline6-dev
	${CC} shell.c -L/usr/local/lib -I/user/local/include -lreadline -o shell

