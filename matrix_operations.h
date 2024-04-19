#ifndef MATROP_H
#define MATROP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROWS 6
#define COLS 6

double CalcDeterminant(double matrix[ROWS][COLS]);

double CalcAverageDeterminant(const double *determinants, int num_determinants);

void GenerateRandomMatrix(double matrix[ROWS][COLS]);
#endif