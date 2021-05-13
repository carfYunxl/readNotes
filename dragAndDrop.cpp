#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QGraphicsView>
#include <QSplitter>
#include <QHBoxLayout>
#include <QDebug>
#include <QMdiSubWindow>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>
bool MainWindow::readFile(QString filePath)
{
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString read = file.readAll();
        edit->setText(read);
        file.close();
        return true;
    }
    else
        return false;

}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    edit = new QTextEdit(this);
    setCentralWidget(edit);

    edit->setAcceptDrops(false);
    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
              event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())
    {
        return;
    }

    QString fileName = urls.first().toLocalFile();
    if(fileName.isEmpty())
    {
        return;
    }
    if(readFile(fileName))
    {
        setWindowTitle(tr("%1 - %2").arg(fileName).arg(tr("Drag File")));
    }

}