#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;//1
	cin >> n; //1
	if (n>100 || n<0)//1
	{
		cout << "Unkorrekt N";
		return 0;
	}
	int* Arr = new int[n];//1s
	for (int i = 0; i < n; i++) //n
	{
		cin >> Arr[i];//n
		if (Arr[i] > 0)//n
			Arr[i] = pow(Arr[i], 3);//n
		if (Arr[i] < 0)//n
			Arr[i] = pow(Arr[i], 2);
	}//5*n
	for (int i = 0; i < n; i++)//n
	{
		cout << "Arr[" << i << "] = " << Arr[i] << endl;//n
	}//2*n
	return 0;//1
}

// Память максимально n+1=101
// время максимально 1+1+1+1+5*n+2*n+1=705с