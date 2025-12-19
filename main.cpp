/*
* This program prints out
* the Magic Sqaures.
*
* @author  D. Jeffrey
* @version 1.0
* @since   2025-12-19
*/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::vector;


class Main {
 public:
    /** The top left index. */
    static const int ZERO = 0;
    /** The top middle index. */
    static const int ONE = 1;
    /** The top right index. */
    static const int TWO = 2;
    /** The middle left index. */
    static const int THREE = 3;
    /** The center index. */
    static const int FOUR = 4;
    /** The middle right index. */
    static const int FIVE = 5;
    /** The lower left index. */
    static const int SIX = 6;
    /** The lower center index. */
    static const int SEVEN = 7;
    /** The lower right index. */
    static const int EIGHT = 8;
    /** The maximum number for magicNumbers. */
    static const int NINE = 9;
    /** The maximum number for magicNumbers. */
    static const int MAGICNUM = 15;

    /**
    * Process numbers.
    */
    int numberOfProcess = 0;
    /**
     * Number of magic squares.
     */
    int numberOfMagicSquares = 0;


    /**
     * Generates all possible 3x3 magic squares.
     * Heap's Algorithm explanation and code from https://www.geeksforgeeks.org/dsa/heaps-algorithm-for-generating-permutations/
     *
     * @param square The current state of the square being generated.
     * @param size the current index after the section that is undergoing "permutation" (AKA reordering all values up until size - 1)
     */
    void genSquare(vector<int> square, int size) {
        // if size becomes 1 then prints the square
        if (size == 1) {
            numberOfProcess ++;
            if (isMagic(square)) {
                printMagicSquare(square);
                numberOfMagicSquares++;
            }
        }

        // loop through each position of the part of the array that is actively changing, generate all possible combinations of elements up until size - 1
        for (int counter = 0; counter < size; counter++) {
            genSquare(square, size - 1);

            // if size is odd, swap first and (size-1)th element
            if (size % 2 == 1) {
                int temporaryFirstValue = square[0];
                square[0] = square[size - 1];
                square[size - 1] = temporaryFirstValue;

            // If size is even, swap ith and 
            // (size-1)th i.e (last) element
            } else {
                int temporaryCounterValue = square[counter];
                square[counter] = square[size - 1];
                square[size - 1] = temporaryCounterValue;
            }
        }
    }

    /**
     * Checks if the given square is a magic square.
     *
     * @param preSquare The square to check.
     * @return True if the square is a magic square, false otherwise.
     */
    bool isMagic(vector<int> preSquare) {
        // returns true or false for whether or not array is a magic square
        // this assumes there are no repeats in the square
        int row1 = preSquare[ZERO] + preSquare[ONE] + preSquare[TWO];
        int row2 = preSquare[THREE] + preSquare[FOUR] + preSquare[FIVE];
        int row3 = preSquare[SIX] + preSquare[SEVEN] + preSquare[EIGHT];
        int col1 = preSquare[ZERO] + preSquare[THREE] + preSquare[SIX];
        int col2 = preSquare[ONE] + preSquare[FOUR] + preSquare[SEVEN];
        int col3 = preSquare[TWO] + preSquare[FIVE] + preSquare[EIGHT];
        int diag1 = preSquare[ZERO] + preSquare[FOUR] + preSquare[EIGHT];
        int diag2 = preSquare[TWO] + preSquare[FOUR] + preSquare[SIX];

        return row1 == MAGICNUM && row2 == MAGICNUM && row3 == MAGICNUM
               && col1 == MAGICNUM && col2 == MAGICNUM
               && col3 == MAGICNUM && diag1 == MAGICNUM && diag2 == MAGICNUM;
    }

    /**
     * Prints the given square in a 3x3 magic square format.
     *
     * @param outputSquare The square to print.
     */
    void printMagicSquare(vector<int> outputSquare) {
        // prints inputted array in a magic square format
        cout << "\n\n*****\n";
        for (int count = 0; count < NINE; count++) {
            if (count == THREE || count == SIX) {
                cout << "\n";
                cout << outputSquare[count] << " ";
            } else {
                cout << outputSquare[count] << " ";
            }
        }
        cout << "\n\n*****";
    }

    /**
     * This is the main function.
     */
    void main() {
        // main stub, get user input here
        std::vector<int> magicSquare = {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
        cout << "\n\n";
        cout << "\nAll Possible Magic Squares (3x3):\n";
        genSquare(magicSquare, NINE);

        cout << "\n\nNumber of processes: " << numberOfProcess;
        cout << "\nNumber of Magic Squares: " << numberOfMagicSquares;
        cout << "\n\nDone.";
    }
};