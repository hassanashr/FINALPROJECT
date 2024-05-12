#ifndef LOSE_H
#define LOSE_H

#include <QWidget>

namespace Ui {
class lose;
}

class lose : public QWidget
{
    Q_OBJECT

public:
    explicit lose(QWidget *parent = nullptr);
    ~lose();
signals:
    void retry();
    void back();
private slots:
    void on_retry_clicked();

    void on_back_clicked();

private:
    Ui::lose *ui;
};

#endif // LOSE_H
