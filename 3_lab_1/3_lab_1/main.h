class CRectangle
{
public:
    struct Point
    {
        int x;
        int y;
    };
    struct Size
    {
        int width;
        int heigth;
    };
    void Move(int dx, int dy);
    void Scale(int sx, int sy);
    void SetRectangleParametrs(std::ifstream & commandsFile);
    bool Intersect(CRectangle const& other);
    int CountArea()const;
    int CountPerimetr()const;
    int SetBottomY()const;
    int SetRightX()const;
    Point GetLeftTopPoint()const;
    Point GetRightBottomPoint()const;
    Size GetSize()const;
private:
    int m_leftX = 0;
    int m_topY = 0;
    int m_recWidth = 0;
    int m_recHeight = 0;
};
