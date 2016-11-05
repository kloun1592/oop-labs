#include <iostream>
#include <fstream>
#include <string>
#include "Rectangle.h"

using namespace std;

struct RecParam
{
    int leftX;
    int topY;
    int width;
    int height;
};

void RemoveSpaces(string & strWithBlanks)
{
    strWithBlanks.erase(remove(strWithBlanks.begin(), strWithBlanks.end(), ' '), strWithBlanks.end());
}

RecParam GetIntersectRecParam(CRectangle const& rectangle1, CRectangle const& rectangle2)
{
    Point leftTopPoint1 = rectangle1.GetLeftTopPoint();
    Point rightBottomPoint1 = rectangle1.GetRightBottomPoint();
    
    Point leftTopPoint2 = rectangle2.GetLeftTopPoint();
    Point rightBottomPoint2 = rectangle2.GetRightBottomPoint();
    
    int interRightX = min(rightBottomPoint1.x, rightBottomPoint2.x);
    int interBottomY = min(rightBottomPoint1.y, rightBottomPoint2.y);
    RecParam recParam;
    recParam.leftX = max(leftTopPoint1.x, leftTopPoint2.x);
    recParam.topY = max(leftTopPoint1.y, leftTopPoint2.y);
    recParam.width = interRightX - recParam.leftX;
    recParam.height = interBottomY - recParam.topY;
    return recParam;
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

Point GetMoveOrScaleParam(ifstream & commandsFile)
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
    return recParam;
}

void ReadCommands(ifstream & commandsFile, CRectangle & rectangle)
{
    string command;
    while(getline(commandsFile, command, ':'))
    {
        if (command == "Move")
        {
            Point coordinates = GetMoveOrScaleParam(commandsFile);
            rectangle.Move(coordinates.x, coordinates.y);
        }
        
        if (command == "Scale")
        {
            Point coordinates = GetMoveOrScaleParam(commandsFile);
            rectangle.Scale(coordinates.x, coordinates.y);
        }
    }
}

int main(int argc, const char * argv[])
{
    ifstream firstRecFile(argv[1]);
    ifstream secondRecFile(argv[2]);
    RecParam recParam;
    
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
            RecParam recParam = GetIntersectRecParam(rectangle1, rectangle2);
            CRectangle intersectRectangle(recParam.leftX, recParam.topY, recParam.width, recParam.height);
            PrintRectangleParam(intersectRectangle, "Intersection rectangle:");
        }
    }
    return 0;
}
