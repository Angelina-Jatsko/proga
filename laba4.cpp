/*Создать базовый класс «Вектор на плоскости». Элементы класса: поля,
задающие координаты точки (статус доступа protected), определяющей конец
вектора (начало вектора находится в точке с координатами 0, 0); конструктор
для инициализации полей; функция для вычисления длины вектора; функция для печати полей и длины вектора. Создать производный класс «Вектор в
трехмерном пространстве». Элементы класса: дополнительное поле, задающее
дополнительную координату; конструктор для инициализации полей;
переопределенная функция для вычисления длины вектора; переопределенная
функция для печати полей и длины вектора. Создать по одному объекту
каждого из классов. Показать вызов созданных функций. При переопределении
функций обеспечить статический полиморфизм, показать его особенности в
программе.*/
#include <iostream>
#include <cmath>

using namespace std;

class Vector2D {
protected:
    double x, y;
public:
    Vector2D(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }
    double length() {
        return sqrt(x * x + y * y);
    }
    virtual void print() {
        cout << "x = " << x << ", y = " << y << ", length = " << length() << endl;
    }
};

class Vector3D : public Vector2D {
protected:
    double z;
public:
    Vector3D(double x = 0, double y = 0, double z = 0) : Vector2D(x, y) {
        this->z = z;
    }
    double length() {
        return sqrt(x * x + y * y + z * z);
    }
    virtual void print() {
        cout << "x = " << x << ", y = " << y << ", z = " << z << ", length = " << length() << endl;
    }
};

int main() {
    Vector2D v2d(3, 4);
    Vector3D v3d(3, 4, 5);
    Vector2D* pv = &v3d;
    v2d.print();
    v3d.print();
    pv->print();
    return 0;
}