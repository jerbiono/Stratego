#ifndef GAME_H
#define GAME_H

#include <Board.h>
/**
 * @brief represente la façade, elle contient les méthodes essentielles pour le déroulement du jeu.
 */

class Game{
    Board board_;
    PawnTeam teamTurn_;
    PawnTeam winner_;

public:

    /**
     * @brief Game Simple constructeur de Game.
     */
    Game();

    /**
     * @brief Game simple constructeur de Game.
     * @param teamBluePawn la liste des pions de l'equipe blue.
     * @param teamRedPawn la liste des pions de l'equipe red.
     */
    Game(std::vector<char>& teamBluePawn, std::vector<char>& teamRedPawn);

    /**
     * @brief getWinner Simple getter of winner.
     * @return l'equipe gagnante de la partie.
     */
    inline PawnTeam getWinner(){
        return winner_;
    }

    /**
     * @brief isOver permet de détecter si le jeu est fini ou pas.
     * @param turn le tour de l'équipe qui joue.
     * @return true si le jeu est fini, sinon return false.
     */
    bool isOver(PawnTeam turn);

    /**
     * @brief getGameBoard simple getteur de la liste de tous les pions.
     * @return la liste de tous les pions utilisés.
     */
    std::vector<std::vector<Pawn>>&  getGameBoard();

    /**
     * @brief getBoard simple getteur de plateau de jeu.
     * @return le plateau de jeu.
     */
    Board & getBoard();

    /**
     * @brief canMove permet de vérifier si un pion peut bouger vers une tel direction.
     *
     * @param pos la position de pion.
     * @param direction la direction donnée.
     * @return true si c'est possible sinon return false.
     */
    bool canMove( PawnTeam hisTeam, Position pos,
                  Direction direction, int deplacement =1);
    /**
     * @brief move permet de faire un déplacement d'une tel position à une autre.
     * @param pos la position courante.
     * @param direction la direction indiquée.
     * @param deplacement le nombre de deplacement.
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
    bool canFight (PawnTeam hisTeam, const Position & pos,
                   Direction direction, int deplacement);

    /**
     * @brief fight permet de faire un combat.
     * @param pos la position courante de pion.
     * @param direction la direction indiquee.
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
     * @brief getAlivePawn simple getteur des pions vivants.
     * @param pawnTeam l'équipe correspondante pions.
     * @return le nombre des pions restan de l'équipe.
     */
    inline int getAlivePawn(PawnTeam pawnTeam){
        if(pawnTeam == RED){
            return board_.getRedAlivePawn();
        }
        if(pawnTeam == BLUE){
            return board_.getBlueAlivePawn();

        }
        return -1;
    }


    /**
    * @brief getTeamTurn simple getteur de l'equipe qui entrain de jouer.
    * @return le tour de l'équipe qui est entrain de jouer.
    */
    inline PawnTeam &getTeamTurn(){
        return teamTurn_;
    }



private:
    /**
    * @brief correspondingPawn permet de créer les pions selon les choix
    * adapté par l'utilisateur avec des charactères.
    * @param pawnChar le symbol de pion en charactère.
    * @param team
    * @return
    */
    Pawn correspondingPawn(char pawnChar, PawnTeam team);

    /**
    * @brief toggleWinner permet de passé au turn précident afin de connaitre le vainqueur.
    * @param turn le turn de vainqueur.
    */
    inline void toggleWinner(PawnTeam turn){
        if(turn == BLUE){
            winner_ = RED;
        }else{
            if(turn == RED){
                winner_ = BLUE;
            }
        }

    }

    /**
    * @brief changeTurn permet de changer le tour des équipes.
    */
    inline void changeTurn(){
        if(teamTurn_ == RED){
            teamTurn_ = BLUE;
        }else{
            if(teamTurn_ == BLUE){
                teamTurn_ = RED;
            }
        }

    }

    /**
    * @brief convertCharsToPawns permet de convertir la listes de chars donnée en liste de pion.
    * @param charPawns liste de char qui reprénte des pawn.
    * @param team l'equipe correspondante.
    * @return vector de pawn la liste des pions convertie.
    */
    std::vector<Pawn> convertCharsToPawns(std::vector<char>&charPawns, PawnTeam team);

};
#endif // GAME_H

