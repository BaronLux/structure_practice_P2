﻿// algorithms.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "Algorithm.h"
#include "Generators.h"
#include "QuikSort.h"
using namespace std;
int main()
{
	auto q = new QuickSort();
	auto gen = new Generators();

	cout << "RANDOM" << endl;
	for (size_t i = 2, n = 100; 
		i < 6; i++, n = pow(10, i))
	{
		cout << "n=" << n << endl;

		auto arr = gen->RandomGen(n); // выполняет генерацию случайного массива из n элементов
		q->Run(arr, n);
		q->Print();
	}

	cout << "DES" << endl;
	for (size_t i = 2, n = 100;
		i < 4; i++, n = pow(10, i))
	{
		cout << "n=" << n << endl;

		auto arr = gen->DesksortedGen(n);

		q->Run(arr, n);
		q->Print();
		
	}

	cout << "ACS" << endl;
	for (size_t i = 2, n = 100;
		i < 4; i++, n = pow(10, i))
	{
		cout << "n=" << n << endl;

		auto arr = gen->AcsSortedGen(n);

		q->Run(arr, n);
		q->Print();
	}
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
