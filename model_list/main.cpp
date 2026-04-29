#include "main_window.h"

#include <QApplication>
#include "string_list_model.h"
#include <QListView>
#include <QTableView>
#include <QAbstractItemView>
#include <QListView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList list;
    list << "a" << "b" << "c";

    StringListModel model(list);
    model.insertRows(model.rowCount(),2); //插入调试,不能使用list，因为该list不是model里面的list
    model.removeRows(model.rowCount()-1,1); //删除调试

    QTableView tableView;
    tableView.setModel(&model);
    tableView.show();

    QListView listView;
    listView.setModel(&model);
    listView.show();
    //设置选择模式为单选
    listView.setSelectionMode(QAbstractItemView::ExtendedSelection);
    //设置可拖拽
    listView.setDragEnabled(true);
    //设置可拖放
    listView.setAcceptDrops(true);
    //设置显示拖放位置
    listView.setDropIndicatorShown(true);

    return a.exec();
}
