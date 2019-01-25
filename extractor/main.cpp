#include <QCoreApplication>
#include <QFile>
#include <iostream>
#include <QDebug>
#include <QRegularExpression>
#include <QSize>
#include <QUuid>

using namespace std;

// new comment


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString guid = QUuid::createUuid().toString(QUuid::Id128);

    cout << guid.toLocal8Bit().data() << endl;

    return 0;
    //return a.exec();
}




//// 4 - extract numbers from the line
//void extractNumbersFromLine(QString& line, QMap<QString,double>& numberMap);

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    QString line = "a=1.8799 some text 2345 goes .8973 after";
//    cout << "line before: " << line.toLocal8Bit().data() << endl;

//    QMap<QString,double> numberMap;
//    extractNumbersFromLine(line, numberMap);

//    cout << "line  after: " << line.toLocal8Bit().data() << endl;
//    for(auto key: numberMap.keys())
//    {
//        cout << "number -> " << key.toLocal8Bit().data() << " " <<
//                QString::number(numberMap.value(key)).toLocal8Bit().data() << '\n';
//    }

//    return 0;
//    //return a.exec();
//}

//// extract numbers and replace them with tokens
//void extractNumbersFromLine(QString& line, QMap<QString,double>& numberMap)
//{
//    // finds number after decimal point or number in front and after decimal point
//    // BUT NOT the number which comes in front of '###'
//    // -> to avoid ###strXXX### and ###numXXX### tokens
//    QString regexExpr = "(\\d+\\.?\\d*(?!###)|\\.?\\d+(?!###))";
//    QRegularExpression regex(regexExpr);
//    int numberNr = 0;
//    while(true)
//    {
//        QRegularExpressionMatch match = regex.match(line);
//        if (!match.hasMatch())
//        {
//            break;
//        }
//        else
//        {
//            int pos1 = match.capturedStart();
//            int pos2 = match.capturedEnd();
//            //cout << ">>>" << pos1 << " " << pos2 << " " << numberNr << endl;
//            QString key = "###num" + QString::number(++numberNr) + "###";
//            numberMap.insert(key, match.captured().toDouble());
//            line.replace(pos1, pos2 - pos1, key);
//            //cout << "2:" << line.toLocal8Bit().data() << endl;
//        }
//    }
//}






//// 3 - extract token from line
//void splitLineIntoTokens(const QString& line, QStringList& tokensList);

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    QString text = "a = 567.894";
//    QStringList tokensList;
//    splitLineIntoTokens(text, tokensList);
//    for(const QString& token: tokensList)
//    {
//        cout << "\"" << token.toLocal8Bit().data() << "\"\n";
//    }

//    return 0;
//    //return a.exec();
//}

//// splits line into parts, based on delimiters but keeps delimiters as well (except space)...
//void splitLineIntoTokens(const QString& line, QStringList& tokensList)
//{
//    // delimiters: +,-,/,!, ,,,:,?,;,{,},(,),[,],%,|,*,.
//    QString delimiters ="\\+-/! ,:\\?;\\{\\}\\(\\)\\[\\]%\\|\\*\\.";

//    // (?=[+-/!])|(?<=[+-/!])
//    QStringList list = line.split(QRegularExpression("(?=[" + delimiters + "])|(?<=[" + delimiters + "])"));
//    for(const QString& part: list)
//    {
//        QString token = part.trimmed();
//        if (!token.isEmpty())
//        {
//            tokensList.append(token);
//        }
//    }
//}


//// 2 - extract strings and remove comments
//int findStartPositionOfInlineComment(const QString& line);
//void normalizeLine(QString& line, QMap<QString,QString>& stringMap);

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    // TODO -> multiline comments handling

//    QString line = "Line with \"first    unqoted text\"    \"second 'quoted'  text\" \"third \\\"quoted\\\" text\"  comment goes after... ";
//    QMap<QString,QString> stringMap;
//    normalizeLine(line, stringMap);
//    cout << "line: \"" << line.toLocal8Bit().data() << "\"\n";

//    for(auto e : stringMap.keys())
//    {
//      cout << "string -> " << e.toLocal8Bit().data() << " " << stringMap.value(e).toLocal8Bit().data() << '\n';
//    }

