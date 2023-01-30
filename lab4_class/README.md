### Разработать указанные классы.
- Можно создать более одного класса, если вы считаете, что это логично для вашей задачи.
- Реализовать необходимые конструкторы.
- Конструкторы копирования/перемещения, операторы присваивания и деструкторы в этом
задании не требуются, т.к. классы не должны напрямую владеть ресурсами (в т.ч.
динамической памятью)
- Реализовать методы доступа к полям (если нужно).
- Реализовать перегруженный оператор &lt;&lt; для вывода информации в поток.
- Классы должны контролировать свои данные и не допускать создания объектов с
некорректным состоянием (можно выбрасывать исключения с помощью throw).
- Некоторые методы можно реализовать в виде перегруженных операторов (если подходят
по смыслу).
- Объявление класса должно быть в заголовочном файле (.h, не забывайте про header guard),
а определения методов в файле реализации (.cpp).
- В main продемонстрировать работу всех(!) написанных методов и конструкторов.

---
3. Разработать класс прямоугольников на координатной плоскости (можно считать, что стороны
прямоугольников параллельны осям координат). Методы для масштабирования
прямоугольника, для перемещения вдоль осей координат, для вычисления площади и
периметра, для определения, пересекаются ли два прямоугольника.