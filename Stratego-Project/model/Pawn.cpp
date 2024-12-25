#include "./Pawn.h"
#include "string"
#include <iostream>
using namespace std;

Pawn::Pawn(PawnType pawnType){
    if(pawnType != UNUSED && pawnType != SPECIAL){
        throw invalid_argument("Seules les types unused et special sont autorises");
    }

    pawnType_= pawnType;
    pawnTeam_= NEUTRAL;
    power_= correspondingPower();
    hidden_= false;


}

Pawn::Pawn(PawnType pawnType, PawnTeam pawnTeam){
    if(pawnType == UNUSED || pawnType == SPECIAL){
        throw invalid_argument("les types unused et special ne sont pas autorises");
    }
    pawnType_= pawnType;
    pawnTeam_= pawnTeam;
    power_= correspondingPower();
    hidden_= true;

}


bool Pawn::operator==(Pawn pawn){

    return this->pawnType_ == pawn.pawnType_;
}

PawnTeam Pawn::operator*(Pawn pawn){

    if(pawn.getPawnType()== UNUSED || pawn.getPawnType() == SPECIAL){
        throw invalid_argument("Pas de comparasion avec un pion spécial");
    }

    if(*this == pawn){
        return NEUTRAL;
    }else{
        return comparaison(pawn);

    }

}

PawnTeam Pawn::comparaison(Pawn pawn){
    switch(pawnType_){

    case MINER :
        if(pawn.getPawnType() == BOMB){
            return pawnTeam_;
        }
        break;
    case SPY:
        if(pawn.getPawnType() == MARSHAL){
            return pawnTeam_;
        }
        break;

    default:
        break;
    }
    return power_ > pawn.getPower() ? pawnTeam_ : pawn.getPawnTeam();

}


void Pawn::setPawn(const Pawn &pawn){
    *this = pawn;
}

void Pawn::setHidden(bool isHidden){
    hidden_ = isHidden;
}

string Pawn::toString(){
    switch(this->power_){
    default: return "";
    case -2: return "FLAG";
    case 1: return "SPY";
    case 2: return "SCOUT";
    case 3: return "MINER";
    case 4: return "SERGEANT";
    case 5: return "LIEUTENANT";
    case 6: return "COMMANDANT";
    case 7: return "MAJOR";
    case 8: return "COLONEL";
    case 9: return "GENERAL";
    case 10: return "MARSHAL";
    case 11: return "BOMB";
    }
}

