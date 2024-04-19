#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "erprocessing.h"
#include "matrix_operations.h"


int main() {
    int fd = Socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;
    adr.sin_port = htons(34570);

    Inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);

    Connect(fd, (struct sockaddr *) &adr, sizeof adr);
    
    int c;
    
    while((c=getchar())!=EOF) {

    double data_matrix[ROWS][COLS];
    GenerateRandomMatrix(data_matrix);
    char buf[ROWS*COLS];
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            buf[i*j + j] = data_matrix[i][j];
                
        }
    }
   
    write(fd, buf, sizeof(char)*ROWS*COLS);
    }
    close(fd);
    return 0;
}