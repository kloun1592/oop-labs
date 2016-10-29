#include <iostream>
#include <fstream>
#include <string>
#include "main.h"

using namespace std;

struct Point
{
    int x;
    int y;
};

void RemoveSpaces(string & strWithBlanks)
{
    strWithBlanks.erase(remove(strWithBlanks.begin(), strWithBlanks.end(), ' '), strWithBlanks.end());
}

void PrintRectangleParam(CRectangle & rectangle)
{
    cout << "Rectangle:" << endl;
    CRectangle::Point point = rectangle.GetLeftTopPoint();
    cout << "\t Left Top: (" << point.x << "; " << point.y << ")" << endl;
    CRectangle::Size size = rectangle.GetSize();
    cout << "\t Size: " << size.width << '*' << size.heigth << endl;
    CRectangle::Point point1 = rectangle.GetRightBottomPoint();
    cout << "\t Right bottom: (" << point1.x << "; " << point1.y << ")" << endl;
    cout << "\t Area: " << rectangle.CountArea() << endl;
    cout << "\t Perimetr: " << rectangle.CountPerimetr() << endl;
}

int CRectangle::CountArea()const
{
    return m_recWidth * m_recHeight;
}

int CRectangle::CountPerimetr()const
{
    return 2 * (m_recWidth + m_recHeight);
}

int CRectangle::SetBottomY() const
{
    return m_topY + m_recHeight;
}

int CRectangle::SetRightX() const
{
    return m_leftX + m_recWidth;
}

CRectangle::Point CRectangle::GetRightBottomPoint()const
{
    CRectangle::Point point;
    point.x = this->SetRightX();
    point.y = this->SetBottomY();
    return point;
}

CRectangle::Point CRectangle::GetLeftTopPoint()const
{
    CRectangle::Point point;
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
    if (CRectangle::SetBottomY() > LeftTopPointOfSecondRec.y || m_topY < RightBottomPointOfSecondRec.y || m_leftX > RightBottomPointOfSecondRec.x || CRectangle::SetRightX() < LeftTopPointOfSecondRec.x)
    {
        return false;
    }
    else
    {
        m_recWidth, m_recHeight = 0;
        return true;
    }
}

CRectangle::Size CRectangle::GetSize()const
{
    CRectangle::Size size;
    size.width = m_recWidth;
    size.heigth = m_recHeight;
    return size;
}

CRectangle CreateRectangle(ifstream & commandsFile)
{
    CRectangle rectangle;
    rectangle.SetRectangleParametrs(commandsFile);
    rectangle.CountArea();
    return rectangle;
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

void CRectangle::SetRectangleParametrs(ifstream & commandsFile)
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
    m_leftX = stoi(leftX);
    m_topY = stoi(topY);
    m_recWidth = stoi(width);
    m_recHeight = stoi(height);
}

void ReadCommands(ifstream & commandsFile, CRectangle & rectangle1)
{
    string command;
    while(getline(commandsFile, command, ':'))
    {
        if (command == "Rectangle")
        {
            rectangle1 = CreateRectangle(commandsFile);
        }
        
        if (command == "Move")
        {
            Point coordinates = GetMoveOrScaleParam(commandsFile);
            rectangle1.Move(coordinates.x, coordinates.y);
        }
        
        if (command == "Scale")
        {
            Point coordinates = GetMoveOrScaleParam(commandsFile);
            rectangle1.Scale(coordinates.x, coordinates.y);
        }
    }
}

int main(int argc, const char * argv[])
{
    ifstream commandsFile(argv[1]);
    if(!commandsFile.is_open())
    {
        cout << "Can't read file" << endl;
    }
    else
    {
        CRectangle rectangle1;
        ReadCommands(commandsFile, rectangle1);
        rectangle1.Intersect(rectangle1);
        PrintRectangleParam(rectangle1);
    }
    return 0;
}
