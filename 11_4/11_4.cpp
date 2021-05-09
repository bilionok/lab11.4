// Звітна відомість результатів екзаменаційної сесії студентської групи для кожного
// студента містить прізвище, ініціали і оцінки з п’яти предметів.
// Скласти програму, за допомогою якої можна коректувати список(добавляти,
// вилучати, редагувати інформацію) і отримувати :

//  список всіх студентів;
//  список студентів, що склали іспити тільки на «5»;
//  список студентів, що мають трійки;
//  список студентів, що мають двійки.При цьому студент, що має більш ніж одну
// двійку, виключається із списку.



#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Rep // Звіт 
{
	char surname[100]; // прізвище
	char init[100]; // ініціали
	double fiz; // оцінки з 5 предметів
	double math;
	double prog;
	double web;
	double elect;
};

void Create(char* fname);
void Print(char* fname);
void EditFile(char* fname, const char* gname);
void AddStud(char* fname, const char* gname);
void EditStudent(char* fname);
void DelStudent(char* fname, const char* gname);
void StudMax(char* fname);
bool StudThree(char* fname);
void StudTwo(char* fname);

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	char ch;
	string store;
	char fname[100];
	char gname[100];
	do
	{
		cout << endl;
		cout << "Зробіть вибір:" << endl;
		cout << "[1] - запис даних у файл" << endl;
		cout << "[2] - зміна даних" << endl;
		cout << "[3] - список всіх студентів;" << endl;
		cout << "[4] - список студентів, що склали іспити тільки на «5»;" << endl;
		cout << "[5] - список студентів, що мають трійки;" << endl;
		cout << "[6] - список студентів, що мають одну двійку;" << endl << endl;

		cout << "[0] - завершення роботи." << endl << endl;
		cout << "Ваш вибір: "; cin >> ch;
		switch (ch)
		{
		case '0':
			break;
		case '1':
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << endl;
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			Create(fname);
			break;
		case '2':
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << endl;
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			cout << "Введіть назву допоміжного файлу: "; cin.getline(gname, sizeof(gname));
			cout << endl;
			EditFile(fname, gname);
			cout << endl;
			break;
		case '3':
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << endl;
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			Print(fname);
			break;
		case '4':
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << endl;
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			cout << "Студенти, що склали всі екзамени на макс. бал: " << endl;
			StudMax(fname);
			break;
		case '5':
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << endl;
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			cout << "Студенти, що мають хоча б одну трійку: " << endl;
			StudThree(fname);
			break;
		case '6':
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << endl;
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			cout << "Студенти, що мають одну двійку: " << endl;
			StudTwo(fname);
			break;
		default:
			cout << "Помилка вводу! ";
		}
	} while (ch != '0');
	return 0;
}

void Create(char* fname) // створення файлу з введених рядків
{
	ofstream fout(fname, ios::binary); // відкрили файл для запису
	char ch; // відповідь користувача – чи продовжувати введення
	Rep p;
	do {
		cout << endl;
		cout << "Прізвище студента: "; cin >> p.surname;
		cout << "Ініціали: "; cin >> p.init;
		cout << "Оцінка з Фізики: "; cin >> p.fiz;
		if (p.fiz > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p.fiz = 5;
		}
		if (p.fiz < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p.fiz = 0;
		}
		cout << "Оцінка з Математики: "; cin >> p.math;
		if (p.math > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p.math = 5;
		}
		if (p.math < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p.math = 0;
		}
		cout << "Оцінка з Програмування: "; cin >> p.prog;
		if (p.prog > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p.prog = 5;
		}
		if (p.prog < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p.prog = 0;
		}
		cout << "Оцінка з Веб - дизайну: "; cin >> p.web;
		if (p.web > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p.web = 5;
		}
		if (p.web < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p.web = 0;
		}
		cout << "Оцінка з Електромеханіки: "; cin >> p.elect;
		if (p.elect > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p.elect = 5;
		}
		if (p.elect < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p.elect = 0;
		}
		if (!fout.write((char*)&p, sizeof(Rep)))
		{
			cerr << "Помилка запису у файл." << endl;
		}
		cout << "Продовжити? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
	fout.close();
}

void Print(char* fname) // виведення файлу на екран
{
	ifstream fin(fname, ios::binary); // відкрили файл для зчитування
	if (fin.fail())
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Rep p;
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int i = 0;
	while (fin.read((char*)&p, sizeof(Rep)))
	{
		cout << "|" << setw(3) << ++i << setw(3) << "|";
		cout << setw(6) << p.surname << setw(7) << "|";
		cout << setw(6) << p.init << setw(7) << "|";
		cout << setw(5) << p.fiz << setw(6) << "|";
		cout << setw(7) << p.math << setw(8) << "|";
		cout << setw(9) << p.prog << setw(9) << "|";
		cout << setw(8) << p.web << setw(9) << "|";
		cout << setw(10) << p.elect << setw(10) << "|";
		cout << endl;
	}
	cout << "=================================================================================================================="
		<< endl;
	cout << endl;
	fin.close();
}

void EditFile(char* fname, const char* gname) {
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Помилка відкриття файлу '" << fname << "'" << endl;
		f.close();
		return;
	}
	char ch;
	f.seekg(0, ios::end);
	int size = f.tellg();
	size = size / sizeof(Rep);
	f.seekg(0, ios::beg);
	cout << endl;
	cout << "Кількість студентів у списку: " << size << endl << endl;
	cout << "[1] - добавити нового студента" << endl;
	cout << "[2] - редагувати інформацію про студента" << endl;
	cout << "[3] - вилучити інформацію про студента" << endl << endl;

	cout << "[0] - повернутись назад" << endl << endl;
	cout << "Ваш вибір: "; cin >> ch;
	switch (ch) {
	case '0':
		return;
		break;
	case '1':
		AddStud(fname, gname);
		break;
	case '2':
		EditStudent(fname);
		break;
	case '3':
		DelStudent(fname, gname);
		cout << "Інформація про студента видалена!" << endl;
		break;
	default:
		cout << "Помилка вводу!" << endl;
	}
}

