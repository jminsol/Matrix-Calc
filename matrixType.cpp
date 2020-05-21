//
//  matrixType.cpp
//  Assignment 1
//
//  Created by JeongMinsol on 2/9/20.
//  Copyright © 2020 JeongMinsol. All rights reserved.
//

#include "matrixType.h"
#include <iostream>

MatrixType:: MatrixType()
{
    numRows = 0;
    numCols = 0;
}

void MatrixType::MakeEmpty()
{
    numRows=0;
    numCols=0;
}
void MatrixType::SetSize(int rowSize, int colSize)
{
    
    values = new int[rowSize*colSize];
    numRows = rowSize;
    numCols = colSize;
}


void MatrixType::StoreItem(int item, int row, int col)
{
    values[row*numCols + col] = item;
}

void MatrixType::Add(MatrixType otherOperand, MatrixType &result)
{
    result.SetSize(numRows, numCols);
    int newelement;
    for (int r = 0; r < numRows; r++){
        for(int c =0; c< numCols; c++){
            newelement=values[r*numCols+c] + otherOperand.values[r*numCols+c];
            result.StoreItem(newelement, r, c);
            newelement=0;
        }
    }
}

void MatrixType::Sub(MatrixType otherOperand, MatrixType &result){
    result.SetSize(numRows, numCols);
    int newelement;
    for (int r = 0; r < numRows; r++){
        for(int c =0; c< numCols; c++){
            newelement=values[r*numCols+c] - otherOperand.values[r*numCols+c];
            result.StoreItem(newelement, r, c);
            newelement=0;
        }
    }
}

void MatrixType::Mult(MatrixType otherOperand, MatrixType &result)
{
    result.SetSize(numRows, otherOperand.numCols);
    int newelement=0;
    for (int r = 0; r < numRows; r++){
        for (int other_c = 0; other_c < otherOperand.numCols; other_c++){
            for(int c =0; c < numCols; c++){ // c == other_row
            newelement+=values[r*numCols+c]*otherOperand.values[c*otherOperand.numCols+other_c];
        }
        result.StoreItem(newelement, r, other_c);
        newelement=0;
        }
    }
    }

void MatrixType::Print(std::ofstream &outfile){
    
    for (int r =0; r < numRows; r ++){
        for(int c =0; c < numCols; c++){
            if (c == 0){
                outfile << "[ ";
            }
            else if (c == numCols-1){
                outfile << " ";
                outfile << values[(r*numCols) + c];
                outfile << " ]\n";
                continue;
            }
            else
                outfile << " ";
            outfile << values[(r*numCols) + c];
        }
    }
    }

bool MatrixType::AddSubCompatible(MatrixType otherOperand)
{
    return numRows == otherOperand.numRows && numCols == otherOperand.numCols;
}

bool MatrixType::MultCompatible(MatrixType otherOperand)
{
    return numCols == otherOperand.numRows;
}

std::ostream &operator<<(std::ostream & os, const MatrixType & obj){

    for (int r =0; r < obj.numRows; r ++){
        for(int c =0; c < obj.numCols; c++){
            if (c == 0){
                os << "[ ";
            }
            else if (c == obj.numCols-1){
                os << " ";
                os << obj.values[(r*obj.numCols) + c];
                os << " ]\n";
                continue;
            }
            else
                os << " ";
        os << obj.values[(r*obj.numCols) + c];
        }
    }
    return os;
}
