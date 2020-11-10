#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;
void change(double* a, double* b, int N)
{
	int l = 0;
	for (int i = 0;i <= N - 1; ++i)
	{
		if (a[i] < 0)
		{
			b[l] = a[i]; // 7) <- створення модифікованого масиву
			++l;
		}
	}
	for (int i = 0; i <= N - 1; ++i)
	{
		if (a[i] >= 0)
		{
			b[l] = a[i]; // 8) <- продовження створення модифікованого масиву
			++l;
		}
	}
	for (int l = 0; l <= N - 1; ++l)
		cout << setw(5) << b[l] << " "; // 9) <- вивід модифікованого масиву
}
void iter(double* a, double Low, double Max, int N, double C, double* b)
{
	int j = 0;
	for (int i = 0; i <= N - 1; ++i)
	{
		a[i] = (Max - Low) * rand() / RAND_MAX + Low; // 1) <- створення масиву
		if (a[i] > C)
			++j;
		cout << setw(5) << a[i] << " ";
	}
	double dobutok = 1;
	double max = a[0];
	int l = 0;
	for (int i = 0; i <= N - 1; ++i) // 2) <- цикл обрахунку добутку 
	{
		if (fabs(max) <= fabs(a[i]))
		{
			max = a[i];
			l = i;                    // 3) <- знаходження індексу з максимальним за модулем значенням
		}
	}
	for (l; l <= N - 1; ++l)        // 4) <- цикл обрахунку добутка
		dobutok *= a[l];                 
	cout << endl;
	cout << "Добуток елементів розміщені після останнього більшого за модулем елемента: " << dobutok << endl;
	cout << "Кількість елементів більших від С: " << j << endl;
	change(a, b, N); // 5) <- виклик для створення модифікованого масиву
}
int unittest(double* y, double C, const int N)
{
	int j = 0;
	for (int i = 0; i <= N - 1; ++i)
	{
		if (y[i] > C)
			++j;
	}
	return j;
}

int main()
{
	cout << fixed << setprecision(2);
	int N;
	double C, Max, Low;
	srand((unsigned)time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Введіть кількість елементів масиву: "; cin >> N;
	cout << "Введіть число С: "; cin >> C;
	cout << "Введіть мінімальне значення масиву: "; cin >> Low;
	cout << "Введіть максимальне значення масиву: "; cin >> Max;
	cout << endl;
	cout << "Ітераційний" << endl;
	double* a = new double[N];
	double* b = new double[N];
	iter(a, Low, Max, N, C, b);
	delete[] a;
	delete[] b;
	cout << endl;
	double y[10] = { -10.20, 25.34, 7.89, -15.01, 17.53, 3.21, 31.10, 0.35, 4.00, 5.5 };
	cout << endl;
	cout << "Unit test result: " << unittest(y, 8.8, 10) << endl;
}


