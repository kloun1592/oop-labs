struct Point
{
    int x;
    int y;
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
    struct Size
    {
        int width;
        int height;
    };
    void Move(int dx, int dy);
    void Scale(int sx, int sy);
    void SetRectangleParametrs(RecParam const& recParam);
    RecParam GetParametrs();
    bool Intersect(CRectangle const& other);
    int CountArea()const;
    int CountPerimetr()const;
    Point GetLeftTopPoint()const;
    Point GetRightBottomPoint()const;
    Size GetSize()const;
private:
    int m_leftX = 0;
    int m_topY = 0;
    int m_recWidth = 0;
    int m_recHeight = 0;
};
