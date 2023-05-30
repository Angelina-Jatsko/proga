/*Разработать класс Date для работы с датами; В классе должно быть
три поля: год, месяц и день. Для представления месяцев определить в классе
перечислимый тип month. Перегрузить операцию operator+ для вычисления
даты через заданное количество дней. Перегрузить операции инкремента
operator++ и декремента operator-- для вычисления следующей и предыдущей
дат.*/
#include <iostream>
#include <string>

class Date {
public:
    enum Month { january = 1, february, march, april, may, june, july, august, september, october, november, december };
    Date(int y, Month m, int d) : year(y), month(m), day(d) {}

    void addDays(int n);
    void printDate() const;

    Date& operator++();
    Date& operator--();
    Date operator+(int n) const;

private:
    int year;
    Month month;
    int day;
};

Date Date::operator+(int n) const {
    Date res(*this);
    res.addDays(n);
    return res;
}

Date& Date::operator++() {
    addDays(1);
    return *this;
}

Date& Date::operator--() {
    addDays(-1);
    return *this;
}

void Date::printDate() const {
    std::cout << year << " " << month << " " << day << '\n';
}

void Date::addDays(int n) {
    bool added_day;
    if (n > 0) {
        added_day = true;
    }
    else {
        added_day = false;
        n = -n;
    }

    while (n > 0) {
        int days_in_month;
        switch (month) {
        case january: case march: case may: case july: case august: case october: case december:
            days_in_month = 31;
            break;
        case april: case june: case september: case november:
            days_in_month = 30;
            break;
        case february:
            days_in_month = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
            break;
        }

        if (added_day) {
            day++;
            if (day > days_in_month) {
                day = 1;
                month = static_cast<Date::Month>((month % 12) + 1);
                if (month == january) {
                    year++;
                }
            }
        }
        else {
            day--;
            if (day < 1) {
                month = static_cast<Date::Month>((month + 10) % 12 + 1);
                if (month == december) {
                    year--;
                }
                day = 31;
                if (month == april || month == june || month == september || month == november) {
                    day = 30;
                }
                else if (month == february) {
                    day = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
                }
            }
        }
        n--;
    }
}

int main() {
    Date d(2021, Date::january, 1);
    d.printDate();

    d = d + 100;
    d.printDate();

    ++d;
    d.printDate();

    --d;
    d.printDate();

    return 0;
}