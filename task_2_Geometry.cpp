#include <iostream>
#include <cassert>

enum Color
{
    black = 1,
    white,
    green,
    red,
    blue,
    none
};

Color TextToColor(std::string user_color)
{
    if(user_color == "black") return Color::black;
    if(user_color == "white") return Color::white;
    if(user_color == "green") return Color::green;
    if(user_color == "red") return Color::red;
    if(user_color == "blue") return Color::blue;
    else return Color::none;
}

std::string ColorToText(Color color)
{
    if(color == Color::black ) return "black";
    if(color == Color::white ) return "white";
    if(color == Color::green ) return "green";
    if(color == Color::red ) return "red";
    if(color == Color::blue ) return "blue";
    else return "none";
}

class Figure
{
private:
    double start_point[2] = {0, 0};
    double end_point[2] = {0, 0};
    Color color = black;
public:
    Figure()
    {
        std::cout << "\nFigure Super Class generated" << std::endl;
    }

    Color getColor()
    {
        return color;
    }

    void setColor()
    {
        std::string user_color;
        std::cout << "Input circle color:";
        std::cin >> user_color;
        bool flag_for_color_match = false;

        while (!flag_for_color_match)
        {
            for(int i = 1; i <= Color::blue; i++)
            {
                if(TextToColor(user_color) >= Color::black &&
                   TextToColor(user_color) <= Color::blue)
                {
                    flag_for_color_match = true;
                    this->color = (TextToColor(user_color));
                }
                else
                {
                    std::cout << "Error. Input circle color:";
                    std::cin >> user_color;
                }
            }
        }
    }

    void setStartPoint()
    {
        std::cout << "Input coordinates for down left corner\nx:";
        double tmp;
        std::cin >> tmp;
        start_point[0] = tmp;
        std::cout << "y:";
        std::cin >> tmp;
        start_point[1] = tmp;
    }

   double getStartPoint(int index)
    {
        return start_point[index];
    }

};

class Circle: public Figure
{
private:
    double radius = 1.f;
public:
    Circle()
    {
        std::cout << ColorToText(this->getColor()) << " Circle generated"
        << " with radius " << this->radius << std::endl << std::endl;

        std::cout << "Input circle radius:";
        double user_radius;
        std::cin >> user_radius;
        this->radius = user_radius;
        while(user_radius < 0.f)
        {
            std::cout << "Edges can't be less than 0. Input triangle edge\n:";
            std::cin >> user_radius;
        }
        this->radius = user_radius;

        setStartPoint();
        setColor();
    }

    void getInfo()
    {
        const double Pi = 3.1415;
        double result = 0;
        std::cout << "Circle color is: " << ColorToText(this->getColor()) << std::endl;
        std::cout << "Circle figure area = " <<  Pi * pow(this->radius, 2) << std::endl;
        std::cout << "Edge of the square around circle is = " << this->radius * 2 << std::endl;
        std::cout << "Start_point: " << getStartPoint(0) << "  " << getStartPoint(1) << std::endl
                  << "End_point  : " << getStartPoint(0) + this->radius * 2
                  << "  " << getStartPoint(1) + this->radius * 2 << std::endl;
    }
};

class Square: public Figure
{
private:
    double edge = 1;
public:
    Square()
    {
        std::cout << ColorToText(this->getColor()) << " Square generated"
                  << " with edges " << this->edge << std::endl << std::endl;

        std::cout << "Input square edge:";
        double user_edge;
        std::cin >> user_edge;
        this->edge = user_edge;
        while(user_edge < 0.f)
        {
            std::cout << "Edges can't be less than 0. Input triangle edge\n:";
            std::cin >> user_edge;
        }
        this->edge = user_edge;

        setStartPoint();
        setColor();
    }

