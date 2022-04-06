#include "image.h"

imgmanager::Image::Image(QString& arg_path, QString& arg_name, QList<QString>& arg_categories, QList<QString>& arg_tags):
    path(arg_path),
    name(arg_name),
    categories(arg_categories),
    tags(arg_tags)
{

}

//getters
QString imgmanager::Image::getPath()
{
    return path;
}

QString imgmanager::Image::getName()
{
    return name;
}

QList<QString> imgmanager::Image::getCategories()
{
    return categories;
}

QList<QString> imgmanager::Image::getTags()
{
    return tags;
}

//add
void imgmanager::Image::addCategory(QString& arg_category)
{
    categories.push_back(arg_category);
}

void imgmanager::Image::addTag(QString& arg_tag)
{
    tags.push_back(arg_tag);
}

//remove
void imgmanager::Image::removeCategory(QString& arg_category)
{
    categories.removeOne(arg_category);
}

void imgmanager::Image::removeTag(QString& arg_tag)
{
    tags.removeOne(arg_tag);
}
