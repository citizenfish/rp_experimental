#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void receiveText(const QString &text);

private:
    Ui::MainWindow *ui;
    QWebEngineView webView;

signals:
    /*!
        This signal is emitted from the C++ side and the text displayed on the HTML client side.
    */
    void sendText(const QString &text);

public slots:
    /*!
        This slot is invoked from the HTML client side and the text displayed on the server side.
    */
    void receiveText(const QString &text);


};

#endif // MAINWINDOW_H
