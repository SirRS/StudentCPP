#include "pch.h"
#include <iostream>
#include <locale>
#include <cmath>

using namespace std;

int proverkazn(char x);
void priority2(char z, double *x, double *y); int priority1(char z, double *x, double *y);

int main()
{
	char vvod[255], answer;
	char vse_znaki[][2] = { {'+', '0'}, {'-', '0'}, {'/', '1'}, {'^', '1'}, {'&','1'}, {'#','1'}, {'%','1'} };
	setlocale(LC_ALL, "RUSSIAN");
	do {
		cout << "Введите выражение" << endl << ' ' << endl;
		/*for (unsigned char i = 0; vvod[i - 1] != '=' && i < 255; i++) {
			cin >> vvod[i];
			if (vvod[i] == '\n') vvod[i] = '=';
		}*/
		cin.getline(vvod, 255);
		vvod[strlen(vvod)] = '=';
		for (unsigned char i = 0; vvod[i] != '='; i++) {
			if (vvod[i] == '\n') {
				swap(vvod[i], vvod[i + 1]);
			}
		}

		short int bukv = 0, znn = 0, userbukv, chn = 0, numneiz = 0, proof = 1;
		cout << "Сколько неизвестных переменных в уравнении?" << endl;
		while (!(cin >> userbukv) || (cin.peek() != '\n')) {
			cin.clear(); while (cin.get() != '\n'); cout << "Введите значение корректно" << endl;
		}

		// Сколько всего неизвестных переменных (букв) и сколько введет пользователь
		for (unsigned char i = 0; vvod[i] != '='; i++) {
			if (vvod[i] > 96 && vvod[i] < 123) {
				bukv = bukv + 1;
			}
		}
		if (userbukv != bukv) { cout << "ERROR" << endl; proof = 0; }

		//Ввод переменных если они есть, запоминается какая переменная встречается в каком порядке, позже значиния подставляются в нужном порядке.
		//Если пользователь вводит букву которой не было или вводит некоректное значение выводится ошибка. 
		double neizm[100]; short int kodel, neiz_zn;
		for (bukv; bukv != 0 && proof != 0; bukv--) {
			cout << "Какой переменной внести значение?" << endl;
			char neiz; cin >> neiz; proof = 0;
			for (unsigned char i = 0; vvod[i] != '='; i++) {
				if (vvod[i] == neiz) { proof = 1; }
			}
			if (proof != 1) {continue; }
			cout << "Введите значение переменной" << ' ' << neiz << endl; neiz_zn = 0;
			while (!(cin >> neiz_zn) || (cin.peek() != '\n')) {
				cin.clear(); while (cin.get() != '\n'); cout << "Введите значение переменной -" << neiz << "- корректно" << endl;
			}
			numneiz = 0;
			for (unsigned char i = 0; vvod[i] != '='; i++) {
				kodel = vvod[i]; if (kodel > 96 && kodel < 123) {
					if (vvod[i] == neiz) {
						neizm[numneiz] = neiz_zn;
					} numneiz++;
				}
			}
		}

		numneiz = 0; short int s = 0; char znak[200]; double chisl[150]; chn = 0;
		for (short int i = 0; vvod[i] != '=' && proof != 0; i++) {
			proof = 0;
			if (vvod[i] == '+' || vvod[i] == '-' || vvod[i] == '/' || vvod[i] == '*' || vvod[i] == '#' || vvod[i] == '^' || vvod[i] == '%' || vvod[i] == '&') {
				znak[znn] = vvod[i]; znn++; proof = proverkazn(vvod[i + 1]); continue;
			}
			if (vvod[i] == '(') {
				s++; znak[znn] = '('; znn++; proof = proverkazn(vvod[i + 1]); continue;
			}
			if (vvod[i] == ')') {
				s--; znak[znn] = ')'; znn++; if ((proof = proverkazn(vvod[i + 1])) == 0) { proof = 1; } continue;
			}
			kodel = vvod[i];
			if (kodel > 96 && kodel < 123) {
				chisl[chn] = neizm[numneiz]; chn++; numneiz++; proof = 1;
				if ((vvod[i + 1] > 96 && vvod[i + 1] < 123) || (vvod[i + 1] > 47 && vvod[i + 1] < 58)) { proof = 0; }
				continue;
			}
			if (47 < vvod[i] && vvod[i] < 58) {
				proof = 1; kodel = vvod[i] - 48; chisl[chn] = kodel; int des = 10;
				if (47 < (kodel = vvod[i + 1]) && (kodel = vvod[i + 1]) < 58) {
					for (unsigned char k = i + 1; (47 < vvod[k]) && (vvod[k] < 58); k++) {
						kodel = vvod[k] - 48; chisl[chn] = chisl[chn] * 10 + kodel; i = k;
					}
				}
				if (vvod[i + 1] == '.') {
					if (vvod[i + 2] < 48 || vvod[i + 2] > 57) { proof = 0; }
					for (unsigned char k = i + 2; (47 < vvod[k] && vvod[k] < 58); k++) {
						kodel = vvod[k] - 48;
						double x = double(kodel) / des;
						chisl[chn] = double(chisl[chn] + x);
						des = des * 10; i = k;
					}
				}
				chn++;
			}
		}

		for (unsigned char m = 0; m != znn && proof != 0; m++) {
			if (znak[m] == '(') {
				for (unsigned char k = m; k != znn; k++) { znak[k] = znak[k + 1]; } znn--;
				for (unsigned char i = m; znak[i] != ')' && proof != 0; i++) {
					proof = priority1(znak[i], &chisl[i], &chisl[i + 1]);
					if (proof == 2) {
						for (unsigned char k = i; k != znn; k++) {
							znak[k] = znak[k + 1]; chisl[k] = chisl[k + 1];
						}
						znn--; i--;
					}
				}
				for (unsigned char i = m; znak[i] != ')' && proof != 0 && znak[i] != '('; i++) {
					priority2(znak[i], &chisl[i], &chisl[i + 1]);
					for (unsigned char k = i; k != znn; k++) {
						znak[k] = znak[k + 1]; chisl[k] = chisl[k + 1];
					}
					znn--; i--;
				}
				if (znak[m] == '(') { proof = 0; break; }
				for (unsigned char i = m; i != znn; i++) { znak[i] = znak[i + 1]; } znn--; m--;
			}
		}
		for (unsigned char i = 0; i != znn && proof != 0; i++) {
			proof = priority1(znak[i], &chisl[i], &chisl[i + 1]);
			if (proof == 2) {
				for (unsigned char k = i; k != znn; k++) {
					znak[k] = znak[k + 1]; chisl[k] = chisl[k + 1];
				}
				znn--; i--;
			}
		}

		for (unsigned char i = 0; i != znn && proof != 0; i++) {
			priority2(znak[i], &chisl[i], &chisl[i + 1]);
			for (unsigned char k = i; k != znn; k++) {
				znak[k] = znak[k + 1]; chisl[k] = chisl[k + 1];
			}
			znn--; i--;
		}
		if (proof == 0 || s != 0) { cout << "ERROR" << endl; proof = 0; }
		if (proof != 0) { cout << ' ' << endl << "Ответ = " << chisl[0] << endl; }
		cout << "Хотите решить другой пример?" << endl; cout << "Введите 'y' для повтора" << endl;
		cin >> answer; cout << ' ' << endl; cin.ignore();
	} while (answer == 'y');
	cout << "До свидания" << endl;
	return 0;
}

