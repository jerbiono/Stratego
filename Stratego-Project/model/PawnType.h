#ifndef PAWNTYPE_H
#define PAWNTYPE_H

/**
 * @brief The PawnType enum représente les différents types possibles d'un tel pion.
 */
enum PawnType : char {

    MARSHAL = 'M', //force = 10
    GENERAL = 9,
    COLONEL = 8,
    MAJOR = 7,
    COMMANDANT = 6,
    LIEUTENANT = 5,
    SERGEANT = 4,
    MINER = 3,
    SCOUT = 2,
    SPY = 1,
    FLAG = 'D',  //force = -2
    BOMB = 'B',    //force = 11
    UNUSED = ' ' ,  //force = 0
    SPECIAL = '/'  , //force = -1
};


#endif // PAWNTYPE_H
