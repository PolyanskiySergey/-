#include <iostream>
#include <vector>
using namespace std;

class inv {
public:
	int num;
	string type;
	string brand;
	inv();
	inv(int, string, string);
	inv(const inv&);
	inv operator= (const inv&);
	inv(inv&&);
	inv& operator= (inv&&);
	~inv();
};

//Конструктор по умолчанию
inv::inv() {
	cout << "Конструктор по умолчанию" << endl;
	this->num = 0;
	this->type = '0';
	this->brand = '0';
}

//Конструктор с параметром
inv::inv(int num, string type, string brand) {
	cout << "Конструктор с параметром" << endl;
	this->num = num;
	this->type = type;
	this->brand = brand;
}

 //Конструктор копирования
inv::inv(const inv & I) {
	cout << "Конструктор копирования" << endl;
	num = I.num+1;
	type = I.type;
	brand = I.brand;
}

//Перегрузка =
inv inv::operator=(const inv& I)
{
	if (this == &I)
		return *this;
	this->num = I.num;
	this->type = I.type;
	this->brand = I.brand;
	return *this;
}


//Конструктор перемещения

inv::inv(inv && I)  { // noexcept
	cout << "Конструктор перемещения" << endl;
	num = I.num;
	type = I.type;
	brand = I.brand;
	I.num = 0;

}
inv& inv::operator=(inv && I)  { //noexcept 
	cout << "work" << endl;
	if (this == &I)
		return *this;
	this->num = I.num;
	this->type = I.type;
	this->brand = I.brand;
	I.num = 0;
	return *this;
}

inv::~inv() {
	cout << "Деструктор" << endl;
}


void search(vector <inv*> I) {
	string newtype;
	cout << "Введите слово: " << endl;
	cin >> newtype;
	for (int i = 0; i < I.size(); ++i) {
		if (newtype == I[i]->type) {
			cout << "Number: " << I[i]->num << " Type: " << I[i]->type << " Brand: " << I[i]->brand << endl;
		}
	}
}
void print(vector <inv*> I) {
	for (int i = 0; i < I.size(); ++i) {
			cout << "Number: " << I[i]->num << " Type: " << I[i]->type << " Brand: " << I[i]->brand << endl;
		}
	}

int main() {
	setlocale(LC_ALL, "Russian");
	vector<inv*> I;
	//Добавление элемента по умолчанию
	inv* newInv0 = new inv();
	I.push_back(newInv0);
	//Добавление элемента с параметром
	inv* newInv1 = new inv(1, "Mouse", "Dell");
	I.push_back(newInv1);
	inv* newInv2 = new inv(2, "Monitor", "Logitech");
	I.push_back(newInv2);
	inv* newInv3 = new inv(3, "Mouse", "Logitech");
	I.push_back(newInv3);
	//Добавление элемента с помощью копирования
	inv* newInv4 = new inv(*newInv3);
	I.push_back(newInv4);
	//Конструктор перемещения
	//inv* newInv5 = new inv();
	inv* newInv5 = move(newInv2);
	I.push_back(newInv5); 
	print(I); 
	search(I);
	
}