int proverkazn(char x) {
	short int proof = 1;
	if ((x < 48 || x > 57) && (x != '(') && (x < 97 || x>122)) {
		proof = 0;
	}
	return proof;
}

int priority1(char z, double *x, double *y) {
	short int proof = 2;
	switch (z) {
	case '&': {
		if (*x == 0 || *y == 0) { proof = 0; *x = 1; *y = *x = 1; *y = 1; 1; }
		*y = double(log(*x) / log(*y));
		break;
	}
	case '#': {
		if (*y < 0) { proof = 0; *x = 1; *y = 1; }
		*y = pow(double(*y), (double(1) / *x));
		break;
	}
	case '^': {
		*y = pow(double(*x),
			double(*y));
		break;
	}
	case '%': {
		if (*y == 0) { proof = 0; *x = 1; *y = 1; }
		*y = fmod(*x, *y);
		break;
	}
	case '*': {
		proof = 2;
		*y = double(*x * *y);
		break;
	}
	case '/': {
		if (*y == 0) { proof = 0; *x = 1; *y = 1; }
		*y = double(*x) / double(*y);
		break;
	}
	default: {proof = 1; }
	}
	return proof;
}

void priority2(char z, double *x, double *y) {
	switch (z) {
	case '+': { *y = double(*x + *y); break; }
	case '-': { *y = double(*x - *y); break; }
	}
}