#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

void create(double* a, double Low, double Max, int N);
void print(double* a, int N);
int moreC(double* a, int N, double C);
int find_last_fabs(double* a, int N, double max);
double dob(double* a, int N, int l);
void create2(double* a, double* b, int N);

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
	cout << "Рекурсивний" << endl;
	double* a = new double[N];
	double* b = new double[N];
	create(a, Low, Max, N);
	print(a, N);
	cout << endl;
	cout << "Кількість елементів більших від С: " << moreC(a, N, C) << endl;
	int l = find_last_fabs(a, N, a[0]);
	cout << "Добуток елементів після останнього більшого по модулю елемента: " << dob(a, N, l) << endl;
	create2(a, b, N);
	print(b, N);
	delete[] a;
	delete[] b;
	cout << endl;
}
void create(double* a, double Low, double Max, int N)
{
	int j = 0;
	for (int i = 0; i <= N - 1; ++i)
		a[i] = (Max - Low) * rand() / RAND_MAX + Low; 
}
void print(double* a, int N)
{
	for (int i = 0; i <= N - 1; ++i)
		cout << setw(5) << a[i] << " ";
}
int moreC(double* a, int N, double C)
{
	int j = 0;
	for (int i = 0; i <= N - 1; ++i)
	{
		if (a[i] > C)
			++j;
	}
	return j;

}
int find_last_fabs(double* a, int N, double max)
{
	int l = 0;
	for (int i = 0; i <= N - 1; ++i) 
	{
		if (fabs(max) <= fabs(a[i]))
		{
			max = a[i];
			l = i;                    
		}
	}
	return l;
}
double dob(double*a, int N, int l)
{
	double dobutok = 1;
	for (l; l <= N - 1; ++l)        
		dobutok *= a[l];
	return dobutok;
}
void create2(double* a, double* b, int N)
{
	int l = 0;
	for (int i = 0; i <= N - 1; ++i)
	{
		if (a[i] < 0)
		{
			b[l] = a[i]; 
			++l;
		}
	}
	for (int i = 0; i <= N - 1; ++i)
	{
		if (a[i] >= 0)
		{
			b[l] = a[i]; 
			++l;
		}
	}
}


