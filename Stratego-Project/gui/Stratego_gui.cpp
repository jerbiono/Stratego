#include "Stratego_gui.h"
#include "ui_stratego_gui.h"
#include <QDebug>
#include <chrono>
#include <thread>
using namespace std;




Stratego_gui::Stratego_gui(QWidget *parent)
    : QMainWindow(parent), ctrl_{}, currentPawnPosition_{},
      ui(new Ui::Stratego_gui), pawnButtons_{}, possibleDirections_{},
      choicedDirection_{}, nbDeplacement_{1}, opponentName_{},
      pawnButtonsConnected_{false}, possibleMove_{false}, possibleFight_{false},
      activeButton{nullptr}, activeButtonStyles{}, teamTurn_{BLUE}
{
    ui->setupUi(this);

}


Stratego_gui::~Stratego_gui()
{
    delete ui;
}

void Stratego_gui::displayPlacement(){
    ctrl_.upPosition();
    if(ctrl_.getPosition().first > 5){
        ui->blueChoice->close();
        ui->placementLabel->setGeometry(20,450,421,20);
        ui->redChoice->setEnabled(true);
        ui->redChoice->show();
        ui->row_2->setFontPointSize(14);
        ui->row_2->setFontWeight(QFont::Bold);
        ui->row_2->setText(QString::number(ctrl_.getPosition().first));
        ui->row_2->setStyleSheet("background-color: #f0f0f0");
        ui->row_2->setAlignment(Qt::AlignCenter);

        ui->column_2->setFontPointSize(14);
        ui->column_2->setFontWeight(QFont::Bold);
        ui->column_2->setText(QChar(ctrl_.getPosition().second));
        ui->column_2->setStyleSheet("background-color: #f0f0f0");
        ui->column_2->setAlignment(Qt::AlignCenter);
    }else{
        ui->row->setFontPointSize(14);
        ui->row->setFontWeight(QFont::Bold);
        ui->row->setText(QString::number(ctrl_.getPosition().first));
        ui->row->setStyleSheet("background-color: #f0f0f0");
        ui->row->setAlignment(Qt::AlignCenter);

        ui->column->setFontPointSize(14);
        ui->column->setFontWeight(QFont::Bold);
        ui->column->setText(QChar(ctrl_.getPosition().second));
        ui->column->setStyleSheet("background-color: #f0f0f0");
        ui->column->setAlignment(Qt::AlignCenter);
    }
    if(ctrl_.getPosition().first > 10){
        ui->redChoice->close();
        ui->placementLabel->close();
        ui->startLabel->setText("THE PLACEMENT IS DONE, YOU CAN START !");
        ui->startLabel->show();
        ui->startBtn->setEnabled(true);
        ui->startBtn->show();
    }
}



void Stratego_gui::updateTeamTurn(Controller* obs){
    teamTurn_ = obs->getTurn();
    QString teamTurn{};
    if(teamTurn_== BLUE){
        teamTurn ="BLUE";
    }else{
        teamTurn = "RED";
    }

    if(possibleFight_ || possibleMove_){
        QMessageBox messageBox{};
        messageBox.information(0,"Changement of turn!","the next team is "+ teamTurn);
        messageBox.setEnabled(false);
        this_thread::sleep_for(chrono::seconds(3));
        messageBox.setEnabled(true);
        messageBox.show();


    }

    teamTurn == "BLUE"?
                ui->turnLabel->setText("BLUE TURN !"),
            ui->turnLabel->setStyleSheet("color: black;"):
        ui->turnLabel->setText("RED TURN !"),
        ui->turnLabel->setStyleSheet("color: black;");


}

void Stratego_gui::showPawn(QString pawnName, int pawnTeam , int pawnTurn, int pawnPower, int pawnIndex){
    if(pawnTeam == pawnTurn || pawnTeam == 0){
        pawnButtons_[pawnIndex]->setText(pawnName);
    }else{
        pawnButtons_[pawnIndex]->setText("Unknown");
    }
    if(pawnTeam ==1 ){
        pawnButtons_[pawnIndex]->setStyleSheet("background-color: rgb(0, 170, 255); color: black;");
    }else if(pawnTeam ==2){
        pawnButtons_[pawnIndex]->setStyleSheet("background-color: rgb(255, 0, 0); color: black;");
    }else {
        if(pawnPower == 0 ){
            pawnButtons_[pawnIndex]->setStyleSheet("background-color: rgb(255, 255, 255);");
        }else{
            pawnButtons_[pawnIndex]->setStyleSheet("background-color: transparent;");
        }
    }



}

