#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>
#include <list>

namespace imgmanager
{
    class Image
    {
    private:
        std::string path;
        std::string name;
        std::list<std::string> categories;
        std::list<std::string> tags;

    public:
        Image(std::string arg_path, std::string arg_name, std::list<std::string> arg_categories, std::list<std::string> arg_tags);

        //setters
        //void setPath(std::string arg_path);
        //void setName(std::string arg_name);
        //void setCategories(std::list<std::string> arg_categories);
        //void setTags(std::list<std::string> arg_tags);

        //getters
        std::string getPath();
        std::string getName();
        std::list<std::string> getCategories();
        std::list<std::string> getTags();

        //add
        void addCategory(std::string& arg_category);
        void addTag(std::string& arg_tag);

        //remove
        void removeCategory(std::string& arg_category);
        void removeTag(std::string& arg_tag);
    };
}
#endif // IMAGE_H
