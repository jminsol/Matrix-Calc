//
//  matrixDriver.cpp
//  Assignment 1
//
//  Created by JeongMinsol on 2/9/20.
//  Copyright © 2020 JeongMinsol. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>


#include "matrixType.h"

using namespace std;

bool checkValidMatrix (int first, int second, map<int, MatrixType> matrix);

int main()
{
    enum choices { New, Add, Subtract, Multiply, Print, Quit };

    int choice;
    int parameter, parameter1 = 0, parameter2 = 0, parameter3;
    int rowSize, colSize;
    string str, temp;
    map<int, MatrixType> matrix;
    MatrixType case1, case2;
    

    do{
        //Function: Give menu until user input 5. Quit
        cout << "Choice and parameters: " << endl;
        cout << "0 New Matrix           Usage: 0 <matrix> " << endl;
        cout << "1 Add Matrices         Usage: 1 <matrix> <matrix> <matrix>" << endl;
        cout << "2 Subtract Matrices    Usage: 2 <matrix> <matrix> <matrix>" << endl;
        cout << "3 Multiply Matrices    Usage: 3 <matrix> <matrix> <matrix>" << endl;
        cout << "4 Print Matrix         Usage: 4 <matrix>" << endl;
        cout << "5 Quit                 Usage: 5 " << endl << endl;
        
        cout << "Enter Choice and Parameters: ";
        cin >> choice;
        
        //Receive different numbers of value depends on choice
        if (choice == 0 ){
            cin >> parameter;
            
        //Prevent error to save different matrix in a same slot
            if (matrix.find(parameter)!=matrix.end()){
                cout<< "The slot" << parameter << " exists in matrices. Please choose different parameter."<< endl << endl;
                continue;
            }
        }
        else if (choice == 4){
            cin >> parameter;
        }
        else if (choice == 1 || choice == 2 || choice ==3){
            cin >> parameter1 >> parameter2 >> parameter3;
            //check if the matrices a user choose exist
            if (checkValidMatrix(parameter1, parameter2, matrix)){
                case1 = matrix.at(parameter1);
                case2 = matrix.at(parameter2);
            }
            else
                continue;
        }
        else if (choice == 5)
            cout << "Quitting..." << endl;
    
        else {}
        
        //Execute menu based on the choice a user entered.
        switch (choice) {
            case New:
            {
                cout << "Creating new matrix in slot " << parameter <<"." <<endl;
                cout << "Enter row and column size: ";
                cin >> rowSize >> colSize;
               // cout << endl;
                
                matrix.insert( {parameter, MatrixType()});
                matrix.at(parameter).SetSize(rowSize, colSize);
                
                for (int r = 0; r < rowSize; r++){
                    cout << "Row " << r << ": ";
                    for (int c =0; c < colSize; c++){
                        int item;
                        cin >> item;
                        (matrix.at(parameter)).StoreItem(item, r, c);
                    }
                }
                cout<< (matrix.find(parameter))-> second;
                break;
        }
                
            case Add:
            {
                if (case1.AddSubCompatible(case2)){
                    MatrixType case3;
                    MatrixType* ptr = &case3;
                    case1.Add(case2, *ptr);
                    cout <<"\nThe result is stored under slot" << parameter3 << " which is addition of slot" << parameter1 << " and slot" << parameter2 <<endl;
                    cout << case3;
                    matrix.insert({parameter3, case3});

                }
                else
                    cout << "Can't add these two matrices." <<endl;
                break;
            }
            case Subtract:
            {
                if (case1.AddSubCompatible(case2)){
                    MatrixType case3;
                    MatrixType* ptr = &case3;
                    case1.Sub(case2, *ptr);
                    cout <<"\nThe result is stored under slot" << parameter3 << " which is subtraction of slot" << parameter1 << " and slot" << parameter2 <<endl;
                    cout << case3;
                    matrix.insert({parameter3, case3});
                }
                else
                    cout << "Can't subtract these two matrices." <<endl;
                break;
            }
                
            case Multiply:
            {

                //Check compatability between two matrices
                if (case1.MultCompatible(case2)){
                    MatrixType case3;
                    MatrixType* ptr = &case3;
                    case1.Mult(case2, *ptr);
                    cout <<"\nThe result is stored under slot" << parameter3 << " which is multiplication of slot" << parameter1 << " and slot" << parameter2 <<endl;
                    cout << case3;
                    matrix.insert({parameter3, case3});
                }
                else
                    cout << "Can't multiply these two matrices. " << endl;
            
                break;
            }
            case Print:{
                ofstream outfile;
                string fname = "Slot " + to_string(parameter);
                outfile.open(fname);
                matrix.at(parameter).Print(outfile);
                cout << fname <<" has been printed" <<endl;
                outfile.close();
                break;
            }
            case Quit:
                break;
                
            default:
                cout << "Wrong input. Please enter right number of menu." << endl << endl;
                break;
        }

    } while (choice != Quit);

    
    return 0;
}

bool checkValidMatrix(int first, int second, map<int, MatrixType> matrix){
    //PRE:  More than one matrices has been initialized
    //      Received two parameters for operations.
    //POST: Return Ture if all the matrices exist otherwise, false
    
    bool validity = false;
    if (matrix.find(first) ==  matrix.end() || matrix.find(second) == matrix.end()){
        cout<< "Can't find slots. Please check it again" << endl;
        return validity;

    }
    else
        return validity = true;
}
