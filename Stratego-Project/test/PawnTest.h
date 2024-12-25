#ifndef PAWNTEST_H
#define PAWNTEST_H
#include <vector>
#include <string>
#include "Pawn.h"

/**
 * @brief The PawnTest class cette classe sert à servir la plupart des méthodes de la classe game.
 */

class PawnTest{

private:
    int testPass;
    int testFail;
    std::vector <std::string> listMethodError;


public:

    /**
     * @brief PawnTest simple constructeur de PawnTest.
     */
    PawnTest();

    /**
     * @brief displayTestResults permet d'afficher le nombre de test réussi ainsi que les ratés
     * avec le nom des méthodes qui ont échoué.
     */
    void displayTestResults();




    /**
     * @brief testOperatorDoubleEqual test de la surcharge de l'opérateur ==
     */
    void testOperatorDoubleEqual();

    /**
     * @brief testOperatorDoubleEqual test de la surcharge de l'opérateur ==
     */
    void testOperatorDoubleEqual2();

    /**
     * @brief testOperatorMultiplication test de la surcharge de l'opérator *
     */
    void testOperatorMultiplication();

    /**
     * @brief testOperatorMultiplication test de la surcharge de l'opérator *
     */
    void testOperatorMultiplication2();

    /**
     * @brief testOperatorMultiplication test de la surcharge de l'opérator *
     */
    void testOperatorMultiplication3();

    /**
     * @brief testOperatorMultiplication test de la surcharge de l'opérator *
     */
    void testOperatorMultiplication4();

    /**
     * @brief testOperatorMultiplication test de la surcharge de l'opérator *
     */
    void testOperatorMultiplication5();

    /**
     * @brief testOperatorMultiplication test de la surcharge de l'opérator *
     */
    void testOperatorMultiplication6();

    /**
     * @brief testOperatorMultiplication test de la surcharge de l'opérator *
     */
    void testOperatorMultiplication7();





    inline int getTestPass() const{
        return testPass;
    }

    inline int getTestFail() const{
        return testFail;
    }


    void executeTest();





};
#endif // PAWNTEST_H
