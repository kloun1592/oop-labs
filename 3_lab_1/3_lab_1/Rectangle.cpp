#include "Rectangle.h"

CRectangle::CRectangle(int leftX, int topY, int width, int height)
    : m_leftX(leftX)
    , m_topY(topY)
    , m_width(width)
    , m_height(height)
{
}

int CRectangle::CalculateArea()const
{
    return m_width * m_height;
};

int CRectangle::CalculatePerimeter()const
{
    return 2 * (m_width + m_height);
};

Point CRectangle::GetRightBottomPoint()const
{
    Point point;
    point.x = m_leftX + m_width;
    point.y = m_topY + m_height;
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
    m_width *= sx;
    m_height *= sy;
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
        m_width = m_height = 0;
        return false;
    }
}

Size CRectangle::GetSize()const
{
    Size size;
    size.width = m_width;
    size.height = m_height;
    return size;
}
