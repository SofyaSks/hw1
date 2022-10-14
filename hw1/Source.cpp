#include <iomanip>
#include <iostream>
//#include <conio.h>
//#include <stdio.h>
//#include <io.h>
//#include <fstream>
#include <string>

using namespace std;

class Division {
public:

	Division() {  

		ch = 0;
		zn = 1;
	}

	Division(int num1, int num2) {
		ch = num1;
		zn = num2;
	}

	Division(int num1) {
		ch = num1;
	}

	void PrintDivision() {
		cout << ch << "/" << zn << endl;
	}


	void Convert_(Division tmp) {
		double rez = (double)tmp.ch / tmp.zn;
		cout << ch << "/" << zn << " = " << rez << endl;
	}

	// метод сложения
	void Addition(Division tmp, Division tmp2) {
		int newZn = tmp.zn * tmp2.zn;
		Division tmp3;
		if (tmp.zn == tmp2.zn) {
			cout << tmp.ch << "/" << tmp.zn << " + " << tmp2.ch << "/" << tmp2.zn << " = " 
						<< tmp.ch + tmp2.ch << "/" << tmp.zn << endl;

			tmp3.ch = tmp.ch + tmp2.ch;
			tmp3.zn = tmp.zn;
			Correction(tmp3);
	
		}
		else
		{
			cout << tmp.ch << "/" << tmp.zn << " + " << tmp2.ch << "/" << tmp2.zn << " = " <<
				tmp.ch * tmp2.zn + tmp2.ch * tmp.zn << "/" << newZn << endl;

			tmp3.ch = tmp.ch * tmp2.zn + tmp2.ch * tmp.zn;
			tmp3.zn = newZn;
			Correction(tmp3);
		}
	}

	// метод перевода из неправильной в правильную
	void Correction(Division tmp) {
		if (tmp.ch >= tmp.zn) {
			int fullNum = tmp.ch / tmp.zn;
			int newCh = tmp.ch % tmp.zn;
			if (tmp.ch % tmp.zn != 0) {
				cout << "Correction: " << tmp.ch << "/" << tmp.zn << " = " << fullNum << " and "
					<< newCh << "/" << tmp.zn << endl;
			}
			else
				cout << "Correction: " << fullNum << endl;
		}
		else
			cout << tmp.ch << "/" << tmp.zn << endl;
	}

	// метод умножения на число
	void Multiplication(Division tmp, int num) {
		cout << "Multiplication: " << tmp.ch << "/" << tmp.zn << " * " << num << " = "
			<< tmp.ch * num << "/" << tmp.zn << endl;
		tmp.ch *= num;
		Correction(tmp);
	}

	int getCh() {
		return ch;
	}

	int getZn() {
		return zn;
	}



private:
	int ch;
	int zn;


};



void main() {
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int num1, num2;
	cout << "Enter ch: ";
	cin >> num1;
	cout << "Enter zn: ";
	cin >> num2;

	int num3, num4;
	cout << "Enter ch2: ";
	cin >> num3;
	cout << "Enter zn2: ";
	cin >> num4;

	cout << endl;

	Division d1(num1, num2);

	Division d2(num3,num4);


	d1.Addition(d1, d2);
	cout << endl;

	int newnum;
	cout << "Enter ch: ";
	cin >> num1;
	cout << "Enter zn: ";
	cin >> num2;
	cout << "Enter number for multiplication: ";
	cin >> newnum;

	Division d3(num1, num2);

	d3.Multiplication(d3, newnum);


}