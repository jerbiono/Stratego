#include <iostream>
#include <Position.h>
#include "BoardTest.h"
#include "PawnTest.h"

using namespace std;

int main()
{
    BoardTest boardTest{};
    boardTest.executeTest();
    cout << "Class Board test : " << endl;
    cout << "test passed : " << boardTest.getTestPass() << " test failed: " << boardTest.getTestFail();


    boardTest.displayTestResults();

    cout << endl;
    PawnTest pawnTest{};
    pawnTest.executeTest();
    cout << "Class Pawn test : " << endl;
    cout << "test passed : " << pawnTest.getTestPass() << " test failed: " << pawnTest.getTestFail();


    pawnTest.displayTestResults();



    return 0;
}
