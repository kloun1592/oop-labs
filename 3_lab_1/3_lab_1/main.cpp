#include <iostream>
#include <fstream>
#include <string>
#include "Rectangle.h"

using namespace std;

void RemoveSpaces(string & strWithBlanks)
{
    strWithBlanks.erase(remove(strWithBlanks.begin(), strWithBlanks.end(), ' '), strWithBlanks.end());
}

void PrintRectangleParam(CRectangle const& rectangle, string const& title)
{
    cout << title << endl;
    Point point = rectangle.GetLeftTopPoint();
    cout << "\t Left Top: (" << point.x << "; " << point.y << ")" << endl;
    Size size = rectangle.GetSize();
    cout << "\t Size: " << size.width << '*' << size.height << endl;
    Point point1 = rectangle.GetRightBottomPoint();
    cout << "\t Right bottom: (" << point1.x << "; " << point1.y << ")" << endl;
    cout << "\t Area: " << rectangle.CalculateArea() << endl;
    cout << "\t Perimetr: " << rectangle.CalculatePerimeter() << endl;
}

Point ReadPointParameters(ifstream & commandsFile)
{
    string dX, dY;
    getline(commandsFile, dX, ',');
    getline(commandsFile, dY, '\n');
    
    Point coordiantes;
    coordiantes.x = stoi(dX);
    coordiantes.y = stoi(dY);
    
    return coordiantes;
}

RecParam GetRecParam(ifstream & commandsFile)
{
    string leftX, topY, width, height, command;
    getline(commandsFile, command, ':');
    getline(commandsFile, leftX, ',');
    getline(commandsFile, topY, ',');
    getline(commandsFile, width, ',');
    getline(commandsFile, height, '\n');
    
    RemoveSpaces(leftX);
    RemoveSpaces(topY);
    RemoveSpaces(width);
    RemoveSpaces(height);
    
    RecParam recParam;
    recParam.leftX = stoi(leftX);
    recParam.topY = stoi(topY);
    recParam.width = stoi(width);
    recParam.height = stoi(height);
    
    if (recParam.width < 0 || recParam.height < 0)
    {
        recParam.width = recParam.height = 0;
    }
    
    return recParam;
}

void ReadCommands(ifstream & commandsFile, CRectangle & rectangle)
{
    string command;
    while(getline(commandsFile, command, ':'))
    {
        if (command == "Move")
        {
            Point coordinates = ReadPointParameters(commandsFile);
            rectangle.Move(coordinates.x, coordinates.y);
        }
        
        if (command == "Scale")
        {
            Point coordinates = ReadPointParameters(commandsFile);
            rectangle.Scale(coordinates.x, coordinates.y);
        }
    }
}

int main(int argc, const char * argv[])
{
    ifstream firstRecFile(argv[1]);
    ifstream secondRecFile(argv[2]);
    RecParam recParam;
    
    if (argc != 3)
    {
        cout << "Invalid arguments count" << endl
        << "Usage: copyfile.exe <input file> <output file>" << endl;
        return 1;
    }
    
    if(!firstRecFile.is_open() || !secondRecFile.is_open())
    {
        cout << "Can't read one of two commands file" << endl;
        return 1;
    }
    else
    {
        recParam = GetRecParam(firstRecFile);
        CRectangle rectangle1(recParam.leftX, recParam.topY, recParam.width, recParam.height);
        ReadCommands(firstRecFile, rectangle1);
        
        recParam = GetRecParam(secondRecFile);
        CRectangle rectangle2(recParam.leftX, recParam.topY, recParam.width, recParam.height);
        ReadCommands(secondRecFile, rectangle2);
        
        PrintRectangleParam(rectangle1, "Rectangle 1:");
        PrintRectangleParam(rectangle2, "Rectangle 2:");
        
        if(rectangle1.Intersect(rectangle2))
        {
            RecParam recParam = rectangle1.GetIntersectRecParam(rectangle2);
            CRectangle intersectRectangle(recParam.leftX, recParam.topY, recParam.width, recParam.height);
            PrintRectangleParam(intersectRectangle, "Intersection rectangle:");
        }
    }
    return 0;
}
