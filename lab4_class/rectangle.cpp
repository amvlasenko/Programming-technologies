//
// Created by Александр В on 13.12.2022.
//
#include "Rectangle.h"
#include <math.h>


Rectangle::Rectangle() : x1_(0), y1_(0), x2_(0), y2_(0) {}

Rectangle::Rectangle(double x1, double y1, double x2, double y2) :
        x1_(x1), y1_(y1), x2_(x2), y2_(y2) {}

double Rectangle::getPerimeter() const {
    return 2 * abs((x2_ - x1_) + (y2_ - y1_));
}

double Rectangle::getSquare() const {
    return abs((x2_ - x1_) * (y2_ - y1_));
}

void Rectangle::scale(double coefficient) {
    x1_ *= coefficient;
    x2_ *= coefficient;
    y1_ *= coefficient;
    y2_ *= coefficient;
}

void Rectangle::resizeTop(double y2) { y2_ = y2; }

void Rectangle::resizeRight(double x2) { x2_ = x2; }

void Rectangle::resizeBottom(double y1) { y1_ = y1; }

void Rectangle::resizeLeft(double x1) { x1_ = x1; }

void Rectangle::resizeTopLeft(double x1, double y2) {
    x1_ = x1;
    y2_ = y2;
}

void Rectangle::resizeTopRight(double x2, double y2) {
    x2_ = x2;
    y2_ = y2;
}

void Rectangle::resizeBottomRight(double x2, double y1) {
    x2_ = x2;
    y1_ = y1;
}

void Rectangle::resizeBottomLeft(double x1, double y1) {
    x1_ = x1;
    y1_ = y1;
}

void Rectangle::moveX(double x) {
    x1_ += x;
    x2_ += x;
}

void Rectangle::moveY(double y) {
    y1_ += y;
    y2_ += y;
}

void Rectangle::moveXY(double x, double y) {
    x1_ += x;
    x2_ += x;
    y1_ += y;
    y2_ += y;
}

double Rectangle::getX1() const { return x1_; }

double Rectangle::getY1() const { return y1_; }

double Rectangle::getX2() const { return x2_; }

double Rectangle::getY2() const { return y2_; }

bool Rectangle::isCrossing(const Rectangle &r) const {
    const bool yCrossing = y2_ < r.y1_ || y1_ > r.y2_;
    const bool xCrossing = x2_ < r.x1_ || x1_ > r.x2_;
    return !(yCrossing || xCrossing);
}

std::ostream &operator<<(std::ostream &os, const Rectangle &r) {
    os << "x1: " << r.x1_ << ", y1: " << r.y1_ << ", x2: " << r.x2_ << ", y2: " << r.y2_;
    return os;
}