#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include <QMenuBar>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QTextCodec>
#include <QDateTime>
#include <QDebug>

/******变量******/

// 文件名
QString fileName;
// 模块信息列表
QStringList moduleInfoList;
// 当前选中模块标识
int currentModuleIndex = 1;
// 时间数组
QStringList timeStrList1;
// 自定义分割符
QString splitString = "####################################";

/**
 * @brief MyMainWindow::MyMainWindow
 * @param parent
 *
 * 初始化处理
 */
MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);

    ui->menuBar->setStyleSheet("background-color:rgba(240,240,240)");
    ui->menuBar->setStyleSheet("QMenu::item:selected{background-color:rgb(0,100,200);}\
                               QMenuBar{background-color:rgb(200,200,200);}");
    ui->mainToolBar->setFixedHeight(100);
    QIcon saveIcon;
    saveIcon.addFile(tr(":/save.png"));
    ui->saveButton->setIcon(saveIcon);
    ui->saveButton->setIconSize(QSize(25,25));

    QIcon cancelIcon;
    cancelIcon.addFile(tr(":/cancel.png"));
    ui->cancelButton->setIcon(cancelIcon);
    ui->cancelButton->setIconSize(QSize(25,25));

    ui->fileSrcLabel->setHidden(true);
    ui->saveButton->setEnabled(false);
    ui->cancelButton->setEnabled(false);
    ui->saveButton->setText("保存");
    ui->historyTextEdit->setHidden(true);

    QMenuBar *mBar = menuBar();
    QMenu *pFile = mBar->addMenu("文件(F)");
    QMenu *pAbout = mBar->addMenu("关于(A)");
    QAction *pOpen = pFile->addAction("打开(O)");

    connect(pOpen, &QAction::triggered,
            [=](){
                    openFile();
                });
}

/**
 * @brief MyMainWindow::~MyMainWindow
 *
 * ui
 */
MyMainWindow::~MyMainWindow()
{
    delete ui;
}

/**
 * @brief MyMainWindow::ShowTxtToWindow
 *
 * 显示文本文件中的内容
 */
void MyMainWindow::ShowTxtToWindow()
{
     QFile file(fileName);
     if(!file.open(QFile::ReadOnly|QFile::Text))
     qDebug()<< "Can not open";
     QTextStream in(&file);
     in.setCodec("utf-8");
     QString infoString = in.readAll();
     ui->infoTextEdit->setPlainText(infoString);
}

/**
 * @brief MyMainWindow::getText
 * @param index
 * @return
 *
 * 获取字符串信息
 */
QString MyMainWindow::getText(int index)
{
     QFile file(fileName);
     if(!file.open(QFile::ReadOnly|QFile::Text)) {
         qDebug()<< "Can not open";
         ui->saveButton->setEnabled(false);
         ui->cancelButton->setEnabled(false);
         return "";
     }
     QTextStream in(&file);
     in.setCodec("utf-8");
     QString infoString = in.readAll();
     QStringList list = infoString.split(splitString);
     if (infoString != "") {
         switch (index) {
         case 0:
             return list.at(0);
             break;
         case 1:
             return list.at(1);
             break;
         case 2:
             return list.at(2);
             break;
         case 3:
             return list.at(3);
             break;
         case 4:
             return list.at(4);
             break;
         case 5:
             return list.at(5);
             break;
         case 6:
             return list.at(6);
             break;
         case 7:
             return list.at(7);
             break;
         default:
             return "";
             break;
         }
     }
}

void MyMainWindow::openFile() {
    qDebug()<<"open file...";
    //定义文件对话框类
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(tr("打开文件"));
    //设置默认文件路径
    fileDialog->setDirectory("C:/Desktop");
    //设置文件过滤器
    fileDialog->setNameFilter(tr("text(*.txt)"));
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径
    QStringList fileNames;
    if (fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
    }
    for (auto tmp : fileNames)
    {
        ui->fileSrcLabel->setHidden(false);
        ui->pathLabel->setText(tmp);
        fileName = tmp;
    }
        if (!fileName.isEmpty()){
        ShowTxtToWindow();
        saveData();
        ui->infoTextEdit->setStyleSheet("background-color:rgba(255,255,255)");
        ui->saveButton->setEnabled(false);
        ui->cancelButton->setEnabled(false);
    }
        qDebug()<<fileName;
}

