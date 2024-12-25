#include "Board.h"
#include "vector"
#include "BoardTest.h"
using namespace std;


BoardTest::BoardTest():testPass_{0},testFail_{0},listMethodError{},board_{56387}{
}



void BoardTest::displayTestResults(){

    cout << endl;
    for (auto & e : listMethodError){
        cout << e << endl;
    }
    if(listMethodError.size() == 0){
        cout  << "=====================================" << endl;

        cout << "All tests passed " << endl;
    }
}

void BoardTest::testCanMove_withImpossibleMove(){

    if(!board_.canMove(BLUE,Position{0,0},SOUTH)){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__FUNCTION__) ;
    }
}
void BoardTest::testCanMove2_withBomb(){

    if(!board_.canMove(BLUE, Position{3,0}, SOUTH)){

        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;

    }
}
void BoardTest::testCanMove3_withWater(){

    if(!board_.canMove(BLUE, Position{3,3}, SOUTH)){

        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }
}
void BoardTest::testCanMove4_withPlayer2(){
    if(board_.canMove(RED, Position{6,4}, NORTH)){

        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }
}

void BoardTest::testCanMove5_withCheat(){

    if(board_.canMove(BLUE, Position{6,4}, NORTH)){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }

}
void BoardTest::testCanMove6_neutralTeam(){
    if(!board_.canMove(NEUTRAL , Position{5,0}, NORTH)){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }


}
void BoardTest::testCanMove7_withWater2(){
    if(!board_.canMove(NEUTRAL , Position{4,2}, EAST)){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }


}
void BoardTest::testCanMove8_scoutToNotUnsused(){

    if(!board_.canMove(BLUE , Position{3,5}, SOUTH,2)){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }


}
void BoardTest::testCanMove9_eclaireurLongMove(){
    if(!board_.canMove(BLUE , Position{3,5}, SOUTH,3)){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }


}
void BoardTest::testCanMove10_normalPawnWithLongMove(){
    if(!board_.canMove(BLUE , Position{3,4}, SOUTH,2)){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }


}
void BoardTest::testCanMove11_eclaireurWithPawnInIsWayLongMove(){

    board_.setPawnTest(Position{7,5},Pawn{UNUSED}, 54685);

    if(!board_.canMove(BLUE , Position{3,5}, SOUTH,4)){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }


}

//void BoardTest::testMove1_withBomb(){


//    if(!board_.move({3,0}, SOUTH)){
//        testPass_++;
//    }else{
//        testFail_++;
//        listMethodErro.push_back(__func__) ;
//    }

//}
void BoardTest::testMove2_toUnusedPawn(){

    board_.move({3,4},SOUTH);
    if(board_.getBoard()[3][4].getPawnType() == UNUSED &&
            board_.getBoard()[4][4].getPawnType() == MINER ){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }


}
void BoardTest::testMove3_redPlayer(){
    board_.move({6,4},NORTH);
    if(board_.getBoard()[6][4].getPawnType() == UNUSED &&
            board_.getBoard()[5][4].getPawnType() == MINER ){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }

}


void BoardTest::testKillPawn1(){

    board_.killPawn({0,0},BLUE);
    if(board_.getBoard()[0][0].getPawnType() == UNUSED ){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }

}

void BoardTest::testKillPawn2(){
    board_.killPawn({1,1},BLUE);
    if(board_.getBoard()[1][1].getPawnType() == UNUSED ){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }

}

void BoardTest::testCanFight1_DEMINEUR_VS_UNUSED(){

    if(!board_.canFight(BLUE,{3,4},SOUTH,1)){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }


}
void BoardTest::testCanFight2_DEMINEUR_VS_LIEUTANT(){
    if(board_.canFight(BLUE,{3,5},SOUTH,3)){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }


}

void BoardTest::testFight1_DEMINEUR_VS_LIEUTANT(){

    board_.fight({3,5}, SOUTH,3);
    if(board_.getBoard()[3][5].getPawnType() == UNUSED){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }


}
void BoardTest::testNewPositionAfterMove1(){

    Position pos = board_.newPositionAfterMove({0,0},EAST,4);
    if(pos.getRow() == 0 &&  pos.getColumn() == 4 ){  //surcharger le == dans position?
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }

}
void BoardTest::testNewPositionAfterMove2(){

    Position pos = board_.newPositionAfterMove({5,5},NORTH,1);
    if(pos.getRow() == 4 &&  pos.getColumn() == 5 ){  //surcharger le == dans position?
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__) ;
    }

}

void BoardTest::testIsInside(){

    if(board_.isInside({4,5})){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__);
    }



}

void BoardTest::testIsInside2(){

    if(!board_.isInside({-6,5})){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__);
    }

}

void BoardTest::testIsInside3(){


    if(board_.isInside({9,9})){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__);
    }

}


void BoardTest::testIsInside4(){


    if(!board_.isInside({10,9})){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__);
    }

}

void BoardTest::testIsInside5_outOfBoard(){


    if(!board_.isInside({-12,-9})){
        testPass_++;
    }else{
        testFail_++;
        listMethodError.push_back(__func__);
    }

}

//void BoardTest::testIsBlocked(){
//    if(board_.isBlocked({9,9})){
//        testPass_++;
//    }else{
//        testFail_++;
//        listMethodErro.push_back(__func__);
//    }

//}
//void BoardTest::testIsBlocked2(){

//    if(!board_.isBlocked({7,4})){
//        testPass_++;
//    }else{
//        testFail_++;
//        listMethodErro.push_back(__func__);
//    }

//}
//void BoardTest::testIsBlocked3(){
//    if(!board_.isBlocked({3,4})){
//        testPass_++;
//    }else{
//        testFail_++;
//        listMethodErro.push_back(__func__);
//    }

//}
//void BoardTest::testIsBlocked4(){

//    if(!board_.isBlocked({3,3})){
//        testPass_++;
//    }else{
//        testFail_++;
//        listMethodErro.push_back(__func__);
//    }

//}





void BoardTest::executeTest(){

   // testIsBlocked3();
    testCanMove_withImpossibleMove();
    testCanMove2_withBomb();
    testCanMove3_withWater();
    testCanMove4_withPlayer2();
    // testCanMove5_withCheat(); lance une exce  ption
    testCanMove6_neutralTeam();
    testCanMove7_withWater2();
    testCanMove8_scoutToNotUnsused();
    testCanMove9_eclaireurLongMove();
    testCanMove10_normalPawnWithLongMove();
    testCanMove11_eclaireurWithPawnInIsWayLongMove();
    //testMove1_withBomb();
    testMove2_toUnusedPawn();
    testKillPawn1();
    testKillPawn2();
    testCanFight1_DEMINEUR_VS_UNUSED();
    testCanFight2_DEMINEUR_VS_LIEUTANT();
    testFight1_DEMINEUR_VS_LIEUTANT();
    testNewPositionAfterMove1();
    testNewPositionAfterMove2();
    testMove3_redPlayer();
    testIsInside();
    testIsInside2();
    testIsInside4();
    testIsInside5_outOfBoard();
//    testIsBlocked();
//    testIsBlocked2();
//    testIsBlocked4();


}




