#include "View.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>

using namespace std;
const unsigned format{3};
const unsigned assciConvert{48};
const unsigned alphaConvert{65};


View::View(){

}
void View::displayRemainsPawns(){
    cout << "pions restant : ";
}

void View::displayPawnChar(char pawnChar){
    cout << pawnChar << setw(format-1);

}


void View::displayWelcome(){
    cout << endl << setw(format + 65) << "<<<<<<<<<<<<< STRATEGO >>>>>>>>>>>>>" << endl<< endl;
    cout << "Bienvenue a vous et bonne chance pour cette partie :)" << endl;
    cout << "Pour info: deux fichiers blue.txt et red.txt sont a votre disposition dans le repertoire placementPawn" << endl
         << "Vous pouvez les adapter selon vos strategies mais ils doivent bien respecter les regles du jeu!" << endl;
}

void View::askSetUpFiles(){
    cout << "Voulez vous choisir l'encodage de vos pions par fichier?[o/n]" << endl;
}

void View::displayfileSetUpError(){
    cout<< " votre mise en place ne respecte pas les regle de jeu !"<< endl;
}
void View::fileErrorFeedBack(const string & fileName){
    cout<< "votre fichier: "+ fileName + "ne correspond pas  à l'endroit prevu !"<< endl;
}
void View::fileFeedBack(){

    cout << "nous allons recuperer vos deux fichiers " << endl<<endl;
}
void View::interactiveFeedBack(const string & teamName){
    if(teamName != "red"){
        cout << "OK, la mise en place se fera interactivement ! " << endl;
    }
    cout << "C'est le tour de l'equipe "+ teamName<< endl<<endl;
}

void View::askPawnReamaing(int row, char column){
    cout << endl << "Veuillez choisir un pion pour la position {" << row << " - " << column << "}" <<endl;

}

void View::displayErrorPawn(){
    cout << "Pion non present dans la liste !" << endl;

}
void View::displayHeader(){
    char letter = 'A';
    cout << std::setw(7);

    for(int i = 0; i < 10; i++){
        cout << letter << std::setw(format);
        letter++;
    }

    cout << endl << "__" << endl << std::setw(format);


}

void View::printFormat(int ligne){
    cout << ligne << "|" <<setw(format);

}
void View::printSymbol(const string & symbol){
    cout << symbol << std::setw(format);
}

void addColorConsole(PawnTeam pawnTeam){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(pawnTeam == RED){
        SetConsoleTextAttribute(hConsole,0x04);

    }else if(pawnTeam == BLUE){
        SetConsoleTextAttribute(hConsole,0x09);

    }else{
        SetConsoleTextAttribute(hConsole,0x07);
    }

}


void View::printPawn(Pawn & pawn, PawnTeam & teamTurn){
    addColorConsole(pawn.getPawnTeam());
    if(pawn.getPawnTeam() == teamTurn || pawn.getPawnTeam() == NEUTRAL || ! pawn.isHidden()){
        cout << pawn << std::setw(format);
    }else{

        if( pawn.isHidden()){
            cout << "*" << std::setw(format);
        }

    }
    addColorConsole(NEUTRAL);


}

void View::printEmptyLine(){
    cout << endl;
}


Direction View::directionChoice(){

    string directionChoice;

    do{

        cout << "Veuillez entrez une direction [ N - S - O - E ]" << endl;

        cin >> directionChoice;

    }while(!checkDirectionInput(directionChoice));
    char d = toupper(directionChoice.at(0));


    switch(d){
    case 'S':
        return SOUTH;

    case 'N':
        return NORTH;

    case 'E':
        return EAST;

    default:
        return WEST;

    }

}

bool View::checkDirectionInput(string dir){

    if(dir.size() != 1){
        return false;
    }

    char d = toupper(dir.at(0));
    return d == 'N' ||  d == 'S' || d == 'O' || d == 'E';

}

int View::nbDeplacementSpy(){
    string deplacement;
    do{

        cout << "Veuillez entrer le nombre de deplacement de votre espion" << endl;
        cin >> deplacement;
    }while(!checkValidInputRow(deplacement));

    return deplacement.at(0)-assciConvert;
}


bool View::checkValidInputRow(string input){
    if(input.size() > 2){
        return false;
     }

    return ((static_cast<int>(input.at(0) - assciConvert )) <= 10) &&
            ((static_cast<int>(input.at(0) - assciConvert )) >0);

}

bool View::checkValidInputColumn(string input){


    if(input.size() != 1){
        return false;
    }


    return (toupper(input.at(0)) - 65) >= 0
            && (toupper(input.at(0)) - 65 ) <= 9;

}

void View::printTurn(PawnTeam turn){

    cout << "Au tour de l'equipe : " << turn << endl;

}

void View::printMsg(const string & msg){
    cout << msg;
}

void View::printNbPawnAlives(int nbPawn){
    cout << "le combat il est fini !\nil vous reste :" << nbPawn << " pions" << endl;
}

void View::showEmptyBoard(){
    displayHeader();
    for(auto i{0};i < 10; i++){
        printFormat(i+1);
        for(auto j{0};j < 10; j++){
            if(i == 4 || i == 5){
                if(j == 2 || j==3 || j ==6 || j==7){
                    printSymbol("/");
                }else{
                    printSymbol(" ");
                }
            }else{
                printSymbol("*");

            }
        }
        printEmptyLine();

    }
}

int View::convertedRow(string strRow){
    if(strRow.size() == 2){
        return 9;
    }
    return strRow.at(0) - assciConvert -1;
}


int View::convertedColumn(string strColumn){

    return toupper(strColumn.at(0)) - alphaConvert;
}


