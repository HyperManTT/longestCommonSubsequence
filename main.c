//
//  main.c
//  longestCommonSubsequence
//
//  Created by Randy Ram on 11/10/2015.
//  Copyright (c) 2015 Randy Ram. All rights reserved.
//

#include <stdio.h>
#include "string.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

void printArray(int numRow, int numCol,  int dpArray[][numCol])
{
    //printf("%d\n", dpArray[1][4]);
    for (int i = 0; i <= numRow; i++)
    {
        for (int j = 0; j < numCol; j++) {
            printf("%d ", dpArray[i][j]);
        }
        printf("\n");
    }
}


void printLCS(int numRow, int numCol, int dpArray[][numCol], char* X, char* Y)
{
    //printf("%c %c \n", X[numCol - 1], Y[numRow - 1]);
    if (numRow == 0 || numCol == 0) {
        return;
    }
    if (X[numCol - 1] == Y[numRow - 1]) {
        printLCS(numRow - 1, numCol - 1, dpArray, X, Y);
        printf("%c ", Y[numRow - 1]);
    }
    else
    {
        if (dpArray[numRow][numCol - 1] >= dpArray[numRow - 1][numCol]) {
            printLCS(numRow, numCol - 1, dpArray, X, Y);
        }
        else
        {
            printLCS(numRow - 1, numCol, dpArray, X, Y);
        }
    }
}

void getLCS(char* X, char* Y)
{
    int numCols = strlen(X);
    int numRows = strlen(Y);
    int dpArray[numRows + 1][numCols + 1];
    //Initialize everything to 0
   for (int i = 0 ; i <= numRows; i++)
   {
       for (int j = 0; j <= numCols; j++)
       {
           dpArray[i][j] = 0;
       }
   }
 
    //Perform the dynamic programming part
    for (int k = 1; k <= numRows; k++) {
        for (int l = 1; l <= numCols; l++) {
            //printf("%c, %c\n", X[l - 1], Y[k - 1]);
            if (X[l - 1] == Y[k - 1])
            {
                dpArray[k][l] = dpArray[k-1][l - 1] + 1;
            }
            else
            {
                dpArray[k][l] = MAX(dpArray[k - 1][l], dpArray[k][l-1]);
            }
            //printf("%d", dpArray[1][4]);
            //printf("\n");
            //printArray(numRows, numCols + 1, dpArray);
            //printf("\n");
        }
    }
    
    printArray(numRows, numCols + 1, dpArray);
    printf("\n");
    printLCS(numRows, numCols, dpArray, X, Y);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char* X = "BDCABA";
    char* Y = "ABCBDAB";
    
    getLCS(X, Y);
    return 0;
    
}
