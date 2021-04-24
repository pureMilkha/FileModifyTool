#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
    void ShowTxtToWindow();
    QString getText(int index);
    void openFile();
    void saveData();
    void fileClear();

private slots:
    void on_moduleButton1_clicked();

    void on_moduleButton2_clicked();

    void on_moduleButton3_clicked();

    void on_moduleButton4_clicked();

    void on_moduleButton5_clicked();

    void on_moduleButton6_clicked();

    void on_moduleButton7_clicked();

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_infoTextEdit_textChanged();

    void on_historyButton_clicked();

    void on_okButton_clicked();

    void on_pOpen_triggered();

    void on_pAbout_triggered();

    void on_pSetting_triggered();

private:
    Ui::MyMainWindow *ui;
};

#endif // MYMAINWINDOW_H
