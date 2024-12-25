#ifndef BOARDTEST_H
#define BOARDTEST_H
#include <vector>
#include <string>
#include "Board.h"

/**
 * @brief The BoardTest class cette classe sert à servir la plupart des méthodes de la classe game.
 */

class BoardTest{

private:
    int testPass_;
    int testFail_;
    std::vector <std::string> listMethodError;
    Board board_;

public:

    /**
     * @brief BoardTest simple constructeur de BoardTest.
     */
    BoardTest();

    /**
     * @brief displayTestResults permet d'afficher le nombre de test réussi ainsi que les ratés
     * avec le nom des méthodes qui ont échoué.
     */
    void displayTestResults();

    /**
     * @brief testCanMove_withImpossibleMove test d'un déplacement impossible
     * présence d'un pion sur la case visé par le déplacement.
     */
    void testCanMove_withImpossibleMove();

    /**
     * @brief testCanMove2_withBomb test d'un déplacement d'une bombe
     */
    void testCanMove2_withBomb();

    /**
     * @brief testCanMove3_withWater test d'un dépacement du pawn special (water)
     */
    void testCanMove3_withWater();

    /**
     * @brief testCanMove4_withPlayer2 test de la méthode move avec un déplacement légale
     */
    void testCanMove4_withPlayer2();

    /**
     * @brief testCanMove5_withCheat test de la méthode move avec une tentaive de triche (déplacement d'un pion de l'adversaire)
     */

    void testCanMove5_withCheat();

    void testCanMove6_neutralTeam();
    void testCanMove7_withWater2();
    void testCanMove8_scoutToNotUnsused();
    void testCanMove9_eclaireurLongMove();
    void testCanMove10_normalPawnWithLongMove();

    void testCanMove11_eclaireurWithPawnInIsWayLongMove();

    void testMove1_withBomb();

    void testMove2_toUnusedPawn();
    void testMove3_redPlayer();

    void testKillPawn1();
    void testKillPawn2();
    void testCanFight1_DEMINEUR_VS_UNUSED();
    void testCanFight2_DEMINEUR_VS_LIEUTANT();
    void testFight1_DEMINEUR_VS_LIEUTANT();
    void testNewPositionAfterMove1();
    void testNewPositionAfterMove2();

    void changePawnSpecifities_possible();
    void changePawnSpecifities2_notPossible();

    /**
     * @brief testIsInside test de la méthode isInside de la classe baord
     */
    void testIsInside();
    /**
     * @brief testIsInside test de la méthode isInside de la classe baord
     */
    void testIsInside2();

    /**
     * @brief testIsInside test de la méthode isInside de la classe baord
     */
    void testIsInside3();

    /**
     * @brief testIsInside test de la méthode isInside de la classe baord
     */
    void testIsInside4();


    /**
     * @brief testIsInside test de la méthode isInside de la classe baord
     */
    void testIsInside5_outOfBoard();

    /**
     * @brief testIsBlocked
     */
    void testIsBlocked();
    /**
     * @brief testIsBlocked
     */
    void testIsBlocked2();
    /**
     * @brief testIsBlocked
     */
    void testIsBlocked3();
    /**
     * @brief testIsBlocked
     */
    void testIsBlocked4();




    void executeTest();


    inline int getTestPass() const{
        return testPass_;
    }

    inline int getTestFail() const{
        return testFail_;
    }






};

#endif // BOARDTEST_H
