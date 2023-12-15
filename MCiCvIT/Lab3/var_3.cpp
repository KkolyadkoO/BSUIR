#include <iostream> // Подключение стандартной библиотеки
#include <string>
using namespace std;
int SolveCurrNum(int q, char arri){
return q * (arri - '0');
}
char* getString(int* k){
	char arr[1000] = { ' ' };
	printf ("Enter a numeric string: "); // Вывод сообщения
	char c = getchar();
	while (c != '\n') {
		
		arr[*k++] = c;
		c = getchar();
	}
	return arr;
}
int numArr[1000], cnt;

int main()  //Основное тело программы
{
	int currNum = 0;
	int k=1;
	char* arr = getString(&k);
	printf("\n"); // Перевод каретки
	int q = 1;
	for (int i = k; i >= 0; i--) {
		if (isdigit(arr[i])) {
			currNum += SolveCurrNum(q, arr[i]);
			q *= 10;
		}
		else if (q != 1) {
			numArr[cnt++] = currNum;
			currNum = 0;
			q = 1;
		}
	}
}