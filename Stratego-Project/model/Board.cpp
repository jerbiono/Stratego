#include "Board.h"
using namespace std;
Board::Board(vector<Pawn>& pawnsRedTeam, vector<Pawn>& pawnsBlueTeam): boardSize_{10}{
    if(pawnsRedTeam.size() != 40 || pawnsBlueTeam.size() != 40){
        throw invalid_argument("le nombre des pions totale doit etre egale a 40 pions par joueur!");
    }
    
    blueAlivePawn_ = 40;
    redAlivePawn_ = 40;
    fill(pawnsRedTeam,pawnsBlueTeam);
    
    
}

Board::Board(){

}

void Board::fill(vector<Pawn>& pawnsRedTeam,vector<Pawn>& pawnsBlueTeam){
    
    vector<Pawn> inColumnPawns;
    Pawn specialPawn{SPECIAL};
    Pawn unusedPawn{UNUSED};
    
    for(int i{0}; i< boardSize_; ++i ){
        for(int j{0}; j < boardSize_; ++j){
            
            if(i == 4 || i == 5){
                if(j == 2 || j==3 || j ==6 || j==7){
                    inColumnPawns.push_back(specialPawn);
                }else{
                    inColumnPawns.push_back(unusedPawn);
                }
            }else{
                if(i<4){
                    inColumnPawns.push_back(pawnsRedTeam.front()) ;
                    pawnsRedTeam.erase(pawnsRedTeam.begin());
                }
                if( i> 5){
                    inColumnPawns.push_back(pawnsBlueTeam.front());
                    pawnsBlueTeam.erase(pawnsBlueTeam.begin());
                }
            }
            
        }
        board_.push_back(inColumnPawns);
        inColumnPawns.clear();
        
    }
    
}


Board::Board(int keyAdmin):redAlivePawn_{40}, blueAlivePawn_{40}, boardSize_{10}{
    if(keyAdmin == 54685 || keyAdmin == 56387){
        vector<Pawn> columnPositions1{
            Pawn{MARSHAL,BLUE}, Pawn{GENERAL,BLUE}, Pawn{FLAG,BLUE}, Pawn{COMMANDANT,BLUE}, Pawn{COMMANDANT,BLUE},
            Pawn{MAJOR,BLUE}, Pawn{MAJOR,BLUE}, Pawn{MAJOR,BLUE}, Pawn{COLONEL,BLUE}, Pawn{COLONEL,BLUE}};
        board_.push_back(columnPositions1);
        columnPositions1.clear();

        vector<Pawn> columnPositions2 = {Pawn{SPY,BLUE}, Pawn{LIEUTENANT,BLUE}, Pawn{SERGEANT,BLUE}, Pawn{SERGEANT,BLUE}, Pawn{COMMANDANT,BLUE},
                                         Pawn{COMMANDANT,BLUE}, Pawn{SERGEANT,BLUE}, Pawn{SERGEANT,BLUE}, Pawn{LIEUTENANT,BLUE}, Pawn{LIEUTENANT,BLUE}};
        board_.push_back(columnPositions2);
        columnPositions2.clear();

        vector<Pawn> columnPositions3 = {{SCOUT,BLUE}, Pawn{SCOUT,BLUE}, Pawn{SCOUT,BLUE}, Pawn{MINER,BLUE}, Pawn{MINER,BLUE},
                                         Pawn{MINER,BLUE}, Pawn{MINER,BLUE}, Pawn{SCOUT,BLUE}, Pawn{SCOUT,BLUE}, Pawn{SCOUT,BLUE}};
        board_.push_back(columnPositions3);
        columnPositions3.clear();

        vector<Pawn> columnPositions4 = {Pawn{BOMB,BLUE}, Pawn{BOMB,BLUE}, Pawn{BOMB,BLUE}, Pawn{SCOUT,BLUE}, Pawn{MINER,BLUE},
                                         Pawn{SCOUT,BLUE}/* devient LIEUTENANT **/, Pawn{SCOUT,BLUE}, Pawn{BOMB,BLUE}, Pawn{BOMB,BLUE}, Pawn{BOMB,BLUE}};
        board_.push_back(columnPositions4);
        columnPositions4.clear();

        vector<Pawn> columnPositions5 = {Pawn{UNUSED}, Pawn{UNUSED}, Pawn{SPECIAL}, Pawn{SPECIAL}, Pawn{UNUSED},
                                         Pawn{UNUSED}, Pawn{SPECIAL}, Pawn{SPECIAL}, Pawn{UNUSED}, Pawn{UNUSED}};
        board_.push_back(columnPositions5);
        columnPositions5.clear();

        vector<Pawn> columnPositions6 = {Pawn{UNUSED}, Pawn{UNUSED}, Pawn{SPECIAL}, Pawn{SPECIAL}, Pawn{UNUSED},
                                         Pawn{UNUSED}, Pawn{SPECIAL}, Pawn{SPECIAL}, Pawn{UNUSED}, Pawn{UNUSED}};
        board_.push_back(columnPositions6);
        columnPositions6.clear();

        vector<Pawn> columnPositions7 = {Pawn{BOMB,RED}, Pawn{BOMB,RED}, Pawn{BOMB,RED}, Pawn{SCOUT,RED}, Pawn{MINER,RED},
                                         Pawn{LIEUTENANT,RED}, Pawn{SCOUT,RED}, Pawn{BOMB,RED}, Pawn{BOMB,RED}, Pawn{BOMB,RED}};
        board_.push_back(columnPositions7);
        columnPositions7.clear();

        vector<Pawn> columnPositions8 = {Pawn{SCOUT,RED}, Pawn{SCOUT,RED}, Pawn{SCOUT,RED}, Pawn{MINER,RED}, Pawn{MINER,RED},
                                         Pawn{MINER,RED}, Pawn{MINER,RED}, Pawn{SCOUT,RED}, Pawn{SCOUT,RED}, Pawn{SCOUT,RED}};
        board_.push_back(columnPositions8);
        columnPositions8.clear();

        vector<Pawn> columnPositions9 = {Pawn{SPY,RED}, Pawn{LIEUTENANT,RED}, Pawn{SERGEANT,RED}, Pawn{SERGEANT,RED}, Pawn{COMMANDANT,RED},
                                         Pawn{COMMANDANT,RED}, Pawn{SERGEANT,RED}, Pawn{SERGEANT,RED}, Pawn{LIEUTENANT,RED}, Pawn{LIEUTENANT,RED}};
        board_.push_back(columnPositions9);
        columnPositions9.clear();

        vector<Pawn> columnPositions10 = {Pawn{MARSHAL,RED}, Pawn{GENERAL,RED}, Pawn{FLAG,RED}, Pawn{COMMANDANT,RED}, Pawn{COMMANDANT,RED},
                                          Pawn{MAJOR,RED}, Pawn{MAJOR,RED}, Pawn{MAJOR,RED}, Pawn{COLONEL,RED}, Pawn{COLONEL,RED}};
        board_.push_back(columnPositions10);
        columnPositions10.clear();
    }else{
        throw std::invalid_argument("arrete de tricher !!, cette création de board est juste pour les tests !!!");
    }

}

