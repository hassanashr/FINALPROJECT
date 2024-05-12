#ifndef WIN_H
#define WIN_H

#include <QWidget>

namespace Ui {
class win;
}

class win : public QWidget
{
    Q_OBJECT

public:
    explicit win(QWidget *parent = nullptr);
    ~win();
signals:
    void next();
    void back();
private slots:
    void on_next_clicked();

    void on_back_clicked();

private:
    Ui::win *ui;
};

#endif // WIN_H
