#ifndef STRATEGO_GUI_H
#define STRATEGO_GUI_H
#include "Controller.h"
#include "Observer.h"
#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Stratego_gui; }
QT_END_NAMESPACE

class Stratego_gui : public QMainWindow, Observer
{
    Q_OBJECT
private:
    //PawnPlacement pawnPlacement_;
    Controller ctrl_;
    Position currentPawnPosition_;
    Ui::Stratego_gui *ui;
    QPushButton * pawnButtons_[100];
    QList<QRadioButton*> possibleDirections_;
    Direction choicedDirection_;
    int nbDeplacement_;
    QString opponentName_;
    bool pawnButtonsConnected_;
    bool possibleMove_;
    bool possibleFight_;
    QPushButton* activeButton ;
    QString activeButtonStyles;
    PawnTeam teamTurn_;

public:

    Stratego_gui(QWidget *parent = nullptr);
    ~Stratego_gui();

    virtual void update(void * observable) override{
        Controller * ctrl = static_cast<Controller*>(observable) ;

        updateTeamTurn(ctrl);
        updateBoard(ctrl);
        updateResultat(ctrl);

    }

    inline Controller getController(){
        return ctrl_;
    }

private:
    void displayPlacement();
    void addPawnChar(const std::string & teamChar);
    void updateGameStatus();
    void updateBoard(Controller *obs);
    void updateResultat(Controller * obs);
    void updateTeamTurn(Controller* obs);
    void showPawn(QString pawnName, int pawnTeam, int pawnTurn, int pawnPower, int pawnIndex);
    void updateTeamInput();



private slots:

    void on_btnM_clicked();

    void on_btn9_clicked();

    void on_btn8_clicked();

    void on_btn7_clicked();

    void on_btn6_clicked();

    void on_btn5_clicked();

    void on_btn4_clicked();

    void on_btn3_clicked();

    void on_btn2_clicked();

    void on_btn1_clicked();

    void on_btnD_clicked();

    void on_btnB_clicked();

    void on_btnM_2_clicked();

    void on_btn9_2_clicked();

    void on_btn8_2_clicked();

    void on_btn7_2_clicked();

    void on_btn6_2_clicked();

    void on_btn5_2_clicked();

    void on_btn4_2_clicked();

    void on_btn3_2_clicked();

    void on_btn2_2_clicked();

    void on_btn1_2_clicked();

    void on_btnD_2_clicked();

    void on_btnB_2_clicked();

    void on_startBtn_clicked();

    void pawnClicked();
    void on_moveBtn_clicked();
    void on_attackBtn_clicked();
};
#endif // STRATEGO_GUI_H
