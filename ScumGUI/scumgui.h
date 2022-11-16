#ifndef SCUMGUI_H
#define SCUMGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ScumGUI; }
QT_END_NAMESPACE

class ScumGUI : public QMainWindow
{
    Q_OBJECT

public:
    ScumGUI(QWidget *parent = nullptr);
    ~ScumGUI();

private:
    Ui::ScumGUI *ui;
};
#endif // SCUMGUI_H
