#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <string>
#include "Game.h"
#include "View.h"
#include <map>
#include "Observable.h"
#include <map>
#include <iostream>
#include <vector>
class Controller : public Observable{

private:
    Game game_;
    View view_;

    std::map<char, int> pawnMap_;
    std::vector<char> bluePawnChars_;
    std::vector<char> redPawnChars_;
    std::pair<int,char> position_;



public:
    /**
     * @brief getPawnMap simple getteur de la map des pions.
     * @return la map des pions.
     */
    inline std::map<char, int>& getPawnMap(){
        return pawnMap_;
    }
    /**
     * @brief addBluePawnChar permet d'ajouter des pions à la liste de l'équipe bleu.
     * @param pawnChar le symbole de pion.
     */
    inline void addBluePawnChar(char pawnChar){
        bluePawnChars_.push_back(pawnChar);
    }

    /**
     * @brief addRedPawnChar permet d'ajouter des pions à la liste de l'équipe red.
     * @param pawnChar le symbol de pion.
     */
    inline void addRedPawnChar(char pawnChar){

        redPawnChars_.push_back(pawnChar);
    }
    /**
     * @brief getBlueSize simple getteur de taille de la liste de l'équipe bleu.
     * @return la taille de la listede l'équipe bleu.
     */
    inline int getBlueSize() const {
        return bluePawnChars_.size();
    }

    /**
     * @brief getRedSize simple getteur de taille de la liste de l'équipe red.
     * @return la taille de la listede l'équipe red.
     */
    inline int getRedSize() const {
        return redPawnChars_.size();
    }


    /**
     * @brief getPosition simple getteur de la position courante.
     * @return la position courante.
     */
    inline std::pair<int, char>& getPosition(){
        return  position_;
    }

    /**
     * @brief getBluePawnChars simple getteur de la liste des symboles des pions de l'équipe blue.
     * @return la liste des symboles des pions de l'équipe blue.
     */
    inline std::vector<char>& getBluePawnChars(){
        return bluePawnChars_;
    }

    /**
     * @brief getRedPawnChars simple getteur de la liste des symboles des pions de l'équipe red.
     * @return la liste des symboles des pions de l'équipe red.
     */
    inline std::vector<char>& getRedPawnChars(){
        return redPawnChars_;
    }

    /**
     * @brief upPosition permet d'augmenter à chaque fois la position de pion à placer.
     */
    void upPosition();

private:
    /**
     * @brief readStrategy permet de lire interactivement les données des deux équipes.
     * @param team l'équipe indiquée
     * @return la liste des pions en charactères.
     */
    std::vector<char> readStrategy(PawnTeam team);
    /**
     * @brief fileReaderTeam permet de lire un fichier.
     * @param fileName le nom de fichier à lire.
     * @return la liste des pions en charactères.
     */
    std::vector<char> fileReaderTeam(const std::string & fileName);

    /**
     * @brief isCorrectFile permet de vérifier si le contenu de fichier respecte les regles de jeux.
     * @param pieces la liste des pions en charactères.
     * @return  true si il respecte, sinon return false.
     */
    bool isCorrectFile(std::vector<char> pieces);
    /**
     * @brief isfileSetUp permet de récuper le choix de joueur
     * si il veut passer les données à travers d'un fichier.
     * @return true si oui sinon return false.
     */
    bool isfileSetUp();
    /**
     * @brief continueAsking permet de checker si on peut encore demandé au joueur de placer ses pions.
     * @param map la map qui contient le type de pion avec le nombre de fois qu'on peut le placer.
     * @return true si on peut lui demander sinon return false.
     */
    bool continueAsking(std::map<char,int>map);

    /**
     * @brief pawnRemains permet de vérifier si on a encore des pions à placer.
     * @param pawnRemains la liste des pions avec le nombre de fois qu'on peut les placer.
     */
    void pawnRemains(const std::map<char,int> & pawnRemains);

    /**
     * @brief setUp permet de mettre enplace tous les pions dans le jeu.
     */
    void setUp();