void AddStud(char* fname, const char* gname) {
	ifstream f(fname, ios::binary);
	f.seekg(0, ios::end);
	int size = f.tellg();
	size = size / sizeof(Rep);
	f.seekg(0, ios::beg);
	ofstream g(gname, ios::binary);
	cout << endl;
	Rep p;
	int k = 0;
	while (k < size) {
		f.read((char*)&p, sizeof(Rep));
		g.write((char*)&p, sizeof(Rep)); // запис всього у допоміжний файл
		k++;
	}
	cout << endl; // запис про нового студента
	cout << "Прізвище студента: "; cin >> p.surname;
	cout << "Ініціали: "; cin >> p.init;
	cout << "Оцінка з Фізики: "; cin >> p.fiz;
	if (p.fiz > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p.fiz = 5;
	}
	if (p.fiz < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p.fiz = 0;
	}
	cout << "Оцінка з Математики: "; cin >> p.math;
	if (p.math > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p.math = 5;
	}
	if (p.math < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p.math = 0;
	}
	cout << "Оцінка з Програмування: "; cin >> p.prog;
	if (p.prog > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p.prog = 5;
	}
	if (p.prog < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p.prog = 0;
	}
	cout << "Оцінка з Веб - дизайну: "; cin >> p.web;
	if (p.web > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p.web = 5;
	}
	if (p.web < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p.web = 0;
	}
	cout << "Оцінка з Електромеханіки: "; cin >> p.elect;
	if (p.elect > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p.elect = 5;
	}
	if (p.elect < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p.elect = 0;
	}
	if (!g.write((char*)&p, sizeof(Rep)))
	{
		cerr << "Помилка запису у файл." << endl;
	}
	f.close();
	g.close();
	ofstream file(fname, ios::binary);
	ifstream gfile(gname, ios::binary);
	while (gfile.read((char*)&p, sizeof(Rep))) { // перезапис всього з допоміжного файлу в основний 
		file.write((char*)&p, sizeof(Rep));  // з врахуванням нового запису
	}
	file.close();
	gfile.close();
	cout << endl;
	cout << "Відомості про студента успішно додано" << endl;
	cout << endl;
}

void EditStudent(char* fname) {
	ifstream f(fname, ios::binary);
	f.seekg(0, ios::end);
	int size = f.tellg();
	size = size / sizeof(Rep);
	f.seekg(0, ios::beg);
	Rep* p = new Rep[size];
	f.read((char*)p, size * sizeof(Rep));
	int numb;
	cout << "Номер студента для редагування: "; cin >> numb;
	if (numb > size) {
		cout << endl;
		cout << "Схоже ви ввели неправильний номер студента, будь ласка повторіть спробу з правильним номером студента." << endl << endl;
	}
	else {
		int i = numb - 1; // номер студента у структурі
		cout << "Прізвище студента: "; cin >> p[i].surname;
		cout << "Ініціали: "; cin >> p[i].init;
		cout << "Оцінка з Фізики: "; cin >> p[i].fiz;
		if (p[i].fiz > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p[i].fiz = 5;
		}
		if (p[i].fiz < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p[i].fiz = 0;
		}
		cout << "Оцінка з Математики: "; cin >> p[i].math;
		if (p[i].math > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p[i].math = 5;
		}
		if (p[i].math < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p[i].math = 0;
		}
		cout << "Оцінка з Програмування: "; cin >> p[i].prog;
		if (p[i].prog > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p[i].prog = 5;
		}
		if (p[i].prog < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p[i].prog = 0;
		}
		cout << "Оцінка з Веб - дизайну: "; cin >> p[i].web;
		if (p[i].web > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p[i].web = 5;
		}
		if (p[i].web < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p[i].web = 0;
		}
		cout << "Оцінка з Електромеханіки: "; cin >> p[i].elect;
		if (p[i].elect > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p[i].elect = 5;
		}
		if (p[i].elect < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p[i].elect = 0;
		}
	}
	f.close();
	ofstream file(fname, ios::binary);
	file.write((char*)p, size * sizeof(Rep));
	cout << endl;
	cout << "Данні про студента успішно змінені." << endl << endl;
	file.close();
}

