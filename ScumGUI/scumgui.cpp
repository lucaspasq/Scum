#include "scumgui.h"
#include "ui_scumgui.h"

ScumGUI::ScumGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ScumGUI)
{
    ui->setupUi(this);
}

ScumGUI::~ScumGUI()
{
    delete ui;
}

