#include "fileparser.h"

parser::FileParser::FileParser()
{

}

void parser::FileParser::toFile(QList<imgmanager::Image> &data_list)
{
    QString data = "";

    for(auto item : data_list)
    {
        data += item.getPath() + ";";
        int counter = 0;

        for(auto cat : item.getCategories())
        {
            if(counter < item.getCategories().size()-1)
            {
                data += cat + ",";
            }
            else
            {
                data += cat;
            }
            counter++;
        }
        data += ";";

        counter = 0;
        for(auto tag : item.getTags())
        {
            if(counter < item.getTags().size()-1)
            {
                data += tag + ",";
            }
            else
            {
                data += tag;
            }
            counter++;
        }
        data += "!";
    }

    QFile file("data.dat");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
           return;
    }

    QTextStream out(&file);
    out << data;
    file.close();
}

QList<imgmanager::Image> parser::FileParser::toObject()
{
    QString data;
    QList<imgmanager::Image> result;

    QFile file("data.dat");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return QList<imgmanager::Image>();
    }

    QTextStream in(&file);
    data += in.readAll();
    file.close();

    QList<QString> rows;

    rows = data.split("!");
    std::cout << rows.length() << std::endl;


    for(QString row : rows)
    {
        if(row.length() != 0)
        {
            QString path, categories_s, tags_s, name = "";
            QList<QString> items = row.split(";");

            path = items.at(0);
            categories_s = items.at(1);
            tags_s = items.at(2);

            QList<QString> get_name = path.split("/");
            for(QString n : get_name)
            {
                name = n;
            }

            QList<QString> categories = categories_s.split(",");
            QList<QString> tags = tags_s.split(",");

            imgmanager::Image img = imgmanager::Image(path, name, categories, tags);
            result.append(img);
        }
    }

    return result;
}