/**
 * @brief MyMainWindow::saveData
 *
 * 保存数据
 */
void MyMainWindow::saveData(){
    for(int i = 0; i<7; i++) {
        moduleInfoList.append(getText(i));
    }
}

/**
 * @brief MyMainWindow::on_moduleButton1_clicked
 *
 * 模块1按钮按下处理
 */
void MyMainWindow::on_moduleButton1_clicked()
{
    ui->historyTextEdit->setHidden(true);
    ui->saveButton->setEnabled(true);
    ui->cancelButton->setEnabled(true);
    ui->infoTextEdit->setText(getText(0));
    currentModuleIndex = 1;
    ui->moduleGroupBox->setTitle("模块1");
    ui->infoTextEdit->setStyleSheet("background-color:rgba(255,255,255)");
    ui->saveButton->setText("保存");

}

/**
 * @brief MyMainWindow::on_moduleButton2_clicked
 *
 * 模块2按钮按下处理
 */
void MyMainWindow::on_moduleButton2_clicked()
{
    ui->historyTextEdit->setHidden(true);
    ui->saveButton->setEnabled(true);
    ui->cancelButton->setEnabled(true);
    ui->infoTextEdit->setText(getText(1));
    currentModuleIndex = 2;
    ui->moduleGroupBox->setTitle("模块2");
    ui->infoTextEdit->setStyleSheet("background-color:rgba(255,255,255)");
    ui->saveButton->setText("保存");
}

/**
 * @brief MyMainWindow::on_moduleButton3_clicked
 *
 * 模块3按钮按下处理
 */
void MyMainWindow::on_moduleButton3_clicked()
{
    ui->historyTextEdit->setHidden(true);
    ui->saveButton->setEnabled(true);
    ui->cancelButton->setEnabled(true);
    ui->infoTextEdit->setText(getText(2));
    currentModuleIndex = 3;
    ui->moduleGroupBox->setTitle("模块3");
    ui->infoTextEdit->setStyleSheet("background-color:rgba(255,255,255)");
    ui->saveButton->setText("保存");
}

/**
 * @brief MyMainWindow::on_moduleButton4_clicked
 *
 * 模块4按钮按下处理
 */
void MyMainWindow::on_moduleButton4_clicked()
{
    ui->historyTextEdit->setHidden(true);
    ui->saveButton->setEnabled(true);
    ui->cancelButton->setEnabled(true);
    ui->infoTextEdit->setText(getText(3));
    currentModuleIndex = 4;
    ui->moduleGroupBox->setTitle("模块4");
    ui->infoTextEdit->setStyleSheet("background-color:rgba(255,255,255)");
    ui->saveButton->setText("保存");
}

/**
 * @brief MyMainWindow::on_moduleButton5_clicked
 *
 * 模块5按钮按下处理
 */
void MyMainWindow::on_moduleButton5_clicked()
{
    ui->historyTextEdit->setHidden(true);
    ui->saveButton->setEnabled(true);
    ui->cancelButton->setEnabled(true);
    ui->infoTextEdit->setText(getText(4));
    currentModuleIndex = 5;
    ui->moduleGroupBox->setTitle("模块5");
    ui->infoTextEdit->setStyleSheet("background-color:rgba(255,255,255)");
    ui->saveButton->setText("保存");
}

/**
 * @brief MyMainWindow::on_moduleButton6_clicked
 *
 * 模块6按钮按下处理
 */
void MyMainWindow::on_moduleButton6_clicked()
{
    ui->historyTextEdit->setHidden(true);
    ui->saveButton->setEnabled(true);
    ui->cancelButton->setEnabled(true);
    ui->infoTextEdit->setText(getText(5));
    currentModuleIndex = 6;
    ui->moduleGroupBox->setTitle("模块6");
    ui->infoTextEdit->setStyleSheet("background-color:rgba(255,255,255)");
    ui->saveButton->setText("保存");
}

/**
 * @brief MyMainWindow::on_moduleButton7_clicked
 *
 * 模块7按钮按下处理
 */
