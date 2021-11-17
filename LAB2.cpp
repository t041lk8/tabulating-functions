/***---------------------------------------****
****-----------Курс информатика------------****
****---------------------------------------****
* Project Type : Win32 Console Application    *
* Project Name : LAB2.CPP                     *
* Language     : CPP, MSVS ver 2015 and above *
* Programmers  : Zhbanov I.A.                 *
* Modified By  : Zhbanov I.A.                 *
* Created      : 30/10/2020                   *
* Last Revision: 31/10/2020                   *
* --------------------------------------------*
* Comment      : Вторая лабораторная работа   *
****------------------------------------------*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double A,  //Левая граница отрезка
		B,     //Правая граница отрезка
		x,     //Аргумент функции х
		h,     //Длина шага
		G,     //Функция G(x)
		F;     //Функция F(x)
	int N;     //Количество шагов

	cout << "Write A: ";           //Ввод левой границы отрезка
	cin >> A;
	cout << "A = " << A << endl;   //ЭХО-печать А
	cout << "Write B: ";           //Ввод правой границы отрезка
	cin >> B;
	cout << "B = " << B << endl;   //ЭХО-печать В

	if (A > B)                     //Входной контроль
	{
		cout << "Error! A should be less than B, swap A and B" << endl;  //Выводим сообщение об ошибке и меняем А и В местами
		double buff;               //Буффер для переменной А
		buff = A;
		A = B;
		B = buff;
		cout << "A = " << A << " B = " << B << endl; //Выводим новые значения А и В
	}//if

	//Формирование таблицы
	if (A == B)
	{
		h = 0;
		N = 0;
	}
	else
	{
		cout << "Write N: ";
		cin >> N;                      //Ввод количества шагов
		cout << "N = " << N << endl;   //ЭХО-печать N
		if (N <= 0)
		{
			cout << "Error! N should be > 0";
			return 2;
		}//if
		h = (B - A) / N;
	}//if

	//Печать шапки
	//╔════╦═══════════════════╦═══════════════════╦═══════════════════╗
	//║   i║                  x║                  F║                  G║
	//╠════╬═══════════════════╬═══════════════════╬═══════════════════╣

	cout << char(201) << setw(5) << setfill(char(205)) << char(203) << setw(20) << setfill(char(205)) << char(203) << setw(20) << setfill(char(205)) << char(203) << setw(20) << setfill(char(205)) << char(187) << endl;
	cout << char(186) << setw(4) << setfill(' ') << "i" << char(186) << setw(19) << "x" << char(186) << setw(19) << "F" << char(186) << setw(19) << "G" << char(186) << endl;
	cout << char(204) << setw(5) << setfill(char(205)) << char(206) << setw(20) << setfill(char(205)) << char(206) << setw(20) << setfill(char(205)) << char(206) << setw(20) << setfill(char(205)) << char(185) << endl;

	//Расчет функций и вывод построчно
	for (int i = 0; i < N + 1; i++)
	{
		x = A + i * h;                                                         //Считаем новое значение аргумента функции х    
		F = (x - 1) * (x - 1) * (x - 1);                                       //Расчет функции F(x)
		G = (x + 5) * (x + 5) * (x + 5) / (1 + sin(x) * sin(x));               //Расчет функции G(x)
		cout << char(186) << setw(4) << setfill(' ') << i + 1 << char(186);    //Вывод номера строки/шага
		cout << setw(19) << x << char(186);     //Вывод аргумента функции х 
		cout << setw(19) << F << char(186);     //Вывод значения функции F(x)
		cout << setw(19) << G << char(186);     //Вывод значения функции G(x)
		cout << endl;
		if (i != N)
		{
			//Печать строки
			//╠════╬═══════════════════╬═══════════════════╬═══════════════════╣
			cout << char(204) << setw(5) << setfill(char(205)) << char(206) << setw(20) << setfill(char(205)) << char(206) << setw(20) << setfill(char(205)) << char(206) << setw(20) << setfill(char(205)) << char(185) << endl;
		}
		else
		{
			//Печать дна таблицы
			//╚════╩═══════════════════╩═══════════════════╩═══════════════════╝
			cout << char(200);
			cout << setw(5) << setfill(char(205)) << char(202) << setw(20) << setfill(char(205)) << char(202) << setw(20) << setfill(char(205)) << char(202) << setw(20) << setfill(char(205)) << char(188) << endl;
		}//if
	}//for
	return 0;
}//main
/****End of File LAB2.CPP ****/
