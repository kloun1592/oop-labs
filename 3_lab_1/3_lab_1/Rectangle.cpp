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
    int otherRec_leftX = other.GetLeftTopPoint().x;
    int otherRec_topY = other.GetLeftTopPoint().y;
    int otherRec_rightX = other.GetRightBottomPoint().x;
    int otherRec_bottomY = other.GetRightBottomPoint().y;

    if (m_leftX < otherRec_rightX &&
        GetRightBottomPoint().x > otherRec_leftX &&
        m_topY < otherRec_bottomY &&
        GetRightBottomPoint().y > otherRec_topY)
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
