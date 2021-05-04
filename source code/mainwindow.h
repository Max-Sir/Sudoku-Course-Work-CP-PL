#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include <QPushButton>
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QFrame>
#include <QGridLayout>
#include <QTableWidget>
#include <QVector>
#include <QMediaPlayer>
#include "solver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    qint32 now,flag;
    QTimer*Timer;
    QTime*Time_record;
    qint32 select_x,select_y,wrong_state;
    Matrix m,prob,mark;//Matrix m is stored in binary mode, e.g. (100010010)2 means selecting number 1,5,8
    Solver sol;
    qint32 stage,//0:random 1-4:...
        level,//0:custom, 1:easy, 2:normal, 3:hard, 4:crazy
        state,//0:empty, 1:start, 2:pause, 3:end
        history_temp;//количество записей в истории/ current index of history
    QVector<Matrix> history,hmark;
    QVector<qint32>hx,hy;
    QMediaPlayer* player;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QPushButton ***button,**num,*record_button,*delete_button;
protected:
    void keyPressEvent(QKeyEvent *);
    void newgame();
    void pause();
    void continuegame();
    void refresh_xy(int add);
    void load_prob(int clear);
    void show_solution(int origin);
    void show_tip();
    void show_info();
    void redo();
    void undo();
    void mark_grid();
    void finish();
    void timer_start();
    int checkavailable(int,int);
    QString change_bin_number_into_String(int);
    void addnumber(int);
    void deletegrid();
private slots:
    void time_update();
    void on_button_clicked();
    void on_num_clicked();
    void on_mark_button_clicked();
    void on_del_button_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_actionInfo_triggered();
    void on_actionReset_triggered();
    void on_actionSolve_triggered();
    void on_actionPause_triggered();
    void on_actionStart_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionLv_1_triggered();
    void on_actionLv_2_triggered();
    void on_actionLv_3_triggered();
    void on_actionLv_4_triggered();
    void on_actionLv_5_triggered();
    void on_actionLv_6_triggered();
    void on_actionLv_7_triggered();
    void on_actionLv_8_triggered();
    void on_actionLv_9_triggered();
    void on_actionLv_10_triggered();
    void on_actionLv_11_triggered();
    void on_actionLv_12_triggered();
    void on_actionLv_13_triggered();
    void on_actionLv_14_triggered();
    void on_actionLv_15_triggered();
    void on_actionLv_16_triggered();
    void on_actionRandom_triggered();
    void on_actionRandom_2_triggered();
    void on_actionRandom_3_triggered();
    void on_actionRandom_4_triggered();
    void on_actionInput_Sudoku_Game_triggered();
    void on_actionMusic_triggered();
};

#endif // MAINWINDOW_H
