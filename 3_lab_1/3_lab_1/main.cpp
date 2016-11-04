#include <iostream>
#include <fstream>
#include <string>
#include "main.h"

using namespace std;

int CRectangle::CountArea()const
{
    return m_recWidth * m_recHeight;
}

int CRectangle::CountPerimetr()const
{
    return 2 * (m_recWidth + m_recHeight);
}

Point CRectangle::GetRightBottomPoint()const
{
    Point point;
    point.x = m_leftX + m_recWidth;
    point.y = m_topY + m_recHeight;
    return point;
}

Point CRectangle::GetLeftTopPoint()const
{
    Point point;
    point.x = m_leftX;
    point.y = m_topY;
    return point;
}

void CRectangle::Move(int dx, int dy)
{
    m_leftX += dx;
    m_topY += dy;
}

void CRectangle::Scale(int sx, int sy)
{
    m_recWidth *= sx;
    m_recHeight *= sy;
}

bool CRectangle::Intersect(CRectangle const& other)
{
    Point LeftTopPointOfSecondRec = other.GetLeftTopPoint();
    Point RightBottomPointOfSecondRec = other.GetRightBottomPoint();
    if (m_leftX < RightBottomPointOfSecondRec.x && GetRightBottomPoint().x > LeftTopPointOfSecondRec.x && m_topY < RightBottomPointOfSecondRec.y && GetRightBottomPoint().y > LeftTopPointOfSecondRec.y)
    {
        return true;
    }
    else
    {
        m_recWidth = m_recHeight = 0;
        return false;
    }
}

CRectangle::Size CRectangle::GetSize()const
{
    CRectangle::Size size;
    size.width = m_recWidth;
    size.height = m_recHeight;
    return size;
}

void CRectangle::SetRectangleParametrs(RecParam const& recParam)
{
    m_leftX = recParam.leftX;
    m_topY = recParam.topY;
    m_recWidth = recParam.width;
    m_recHeight = recParam.height;
}

RecParam CRectangle::GetParametrs()
{
    RecParam recParam;
    recParam.leftX = m_leftX;
    recParam.topY = m_topY;
    recParam.width = m_recWidth;
    recParam.height = m_recHeight;
    return recParam;
}




void RemoveSpaces(string & strWithBlanks)
{
    strWithBlanks.erase(remove(strWithBlanks.begin(), strWithBlanks.end(), ' '), strWithBlanks.end());
}

CRectangle CreateIntersectRectangle(RecParam & recParam)
{
    CRectangle rectangle;
    rectangle.SetRectangleParametrs(recParam);
    rectangle.CountArea();
    return rectangle;
}

RecParam GetIntersectRecParam(CRectangle const& rectangle1, CRectangle const& rectangle2)
{
    Point leftTopPoint1 = rectangle1.GetLeftTopPoint();
    Point rightBottomPoint1 = rectangle1.GetRightBottomPoint();
    
    Point leftTopPoint2 = rectangle2.GetLeftTopPoint();
    Point rightBottomPoint2 = rectangle2.GetRightBottomPoint();
    
    int interRightX = max(rightBottomPoint1.x, rightBottomPoint2.x);
    int interBottomY = max(rightBottomPoint1.y, rightBottomPoint2.y);
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
    CRectangle::Size size = rectangle.GetSize();
    cout << "\t Size: " << size.width << '*' << size.height << endl;
    Point point1 = rectangle.GetRightBottomPoint();
    cout << "\t Right bottom: (" << point1.x << "; " << point1.y << ")" << endl;
    cout << "\t Area: " << rectangle.CountArea() << endl;
    cout << "\t Perimetr: " << rectangle.CountPerimetr() << endl;
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
    string leftX, topY, width, height;
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

CRectangle CreateRectangle(ifstream & commandsFile)
{
    CRectangle rectangle;
    RecParam recParam = GetRecParam(commandsFile);
    rectangle.SetRectangleParametrs(recParam);
    rectangle.CountArea();
    return rectangle;
}

void ReadCommands(ifstream & commandsFile, CRectangle & rectangle)
{
    string command;
    while(getline(commandsFile, command, ':'))
    {
        if (command == "Rectangle")
        {
            rectangle = CreateRectangle(commandsFile);
        }
        
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
        
        if (command == "Intersect")
        {
            rectangle.Intersect(rectangle);
        }
    }
}

int main(int argc, const char * argv[])
{
    ifstream firstRecFile(argv[1]);
    ifstream secondRecFile(argv[2]);
    
    if(!firstRecFile.is_open() || !secondRecFile.is_open())
    {
        cout << "Can't read one of two commands file" << endl;
        return 1;
    }
    else
    {
        CRectangle rectangle1;
        ReadCommands(firstRecFile, rectangle1);
        
        CRectangle rectangle2;
        ReadCommands(secondRecFile, rectangle2);
        
        CRectangle intersectRectangle;
        if(rectangle1.Intersect(rectangle2))
        {
            RecParam recParam = GetIntersectRecParam(rectangle1, rectangle2);
            intersectRectangle = CreateIntersectRectangle(recParam);
        }
        
        PrintRectangleParam(rectangle1, "Rectangle 1:");
        PrintRectangleParam(rectangle2, "Rectangle 2:");
        PrintRectangleParam(intersectRectangle, "Intersection rectangle:");
    }
    return 0;
}