void DelStudent(char* fname, const char* gname) {
	ifstream f(fname, ios::binary);
	f.seekg(0, ios::end);
	int size = f.tellg();
	size = size / sizeof(Rep);
	f.seekg(0, ios::beg);
	ofstream g(gname, ios::binary);
	cout << endl;
	int numb;
	cout << "Введіть номер студента, якого потрібно видалити: "; cin >> numb;
	Rep p;
	int k = 1;
	while (k <= size) {
		if (k != numb) { // перезапис у новий файл всіх записів, крім того, який потрібно видалити
			f.read((char*)&p, sizeof(Rep));
			g.write((char*)&p, sizeof(Rep));
		}
		k++;
	}
	f.close();
	g.close();
	ofstream file(fname, ios::binary);
	ifstream gfile(gname, ios::binary);
	while (gfile.read((char*)&p, sizeof(Rep))) {
		file.write((char*)&p, sizeof(Rep));
	}
	file.close();
	gfile.close();
	cout << endl;
	cout << "Дані про студента успішно видалено" << endl;
	cout << endl;
}

void StudMax(char* fname)
{
	ifstream fin(fname, ios::binary);
	if (!fin)
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Rep p;
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int k = 0;
	int i = 0;
	while (fin.read((char*)&p, sizeof(Rep)))
	{
		if (p.math == 5.0 &&
			p.fiz == 5.0 &&
			p.prog == 5.0 &&
			p.web == 5.0 &&
			p.elect == 5.0) { // первірка на студента, який здав все на макс. бал
			cout << "|" << setw(3) << ++i << setw(3) << "|";
			cout << setw(6) << p.surname << setw(7) << "|";
			cout << setw(6) << p.init << setw(7) << "|";
			cout << setw(5) << p.fiz << setw(6) << "|";
			cout << setw(7) << p.math << setw(8) << "|";
			cout << setw(9) << p.prog << setw(9) << "|";
			cout << setw(8) << p.web << setw(9) << "|";
			cout << setw(10) << p.elect << setw(10) << "|";
			cout << endl;
			k++;
		}
	}
	if (k == 0) {
		cout << endl;
		cout << "Схоже, що по заданому фільтру студентів не було знайдено." << endl << endl;
	}
	cout << "=================================================================================================================="
		<< endl;
	cout << endl;
}

bool StudThree(char* fname) {
	ifstream fin(fname, ios::binary);
	if (!fin)
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return false;
	}
	cout << endl;
	Rep p;
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int k = 0;
	int i = 0;
	while (fin.read((char*)&p, sizeof(Rep)))
	{
		if (p.math == 3.0 ||
			p.fiz == 3.0 ||
			p.prog == 3.0 ||
			p.web == 3.0 ||
			p.elect == 3.0) { // первірка на студента, який має хоча б одну 3
			cout << "|" << setw(3) << ++i << setw(3) << "|";
			cout << setw(6) << p.surname << setw(7) << "|";
			cout << setw(6) << p.init << setw(7) << "|";
			cout << setw(5) << p.fiz << setw(6) << "|";
			cout << setw(7) << p.math << setw(8) << "|";
			cout << setw(9) << p.prog << setw(9) << "|";
			cout << setw(8) << p.web << setw(9) << "|";
			cout << setw(10) << p.elect << setw(10) << "|";
			cout << endl;
			k++;
		}
	}
	if (k == 0) {
		cout << endl;
		cout << "Схоже, що по заданому фільтру студентів не було знайдено." << endl << endl;
		return false;
	}
	cout << "=================================================================================================================="
		<< endl;
	cout << endl;
	return true;
}

void StudTwo(char* fname) {
	ifstream fin(fname, ios::binary);
	if (!fin)
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Rep p;
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int i = 0;
	int k = 0; // оголошення лічильника двійок
	while (fin.read((char*)&p, sizeof(Rep)))
	{
		if (p.elect == 2.0) {
			k++;
		}
		if (p.web == 2.0) {
			k++;
		}
		if (p.prog == 2.0) {
			k++;
		}
		if (p.fiz == 2.0) {
			k++;
		}
		if (p.math == 2.0) {
			k++;
		}
		if (k == 1) { // перевірка на кількість двійок
			cout << "|" << setw(3) << ++i << setw(3) << "|";
			cout << setw(6) << p.surname << setw(7) << "|";
			cout << setw(6) << p.init << setw(7) << "|";
			cout << setw(5) << p.fiz << setw(6) << "|";
			cout << setw(7) << p.math << setw(8) << "|";
			cout << setw(9) << p.prog << setw(9) << "|";
			cout << setw(8) << p.web << setw(9) << "|";
			cout << setw(10) << p.elect << setw(10) << "|";
			cout << endl;
		}
		k = 0;
	}
	cout << "=================================================================================================================="
		<< endl;
	cout << endl;
	fin.close();
}