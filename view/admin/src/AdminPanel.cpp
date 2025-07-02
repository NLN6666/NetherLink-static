#include "AdminPanel.h"
#include "UserRepository.h"
#include <QHeaderView>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>

AdminPanel::AdminPanel(QWidget* parent)
    : QWidget(parent), table(new QTableWidget(this))
{
    table->setColumnCount(3);
    QStringList headers;
    headers << tr("ID") << tr("昵称") << tr("操作");
    table->setHorizontalHeaderLabels(headers);
    table->horizontalHeader()->setStretchLastSection(true);
    loadUsers();
}

void AdminPanel::loadUsers()
{
    auto users = UserRepository::instance().getAllUser();
    table->setRowCount(users.size());
    for (int i = 0; i < users.size(); ++i) {
        const User& u = users[i];
        table->setItem(i, 0, new QTableWidgetItem(u.id));
        table->setItem(i, 1, new QTableWidgetItem(u.nick));
        QPushButton* btn = new QPushButton(tr("管理"), table);
        btn->setProperty("uid", u.id);
        connect(btn, &QPushButton::clicked, this, &AdminPanel::onActionClicked);
        table->setCellWidget(i, 2, btn);
    }
}

void AdminPanel::onActionClicked()
{
    auto btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;
    QString uid = btn->property("uid").toString();
    QMessageBox::information(this, tr("操作"),
                             tr("对用户 %1 的管理操作在此示例中未实现").arg(uid));
}
