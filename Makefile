# Makefile

client: client.c erprocessing.c matrix_operations.c
	gcc client.c erprocessing.c matrix_operations.c -W -Wall -Werror -o client

server: server.c erprocessing.c matrix_operations.c
	gcc server.c erprocessing.c matrix_operations.c -W -Wall -Werror -o server

chmod:
	chmod a+x c.sh
	chmod a+x s.sh

run_server: server
	./server

run_client: client
	./client
