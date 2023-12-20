//Чтение, запись и преобразование сообщений из разных источников 
#include <iostream>
#include <string>
#include <vector>
#define message_file "123;456;789;24651981;864;1351581;975;"
#define message_uart "D some errors..."
#define message_usb "123;456;789;"
using namespace std;

class action {
protected:
	virtual void initiate() = 0;
};

class reading : public action {
public:
	void initiate() override{
		cout << "Чтение инициализировано" << endl;
	}
	string file() {
		cout << "Чтение из файла: " << message_file << endl;
		return message_file;
	}
	string uart() {
		if (message_uart[0] == 'D') {
			cout << "Чтение отладочного сообщения UART: " << message_uart << endl;
		}
		else {
			if (message_uart[0] == 'I') {
				cout << "Чтение информационного сообщения UART: " << message_uart << endl;
			}
			else {
				cout << "Характер сообщения UART не определен, сообщение: " << message_uart << endl;
			}
		}
		return message_uart;
	}
	string usb() {
		cout << "Чтение USB: " << message_usb << endl;
		return message_usb;
	}
};
class recording : public action {
public:
	void initiate() override {
		cout << "Запись инициализирована" << endl;
	}
	void file(string S) {
		getline(cin, S);
		cout << "Запись в файл: " << S << endl;
	}
	void uart(string S) {
		getline(cin, S);
		cout << "Запись в UART: " << S << endl;
	}
	void usb(string S) {
		getline(cin, S);
		cout << "Запись на USB: " << S << endl;
	}
};
class separation {
private:
	int a;
public:
	int d;
	int size=0;
	int count = 0;
	void reader(string str, vector <int> dig){
		int d = 0;
		size = (int)str.size();
		for (int i = 0; i < size; i++) {
			if (str[i] == ';') {
				a = stoi(str.substr(d, i));
				dig.push_back(a);
				cout << "Digit №" << count + 1 << " is " << dig[count] << endl;
				count++;
					d = i + 1;
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	vector <int> dig;
	reading read;
	read.initiate();
	recording rec;
	rec.initiate();
	separation sep;
	sep.reader(read.file(), dig);
	read.uart();
	string S;
	rec.usb(S);
	return 0;
}

/*
1. Убрали все 'std::' подключили 'using namespace std'
2. Изменили имена по шаблону 'word_word', регистр изменен на правильный, улучшена читаемость кода
3. Добавлена переопределяемая функция 'initiate'
4. Табуляция расставлена автоматически)
5. Добавлена масштабируемость кода в блоке separation, уменьшена длина кода
6. В блоке recording добавлена возможность ввода строки с пробелами, предложения
7. Применены принципы S.O.L.I.D.
*/
