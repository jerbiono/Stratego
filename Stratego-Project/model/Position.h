#ifndef POSITION_H
#define POSITION_H

/**
 * @brief représente la postition des pions dans le plateau de jeu.
 *
 */
class Position{

    int row_;
    int column_;

public:
    /**
     * @brief Position Simple constructeur de pion.
     */
    Position();

    /**
 * @brief Position Simple constructeur de position.
 * @param x la ligne donnée.
 * @param y la colonne donée.
 */
    Position(int row, int column);

    /**
 * @brief simple getteur de ligne.
 *
 * @return int la ligne.
 */
    inline int getRow() const{

         return row_;
    }

    /**
 * @brief simple getteur de colonne.
 *
 * @return int la colonne.
 */
    inline int getColumn() const{
        return column_;

    }

    /**
 * @brief simple setteur de position.
 *
 * @param row la nouvelle ligne.
 * @param column la nouvelle colonne.
 */
    void setPosition(int row, int column);

};


#endif // POSITION_H
