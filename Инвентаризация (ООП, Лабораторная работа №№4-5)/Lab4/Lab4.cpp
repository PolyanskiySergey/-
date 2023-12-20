#include <iostream>
#include <vector>
using namespace std;

//Родительский класс Инвентаризация
class Inventorization {
    friend class Workplace;
protected:
    int number;
    double weight;
    string type;
    string color;
    int workplace_number;
public:
    Inventorization();
    ~Inventorization();
    virtual void information() = 0;
    friend void search(vector <Inventorization*> inv);
};

Inventorization::Inventorization() {
    cout << "Object created" << endl;
    this->number = 0;
    this->weight = 0;
    this->type = "";
    this->color = "";
    this->workplace_number = 0;
};

Inventorization::~Inventorization() {
    cout << "Object delete" << endl;
};

void Inventorization::information() {
    cout << "Additional information: "<< endl;
};

void search(vector <Inventorization*> inv) {
    int newn;
    cout << "Введите инв. номер: " << endl;
    cin >> newn;
    for (int i = 0; i < inv.size(); ++i) {
        if (newn == inv[i]->number) {
            inv[i]->information();
        }
    }
};


//Дочерний класс Стол
class Table : public Inventorization
{
public:
    Table();
    Table(int number, double weight, string type, string color,int workplace_number, string shape);
    void information() override;
    string shape;
};

void Table::information() {
    cout << "Номер: " << number << "\tВес: " << weight << " кг\tНазвание: " << type << "\tЦвет:" << color;
    cout << "\tФорма стола: " << shape << endl;
};

Table::Table() {
    cout << "Empty 'Table' object" << endl;
};
Table::Table(int number, double weight, string type, string color, int workplace_number, string shape) {
    cout << "Object 'Table' added" << endl;
    this->number = number;
    this->type = type;
    this->weight = weight;
    this->color = color;
    this->workplace_number = workplace_number;
    this->shape = shape;
};

//Дочерний класс Стул
class Chair : public Inventorization
{
public:
    Chair();
    Chair(int number, double weight, string type, string color, int workplace_number, string adjustment);
    void information() override;
    string adjustment;
};

void Chair::information() {
    cout << "Номер: " << number << "\tВес: " << weight << " кг\tНазвание: " << type << "\tЦвет:" << color;
    cout << "\tРегулировка стула: " << adjustment << endl;
};

Chair::Chair() {
    cout << "Empty 'Chair' object" << endl;
};
Chair::Chair(int number, double weight, string type, string color, int workplace_number, string adjustment) {
    cout << "Object 'Chair' added" << endl;
    this->number = number;
    this->type = type;
    this->weight = weight;
    this->color = color;
    this->workplace_number = workplace_number;
    this->adjustment = adjustment;
};

//Дочерний класс Мышь
class Mouse : public Inventorization
{
public:
    Mouse();
    Mouse(int number, double weight, string type, string color, int workplace_number, int additional_buttons);
    void information() override;
    int additional_buttons;
};

void Mouse::information() {
    cout << "Номер: " << number << "\tВес: " << weight << " кг\tНазвание: " << type << "\tЦвет:" << color;
    cout << "\tКол-во дополнительных кнопок: " << additional_buttons << endl;
};

Mouse::Mouse() {
    cout << "Empty 'Mouse' object" << endl;
};
Mouse::Mouse(int number, double weight, string type, string color, int workplace_number, int additional_buttons) {
    cout << "Object 'Mouse' added" << endl;
    this->number = number;
    this->type = type;
    this->weight = weight;
    this->color = color;
    this->workplace_number = workplace_number;
    this->additional_buttons = additional_buttons;
};

//Дочерний класс Компьютер
class Computer : public Inventorization
{
public:
    Computer();
    Computer(int number, double weight, string type, string color, int workplace_number, string characteristics);
    void information() override;
    string characteristics;
};