void MyMainWindow::on_moduleButton7_clicked()
{
    ui->historyTextEdit->setHidden(true);
    ui->saveButton->setEnabled(true);
    ui->cancelButton->setEnabled(true);
    ui->infoTextEdit->setText(getText(6));
    currentModuleIndex = 7;
    ui->moduleGroupBox->setTitle("模块7");
    ui->infoTextEdit->setStyleSheet("background-color:rgba(255,255,255)");
    ui->saveButton->setText("保存");
}

/**
 * @brief MyMainWindow::on_saveButton_clicked
 *
 * 保存按钮按下处理
 */
void MyMainWindow::on_saveButton_clicked()
{
    qDebug()<<moduleInfoList[currentModuleIndex-1];
    qDebug()<<ui->infoTextEdit->toPlainText();
    qDebug()<<moduleInfoList.length();
    if(moduleInfoList.isEmpty()) {
        qDebug()<<moduleInfoList.length();
        return;
    }

    moduleInfoList[currentModuleIndex-1] = ui->infoTextEdit->toPlainText();
    QString e = "";
    for(int i=0;i<7;i++) {
        qDebug()<<moduleInfoList[i];
        e += moduleInfoList[i];
        if(i==6) {
            // TODO:
        } else {
            e += splitString;
        }
    }

    QFile fileRemove(fileName);

    bool ok = fileRemove.remove();
    moduleInfoList.clear();

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        return;
    }
    file.write(e.toUtf8());
    file.close();
    saveData();
    ui->infoTextEdit->setStyleSheet("background-color:rgba(255,255,255)");
    ui->saveButton->setText("保存成功");
    if (currentModuleIndex = 1) {
        QDateTime curDateTime=QDateTime::currentDateTime();
        QString timeStr1 = curDateTime.toString("yyyy-MM-dd hh:mm:ss");
        timeStrList1.append(timeStr1);
    }
    ui->saveButton->setText("保存成功");
}

/**
 * @brief MyMainWindow::on_cancelButton_clicked
 *
 * 取消按钮按下处理
 */
void MyMainWindow::on_cancelButton_clicked()
{
    ui->infoTextEdit->setText(moduleInfoList[currentModuleIndex-1]);
    ui->infoTextEdit->setStyleSheet("background-color:rgba(255,255,255)");
}

/**
 * @brief MyMainWindow::on_infoTextEdit_textChanged
 *
 * 编辑框编辑时处理
 */
void MyMainWindow::on_infoTextEdit_textChanged()
{
    ui->saveButton->setText("保存");
    ui->infoTextEdit->setStyleSheet("background-color:rgba(240,128,128,120)");
}

/**
 * @brief MyMainWindow::on_historyButton_clicked
 *
 * 历史记录按钮按下处理
 */
void MyMainWindow::on_historyButton_clicked()
{
    ui->historyTextEdit->setHidden(false);
    ui->historyTextEdit->clear();
    ui->historyTextEdit->setEnabled(false);
    ui->historyTextEdit->setStyleSheet("background-color:rgba(240,248,255)");
    qDebug()<<timeStrList1.length();
    if (currentModuleIndex==1) {
        for(int i = timeStrList1.length(); i>0; i--) {
            ui->historyTextEdit->append(timeStrList1[i-1]+"被修改");
            qDebug()<<"qqqq";
        }
    }
}

void MyMainWindow::on_okButton_clicked()
{
    ui->historyTextEdit->setHidden(true);
}

void MyMainWindow::on_pOpen_triggered()
{
    openFile();
}

void MyMainWindow::on_pAbout_triggered()
{
    QMessageBox::about(this,"关于App", "功能介绍\n1,文件修改；\n2,历史记录查询；\n3,设置自定义分隔符；\n版本：1.0。");
}


void MyMainWindow::on_pSetting_triggered()
{
    bool isOK;
    QInputDialog inputDialog(this);
    inputDialog.resize(QSize(400,700));
    splitString = inputDialog.getText(NULL,
                                    "Input",
                                    "请各模块之间的输入分隔符",
                                    QLineEdit::Normal,
                                    "###",
                                    &isOK);
    if(isOK) {
       QMessageBox::information(NULL,
                                "Information",
                                "请确认分割符: <b>" + splitString + "</b>",
                                QMessageBox::Yes | QMessageBox::No,
                                QMessageBox::Yes);
    }
}
