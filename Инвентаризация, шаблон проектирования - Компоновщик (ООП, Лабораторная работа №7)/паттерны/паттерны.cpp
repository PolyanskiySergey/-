#include <iostream>
#include <vector>
using namespace std;

//Родительский класс
class Inventorization
{
public:
    virtual void info() = 0;
};
//Дочерние классы
class Table : public Inventorization
{
public:
    void info() {
        cout << "\tTable" << endl;
    }
};
class Chair : public Inventorization
{
public:
    void info() {
        cout << "\tChair" << endl;
    }
};
class Mouse : public Inventorization
{
public:
    void info() {
        cout << "\tMouse" << endl;
    }
};
class Computer : public Inventorization
{
public:
    void info() {
        cout << "\tComputer" << endl;
    }
};
class Monitor : public Inventorization
{
public:
    void info() {
        cout << "\tMonitor" << endl;
    }
};
//Компоновщик
class Workplace : public Inventorization
{
public:
    vector <Inventorization*> inv;
    void info()
    {
        for (vector <Inventorization*>:: iterator i = inv.begin(); i != inv.end(); ++i) {
            (*i)->info();
        }
    }
    void add(Inventorization* i)
    {
        inv.push_back(i);
    }
};
int main()
{
    //Создаем элементы дочерних классов
    Table* table = new Table();
    Chair* chair = new Chair();
    Mouse* mouse = new Mouse();
    Computer* computer = new Computer();
    Monitor* monitor = new Monitor();
    //Создаем элементы рабочего места
    Workplace* workplace = new Workplace();
    Workplace* furniture = new Workplace();
    Workplace* it = new Workplace();
    //Добавляем виды элементов рабочего стола и элементы в виды
    workplace->add(furniture);
    workplace->add(it);
    furniture->add(table);
    furniture->add(chair);
    it->add(mouse);
    it->add(computer);
    it->add(monitor);
    //Выводим информацию о рабочем месте
    cout <<"Workplace: " << endl;
    workplace->info();
    cout <<"Furniture: " << endl;
    furniture->info();
    cout <<"Computer: " << endl;
    computer->info();
    return 0;
}