void Computer::information() {
    cout << "Номер: " << number << "\tВес: " << weight << " кг\tНазвание: " << type << "\tЦвет:" << color;
    cout << "\tТехнические характеристики: " <<"\t" << characteristics << endl;
};

Computer::Computer() {
    cout << "Empty 'Computer' object" << endl;
};
Computer::Computer(int number, double weight, string type, string color, int workplace_number, string characteristics) {
    cout << "Object 'Computer' added" << endl;
    this->number = number;
    this->type = type;
    this->weight = weight;
    this->color = color;
    this->workplace_number = workplace_number;
    this->characteristics = characteristics;
};

//Дочерний класс Монитор
class Monitor : public Inventorization
{
public:
    Monitor();
    Monitor(int number, double weight, string type, string color, int workplace_number, double diagonal);
    void information() override;
    double diagonal;
};

void Monitor::information() {
    cout << "Номер: " << number << "\tВес: " << weight << " кг\tНазвание: " << type << "\tЦвет:" << color;
    cout << "\tДиагональ монитора: " << diagonal << '"' << endl;
};

Monitor::Monitor() {
    cout << "Empty 'Monitor' object" << endl;
};
Monitor::Monitor(int number, double weight, string type, string color, int workplace_number, double diagonal) {
    cout << "Object 'Monitor' added" << endl;
    this->number = number;
    this->type = type;
    this->weight = weight;
    this->color = color;
    this->workplace_number = workplace_number;
    this->diagonal = diagonal;
};

//Отдельный класс Рабочее место
class Workplace
{
public:
    string name;
    string surname;
    int workplace_number;
    Workplace();
    Workplace(string name, string surname, int workplace_number);
    void info(vector <Inventorization*> inv);
};

void Workplace::info(vector <Inventorization*> inv) {
    cout << "Сотрудник: " << surname << " " << name;
    cout << "\nРабочее место №" << workplace_number << " включает в себя: ";
    for (int i = 0; i < inv.size(); ++i) {
        if (workplace_number == inv[i]->workplace_number) {
            inv[i]->information();
        }
    }
};

Workplace::Workplace() {
    cout << "Empty 'Worker' object" << endl;
    this->name = " ";
    this->surname = "";
    this->workplace_number = 0;
};

Workplace::Workplace(string name, string surname, int workplace_number) {
    cout << "Object 'Worker' added" << endl;
    this->name = name;
    this->surname = surname;
    this->workplace_number = workplace_number;
};


int main()
{
    setlocale(LC_ALL, "Russian");
    //Создание вектора
    vector <Inventorization*> inv;
    //Создание элементов, вывод информации, добавление в вектор
    //1.
    Table table(1, 7, "Стол", "Коричневый", 1, "Круглый");
    table.information();
    inv.push_back(&table);
    //2.
    Chair chair(2, 3, "Стул", "Черный", 1, "Регулировка по высоте");
    chair.information();
    inv.push_back(&chair);
    //3.
    Mouse mouse(3, 0.1, "Мышь", "Черный", 1, 2);
    mouse.information();
    inv.push_back(&mouse);
    //4.
    Computer computer(4, 3, "Компьютер", "Белый", 2, "Процессор AMD Ryzen 5");
    computer.information();
    inv.push_back(&computer);
    //5.
    Monitor monitor(5, 2, "Монитор", "Черный", 2, 20.1);
    monitor.information();
    inv.push_back(&monitor);
    //Обработка исключений
    int n;
    cout << "Введите инв. номер к удалению: " << endl;
    cin >> n;
    n = n - 1;
    try {
        inv.at(n);
        auto iter = inv.begin() + n;
        inv.erase(iter);
    }
    catch (const exception& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }
    //Создание отдельного класса Рабочее место, вывод информаци
    Workplace worker("Сергей", "Полянский", 1);
    worker.info(inv);
    //Поиск по инвентарным обьектам
    search(inv);
    return 0;
};