void Board::killPawn(Position pawnPosition, PawnTeam pawnTeam){

    switch (pawnTeam){
    case BLUE: blueAlivePawn_--;
        break;
    case RED : redAlivePawn_--;
        break;
    default  : throw invalid_argument("les pions neutres ne peuvent pas etre tuee");
        break;
    }
    Pawn pawnUnsed{UNUSED};
    board_[pawnPosition.getRow()][pawnPosition.getColumn()].setPawn(pawnUnsed);

}


bool Board::isMovebalePawn(vector<vector<Pawn>> & board, Position pos, PawnTeam pawnTeam){

    if (getPawn(pos).getPawnType() == BOMB){
        return false;
    }
    if(getPawn(pos).getPawnType() == FLAG){
        return false;
    }
    return board[pos.getRow()][pos.getColumn()].getPawnTeam() == pawnTeam;
}


bool Board::isInside(Position pos) {
    
    return  (pos.getColumn()>=0
             && pos.getRow() < boardSize_
             && pos.getRow() >= 0
             && pos.getRow() < boardSize_);
    
}


int Board::getDirectionValue(Direction direction) {
    switch(direction){
    case NORTH:
    case WEST:
        return -1;
    default : return 1;
        
    }
}

bool Board::possibleOneMove(Position pos, Direction direction , int deplacement) {
    const int dirValue{getDirectionValue(direction)};
    switch(direction){
    case  NORTH :
    case SOUTH  :
        return isInside({pos.getRow() + (dirValue * deplacement) ,
                         pos.getColumn()}) ? getPawn({pos.getRow() +
                         (dirValue * deplacement),pos.getColumn()}).getPawnType() == UNUSED : false;
        
    default  :
        return isInside({pos.getRow(),pos.getColumn() + (dirValue * deplacement)})?
                    getPawn({pos.getRow(),pos.getColumn() +
                             (dirValue * deplacement)}).getPawnType() == UNUSED : false;
        
    }
}

bool Board::possibleMultipleMove(Position pos, Direction direction, int deplacement) {
    
    if(!possibleOneMove(pos, direction, deplacement)){
        return false;
    }
    int idx{1};
    while(idx < deplacement){
        if(!possibleOneMove(pos, direction, idx)){
            return false;
        }
        idx++;
    }
    return true;
}


Position Board::newPositionAfterMove(Position pos, Direction direction, int deplacement){
    int dirValue = getDirectionValue(direction)*deplacement;
    if(direction == NORTH || direction == SOUTH){
        return {(pos.getRow()+dirValue),pos.getColumn()};

    }else{
        return {pos.getRow(),(pos.getColumn()+dirValue)};

    }
}

void Board::changePawnSpecifities(Position firstPosition, Position secondPosition){

    Pawn firstPawn {getPawn(firstPosition)};
    Pawn secondPawn {getPawn(secondPosition)};
    Pawn pawnTmp = firstPawn;
    board_[firstPosition.getRow()][firstPosition.getColumn()].setPawn(secondPawn);
    board_[secondPosition.getRow()][secondPosition.getColumn()].setPawn(pawnTmp);

}

