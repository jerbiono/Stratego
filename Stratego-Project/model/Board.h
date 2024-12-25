#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "Pawn.h"
#include "Position.h"
#include "Direction.h"

/*!
 * \brief c'est la classe qui représente l'échequier de notre jeu stratego.
 */
class Board{

    int redAlivePawn_ ;
    int blueAlivePawn_ ;
    int boardSize_;
    std::vector<std::vector<Pawn>> board_;

public:
    /**
     * @brief Board simple constructeur d'un plateau de jeu vide.
     */
    Board();

    /*!
     * \brief simple constructeur de plateau de jeu.
     *
     * \param pawnsRedTeam la premier liste qui contient les différents positions des pions de l'équipe RED.
     * \param pawnsBlueTeam la deuxième liste qui contient les différents positions des pions de l'équipe BLUE.
     */
    Board(std::vector<Pawn>& pawnsRedTeam, std::vector<Pawn>& pawnsBlueTeam);

    /**
     * @brief Board Simple constructeur de board utilisé pour les tests.
     * @param keyAdmin la clé pour appelé ce constructeur.
     */
    explicit Board(int keyAdmin);

    /**
     * @brief setPawnTest utilisé pour changer les position des pions juste pour les TESTS !!
     * @param position la position indiquée.
     * @param pawn le pion donnée.
     * @param keyAdmin la clé pour appelé cette méthode.
     */
    void setPawnTest(Position position, Pawn pawn, int keyAdmin);

    /*!
     * \brief fill permet de remplir le board en fonction de la liste de chaque équipe.
     *
     * \param pawnsRedTeam liste des pions de l'équipe RED.
     * \param pawnsBlueTeam liste des pions de l'équipe BLUE.
     */
    void fill(std::vector<Pawn>&pawnsRedTeam, std::vector<Pawn>& pawnsBlueTeam);

    /**
     * @brief isInside permet de vérifier si une position donnée est n'est pas dehors le plateau de jeu.
     *
     * @param pos la position donnée.
     * @return true si c'est vrai sinon return false.
     */
    bool isInside(Position pos) ;


    /*!
     * \brief getBoard simple getteur de plateau de jeu.
     *
     * \return le plateau de jeu.
     */
    inline std::vector<std::vector<Pawn>> &getBoard(){
        return board_;
    };

    /*!
     * \brief getRedAlivePawn simple getteur des pions vivants de l'équipe red
     *
     * \return le nombre de pions restants de l'équipe red.
     */
    inline int& getRedAlivePawn() {

        return redAlivePawn_;
    }

    /*!
     * \brief getBlueAlivePawn simple getteur des pions vivants de l'équipe blue.
     *
     * \return le nombre de pions restants de l'équipe blue.
     */
    inline int& getBlueAlivePawn() {

        return blueAlivePawn_;
    }


    /**
     * @brief getPawn simple getteur de pawn.
     *
     * @param pos la position donnée.
     * @return le pawn situé à la position donnée.
     */
    inline Pawn & getPawn(Position pos) {

        return board_[pos.getRow()][pos.getColumn()];
    }

    /**
     * @brief canMove permet de vérifier si un pion peut bouger vers une tel direction.
     *
     * @param pos la position de pion.
     * @param direction la direction donnée.
     * @return true si c'est possible sinon return false.
     */
    bool canMove( PawnTeam hisTeam, Position pos,
                  Direction direction, int deplacement =1) ;

    /**
     * @brief move permet de modifier un pion selon son type et le nombre de deplacement en respectant les regles de jeu.
     * @param hisTeam l'equipe de joueur peut etre RED ou BLUE.
     * @param pos la position de pion.
     * @param direction la direction indiquee.
     * @param deplacement le nombre de deplacement indiquee.
     */
    void move(Position pos,
              Direction direction, int deplacement =1);

