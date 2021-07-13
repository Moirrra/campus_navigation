#include "sqlhelp.h"

SqlHelp::SqlHelp()
{

}

/*
 * @usage 将数据绑定下拉框
 * @brief SqlHelp::BindDataToCombox
 * @param tableName 表名
 * @param tableColumnName 列名
 * @param where 筛选条件
 * @param cbox 下拉框控件
 * @author ts
 */
void SqlHelp::BindDataToCombox(const QString &tableName,
                               const QString &tableColumnName,
                               const QString &where,
                               QComboBox *cbox)
{
    QSqlQuery query;
    query.exec("SELECT "+tableColumnName+" FROM "+tableName+" "+where);
    while(query.next())
    {
        cbox->addItem(query.value(0).toString());
    }
}

/*
 * @usage 获取数据表某列的值
 * @brief QStringList SqlHelp::GetTableColumnValue
 * @param tableName 表名
 * @param tableColumnName 列名
 * @return 结果列表
 * @author ts
 */
QStringList SqlHelp::GetTableColumnValue(const QString &tableName,
                                         const QString &columnName)
{
    QStringList list;
    QSqlQuery query;
    query.exec("SELECT "+columnName+" FROM "+tableName);
    while(query.next())
    {
        list.append(query.value(0).toString());
    }
    return list;
}

/*
 * @usage 获取数据表某个单元格的值
 * @brief QString SqlHelp::FindValue
 * @param tableName 表名
 * @param tableColumnName 列名
 * @param value 列筛选条件
 * @param type 查找类型
 * @return 目标字符串 空则找不到
 * @author ts
 */
QString SqlHelp::FindValue(const QString &tableName, const QString &columnName,
                           const QString &value, int &type)
{
    QString phy_address = "";
    QSqlQuery query;
    QString where = " WHERE "+columnName+"="+"'"+value+"'";
    qDebug()<<where;
    query.exec("SELECT * FROM "+tableName+where);
    if(query.first())
    {
        phy_address = query.value(3).toString();
        type = query.value(2).toInt();
    }
    else//找不到
    {
        phy_address = "";
        type = 0;
    }
    return phy_address;
}
