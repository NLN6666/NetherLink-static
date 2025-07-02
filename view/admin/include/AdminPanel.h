#pragma once
#include <QWidget>
#include <QTableWidget>

class AdminPanel : public QWidget {
    Q_OBJECT
public:
    explicit AdminPanel(QWidget* parent = nullptr);

private slots:
    void onActionClicked();

private:
    void loadUsers();
    QTableWidget* table;
};
