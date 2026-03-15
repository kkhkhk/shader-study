#include <vector>

using namespace std;

struct Point
{
    double x, y;
};

class Shape
{
public:
    virtual Point center() const = 0; // pure virtual
    virtual void move(Point to) = 0;

    virtual void draw() const = 0;    // draw on current "Canvas"
    virtual void rotate(int angle) = 0;

    virtual ~Shape() {}               // destructor
};

void rotate_all(vector<Shape*>& v, int angle) // rotate v's elements by angle degrees
{
    for (auto p : v)
        p->rotate(angle);
}

class Circle : public Shape
{
private:
    Point c; // center
    int r;   // radius

public:
    Circle(Point p, int rr); // constructor

    Point center() const { return c; }
    void move(Point to) { c = to; }

    void draw() const;
    void rotate(int) {}
};


