#ifndef PAWN_H
#define PAWN_H
#include "PawnType.h"
#include "PawnTeam.h"
#include <ostream>

/**
 * @brief cette classe représente le pion utilisé dans le jeu.
 *
 */
class Pawn{

    PawnType pawnType_;
    PawnTeam pawnTeam_;
    int power_;
    bool hidden_;
public:
    /**
     * @brief simple structeur des pions inutilisé ou des pions spécifiques.
     * @param pawnType le type de pion qui peut etre unused ou spécial.
     *
     */
    explicit Pawn(PawnType pawnType);

    /**
     * @brief simpple constructeur d'un pion.
     * @param pawnType le type de pion.
     * @param pawnTeam son équipe.
     */
    Pawn (PawnType pawnType, PawnTeam pawnTeam);

    /**
     * @brief getPawnTeam simple getteur de l'équipe lié au pion.
     * @return son équipe.
     */
    inline PawnTeam getPawnTeam() {

        return pawnTeam_;

    }

    /**
     * @brief getPawnType simple getteur de type de pion.
     * @return le type de pion correspondant.
     */
    inline PawnType getPawnType() {

        return pawnType_;

    }


    /**
     * @brief getPower simple getteur de force pion.
     * @return sa force.
     */
    inline int& getPower() {

        return power_;
    }

    /**
     * @brief isHidden permet de vérifier si le pion est visible ou non.
     * @return true si il est caché sinon return false.
     */
    inline bool & isHidden() {
        return hidden_;

    }

    /**
     * @brief revealedPawn permet de reveler un pion.
     */
    inline void togglePawnVisibility(){
        if(hidden_)
            hidden_ = false;
        else
            hidden_ = true;
    }


    /**
     * @brief setPawnType permet de changer les caractéristiques de pion.
     * @param pawn le pion donnee.
     */
    void setPawn(const Pawn &pawn);

    /**
     * @brief operator * ca permet de comparer le pion de premier joueur
     *  avec le pion de deuxieme joueur selon leurs forces.
     * @param pawn le pion de deuxième joueur.
     * @return l'équipe qui a le pion le plus fort, en cas d'égalité return neutral
     */
    PawnTeam operator*(Pawn pawn);

    /**
     * @brief operator == ca permet de comparer si les deux pion ils sont de meme type.
     * @param pawn le pion adverse.
     * @return true si ils ont le meme type sinon return false.
     */
    bool operator==(Pawn pawn);

    /**
     * @brief setIsHidden permet de changer la visibilty de pion.
     * @param visibilty true si le pion est cache sinon true pour le reveler.
     */
    void setHidden(bool visibilty);

    /**
     * @brief toString permet d'afficher le type de pion.
     * @return le type de pion.
     */
    std::string toString();
private:
    /**
     * @brief comparaison permet de comparer les pions selon leurs forces et leurs specificite.
     * @param pawn le pion donnee
     * @return l'equipe de pion.
     */
    PawnTeam comparaison(Pawn pawn);

    /**
     * @brief correspondingPower permet de recuperer la force de chaque pion selon son type.
     * @return la force de pion.
     */
    inline int correspondingPower () {
        switch(pawnType_){
        case MARSHAL: return 10;
        case UNUSED: return 0;
        case FLAG: return -2;
        case BOMB: return 11;
        case SPECIAL: return -1;

        default: return pawnType_;
        }
    }

};

/**
 * @brief operator << ca permet d'de rédirgier sur la sortie standrad le type de pion.
 * @param pawn le pion à affichier.
 * @return le nouveau affichage lié à ce pion.
 */
inline std::ostream & operator<<(std::ostream & out, Pawn & pawn){
    if(pawn.getPawnType() == BOMB
            || pawn.getPawnType() == UNUSED
            || pawn.getPawnType() == FLAG
            || pawn.getPawnType() == SPECIAL){
        return out << static_cast<char>(pawn.getPawnType());
    }
    if(pawn.getPawnType() == MARSHAL){
        return out << 10;
    }
    return out << pawn.getPawnType();
}


#endif // PAWN_H
