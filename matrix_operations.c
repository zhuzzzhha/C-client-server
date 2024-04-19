#include "matrix_operations.h"

double CalcDeterminant(double matrix[ROWS][COLS]) {
    
    double copy[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            copy[i][j] = matrix[i][j];
        }
    }

    double det = 1;
    for (int i = 0; i < ROWS; i++) {
        double divisor = copy[i][i];
        if (divisor == 0) {
            return 0;
        }
        det *= divisor;
        for (int j = 0; j < COLS; j++) {
            copy[i][j] /= divisor;
        }

        for (int j = i + 1; j < ROWS; j++) {
            double multiplier = copy[j][i];
            for (int k = 0; k < COLS; k++) {
                copy[j][k] -= multiplier * copy[i][k];
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        det *= copy[i][i];
    }

    return det;
}


double CalcAverageDeterminant(const double *determinants, int num_determinants) {
    double sum = 0;
    for (int i = 0; i < num_determinants; i++) {
        sum += determinants[i];
    }

    return sum / num_determinants;
}


void GenerateRandomMatrix(double matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = (double)rand() / 1000;
        }
    }
}