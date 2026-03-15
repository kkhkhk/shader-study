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

class Smiley : public Circle // use the circle as the base for a face
{
private:
    vector<Shape *> eyes;
    Shape *mouth;

public:
    Smiley(Point p, int r) : Circle{p, r}, mouth{nullptr} {}

    ~Smiley()
    {
        delete mouth;
        for (auto p : eyes)
            delete p;
    }

    void move(Point to) override;

    void draw() const override;
    void rotate(int) override;

    void add_eye(Shape *s) { eyes.push_back(s); }
    void set_mouth(Shape *s);
    virtual void wink(int i);       // wink eye number i 

    // ...
};

void Smiley::draw() const
{
    Circle::draw();
    for (auto p : eyes)
        p->draw();
    mouth->draw();
}