/*Класс "Прямоугольный параллелепипед".Создать объект класса, моделирующий параллелепипед, сделанный из пластмассы, 
с параметрами : а, b - стороны прямоугольника - основания, H - высота параллелепипеда.Вычислить полную поверхность
и объем исходного объекта и нового объекта, полученного удвоением параметров исходного параллелепипеда.*/

#include <iostream>

using namespace std;

class Parallelepiped {
private:
    int a;
    int b;
    int h;

public:
    Parallelepiped(int a, int b, int h) {
        this->a = a;
        this->b = b;
        this->h = h;
    }

    int getA() const {
        return a;
    }

    int getB() const {
        return b;
    }

    int getH() const {
        return h;
    }

    int volume() const {
        return a * b * h;
    }

    int surfaceArea() const {
        return 2 * (a * b + a * h + b * h);
    }
};

int main() {
    Parallelepiped p(3, 4, 5);
    cout << "Initial Parallelepiped - Volume: " << p.volume() << ", Surface Area: " << p.surfaceArea() << endl;

    Parallelepiped p2(2 * p.getA(), 2 * p.getB(), 2 * p.getH());
    cout << "Doubled Parallelepiped - Volume: " << p2.volume() << ", Surface Area: " << p2.surfaceArea() << endl;

    return 0;
}
