#include "PawnTest.h"
#include <iostream>
using namespace std;
PawnTest::PawnTest(): testPass{0},testFail{0},listMethodError{}{

}

void PawnTest::displayTestResults(){

    cout << endl;
    for (auto & e : listMethodError){
        cout << e << endl;
    }
    if(listMethodError.size() == 0){
        cout  << "=====================================" << endl;

        cout << "All tests passed " << endl;
    }
}

void PawnTest::testOperatorDoubleEqual(){

    Pawn pawn {LIEUTENANT,RED};
    Pawn pawn2 {SPY,BLUE};

    if(pawn == pawn2){
        testFail++;
        listMethodError.push_back(__FUNCTION__) ;
    }else{
        testPass++;
    }

}
void PawnTest::testOperatorDoubleEqual2(){

    Pawn pawn {MARSHAL,RED};
    Pawn pawn2 {MARSHAL,BLUE};

    if(pawn == pawn2){
        testPass++;
    }else{
        testFail++;
        listMethodError.push_back(__FUNCTION__) ;
    }

}

void PawnTest::testOperatorMultiplication(){


    Pawn pawn {SPY,RED};
    Pawn pawn2 {MARSHAL,BLUE};

    if(pawn*pawn2 == pawn.getPawnTeam()){
        testPass++;
    }else{
        testFail++;
        listMethodError.push_back(__FUNCTION__) ;
    }


}

void PawnTest::testOperatorMultiplication2(){


    Pawn pawn {SCOUT,BLUE};
    Pawn pawn2 {FLAG,RED};

    if(pawn*pawn2 == BLUE){
        testPass++;
    }else{
        testFail++;
        listMethodError.push_back(__FUNCTION__) ;
    }


}
void PawnTest::testOperatorMultiplication3(){


    Pawn pawn {SPY,RED};
    Pawn pawn2 {SERGEANT,BLUE};

    if(pawn*pawn2 == BLUE){
        testPass++;
    }else{
        testFail++;
        listMethodError.push_back(__FUNCTION__) ;
    }


}
void PawnTest::testOperatorMultiplication4(){


    Pawn pawn {MARSHAL,RED};
    Pawn pawn2 {SPY,BLUE};

    if(pawn*pawn2 == RED){
        testPass++;
    }else{
        testFail++;
        listMethodError.push_back(__FUNCTION__) ;
    }


}
void PawnTest::testOperatorMultiplication5(){


    Pawn pawn {MAJOR,RED};
    Pawn pawn2 {COMMANDANT,BLUE};

    if(pawn*pawn2 == RED){
        testPass++;
    }else{
        testFail++;
        listMethodError.push_back(__FUNCTION__) ;
    }


}
void PawnTest::testOperatorMultiplication6(){


    Pawn pawn {MINER,RED};
    Pawn pawn2 {BOMB,BLUE};

    if(pawn*pawn2 == RED){
        testPass++;
    }else{
        testFail++;
        listMethodError.push_back(__FUNCTION__) ;
    }


}
void PawnTest::testOperatorMultiplication7(){


    Pawn pawn {LIEUTENANT,RED};
    Pawn pawn2 {LIEUTENANT,BLUE};

    if(pawn*pawn2 == NEUTRAL){
        testPass++;
    }else{
        testFail++;
        listMethodError.push_back(__FUNCTION__) ;
    }


}


void PawnTest::executeTest(){
    testOperatorDoubleEqual();
    testOperatorDoubleEqual2();
    testOperatorMultiplication();
    testOperatorMultiplication2();
    testOperatorMultiplication3();
    testOperatorMultiplication4();
    testOperatorMultiplication5();
    testOperatorMultiplication6();
    testOperatorMultiplication7();
}