void Stratego_gui::updateBoard(Controller * obs){
    QString pawnNameButton;
    string pawnType;
    QString pawnName;
    int i{};
    int j{};
    int k{};
    int boardSize {sizeof(pawnButtons_)/ sizeof(*pawnButtons_)};
    while(k < boardSize){
        if(!pawnButtonsConnected_){
            pawnNameButton= "pawn" + QString::number(i) +QString::number(j) ;
            pawnButtons_[k] = Stratego_gui :: findChild<QPushButton *>(pawnNameButton);
        }
        pawnType = obs->getBoard()[i][j].toString();
        pawnName = QString::fromStdString(pawnType);
        int pawnTeam = obs->getBoard()[i][j].getPawnTeam();
        int pawnTurn = obs->getTurn();
        int pawnPower= obs->getBoard()[i][j].getPower();
        pawnTeam == pawnTurn?
                    pawnButtons_[k]->setEnabled(true):
                    pawnButtons_[k]->setEnabled(false);

        if((i == 4 || i == 5) && (j == 2 || j==3 || j ==6 || j==7)) {}
        else
        {
            if(!pawnButtonsConnected_ ){
                connect(pawnButtons_[k], SIGNAL(clicked()), this, SLOT(pawnClicked()));

            }


        }
        showPawn(pawnName , pawnTeam, pawnTurn, pawnPower, k);


        j++;
        k++;
        if(j>9){
            j = 0;
            i++;
        }
    }
    pawnButtonsConnected_ = true;
    updateGameStatus();
}

void Stratego_gui::updateGameStatus(){
    QPushButton *button = (QPushButton *)sender();

    ui->gameStatus->clear();
    if(button->objectName() == "moveBtn"){
        if(possibleMove_){
            ui->gameStatus->addItem("the pawn move is accepted");
        }else{

            for(auto dir : possibleDirections_){
                if(dir->isChecked()){
                    ui->gameStatus->addItem("pawn can't move to the "+ dir->objectName().toLower()+" !");
                }
            }

        }
    }else if (button->objectName() == "attackBtn"){
        if(possibleFight_){

            ui->gameStatus->addItem("the pawn attack is accepted");
            ui->opponent->setText("your opponent was:\n "+ opponentName_);
        }else{
            ui->gameStatus->addItem("pawn can't do the attack !");
        }
    }


}



void Stratego_gui::addPawnChar(const string & teamChar){
    QPushButton *button = (QPushButton *)sender();
    QChar pawnQChar = button->objectName().at(3);
    char pawnChar = pawnQChar.toLatin1();

    ctrl_.getPawnMap()[pawnChar]++;
    if(teamChar == "BLUE"){
        ctrl_.addBluePawnChar(pawnChar);
    }else{
        ctrl_.addRedPawnChar(pawnChar);

    }
    if(!ctrl_.canBeAdded(pawnChar,ctrl_.getPawnMap())){
        button->close();
    }
    if(ctrl_.getBlueSize() == 40 && ctrl_.getRedSize()== 0){
        ctrl_.getPawnMap().clear();
    }
}

void Stratego_gui::pawnClicked(){
    /** position courante **/
    QPushButton *button = (QPushButton *)sender();
    QString rowQstring = button->objectName().at(4);
    int row = rowQstring.toInt();
    QString columnQstring = button->objectName().at(5);
    int column = columnQstring.toInt();
    currentPawnPosition_.setPosition(row,column);


    if(activeButton != nullptr) {
        activeButton->setStyleSheet(activeButtonStyles);
    }
    activeButton = button;
    activeButtonStyles = button->styleSheet();
    button->setStyleSheet("background-color: #FF6B35; color: black;");


    opponentName_ = QString::fromStdString(ctrl_.getBoard()[row][column].toString());
    if(ctrl_.getBoard()[row][column].getPawnType() == SPY){
        ui->spinSpy->setEnabled(true);
    }else{
        ui->spinSpy->setValue(1);
        ui->spinSpy->setEnabled(false);
    }
    /** checkCaseSpy**/

    ui->attackBtn->setEnabled(true);
    ui->moveBtn->setEnabled(true);
    possibleDirections_ = Stratego_gui ::findChildren<QRadioButton*>();
    for(auto dir: possibleDirections_){
        dir->setEnabled(true);
    }

}

