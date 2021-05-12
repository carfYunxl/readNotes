#include <QToolBar>
#include <QMessageBox>
myWindow::myWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QWidget *widget = new QWidget(this);
    widget->setStyleSheet("background-color:blue;"
                          "border-radius:20px");

    QVBoxLayout *layout = new QVBoxLayout;
    widget->setLayout(layout);
    widget->setContentsMargins(0,0,0,0);


    QLabel *lable = new QLabel(this);
    //lable->setContentsMargins(0,0,0,0);
    lable->setFixedHeight(30);

    //lable->setStyleSheet("background-color:blue;"
                         //"border-radius:10px");
    layout->addWidget(lable);
    layout->addWidget(menuBar());
    setMenuWidget(widget);

    QList<QAction *> pf = {new QAction("1",this),new QAction("2",this),new QAction("3",this),new QAction("4",this)};
    QToolBar *toolb = addToolBar("11111111");
    toolb->addActions(pf);

}

myWindow::~myWindow()
{
    delete ui;
}
void myWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPen myPen(Qt::black,3,Qt::SolidLine,Qt::SquareCap);
    painter.setPen(myPen);
    //painter.drawRect(0,0,this->width(),this->height());
    painter.drawRoundRect(0,0,this->width(),this->height(),5,5);

}
void myWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->buttons() == Qt::RightButton)
    {
        int ret = QMessageBox::information(this,"tips:","right can close the window,Yes to do that!",
                                 QMessageBox::Yes |
                                 QMessageBox::No,QMessageBox::Yes);
        if(ret == QMessageBox::Yes)
        {
            this->close();
        }
    }else if(event->buttons() == Qt::LeftButton)
    {
        cPoint = event->globalPos()-frameGeometry().topLeft();
    }
}
void myWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        move(event->globalPos()-cPoint);
    }
}