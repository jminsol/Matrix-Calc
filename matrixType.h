//
//  matrixType.h
//  Assignment 1
//
//  Created by JeongMinsol on 2/9/20.
//  Copyright © 2020 JeongMinsol. All rights reserved.
//

#ifndef matrixType_h
#define matrixType_h
#include <fstream>
// Need pre-conditions and post-conditions
const int MAX_ROWS = 10;
const int MAX_COLS = 10;
class MatrixType
{
public:
    MatrixType();
    //constructor
    
    MatrixType(int rowSize, int colSize);
    
    void MakeEmpty();
    // Function: Return the list to the empty state
    // Post:  List is empty
    
    void SetSize(int rowsSize, int colSize);
    //Function: Initialize list
    //Pre: Receive user's input
    //Post: Make a list with rowSize of height and colSize of width
    
    void StoreItem(int item, int row, int col);
    //Pre:  Received user's input.
    //      List size has been initialized
    //Post: Store values according to its colum/row size
    
    void Add(MatrixType otherOperand, MatrixType& result);
    //Pre:  List has been initialized
    //Post: Add first and second matrices from otherOperand and leave the result on result parameter
    
    void Sub(MatrixType otherOperand, MatrixType& result);
    //Pre:  List has been initialized
    //Post: Subtract second from the first of otherOperand and leave the result on result parameter
    
    void Mult(MatrixType otherOperand, MatrixType& result);
    //Pre:  List has been initialized
    //Post: Multiply first and second matrices from otherOperand and leave the result on result parameter
    
    void Print(std::ofstream& outfile);
    //Pre:  List has been initialized
    //      outFile is open for writing
    //Post: Each component in list has been written to outfile
    //      outfile is closed
    
    bool AddSubCompatible(MatrixType otherOperand);
    //Pre:  List has been initialized
    //      User chose to do Add or Sub on the list
    //Post:True if it is compatible or False.
    
    bool MultCompatible(MatrixType otherOperand);
    //Pre:  List has been initialized
    //      User chose to do Mult on the list
    //Post:True if it is compatible or False.
    
    friend std::ostream & operator<<(std::ostream &, const MatrixType &);
    //Function: Display Matrix
    //Pre: The array has been initialized
    //Post: Display matrix newline per row
    

private:
    int *values;
    //int values[MAX_ROWS][MAX_COLS];
    int numRows;
    int numCols;
};

#endif /* matrixType_h */