bool Board::canSpyAttack(PawnTeam team,Position pos, Direction dir,int deplacement){

    if(!isInside(newPositionAfterMove(pos,dir,deplacement))){
        return false;
    }
    int idx{1};
    while(idx < deplacement){
        if(!possibleOneMove(pos, dir, idx)){
            return false;
        }
        idx++;
    }
    Position posAffronted = newPositionAfterMove(pos,dir,deplacement);
    return getPawn(posAffronted).getPawnTeam() != NEUTRAL
            && getPawn(posAffronted).getPawnTeam() != team;
}



void Board::setPawnTest(Position pawnPosition, Pawn pawn, int keyAdmin){
    if(keyAdmin == 54685 || keyAdmin == 56387){
        board_[pawnPosition.getRow()][pawnPosition.getColumn()].setPawn(pawn);
    }else{
        throw std::invalid_argument("arrete de tricher !!, cette methode est juste pour les tests !!!");
    }
}


void Board::toggleVisibilityStatus(Pawn & pawn) {
    pawn.togglePawnVisibility();
}


bool Board::canFight(PawnTeam hisTeam, Position  pos,
                     Direction direction,int  deplacement){

    Position position = newPositionAfterMove(pos,direction,deplacement);

    if(!isInside(position)){
        return false;
    }
    if(board_[pos.getRow()][pos.getColumn()].getPawnType() == FLAG || board_[pos.getRow()][pos.getColumn()].getPawnType()== BOMB){
        return false;
    }
    Pawn & affrontedPawn = board_[position.getRow()][position.getColumn()];
    if(affrontedPawn.getPawnTeam() == hisTeam || affrontedPawn.getPawnType() == UNUSED
            || affrontedPawn.getPawnType() == SPECIAL ){
        return false;
    }
    if(getPawn(pos).getPawnType() == SPY ){

        if( canSpyAttack(hisTeam,pos,direction,deplacement)){

            toggleVisibilityStatus(affrontedPawn);
            return true;

        }else{
            return false;
        }
    }

    toggleVisibilityStatus(affrontedPawn);
    return true;


}

void Board::fight(Position pos, Direction direction, int deplacement){

    Pawn & fighterPawn = board_[pos.getRow()][pos.getColumn()];
    Position posFight = newPositionAfterMove(pos,direction,deplacement);
    Pawn affrontedPawn = board_[posFight.getRow()][posFight.getColumn()];
    PawnTeam fighterTeam{fighterPawn.getPawnTeam()};
    PawnTeam affrontedTeam {affrontedPawn.getPawnTeam()};
    if(fighterPawn * affrontedPawn == NEUTRAL){
        killPawn(pos, affrontedTeam);
        killPawn(posFight, fighterTeam);

    }else if (fighterPawn * affrontedPawn == fighterPawn.getPawnTeam()){

        changePawnSpecifities(pos,posFight);
        killPawn(pos, affrontedTeam);

    }else{

        killPawn(pos, fighterTeam);
        toggleVisibilityStatus(affrontedPawn);

    }

}
bool Board::canMove( PawnTeam hisTeam, Position pos,
                     Direction  direction,
                     int deplacement) {

    if(getPawn(pos).getPawnTeam() !=  hisTeam ){
        throw std::invalid_argument("Le pion a la position donnee ne correpond pas a son equipe");
    }
    if(getPawn(pos).getPawnType() == BOMB ||
            getPawn(pos).getPawnType() == FLAG ||
            getPawn(pos).getPawnTeam() == NEUTRAL){
        return false;
    }

    if(getPawn(pos).getPawnType() != SPY ){
        if(deplacement !=1){
            return false;
        }
        return possibleOneMove(pos, direction);
    }else{
        return possibleMultipleMove(pos, direction, deplacement);
    }

}

void Board::move(Position pos,
                 Direction  direction, int deplacement){
    Position newPos {newPositionAfterMove(pos, direction, deplacement)};
    changePawnSpecifities(pos, newPos);

}

bool Board::isBlocked(Position pos, PawnTeam turn){
    if(!isInside(pos)){
        throw std::invalid_argument("Position hors du tableau");
    }
    Pawn pawn = getPawn(pos);
    PawnType pawType = pawn.getPawnType();
    if(pawType == UNUSED || pawType == SPECIAL){
        throw std::invalid_argument("Ces pions ne peuvent pas etre bloque vu qu il se deplace pas");

    }

    if(pawn.getPawnTeam() != turn){
        return false;

    }


    return checkIsPositionOccuped(pos,NORTH) &&  checkIsPositionOccuped(pos,EAST)
            &&  checkIsPositionOccuped(pos,SOUTH) && checkIsPositionOccuped(pos,WEST);

}

bool Board::checkIsPositionOccuped(Position pos,Direction dir,int deplacement){

    Position posToCheck = newPositionAfterMove(pos,dir,deplacement);
    if(isInside(posToCheck)){
        if(getPawn(posToCheck).getPawnType() == UNUSED){
            return false;
        }

    }

    return true;
}


