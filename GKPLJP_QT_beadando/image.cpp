#include "image.h"

imgmanager::Image::Image(std::string arg_path, std::string arg_name, std::list<std::string> arg_categories, std::list<std::string> arg_tags):
    path(arg_path),
    name(arg_name),
    categories(arg_categories),
    tags(arg_tags)
{

}

//getters
std::string imgmanager::Image::getPath()
{
    return path;
}

std::string imgmanager::Image::getName()
{
    return name;
}

std::list<std::string> imgmanager::Image::getCategories()
{
    return categories;
}

std::list<std::string> imgmanager::Image::getTags()
{
    return tags;
}

//add
void imgmanager::Image::addCategory(std::string& arg_category)
{
    categories.push_back(arg_category);
}

void imgmanager::Image::addTag(std::string& arg_tag)
{
    tags.push_back(arg_tag);
}

//remove
void imgmanager::Image::removeCategory(std::string& arg_category)
{
    categories.remove(arg_category);
}

void imgmanager::Image::removeTag(std::string& arg_tag)
{
    tags.remove(arg_tag);
}