void Stratego_gui::updateTeamInput(){
    char charDirection{};
    possibleDirections_ = Stratego_gui ::findChildren<QRadioButton*>();
    for(auto dir: possibleDirections_){
        if(dir->isChecked()){
            charDirection =dir->objectName().at(0).toLatin1();
        }
    }
    choicedDirection_ = ctrl_.getDirection(charDirection);

    nbDeplacement_ = ui->spinSpy->value();

}
void Stratego_gui::on_moveBtn_clicked()
{
    updateTeamInput();
    if(ctrl_.canMove(ctrl_.getPawnTeam(currentPawnPosition_), currentPawnPosition_,
                     choicedDirection_, nbDeplacement_ )){
        possibleMove_= true;

        ctrl_.move(currentPawnPosition_,
                   choicedDirection_, nbDeplacement_);


    }else{
        possibleMove_ = false;
    }

    ctrl_.notifyObservers();
    ui->attackBtn->setEnabled(false);
    ui->moveBtn->setEnabled(false);

    possibleDirections_ = Stratego_gui ::findChildren<QRadioButton*>();
    for(auto dir: possibleDirections_){
        dir->setEnabled(false);
    }
    possibleMove_= false;

    activeButton = nullptr;
    activeButtonStyles = "";
}

void Stratego_gui::updateResultat(Controller *obs ){
    if(obs->gameIsOver()){
        QMessageBox messageBox;
        string winner{};
        if(obs->getWinner()== 1){
            winner = "BLUE";
        }else{
            winner = "RED";
        }
        messageBox.information(0,"game is finished!","the winner is "+ QString::fromStdString(winner));
        messageBox.show();
        if(messageBox.Accepted){
            this->close();
        }
    }
}

void Stratego_gui::on_attackBtn_clicked()
{



    updateTeamInput();
    if(ctrl_.canFight(ctrl_.getPawnTeam(currentPawnPosition_), currentPawnPosition_,
                      choicedDirection_, nbDeplacement_ )){
        possibleFight_= true;
        ctrl_.fight(currentPawnPosition_,
                    choicedDirection_, nbDeplacement_);


    }else{
        possibleFight_ = false;
    }
    ctrl_.notifyObservers();
    ui->attackBtn->setEnabled(false);
    ui->moveBtn->setEnabled(false);
    possibleDirections_ = Stratego_gui ::findChildren<QRadioButton*>();

    for(auto dir: possibleDirections_){
        dir->setEnabled(false);
    }
    possibleFight_ = false;

    activeButton = nullptr;
    activeButtonStyles = "";
}


void Stratego_gui::on_startBtn_clicked()
{
    this->ctrl_= Controller(ctrl_.getBluePawnChars(), ctrl_.getRedPawnChars());
    ctrl_.registerObserver(this);
    this->ctrl_.notifyObservers();
    ui->startLabel->close();
    ui->startBtn->close();
}

void Stratego_gui::on_btnM_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();

}

void Stratego_gui::on_btn9_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();


}

void Stratego_gui::on_btn8_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();

}

void Stratego_gui::on_btn7_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}

void Stratego_gui::on_btn6_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}

void Stratego_gui::on_btn5_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}

void Stratego_gui::on_btn4_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}

void Stratego_gui::on_btn3_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}

void Stratego_gui::on_btn2_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}

void Stratego_gui::on_btn1_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}

void Stratego_gui::on_btnD_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}

void Stratego_gui::on_btnB_clicked()
{
    QString qTeamLabel =ui->labelTeam->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}

void Stratego_gui::on_btnM_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();

}


void Stratego_gui::on_btn9_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}


void Stratego_gui::on_btn8_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}


void Stratego_gui::on_btn7_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}


void Stratego_gui::on_btn6_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}


void Stratego_gui::on_btn5_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}


void Stratego_gui::on_btn4_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}


void Stratego_gui::on_btn3_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}


void Stratego_gui::on_btn2_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}


void Stratego_gui::on_btn1_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}


void Stratego_gui::on_btnD_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}


void Stratego_gui::on_btnB_2_clicked()
{
    QString qTeamLabel =ui->labelTeam_2->text();
    string teamLabel = qTeamLabel.toStdString();
    addPawnChar(teamLabel);
    displayPlacement();
}
