#ifndef SQLHELP_H
#define SQLHELP_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include <QString>
#include <QComboBox>
#include <QLabel>
#include <QtSql/QSqlQueryModel>
#include <QStringList>
class SqlHelp
{
public:
    SqlHelp();

    //将数据绑定到下拉框中
    void BindDataToCombox(const QString &tableName,
                                   const QString &tableColumnName,
                                   const QString &where,
                                   QComboBox *cbox);

    QStringList GetTableColumnValue(const QString &tableName,const QString &columnName);
    QString FindValue(const QString &tableName, const QString &columnName,
                      const QString &value, int &type);

};

/*
 * @usage 连接数据库
 * @brief static bool createConnection
 * @author ts
 */
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("campusMap.db");
    if (!db.open())
    {
        qDebug() << "Error: Failed to connect database." << db.lastError();
        return false;
    }
    return true;
}

/*
 * @usage 关闭数据库
 * @brief static bool closeConnection
 * @author ts
 */
static bool closeConnection()
{
    QSqlDatabase::database().close();
    return true;
}

#endif // SQLHELP_H
