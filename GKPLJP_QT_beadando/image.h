#ifndef IMAGE_H
#define IMAGE_H

#include <QString>
#include <QList>
#include <QTextStream>
#include <iostream>

namespace imgmanager
{
    class Image
    {
    private:
        QString path;
        QString name;
        QList<QString> categories;
        QList<QString> tags;

    public:
        Image(QString& arg_path, QString& arg_name, QList<QString>& arg_categories, QList<QString>& arg_tags);

        //setters
        //void setPath(std::string arg_path);
        //void setName(std::string arg_name);
        //void setCategories(std::list<std::string> arg_categories);
        //void setTags(std::list<std::string> arg_tags);

        //getters
        QString getPath();
        QString getName();
        QList<QString> getCategories();
        QList<QString> getTags();

        //add
        void addCategory(QString& arg_category);
        void addTag(QString& arg_tag);

        //remove
        void removeCategory(QString& arg_category);
        void removeTag(QString& arg_tag);
    };
}
#endif // IMAGE_H