//    return 0;
//    //return a.exec();
//}


//// extracts strings, deletes inline comment and simplifies the line
//void normalizeLine(QString& line, QMap<QString,QString>& stringMap)
//{
//    int stringNr = 0;
//    QRegularExpression regex("([\"])(?:(?=(\\\\?))\\2.)*?\\1"); // starts and ends with "
//    while(true)
//    {
//        int commentPos = findStartPositionOfInlineComment(line);
//        QRegularExpressionMatch match = regex.match(line);
//        if (!match.hasMatch())
//        {
//            break;
//        }
//        else
//        {
//            int pos1 = match.capturedStart();
//            int pos2 = match.capturedEnd();
//            if (commentPos == -1 || commentPos > pos1)
//            {
//                QString key = "###str" + QString::number(++stringNr) + "###";
//                stringMap.insert(key, match.captured());
//                line.replace(pos1, pos2 - pos1, key);
//            }
//            else
//            {
//                break;
//            }
//        }
//    }

//    // remove comments
//    line = line.left(findStartPositionOfInlineComment(line));

//    // final cleanup
//    line = line.simplified();
//}



//int findStartPositionOfInlineComment(const QString& line)
//{
//    int pos=-1;
//    QRegularExpression re("//");
//    QRegularExpressionMatch match = re.match(line);
//    if (match.hasMatch())
//    {
//        pos = match.capturedStart();
//    }

//    return pos;
//}


// 1
//void openFileAndReadItLineByLine(QString& filename, QStringList& fileLines);
//void removeSinglelineCommentFromLine(QString& line);
//int findSinglelineCommentPosition(const QString& line);
//void findTextPositions(const QString& line, QList<QPair<int, int>>& posList);

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    QString filename("d:/tmp/text1.txt");
//    QStringList fileLines;
//    openFileAndReadItLineByLine(filename, fileLines);
//    for(int i=0; i<fileLines.count(); ++i)
//    {
//        int commentPos = findSinglelineCommentPosition(fileLines[i]);
//        QList<QPair<int, int>> textPosList;s
//        findTextPositions(fileLines[i], textPosList);
//        // TODO -> find if it overlaps and if it does decide if it is comment or text
//        //removeSinglelineCommentFromLine(fileLines[i]);
//        cout << "\"" << fileLines[i].toUtf8().data() << "\"\n";
//    }

//    return 0;

//    //return a.exec();
//}

//void openFileAndReadItLineByLine(QString& filename, QStringList& fileLines)
//{
//    QFile file(filename);
//    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        QTextStream in(&file);
//        while (!in.atEnd())
//        {
//            QString line = in.readLine();
//            //cout << line.toUtf8().data() << endl;
//            fileLines.append(line);
//        }
//        file.close();
//    }
//}

//// TODO ->what if it is inside of the text?
//// it should return position only and then, what is first (text or comment) has priority...
//// removes everything after // (including //)
//void removeSinglelineCommentFromLine(QString& line)
//{
//    int pos = line.indexOf("//");
//    if (pos > -1)
//    {
//        line = line.left(pos);
//    }
//}

//void extractTextFromLine(QString& line, QMap<string,string>& textMap)
//{
//    int pos = line.indexOf("//");
//    if (pos > -1)
//    {
//        line = line.left(pos);
//    }
//}

//int findSinglelineCommentPosition(const QString& line)
//{
//    int pos = line.indexOf("//");

//    return pos;
//}

//void findTextPositions(const QString& line, QList<QPair<int, int>>& posList)
//{
//    QString anchor1 = "\"";
//    QString anchor2 = "\"";
//    QString anchor3 = "\\";

//    int pos1 = 0;
//    int pos2 = 0;
//    while (true)
//    {
//        pos1 = line.indexOf(anchor1, pos1);
//        if (pos1 == -1) break;
//        pos2 = line.indexOf(anchor2, pos1+1);
//        while (pos2 > 0 && line.at(pos2-1) == anchor3)
//        {
//            pos2 = line.indexOf(anchor2, pos2+1);
//        }
//        if (pos2 == -1) break;

//        QPair<int, int> pair;
//        pair.first = pos1;
//        pair.second = pos2;
//        posList.append(pair);

//        pos1 = pos2 + 1;
//    }
//}





