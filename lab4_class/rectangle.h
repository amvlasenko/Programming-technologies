//
// Created by Александр В on 13.12.2022.
//

#ifndef LAB4_CLASS_RECTANGLE_H
#define LAB4_CLASS_RECTANGLE_H

#include <iostream>

class Rectangle {
public:
    Rectangle();

    Rectangle(double x1, double y1, double x2, double y2);

    double getPerimeter() const;

    double getSquare() const;

//    Масштабируемый коэффициент

    void scale(double coefficient);

    void resizeTop(double y2);

    void resizeRight(double x2);

    void resizeBottom(double y1);

    void resizeLeft(double x1);

    void resizeTopLeft(double x1, double y2);

    void resizeTopRight(double x2, double y2);

    void resizeBottomRight(double x2, double y1);

    void resizeBottomLeft(double x1, double y1);

    void moveX(double x);

    void moveY(double x);

    void moveXY(double x, double y);

    double getX1() const;

    double getY1() const;

    double getX2() const;

    double getY2() const;

//    Параметром должен быть прямоугольник
    bool isCrossing(const Rectangle &r) const;

    friend std::ostream &operator<<(std::ostream &os, const Rectangle &r);

private:
    double x1_;
    double y1_;
    double x2_;
    double y2_;
};

#endif //LAB4_CLASS_RECTANGLE_H
