#include <iostream>
#include <string>
#include <vector>
using namespace std;




class people {
private:
    string name;

public:
    people(const string & name = "") : name(name) {}

        people(const people& other) {
            name = other.name;
    }

    people& operator=(const people& other) {
        if (this != &other) {
            name = other.name;
        }
        return *this;
    }

    void Вивести() const {
        cout << "people: " << name << endl;
    }

    ~people() {}
};

class Квартира {
private:
    people* мешканці;
    size_t кількість;

public:
    Квартира(size_t кількість = 0) : кількість(кількість) {
        мешканці = new people[кількість];
    }

    Квартира(const Квартира& other) : кількість(other.кількість) {
        мешканці = new people[кількість];
        for (size_t i = 0; i < кількість; ++i) {
            мешканці[i] = other.мешканці[i];
        }
    }

    Квартира& operator=(const Квартира& other) {
        if (this != &other) {
            delete[] мешканці;

            кількість = other.кількість;
            мешканці = new people[кількість];
            for (size_t i = 0; i < кількість; ++i) {
                мешканці[i] = other.мешканці[i];
            }
        }
        return *this;
    }

    void ДодатиМешканця(const people& people, size_t індекс) {
        if (індекс < кількість) {
            мешканці[індекс] = people;
        }
    }

    void Вивести() const {
        cout << "Квартира з " << кількість << " мешканцями:" << endl;
        for (size_t i = 0; i < кількість; ++i) {
            мешканці[i].Вивести();
        }
    }

    ~Квартира() {
        delete[] мешканці;
    }
};


class Дім {
private:
    Квартира* квартири;
    size_t кількість;

public:
    Дім(size_t кількість = 0) : кількість(кількість) {
        квартири = new Квартира[кількість];
    }

    Дім(const Дім& other) : кількість(other.кількість) {
        квартири = new Квартира[кількість];
        for (size_t i = 0; i < кількість; ++i) {
            квартири[i] = other.квартири[i];
        }
    }

    Дім& operator=(const Дім& other) {
        if (this != &other) {
            delete[] квартири;

            кількість = other.кількість;
            квартири = new Квартира[кількість];
            for (size_t i = 0; i < кількість; ++i) {
                квартири[i] = other.квартири[i];
            }
        }
        return *this;
    }

    void ДодатиКвартиру(const Квартира& квартира, size_t індекс) {
        if (індекс < кількість) {
            квартири[індекс] = квартира;
        }
    }

    void Вивести() const {
        cout << "Дім з " << кількість << " квартирами:" << endl;
        for (size_t i = 0; i < кількість; ++i) {
            cout << "Квартира " << i + 1 << ":" << endl;
            квартири[i].Вивести();
        }
    }

    ~Дім() {
        delete[] квартири;
    }
};

int main() {
    people people1("Данило");
    people people2("Саша");
    people people3("Іван");
    Квартира квартира1(2);
    квартира1.ДодатиМешканця(people1, 0);
    квартира1.ДодатиМешканця(people2, 1);
    Квартира квартира2(1);
    квартира2.ДодатиМешканця(people3, 0);
    Дім дім(2);
    дім.ДодатиКвартиру(квартира1, 0);
    дім.ДодатиКвартиру(квартира2, 1);
    дім.Вивести();
    return 0;
}
