#ifndef VIEW_H
#define VIEW_H
#include <vector>
#include <string>
#include "../model/Pawn.h"
#include "../model/Direction.h"
#include "../model/Position.h"

class View{

public:

    View ();

    /**
     * @brief displayRemainsPawns permet d'afficher les pions restants.
     */
    void displayRemainsPawns();

    /**
     * @brief displayPawnChar permet d'afficher le caractère correspondant au pion.
     * @param pawnChar le charactère donnée.
     */
    void displayPawnChar(char pawnChar);

    /**
     * @brief displayWelcome affiche le message de bienvenue
     */
    void displayWelcome();

    /**
     * @brief displayHeader permet d'afficher la bordure de tableau de jeu.
     */
    void displayHeader();

    /**
     * permet de demandé au jourues si il préfère encoder si pion à travers d'un fichier.
     */
    void askSetUpFiles();

    /**
     * @brief fileFeedBack affiche un petit message pour qui indique le traitement par fichier.
     */
    void fileFeedBack();

    /**
     * @brief interactiveFeedBack affiche un petit message pour qui indique le traitement interactivement
     * selon l'équipe.
     * @param teamName l'équipe donnée.
     */
    void interactiveFeedBack(const std::string & teamName);

    /**
     * @brief displayfileSetUpError affiche un msg indiquant que les données situé dans le fichier ne repecte pas les regles de jeu.
     */
    void displayfileSetUpError();

    /**
     * @brief fileErrorFeedBack affiche un message indiquant qu'il y a un problèm au niveau de la lecture de fichier.
     * @param fileName le nom de fichier.
     */
    void fileErrorFeedBack(const std::string & fileName);

    /**
     * @brief displayErrorPawn affiche un message indiquant qu'un pion n'existe pas parmi les pions restants et suggérées.
     */
    void displayErrorPawn();

    /**
     * @brief askPawnReamaing permet de demandé le pion à mettre dans la position indiqué.
     * @param row la ligne donnée.
     * @param column la colonne donée.
     */
    void askPawnReamaing(int row,char column);

    /**
     * @brief printFormat permet d'afficher un format pour la bordure de plateau de jeu.
     * @param ligne la ligne de plateau de jeu.
     */
    void printFormat(int ligne);

    /**
     * @brief printPawn permet d'afficher le pion dans la console.
     * @param pawn le pion donnée.
     * @param teamTurn le tour de l'équipe courante.
     */
    void printPawn(Pawn & pawn, PawnTeam & teamTurn);

    /**
     * @brief printSymbol permet d'afficher un symbole pour les cases speciales.
     * @param symbol le symbol choisie.
     */
    void printSymbol(const std::string & symbol);

    /**
     * @brief printEmptyLine permet de retourner à la ligne.
     */
    void printEmptyLine();

    /**
     * @brief directionChoice permet de récupérer la direction choisie par le joueur.
     * @return la direction choisie.
     */
    Direction directionChoice();

    /**
     * @brief nbDeplacementSpy permet de demandé le nombre de déplacement pour un espion.
     * @return le nombre de déplacement choisie.
     */
    int nbDeplacementSpy();

    /**
     * @brief checkValidInput permet de vérifier la ligne donnée par joueur.
     * @param input la donnée de joueur.
     * @return true si elle est valide, sinon return false.
     */
    bool checkValidInputRow(std::string input);

    /**
     * @brief checkValidInputColumn permet de vérifier la colonne que est censé rentré
     * le joueur.
     * @param input la colonne attendu
     * @return vrai si la colonne respecte les normes sinon false
     */
    bool checkValidInputColumn(std::string input);


    /**
     * @brief checkDirectionInput vérifier la direction entrée par le joueur.
     * @param dir la direction donnée.
     * @return true si la donnée est valide sinon return false.
     */
    bool checkDirectionInput(std::string dir);

    /**
     * @brief printMsg permet de d'afficher un message.
     * @param msg le message à afficher.
     */
    void printMsg(const std::string & msg);

    /**
     * @brief printTurn permet d'afficher le tour de l'équipe courante.
     * @param turn le tour de l'équipe courante.
     */
    void printTurn(PawnTeam turn);

    /**
     * @brief printNbPawnAlives permet d'afficher le nombre des pions restants.
     * @param nbAlivePawn le nombre de pions restants.
     */
    void printNbPawnAlives(int nbAlivePawn);

    /**
     * @brief showEmptyBoard permet de visionner le board
     * afin de prendre une idée avant le début de jeu.
     */
    void showEmptyBoard();

    /**
     * @brief convertedRow permet de faire la correspondance entre la ligne entrée
     *  et la ligne requise.
     * @param strRow ligne donnée.
     * @return la valeur de la ligne.
     */
    int convertedRow(std::string strRow);

    /**
     * @brief convertedColumn fais la correspondance entre la valeur entrée et la colonne requise.
     * @param strColumn colonne donnée.
     * @return la valeur de la colonne.
     */
    int convertedColumn(std::string strColumn);



};

#endif // VIEW_H
