#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QFile>
#include <QList>
#include <QString>
#include "image.h"

namespace parser
{
    class FileParser
    {
    public:
        FileParser();

        //write
        void toFile(QList<imgmanager::Image>& data_list);

        //read
        QList<imgmanager::Image> toObject();
    };
}
#endif // FILEPARSER_H
