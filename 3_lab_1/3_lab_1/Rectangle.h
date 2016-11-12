struct Point
{
    int x;
    int y;
};

struct Size
{
    int width;
    int height;
};

struct RecParam
{
    int leftX;
    int topY;
    int width;
    int height;
};

class CRectangle
{
public:
    CRectangle(int leftX, int topY, int width, int height);
    void Move(int dx, int dy);
    void Scale(int sx, int sy);
    bool Intersect(CRectangle const& other);
    RecParam GetIntersectRecParam(CRectangle const& rectangle2);
    int CalculateArea()const;
    int CalculatePerimeter()const;
    Point GetLeftTopPoint()const;
    Point GetRightBottomPoint()const;
    Size GetSize()const;
private:
    int m_leftX = 0;
    int m_topY = 0;
    int m_width = 0;
    int m_height = 0;
};