    /**
     * @brief interactionWithPlayer permet de damandé au joueur
     * la position de pion qui veux le placer en vérifiant que c'est à son tour.
     * @param turn le tour de l'équipe courante.
     * @return la position indiquée par le joueur.
     */
    Position interactionWithPlayer(PawnTeam turn);

    /**
     * @brief showBoard affcihe le plateau du jeu
     * @param teamTurn prends en compte le turn de l'équipe qui doit jouer
     */
    void showBoard(PawnTeam teamTurn);

public:

    /**
     * @brief Controller simple constructeur du Conrtroller
     */
    Controller();

    /**
     * @brief Controller utilisé par la partie graphique après le placement des pions.
     * @param bluePawnChars la liste de pions de l'équipe blue.
     * @param redPawnChars la liste de pions de l'équipe red.
     */
    Controller(std::vector<char> bluePawnChars, std::vector<char> redPawnChars);

    /**
     * @brief startGame permet de démarrer le jeu
     */
    void startGame();

    /**
     * @brief canBeAdded permet de vérifier si un pion peut etre plaçable encore ou pas
     * @param pawnChar le charactère de pion.
     * @param map la liste de pions avec leurs nombres.
     * @return  true si on peut encore le placer, sinon return false.
     */
    bool canBeAdded(char pawnChar,std::map<char,int> map);
    /**
     * @brief getBoard simple getteur de plateau de jeu.
     * @return le plateau de jeu.
     */
    inline std::vector<std::vector<Pawn>> getBoard(){
        return game_.getGameBoard();
    }

    /**
     * @brief canMove permet de vérifier si un pion peut bouger vers une tel direction.
     *
     * @param pos la position de pion.
     * @param direction la direction donnée.
     * @return true si c'est possible sinon return false.
     */
    bool canMove(PawnTeam hisTeam, Position pos,
                         Direction direction, int deplacement);

    /**
     * @brief move permet de faire un déplacement d'une tel position à une autre.
     * @param pos la position courante.
     * @param direction la direction indiquée.
     * @param deplacement le nombre de deplacement.
     */
    void move(Position pos,
                    Direction direction, int deplacement);

    /**
     * @brief canFight permet de verifier si on peut attacker.
     * @param hisTeam l'equipe de pion.
     * @param pos sa position.
     * @param direction la direction choisie.
     * @return true si l'attaque est possible, sinon return false.
     */
    bool canFight(PawnTeam hisTeam, const Position & pos, Direction direction, int deplacement);

    /**
     * @brief fight permet de faire un combat.
     * @param pos la position courante de pion.
     * @param direction la direction indiquee.
     * @param deplacement le nombre de deplacement.
     */
    void fight(Position pos, Direction direction, int deplacement);

    /**
     * @brief getTurn simple getteur de turn.
     * @return l'équipe qui joue au tour courant.
     */
    inline PawnTeam getTurn(){
        return game_.getTeamTurn();
    }

    /**
     * @brief isOver permet de détecter si le jeu est fini ou pas.
     * @return true si le jeu est fini, sinon return false.
     */
    bool gameIsOver();

    /**
     * @brief getWinner permet de recupere l'equipe gagnante de la partie.
     * @return l'equipe gagnante.
     */
    PawnTeam getWinner();

    /**
     * @brief getDirection simple getteur de la valeur de la direction.
     * @param directionStr la direction donnée.
     * @return la valeur de la direction.
     */
    Direction getDirection(char directionChar);

    /**
     * @brief getPawnTeam simple getteur de l'équipe correspondante d'un tel pion.
     * @param pos la position de pion.
     * @return l'équipe correspondante de pion.
     */
    inline PawnTeam getPawnTeam(Position pos){
        return game_.getGameBoard()[pos.getRow()][ pos.getColumn()].getPawnTeam();
    }

    /**
     * @brief newPositionAfterMove la nouvelle position après le déplacement.
     * @param pos la position courante de pion.
     * @param dir la direction inidiquee.
     * @param deplacement la deplacement indiquee.
     * @return la nouvelle position après le deplacement.
     */
    Position newPositionAfterMove(Position pos, Direction dir, int deplacement = 1);

};


#endif // CONTROLLER_H
