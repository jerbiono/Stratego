#include "Game.h"
using namespace std;


Game::Game(){
}

Pawn Game::correspondingPawn(char pawnChar, PawnTeam team){

    switch(pawnChar){
    case '1': return Pawn(SPY, team);
    case '2': return Pawn(SCOUT, team);
    case '3': return Pawn(MINER, team);
    case '4': return Pawn(SERGEANT, team);
    case '5': return Pawn(LIEUTENANT, team);
    case '6': return Pawn(COMMANDANT, team);
    case '7': return Pawn(MAJOR, team);
    case '8': return Pawn(COLONEL, team);
    case '9': return Pawn(GENERAL, team);
    case 'M': return Pawn(MARSHAL, team);
    case 'D': return Pawn(FLAG, team);
    case 'B': return Pawn(BOMB, team);
    default:
        throw invalid_argument("une equipe ne doit pas avoir un autre type de pion !");

    }
}

vector<Pawn> Game::convertCharsToPawns(vector<char>&charPawns, PawnTeam team){
    vector<Pawn> teamPawns;
    for(unsigned i{0}; i< charPawns.size(); ++i){
        teamPawns.push_back(correspondingPawn(charPawns.at(i), team));
    }
    return teamPawns;

}

Game::Game(vector<char>& teamBlueChars, vector<char>& teamRedChars){
    vector<Pawn> blueTeamPawns = convertCharsToPawns(teamBlueChars,BLUE);
    vector<Pawn> redTeamPawns = convertCharsToPawns(teamRedChars,RED);
    board_ = Board (blueTeamPawns,redTeamPawns);
    teamTurn_ = BLUE;
    winner_ = NEUTRAL;


}

bool Game::isOver(PawnTeam turn){
    bool notBlocked{true};
    bool notExistFlag{true};
    for(auto i{0}; i <board_.getBoardSize();i++ ){

        for(auto j{0}; j < board_.getBoardSize();j++){

            if(board_.getPawn({i,j}).getPawnTeam() == turn && !board_.isBlocked({i,j},turn)){
                notBlocked = false;
            }
            if(board_.getPawn({i,j}).getPawnTeam() == turn && board_.getPawn({i,j}).getPawnType() == FLAG){
                notExistFlag = false;
            }
        }
    }
    if(notExistFlag){
       toggleWinner(turn);
        return true;
    }
    if(notBlocked){
        toggleWinner(turn);
    }
    return notBlocked;
}

Board & Game::getBoard(){

    return board_;
}

bool Game::canMove(PawnTeam hisTeam, Position pos,
                   Direction direction, int deplacement){

    return board_.canMove(hisTeam,pos, direction, deplacement);
}

void Game::move(Position pos,
                Direction direction, int deplacement){


    board_.move(pos,direction,deplacement);
    changeTurn();

}

bool Game::canFight(PawnTeam hisTeam, const Position & pos, Direction direction, int deplacement){


    return board_.canFight(hisTeam,pos,direction,deplacement);

}

void Game::fight(Position pos, Direction direction, int deplacement){

    board_.fight(pos,direction,deplacement);
    changeTurn();

}

Position Game::newPositionAfterMove(Position pos, Direction dir, int deplacement)
{
    return board_.newPositionAfterMove(pos, dir, deplacement);
}


vector<vector<Pawn>>& Game::getGameBoard(){
    return board_.getBoard();
}

