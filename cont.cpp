#include "cont.h"
//#include "ui_cont.h"
using namespace Ui;

cont::cont(QWidget *parent) : Dialog(parent), ui(new Ui::cont)
{
    ui->setupUi(this);
}

cont::~cont()
{
    delete ui;
}

