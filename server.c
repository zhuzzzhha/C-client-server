#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "erprocessing.h"
#include "matrix_operations.h"


int main() {

    int server = Socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;
    adr.sin_port = htons(34570);

    Bind(server, (struct sockaddr *) &adr, sizeof adr);

    Listen(server, 5);

    socklen_t adrlen = sizeof adr;

    int fd = Accept(server, (struct sockaddr *) &adr, &adrlen);
 
    double determinants[5];
    int num_determinants = 0;

while(1) {
    char buf[ROWS*COLS];
    int nread = read(fd, buf, ROWS*COLS);
    if (nread == -1) {
        perror("reading failed");
        exit(EXIT_FAILURE);
    }
    if (nread == 0) {
        printf("end of file occured\n");
    }

    double data_matrix[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
            
                data_matrix[i][j] = (double)buf[i*j + j];
            }
        }
    
    double determinant = CalcDeterminant(data_matrix);
    if (num_determinants < 5) {
            num_determinants++;
        }
    double avg_determinant = CalcAverageDeterminant(determinants, num_determinants);

        double prev_determinant = 0;
        if (num_determinants >= 5) {
            prev_determinant = determinants[0];
        }

        printf("Det. =  %.1f\n", determinant);
        if(num_determinants < 5) {
            printf("Avg. det = N/A\n");
            printf("Del. det = N/A\n");
        }
        else {
            printf("Avg. det =  %.1f\n", avg_determinant);
            printf("Del. det =  %.1f\n\n", prev_determinant);
        }

        for (int i = 4; i > 0; i--) {
            determinants[i] = determinants[i - 1];
        }

        determinants[0] = determinant;

        
}

    close(fd);
    close(server);
    return 0;
}