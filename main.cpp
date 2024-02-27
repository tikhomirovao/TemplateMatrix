#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

//шаблон класса с type параметром и non-type параметрами(строки,столбцы) 
template <class T, int Rows, int Columns>

class Matrixs
{
	//non-type параметр Rows, Columns определяют размер матрицы
	T Matrix[Rows][Columns]{};
public:
	//метод вывода на экран матрицы
	void Show()const
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (Matrix[i][j] >= 0)cout << " "; //добавляем пробел перед положительным числом
				if (Matrix[i][j] > -10 && Matrix[i][j] < 10)cout << " "; //добавляем пробел перед числом из одной цифры
				cout << Matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	//Метод заполнения матрицы случайными числами 
	void Randomize()
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				Matrix[i][j] = rand() % (100 - (-89)) - 89 * 1.1;
			}
		}
	}
	//Метод заполнения матрицы с клавиатуры
	void Сompletion()
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				cout << "Введите число: " << endl;
				cin >> Matrix[i][j];
			}
		}
		cout << endl;
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(nullptr));

	//создание объекта класса(матрицы) с типом данных int 
	Matrixs<int, 5, 5> IntMatrix;
	IntMatrix.Show();
	//заполнения матрицы случайными числами
	IntMatrix.Randomize();
	IntMatrix.Show();
	//создание объекта класса(матрицы) с типом данных double
	Matrixs<double, 10, 10> DoubleMatrix;
	DoubleMatrix.Show();
	//заполнения матрицы случайными числами
	DoubleMatrix.Randomize();
	DoubleMatrix.Show();

	Matrixs<int, 3, 3> IntMatrixA;
	//заполнение матрицы с клавиатуры
	IntMatrixA.Сompletion();
	IntMatrixA.Show();


}