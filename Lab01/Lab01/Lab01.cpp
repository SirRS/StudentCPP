// lab01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include "pch.h"
#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

int main()
{
	char answer;
	setlocale(LC_ALL, "RUSSIAN");
	do {
		char vvod[200];
		int k, i, des, s;
		for (i = 0; i < 200; i++) {
			cin >> vvod[i];
			if (vvod[i] == '=') i = 200;
		}
		int kodel, bukv, userbukv; bukv = 0;
		int proverka, numneiz, proof; numneiz = 0; proof = 0;
		double neiz_zn, x;
		char neiz;
		cout << "Сколько неизвестных переменных в уравнении?" << endl;
		cin >> userbukv;
		// Сколько всего неизвестных переменных (букв) и сколько введет пользователь
		for (i = 0; vvod[i] != '='; i++) {
			kodel = vvod[i];
			if (kodel > 96 && kodel < 123) {
				bukv = bukv + 1;
			}
		}
		if (userbukv != bukv) {
			cout << "ERROR" << endl;
		}
		//Ввод переменных если они есть, запоминается какая переменная встречается в каком порядке, позже значиния подставляются в нужном порядке.
		//Если пользователь вводит букву которой не было или вводит некоректное значение выводится ошибка. 
		double neizm[100];
		for (bukv; bukv != 0; bukv--) {
			cout << "Какую переменную вывести?" << endl;
			cin >> neiz;
			for (i = 0; vvod[i] != '='; i++) { if (vvod[i] == neiz) { proverka = 1; } } if (proverka != 1) { cout << "ERROR" << endl;  return 1; }
			cout << "Введите значение переменной" << ' ' << neiz << endl; neiz_zn = 0; cin >> neiz_zn; numneiz = 0;
			for (i = 0; vvod[i] != '='; i++) {
				kodel = vvod[i]; if (kodel > 96 && kodel < 123) { if (vvod[i] == neiz) { neizm[numneiz] = neiz_zn; } numneiz = numneiz + 1; }
			}
		}
		numneiz = 0; s = 0;
		//Массив знаков и чисел для обратной польской записи
		char znak[100]; double chisl[100]; int znn, chn; znn = 0; chn = 0;
		for (i = 0; vvod[i] != '='; i++) {
			kodel = vvod[i];
			if (vvod[i] == '(') { s = s + 1; znak[znn] = '('; proof = 1; znn++; if ((vvod[i + 1] < 48 || vvod[i + 1] > 57) && (vvod[i + 1] != '(') && (vvod[i + 1] < 97 || vvod[i + 1]>122)) { cout << "ERROR" << endl; return 1; } }
			if (vvod[i] == ')') { s = s - 1; znak[znn] = ')'; proof = 1; znn++; /*if ((vvod[i + 1] < 48 || vvod[i + 1] > 57) && (vvod[i + 1] != '(') && (vvod[i + 1] < 97 || vvod[i + 1]>122) && (vvod[i+1] != '=')) { cout << "ERROR" << endl; return 1; }*/ }
			if (vvod[i] == '*') { znak[znn] = '*'; proof = 1; znn++; if ((vvod[i + 1] < 48 || vvod[i + 1] > 57) && (vvod[i + 1] != '(') && (vvod[i + 1] < 97 || vvod[i + 1]>122)) { cout << "ERROR" << endl; return 1; } }
			if (vvod[i] == '/') { znak[znn] = '/'; proof = 1; znn++; if ((vvod[i + 1] < 48 || vvod[i + 1] > 57) && (vvod[i + 1] != '(') && (vvod[i + 1] < 97 || vvod[i + 1]>122)) { cout << "ERROR" << endl; return 1; } }
			if (vvod[i] == '^') { znak[znn] = '^'; proof = 1; znn++; if ((vvod[i + 1] < 48 || vvod[i + 1] > 57) && (vvod[i + 1] != '(') && (vvod[i + 1] < 97 || vvod[i + 1]>122)) { cout << "ERROR" << endl; return 1; } }
			if (vvod[i] == '#') { znak[znn] = '#'; proof = 1; znn++; if ((vvod[i + 1] < 48 || vvod[i + 1] > 57) && (vvod[i + 1] != '(') && (vvod[i + 1] < 97 || vvod[i + 1]>122)) { cout << "ERROR" << endl; return 1; } }
			if (vvod[i] == '&') { znak[znn] = '&'; proof = 1; znn++; if ((vvod[i + 1] < 48 || vvod[i + 1] > 57) && (vvod[i + 1] != '(') && (vvod[i + 1] < 97 || vvod[i + 1]>122)) { cout << "ERROR" << endl; return 1; } }
			if (vvod[i] == '%') { znak[znn] = '%'; proof = 1; znn++; if ((vvod[i + 1] < 48 || vvod[i + 1] > 57) && (vvod[i + 1] != '(') && (vvod[i + 1] < 97 || vvod[i + 1]>122)) { cout << "ERROR" << endl; return 1; } }
			if (vvod[i] == '+') { znak[znn] = '+'; proof = 1; znn++; if ((vvod[i + 1] < 48 || vvod[i + 1] > 57) && (vvod[i + 1] != '(') && (vvod[i + 1] < 97 || vvod[i + 1]>122)) { cout << "ERROR" << endl; return 1; } }
			if (vvod[i] == '-') { znak[znn] = '-'; proof = 1; znn++; if ((vvod[i + 1] < 48 || vvod[i + 1] > 57) && (vvod[i + 1] != '(') && (vvod[i + 1] < 97 || vvod[i + 1]>122)) { cout << "ERROR" << endl; return 1; } }
			if (kodel > 96 && kodel < 123) { chisl[chn] = neizm[numneiz]; chn++; numneiz++; proof = 1; }
			if (47 < kodel && kodel < 58) {
				kodel = kodel - 48; chisl[chn] = kodel; des = 10; proof = 1;
				if (47 < (kodel = vvod[i + 1]) && (kodel = vvod[i + 1]) < 58) { for (k = i + 1; (47 < vvod[k]) && (vvod[k] < 58); k++) { kodel = vvod[k] - 48; chisl[chn] = chisl[chn] * 10 + kodel; i = k; } }
				if (vvod[i + 1] == '.') { i++; for (k = i + 1; (47 < vvod[k] && vvod[k] < 58); k++) { kodel = vvod[k] - 48; x = double(kodel) / des; chisl[chn] = double (chisl[chn] + x); des = des * 10; i = k; } }
				chn++;
			}
			if (proof != 1) { cout << "ERROR" << endl; return 1; }
			proof = 0;
		}
		if (s != 0) { cout << "ERROR" << endl; return 1; }
		//cout << znak[0] << znak[1] << chisl[0] << chisl[1] << endl;
		for (k = 0; k != znn; k++) {
			if (znak[k] == '(') {
				for (s = k; s != znn; s++) { znak[s] = znak[s + 1]; } znn--;
				for (i = k; znak[i] != ')'; i++) {
					if (znak[i] == '&') { if (chisl[i] == 0 || chisl[i + 1] == 0) { cout << "ERROR" << endl; return 1; } chisl[i + 1] = double(log(chisl[i]) / log(chisl[i + 1])); }
					if (znak[i] == '#') { if (chisl[i + 1] < 0) { cout << "ERROR" << endl; return 1; } chisl[i + 1] = pow(double(chisl[i + 1]), (double(1) / chisl[i])); }
					if (znak[i] == '^') { chisl[i + 1] = pow(double(chisl[i]), double(chisl[i + 1])); }
					if (znak[i] == '%') { if (chisl[i + 1] == 0) { cout << "ERROR" << endl; return 1; } chisl[i + 1] = fmod(chisl[i], chisl[i + 1]); }
					if (znak[i] == '*') { chisl[i + 1] = double(chisl[i] * chisl[i + 1]); }
					if (znak[i] == '/') { if (chisl[i + 1] == 0) { cout << "ERROR" << endl; return 1; } chisl[i + 1] = double(chisl[i]) / double(chisl[i + 1]); }
					if (znak[i] == '/' || znak[i] == '*' || znak[i] == '#' || znak[i] == '%' || znak[i] == '&' || znak[i] == '^') {
						for (s = i; s != znn; s++) { znak[s] = znak[s + 1]; chisl[s] = chisl[s + 1]; } i--; znn--;
					}
				}
				for (i = k; znak[i] != ')'; i++) {
					if (znak[i] == '+') { chisl[i + 1] = double(chisl[i] + chisl[i + 1]); }
					if (znak[i] == '-') { chisl[i + 1] = double(chisl[i] - chisl[i + 1]); }
					for (s = i; s != znn; s++) { znak[s] = znak[s + 1]; chisl[s] = chisl[s + 1]; } i--; znn--;
				}
				for (s = k; s != znn; s++) { znak[s] = znak[s + 1]; } znn--; k--;
			}
		}
		for (i = 0; i != znn; i++) {
			if (znak[i] == '&') { if (chisl[i] == 0 || chisl[i + 1] == 0) { cout << "ERROR" << endl; return 1; } chisl[i + 1] = double(log(chisl[i]) / log(chisl[i + 1])); }
			if (znak[i] == '#') { if (chisl[i + 1] < 0) { cout << "ERROR" << endl; return 1; } chisl[i + 1] = pow(double(chisl[i + 1]), (double(1) / chisl[i])); }
			if (znak[i] == '^') { chisl[i + 1] = pow(double(chisl[i]), double(chisl[i + 1])); }
			if (znak[i] == '%') { if (chisl[i + 1] == 0) { cout << "ERROR" << endl; return 1; } chisl[i + 1] = fmod(chisl[i], chisl[i + 1]); }
			if (znak[i] == '*') { chisl[i + 1] = double (chisl[i] * chisl[i + 1]); }
			if (znak[i] == '/') { if (chisl[i + 1] == 0) { cout << "ERROR" << endl; return 1; } chisl[i + 1] = double(chisl[i]) / double(chisl[i + 1]); }
			if (znak[i] == '/' || znak[i] == '*' || znak[i] == '#' || znak[i] == '%' || znak[i] == '&' || znak[i] == '^') {
				for (s = i; s != znn; s++) { znak[s] = znak[s + 1]; chisl[s] = chisl[s + 1]; } i--; znn--;
			}
		}
		for (i = 0; i != znn; i++) {
			if (znak[i] == '+') { chisl[i + 1] = double (chisl[i] + chisl[i + 1]); }
			if (znak[i] == '-') { chisl[i + 1] = double (chisl[i] - chisl[i + 1]); }
			for (s = i; s != znn; s++) { znak[s] = znak[s + 1]; chisl[s] = chisl[s + 1]; } i--; znn--;
		}
		cout << "Ответ: " << chisl[0] << endl;
		cout << "Хотите решить другой пример?" << endl; cout << "Введите 'y' для повтора" << endl;
		cin >> answer;
	} while (answer == 'y');
	cout << "До свидания" << endl;
	return 0;
}