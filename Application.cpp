// Application.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "../Library/Hex.h"
#include <iostream>

int getint(std::istream& s)
{
	int n;
	const char* err = "";
	do {
		std::cout << err;
		err = "Error. Enter number.\n";
		s.clear();
		s.ignore(s.rdbuf()->in_avail());
		s >> n;
	} while (!s.good());
	s.get();
	return n;
}

int dialog(const char* msgs[], int N)
{
	int rc;
	do {
		system("cls");
		for (int i = 0; i < N; i++)
			std::cout << msgs[i] << std::endl;
		rc = getint(std::cin);
	} while (!std::cin.good());
	return rc;
}

void extand(lab3::Hex*& Hex, int& n) {
	lab3::Hex* tmp = Hex;
	Hex = new lab3::Hex[++n];
	for (int i = 0; i < n-1; i++)
		Hex[i] = tmp[i];
	delete[] tmp;
}

void delete_f(lab3::Hex*& Hex, int& n, int i1) {
	lab3::Hex* tmp = Hex;
	Hex = new lab3::Hex[--n];
	for (int i = 0, k = 0; i < n; i++) {
		if (i == i1) k = 1;
		Hex[i] = tmp[i + k];
	}
	delete[] tmp;
}

int getindex_in_range(int start, int end) {
	int i;
	const char* msg = "";
	do {
		std::cout << msg;
		i = getint(std::cin);
		msg = "Error: out of range\n";
	} while ((i < start) || (i > end));
	return i;
}

int main()
{
	lab3::Hex* Hex = nullptr;
	int n = 0;
	int i1, i2, k;
	int rc;
	const char* msg = "";
	const char* msgs[] = { "0.Quit", "1.Enter new hex number", "2.Delete hex number", "3.Add", "4.Substract", "5.Compare", "6.Shift right", "7.Shift left", "8.Is number even?", "9.Show numbers" };
	while (rc = dialog(msgs, 10)) {
		switch (rc)
		{
		case 1: {
			if (n > 0)
				extand(Hex, n);
			else
				Hex = new lab3::Hex[++n];
			Hex[n - 1].input(std::cin);
			std::cin.get();
			break;
		}
		case 2: {
			if (n < 1) {
				std::cout << "0 Numbers in array." << std::endl;
				break;
			}
			i1 = getindex_in_range(0, n);
			delete_f(Hex, n, i1 - 1);
			break;
		}
		case 3: {
			if (n < 1) {
				std::cout << "0 Numbers in array." << std::endl;
				break;
			}
			std::cout << "choose the first number:" << std::endl;
			i1 = getindex_in_range(0, n);
			std::cout << "choose the second number:" << std::endl;
			i2 = getindex_in_range(0, n);
			Hex[i1 - 1] = Hex[i1 - 1].add(Hex[i2 - 1]);
			break;
		}
		case 4: {
			if (n < 1) {
				std::cout << "0 Numbers in array." << std::endl;
				break;
			}
			std::cout << "choose the first number:" << std::endl;
			i1 = getindex_in_range(0, n);
			std::cout << "choose the second number:" << std::endl;
			i2 = getindex_in_range(0, n);

			Hex[i1 - 1] = Hex[i1 - 1].subtract(Hex[i2 - 1]);
			break;
		}
		case 5: {
			if (n < 1) {
				std::cout << "0 Numbers in array." << std::endl;
				break;
			}
			std::cout << "choose the first number:" << std::endl;
			i1 = getindex_in_range(0, n);
			std::cout << "choose the second number:" << std::endl;
			i2 = getindex_in_range(0, n);
			k = Hex[i1 - 1].comp(Hex[i2 - 1]);
			if (k == 1)
				std::cout << "First number > Second number" << std::endl;
			else if (k == 2)
				std::cout << "First number < Second number" << std::endl;
			else
				std::cout << "First number == Second number" << std::endl;
			break;
		}
		case 6: {
			if (n < 1) {
				std::cout << "0 Numbers in array." << std::endl;
				break;
			}
			std::cout << "choose the number:" << std::endl;
			i1 = getindex_in_range(0, n);
			std::cout << "choose the number to shift right:" << std::endl;
			k = getindex_in_range(0, INT_MAX);
			Hex[i1 - 1].shift_right(k);
			break;
		}
		case 7: {
			if (n < 1) {
				std::cout << "0 Numbers in array." << std::endl;
				break;
			}
			std::cout << "choose the number:" << std::endl;
			i1 = getindex_in_range(0, n);
			std::cout << "choose the number to shift left:" << std::endl;
			k = getindex_in_range(0, INT_MAX);
			Hex[i1 - 1].shift_left(k);
			break;
		}
		case 8: {
			if (n < 1) {
				std::cout << "0 Numbers in array." << std::endl;
				break;
			}
			std::cout << "choose the first number:" << std::endl;
			i1 = getindex_in_range(0, n);
			if (Hex[i1 - 1].is_even() - 1)
				std::cout << "Number Odd" << std::endl;
			else
				std::cout << "Number Even" << std::endl;
			break;
		}
		case 9: {
			if (n < 1) {
				std::cout << "0 Numbers in array." << std::endl;
				break;
			}
			for (int i = 0; i < n; i++) {
				std::cout << i + 1;
				Hex[i].print(std::cout);
			}
			break;
		}
		}
		std::cout << "Type any symbol to continue..."; std::cin.get();
	}
	delete[] Hex;
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
