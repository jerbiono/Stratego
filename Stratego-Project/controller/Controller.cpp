#include <iostream>
#include <vector>
#include <Pawn.h>
#include <fstream>
#include <map>
#include "Controller.h"
#include <iomanip>
using namespace std;
const unsigned assciConvert{48};


Controller::Controller():game_{Game()},view_{View()}, pawnMap_{}, bluePawnChars_{},
    redPawnChars_{}, position_{1,'A'}{}

Controller::Controller(vector<char> bluePawnChars, vector<char> redPawnChars):
    game_(bluePawnChars,redPawnChars){}


void Controller::startGame(){
    view_.displayWelcome();
    setUp();
    bool canMove{false};
    bool canFight{false};
    PawnTeam turn;
    Position currentPos{0,0};
    Direction direction;
    int deplacement{1};
    while(!game_.isOver(BLUE) && !game_.isOver(RED)){

        do{

            deplacement = 1 ;
            turn = game_.getTeamTurn();
            showBoard(turn);
            currentPos = interactionWithPlayer(turn);
            direction = view_.directionChoice();

            if(game_.getBoard().getPawn(currentPos).getPawnType() == SPY) {
                deplacement = view_.nbDeplacementSpy();
            }

            canMove = game_.canMove(turn,currentPos,direction,deplacement);
            canFight = game_.canFight(turn,currentPos,direction,deplacement);
            if(!canMove && !canFight ){
                view_.printMsg("vous ne pouvez faire ce genre de deplacement !\n");
            }
        }while(!canFight && !canMove);

        showBoard(turn);

        if(canFight){
            game_.fight(currentPos,direction,deplacement);
            view_.printNbPawnAlives(game_.getAlivePawn(turn));
        }
        if(canMove){
            game_.move(currentPos, direction, deplacement);
            view_.printMsg("le deplacement est effectuee avec succes\n");
        }

        if(game_.getWinner() == NEUTRAL){
            system("CLS");
            cout << flush;
            view_.printMsg("Changement de tour !\n\n");

        }
    }
    showBoard(game_.getWinner());

    view_.printMsg("La partie est finie !\n");
    view_.printMsg("le gagnant de cette partie c'est l'equipe " + to_string(game_.getWinner())+ " !\n");
}


void Controller::setUp(){
    vector<char>blueChars;
    vector<char>redChars;

    if(isfileSetUp()){

        view_.fileFeedBack();

        if(isCorrectFile(fileReaderTeam("blue.txt")) && isCorrectFile(fileReaderTeam("red.txt")) ){
            blueChars = fileReaderTeam("blue.txt");
            redChars = fileReaderTeam("red.txt");
        }


    }else{
        view_.interactiveFeedBack("blue");
        blueChars = readStrategy(BLUE);
        view_.interactiveFeedBack("red");

        redChars= readStrategy(RED);
    }
    game_ = {Game(blueChars,redChars)};

}

Position Controller::interactionWithPlayer(PawnTeam turn){
    string columnStr{};
    string rowStr{};
    int row{};
    int column{};
    bool valid{false};
    view_.printTurn(turn);
    view_.printEmptyLine();
    do{

        if(valid){
            view_.printMsg("Veuillez entrez une position de votre equipe qui correspond a un pion bougeable "
                           "(pas de BOMB ni de DRAPEAU) \n");
        }

        view_.printEmptyLine();
        view_.printMsg("Ligne : ");
        cin >> rowStr;
        view_.printEmptyLine();
        view_.printMsg("Colonne : ");
        cin >> columnStr;
        if(view_.checkValidInputRow(rowStr) && view_.checkValidInputColumn(columnStr)){
            valid = true;
            row = view_.convertedRow(rowStr);
            column = view_.convertedColumn(columnStr);
        }

        if(!valid){
            view_.printMsg("Les valeurs de la ligne doivent etre entre 1 et 10 \n");
            view_.printMsg("Les valeurs de la colonne doivent etre entre A et J \n");

        }

    }while( !valid || !game_.getBoard().isMovebalePawn(game_.getGameBoard(),{row,column},turn) );

    return {row,column};
}

bool Controller::isCorrectFile(std::vector<char> pieces){
    std::map<char, int> map{};
    const int asciiConversion{assciConvert};

    if(pieces.size() != 40){
        view_.displayfileSetUpError();
        return false;

    }

    for(auto e : pieces){
        if(e-asciiConversion >= 10
                && e != 'B' && e != 'D' && e != 'M'){
            view_.displayfileSetUpError();
            return false;
        }

        if(canBeAdded(e,map)){

            map[e]++;
        }else{
            view_.displayfileSetUpError();
            return false;
        }


    }

    return true;

}


bool Controller::continueAsking(std::map<char,int>map){
    for(auto e : map){
        if(e.second != 0 ){
            return true;
        }
    }

    return false;
}
void Controller::pawnRemains(const map<char,int> & pawnRemains){
    view_.displayRemainsPawns();
    for(auto e : pawnRemains){
        if(e.second != 0){
            view_.displayPawnChar(e.first);
        }
    }
}