    /**
     * @brief canFight permet de verifier si on peut attacker.
     * @param hisTeam l'equipe de pion.
     * @param pos sa position.
     * @param direction la direction choisie.
     * @return true si l'attaque est possible, sinon return false.
     */
    bool canFight (PawnTeam hisTeam, Position pos,
                   Direction direction, int deplacement) ;
    /**
     * @brief fight permet de faire le combat.
     * @param pos la position de pion.
     * @param direction la direction indiquee
     * @param deplacement le nombre de deplacement.
     */
    void fight(Position pos,Direction direction, int deplacement);

    /**
     * @brief newPositionAfterMove la nouvelle position après le déplacement.
     * @param pos la position courante de pion.
     * @param dir la direction inidiquee.
     * @param deplacement la deplacement indiquee.
     * @return la nouvelle position après le deplacement.
     */
    Position newPositionAfterMove(Position pos, Direction dir, int deplacement = 1);

    /**
     *
     * @brief isBlocked permet de voir si un pion est bloqué c'est à dire aucun déplecement possible
     * @param pos
     * @return
     */
    bool isBlocked(Position pos,PawnTeam turn);

    /**
     * @brief getBoardSize permet de retourner la taille de tableau de jeu.
     * @return
     */
    inline int getBoardSize() const{

        return boardSize_;
    }

    /**
     * @brief isMovebalePawnpermet de vérifier si un pion est capable de bouger(ni bomb ni drapeau).
     * @param board le plateau de jeu.
     * @param pos la position de pion.
     * @param pawnTeam l'equipe de pion.
     * @return true si on peut le bouger sinon return false.
     */
    bool isMovebalePawn(std::vector<std::vector<Pawn>> & board, Position pos, PawnTeam pawnTeam);

    /**
     * @brief killPawn permet de diminuer les nombres des pions vivants d'un tel joueur.
     * @param Position la position de pion.
     * @param alivePawn l'equipe de pion.
     */
    void killPawn(Position pawnPosition, PawnTeam pawnTeam);
private:


    /**
     * @brief getDirectionValue permet de récupérer la valeur liée à la direction.
     * @param direction la direction fournie.
     * @return la valeur liée à la direction.
     */
    int getDirectionValue(Direction direction);

    /**
     * @brief switchVisibilityStatus permet de changer la visibility de pion.
     * @param pawn le pion pour lequel on va changer le status.
     */
    void toggleVisibilityStatus(Pawn & pawn);

    /**
    * @brief possibleOneMove permet de verifier si on peut bouger une fois.
    * @param pos la position de pion.
    * @param direction la direction indiquee
    * @param deplacement le nombre de deplacement indiquee et par default c'est UN SEUL!
    * @return true si le mouvement est possible, sinon return false.
    */
    bool possibleOneMove(Position pos, Direction direction, int deplacement = 1) ;

    /**
    * @brief possibleMultipleMove permet de verifier si on peut bouger plusieurs fois.
    * @param pos la position de pion.
    * @param direction la direction indiquee.
    * @param deplacement le nombre de depalement indiquee.
    * @return true si le mouvement est possible, sinon return false.
    */

    bool possibleMultipleMove(Position pos, Direction direction, int deplacement);
    /**
    * @brief changePawnSpecifities permet de changer les specificities
    * @param firstPosition la première position de premier pion.
    * @param secondPosition la deuxième position de deuxieme pion.
    */
    void changePawnSpecifities(Position firstPosition, Position secondPosition);

    /**
     * @brief checkIsPositionOccuped vérifie si la position après le déplacement est libre ou non.
     * @param pos la position courante.
     * @param direction la direction indiquée.
     * @param deplacement le nombre de deplacement.
     * return true si elle est occupé sinon return false si elle est libre.
     *
     */
    bool checkIsPositionOccuped(Position pos,Direction direction,int deplacement = 1);

    /**
         * @brief canSpyAttack vérifie si l'espion peut attacker d'après le déplecement et la direction donnée
         * @param deplacement le nombre de deplacement indiquee
         * @return true  si il peut attacker sinon retrun false
         */
    bool canSpyAttack(PawnTeam team,Position pos, Direction dir,int deplacement);




};

#endif // BOARD_H
