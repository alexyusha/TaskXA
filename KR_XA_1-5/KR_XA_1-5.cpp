//Variant 2

#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <list>
#include <clocale>
using namespace std;

const int COL = 6;
const int ROW = 6;
string textMenu = "Enter the task number(1-5) or 0 for exit: ";

/*
* Обчислити функцію двох змінних
*/
void first() 
{
	double y = 0;

	cout << "Task#1"<<endl;
	for (double x = 1; x <= 8; x = x + 0.5)
	{
		for (int a = 2; a <= 10; a++)
		{
			if (a > x)
			{
				y = pow(a, 2) + x;
				cout << "y=a^2+x(" << a << ">" << x << ") - y = ";
			}
			else if (a == x)
			{
				y = pow(a, 2);
				cout << "y=a^2(" << a << "=" << x << ") - y = ";
			}
			else
			{
				y = pow(a, 2) - x;
				cout << "y=a^2-x(" << a << "<" << x << ") - y = ";
			}
			cout << y << endl;
		}
	}
}

/*
* У матриці замінити нулями всі від’ємні елементи над головною
* діагоналлю. Знайти місце максимуму серед елементів нижче побічної діагоналі.
*/
 void second() {
	int array[COL][ROW];
	int indexColMax = 0;
	int indexRowMax = 0;
	int max = -2147483648;
	int zero = 0;
	srand(time(0));

	cout << "Task #2"<< endl << "Matrix:" << endl;
	for (int i = 0; i < COL; i++) 
	{
		for (int j = 0; j < ROW; j++)
		{
			int random = -10 + rand() % 20;
			array[i][j] = random;
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "=>" << endl;
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (i<j && array[i][j] < 0)
			{
				array[i][j] = zero;
			}

			if(i+j+1 > ROW && max < array[i][j])
			{
				max = array[i][j];
				indexColMax = i;
				indexRowMax = j;
			}
			cout << array[i][j] << "\t";
		}
		cout << endl;
		
	}

	cout << "Max indexes [" << indexColMax << "][" << indexRowMax << "] - " << max << endl;

}

 /*
 * Підрахувати у тексті кількість слів, в яких немає цифр.
 */
void third() {
	cout << "Task#3"<<endl;
	setlocale(LC_ALL, "Russian");

	int countWord = 0;
	string numbers = "0123456789";
	const int N = 256;
	bool flag = true;

	const char *SEPARATORS = "!?.,;/*-+\n\t ";
	char S[N] = "В 1матрице за2менить н34улями все отр6ицательные элементы7  7 над 5+5  главной диагональю. Найти место максимума среди элементов ниже побочной диагонали.";
	char *ptr = 0;

	ptr = strtok(S, SEPARATORS);

	while (ptr) {
		string a = ptr;
		for (int i = 0; i < a.length(); i++) {
			for (int j = 0; j < numbers.length(); j++)
			{
				if (a[i] == numbers[j])
				{
					flag = false;
				}
			}
		}
		if (flag)
		{
			countWord++;
		}

		flag = true;
		ptr = strtok(0, SEPARATORS);
	}

	cout << "Count words = " << countWord << endl;
}

/*
*Враховуючи інформація про абонентів АТС: ПІБ, місце проживання, номер телефону, 
*номер АТС, упорядкувати список абонентів за номерами АТС.
*/

struct Subscriber
{
	string firstName;
	string lastName;
	string MiddleName;
	string address;
	string phoneNumber;
	int ATCNumber;
};

void fourth() {
	cout << "Task#4" << endl;
	list<Subscriber> sub;
	for (int i = 0; i < 10; i++)
	{
		Subscriber subs = { "fistName", "lastName", "middleName", "address", "+380991503644", 1 + rand() % 100 };
		sub.push_front(subs);
	}
	sub.sort([](const Subscriber& a, const Subscriber& b) {
		return a.ATCNumber < b.ATCNumber;
		});
		for (Subscriber s : sub)
	{
		cout << s.firstName << " " << s.ATCNumber << endl;
	}
}


/*
* Створити функцію знаходження мінімального елемента квадратної матриці і сортування її побічної діагоналі.
*/
void fifth() {
	const int SIZE = 5;
	int min = 2147483647;
	int array[SIZE][SIZE];

	cout << "Task #5" << endl << "Matrix:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int random = 1 + rand() % 100;
			array[i][j] = random;
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (array[i][j] < min)
			{
				min = array[i][j];
			}
		}
	}

	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE-i-1; j++)
		{
			if (array[SIZE - 1 - j][j] > array[SIZE - 2 - j][j + 1])
			{
				swap(array[SIZE - 1 - j][j], array[SIZE - 2 - j][j + 1]);
			}
		}
	}

	cout << "=>" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "Min = " << min<<endl;
}


int main()
{
	int numberTask;
	cout << textMenu;
	cin >> numberTask;
	do
	{
		switch (numberTask)
		{
			case 1: first(); cout << textMenu; cin >> numberTask; break;
			case 2: second(); cout << textMenu; cin >> numberTask; break;
			case 3: third(); cout << textMenu; cin >> numberTask; break;
			case 4: fourth(); cout << textMenu; cin >> numberTask; break;
			case 5: fifth(); cout << textMenu; cin >> numberTask; break;
			default:"There is no such task."; break;
		} 
	} while (numberTask != 0);
}