std::vector<char> Controller::readStrategy(PawnTeam team){
    std::map<char,int> pionPossible {{'M',1},{'9',1},{'8',2},{'7',3},{'6',4},{'5',4},{'4',4},{'3',5},
                                     {'2',8},{'1',1},{'D',1},{'B',6}};
    int empty {0};
    std::vector<char> pionInOrder;
    std::string readChar;
    char validChar;
    bool charPresent = false;
    char column {'A'};
    int row {1};
    if(team==RED){
        row = 7;

    }
    view_.showEmptyBoard();
    while(continueAsking(pionPossible)){

        pawnRemains(pionPossible);
        view_.askPawnReamaing(row,column);
        cin >> readChar;
        if(readChar.size() == 1){
            validChar = readChar.at(0);
            validChar = toupper(validChar);
            if(pionPossible.find(validChar) != pionPossible.end() && pionPossible[validChar] != empty){
                pionPossible[validChar]--;
                pionInOrder.push_back(validChar);
                column++;
                if(column == 'K'){
                    row++;
                    column = 'A';

                }
                charPresent = true;
            }
        }
        if(!charPresent){

            view_.displayErrorPawn();
        }
        charPresent = false;


    }

    return pionInOrder;
}

std::vector<char> Controller::fileReaderTeam(const string & fileName){

    ifstream fichierPlayer("../../dev-stratego/Stratego-Project/placement_pawn/" + fileName);

    vector<char> vect;
    if(fichierPlayer){
        char nb;
        for(unsigned i{0}; i < 39; i++){
            fichierPlayer >> nb;
            if(nb == '1' && i+1 < 39 ){
                fichierPlayer >> nb;
                if ( nb == '0') {
                    nb = 'M';
                    vect.push_back(nb);
                }else{
                    vect.push_back('1');
                }
            }

            if( nb != 'M'){

                vect.push_back(nb);
            }

        }
    }else{
        view_.printMsg("il y a un probleme au niveau de chemin de fichier "+ fileName + "\n");
        exit(0);
    }

    return vect;
}

bool Controller::isfileSetUp(){

    string decision{};
    do{
        view_.askSetUpFiles();
        cin>>decision;


    }while(decision.size() != 1 ||( toupper(decision.at(0)) != 'O'
                                    && toupper(decision.at(0)) != 'N'));

    return toupper(decision.at(0)) == 'O';

}

void Controller::showBoard(PawnTeam teamTurn){
    view_.displayHeader();
    for(auto i{0};i < 10; i++){
        view_.printFormat(i+1);
        for(auto j{0};j < 10; j++){
            view_.printPawn(game_.getGameBoard()[i][j], teamTurn);
        }
        view_.printEmptyLine();

    }

}

bool Controller::canBeAdded(char pawnChar,std::map<char,int> map){

    switch (pawnChar) {

    case '1' :
        return map[pawnChar] < 1;
    case '2' :
        return map[pawnChar] < 8;
    case '3':
        return map[pawnChar] < 5;
    case '4':
        return map[pawnChar] < 4;
    case '5':
        return map[pawnChar] < 4;
    case '6':
        return map[pawnChar] < 4;
    case '7':
        return map[pawnChar] < 3;
    case '8':
        return map[pawnChar] < 2;
    case '9':
        return map[pawnChar] < 1;
    case 'M':
        return map[pawnChar] < 1;
    case 'D':
        return map[pawnChar] < 1;

    case 'B':
        return map[pawnChar] < 6;

    default : return false;
    }
}

bool Controller::canMove(PawnTeam hisTeam, Position pos, Direction direction, int deplacement)
{
    return  game_.canMove(hisTeam, pos, direction ,deplacement);
}

void Controller::move(Position pos, Direction direction, int deplacement)
{
    game_.move(pos, direction, deplacement);
}

bool Controller::canFight(PawnTeam hisTeam, const Position &pos, Direction direction, int deplacement)
{
    return game_.canFight(hisTeam, pos, direction, deplacement);
}

void Controller::fight(Position pos, Direction direction, int deplacement)
{
    game_.fight(pos, direction, deplacement);
}

bool Controller::gameIsOver()
{
    return game_.isOver(game_.getTeamTurn());
}

PawnTeam Controller::getWinner()
{
    return game_.getWinner();
}

Direction Controller::getDirection(char directionStr)
{
    switch(directionStr){
    case 'N' : return NORTH;
    case 'E' : return EAST;
    case 'S' : return SOUTH;
    default  : return WEST;
    }
}

Position Controller::newPositionAfterMove(Position pos, Direction dir, int deplacement)
{
    return game_.newPositionAfterMove(pos, dir, deplacement);
}
void Controller::upPosition(){
    if(position_.first <= 10){
        if(position_.second != 'J'){
            position_.second++;
        }else{
            position_.second = 'A';
            position_.first++;
        }
    }
    if(position_.first == 5 && position_.second == 'A'){
        position_.first+=2;
    }
}


