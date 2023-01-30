#include <iostream>
#include "rectangle.h"

int main() {
    Rectangle rec1(0, 1, 3, 8);
    Rectangle rec2(-2, 3, 4, 6);
    std::cout << "Периметр: " << rec1.getPerimeter() << std::endl;
    std::cout << "Площадь: " << rec1.getSquare() << std::endl;
    rec1.scale(0.5);
    std::cout << "Периметр после масштабирования: " << rec1.getPerimeter() << std::endl;
    std::cout << "Площадь после масштабирования: : " << rec1.getSquare() << std::endl;
    rec1.resizeLeft(2);
    std::cout << "Периметр после ресайза: " << rec1.getPerimeter() << std::endl;
    std::cout << "Площадь после ресайза: " << rec1.getSquare() << std::endl;
    std::cout << "Пересечение: "
              << rec1.isCrossing(rec2)
              << std::endl;
    rec2.moveX(10);
    std::cout << "Пересечение после перемещения: "
              << rec1.isCrossing(rec2)
              << std::endl;
    std::cout << "rec1: " << rec1 << std::endl;

    return 0;
}