    void getInfo()
    {
        std::cout << "Square color is: " << ColorToText(this->getColor()) << std::endl;
        std::cout << "Square figure area = " <<  pow(this->edge, 2) << std::endl;
        std::cout << "Start_point: " << getStartPoint(0) << "  " << getStartPoint(1) << std::endl
                  << "End_point  : " << getStartPoint(0) + this->edge << "  " << getStartPoint(1) + this->edge
                  << std::endl;
    }
};

class Triangle: public Figure
{
private:
    double edge = 1;
public:
    Triangle()
    {
        std::cout << ColorToText(this->getColor()) << " Triangle generated"
                  << " with edges " << this->edge << std::endl << std::endl;

        std::cout << "Input triangle edge:";
        double user_edge;
        std::cin >> user_edge;
        while(user_edge < 0.f)
        {
            std::cout << "Edges can't be less than 0. Input triangle edge\n:";
            std::cin >> user_edge;
        }
        this->edge = user_edge;

        this->setStartPoint();
        this->setColor();
    }

    void getInfo()
    {
        std::cout << "Triangle color is: " << ColorToText(this->getColor()) << std::endl;
        std::cout << "Triangle figure area = " << (cbrt(3)/4) * pow(this->edge, 2) << std::endl;
        std::cout << "Edge of the square around square is = " << this->edge << std::endl;
        std::cout << "Start_point: " << getStartPoint(0) << "  " << getStartPoint(1) << std::endl
                  << "End_point  : " << getStartPoint(0) + this->edge
                  << "  " << getStartPoint(1) + ((cbrt(3)/2) * this->edge)
                  << std::endl;
    }
};

class Rectangle: public Figure
{
private:
    double edge_vertical = 1;
    double edge_horizontal = 2;
public:
    Rectangle()
    {
        std::cout << ColorToText(this->getColor()) << " Rectangle generated"
                  << " with edges " << this->edge_horizontal << " " << this->edge_vertical << std::endl << std::endl;

        std::cout << "Input rectangle edge horizontal:";
        double user_edge;
        std::cin >> user_edge;
        while(user_edge < 0.f)
        {
            std::cout << "Edges can't be equal or less than 0. Input rectangle edge vertical\n:";
            std::cin >> user_edge;
        }
        this->edge_horizontal = user_edge;

        std::cout << "Input rectangle edge vertical:";
        std::cin >> user_edge;
        while(user_edge == this->edge_horizontal || user_edge < 0.f)
        {
            std::cout << "Edges can't be equal or less than 0. Input rectangle edge vertical\n:";
            std::cin >> user_edge;
        }
        this->edge_vertical = user_edge;

        setStartPoint();
        setColor();
    }

    void getInfo()
    {
        std::cout << "Rectangle color is: " << ColorToText(this->getColor()) << std::endl;
        std::cout << "Rectangle figure area = " <<  this->edge_horizontal * this->edge_vertical << std::endl;
        std::cout << "Start_point: " << getStartPoint(0) << "  " << getStartPoint(1) << std::endl
                  << "End_point  : " << getStartPoint(0) + this->edge_horizontal
                  << "  " << getStartPoint(1) + this->edge_vertical << std::endl;
    }
};

int main()
{
    std::string user_input = "qwerty";
    std::cout << "Type figure's name\ncircle / square / triangle / rectangle: ";
    std::cin >> user_input;

    if(user_input == "circle")
    {
        Circle* circle = new Circle();
        std::cout << std::endl << "RESULT:" << std::endl;
        circle->getInfo();
        delete circle;
    }

    if(user_input == "square")
    {
        Square* square = new Square();
        std::cout << std::endl << "RESULT:" << std::endl;
        square->getInfo();
        delete square;
    }

    if(user_input == "triangle")
    {
        Triangle* triangle = new Triangle();
        std::cout << std::endl << "RESULT:" << std::endl;
        triangle->getInfo();
        delete triangle;
    }

    if(user_input == "rectangle")
    {
        Rectangle* rectangle = new Rectangle();
        std::cout << std::endl << "RESULT:" << std::endl;
        rectangle->getInfo();
        delete rectangle;
    }


    return 0;
}

