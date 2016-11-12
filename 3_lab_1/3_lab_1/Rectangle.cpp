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
}

int CRectangle::CalculatePerimeter()const
{
    return 2 * (m_width + m_height);
}

Point CRectangle::GetRightBottomPoint()const
{
    return { m_leftX + m_width, m_topY + m_height };
}

Point CRectangle::GetLeftTopPoint()const
{
    return { m_leftX, m_topY };
}

void CRectangle::Move(int dx, int dy)
{
    m_leftX += dx;
    m_topY += dy;
}

void CRectangle::Scale(int sx, int sy)
{
    if (sx < 0 || sy < 0)
    {
        sx = sy = 0;
    }
    m_width *= sx;
    m_height *= sy;
}

bool CRectangle::Intersect(CRectangle const& other)
{
    int SecRec_leftX = other.GetLeftTopPoint().x;
    int SecRec_topY = other.GetLeftTopPoint().y;
    int SecRec_rightX = other.GetRightBottomPoint().x;
    int SecRec_bottomY = other.GetRightBottomPoint().y;

    if (m_leftX < SecRec_rightX &&
        GetRightBottomPoint().x > SecRec_leftX &&
        m_topY < SecRec_bottomY &&
        GetRightBottomPoint().y > SecRec_topY)
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
    return { m_width, m_height };
}
