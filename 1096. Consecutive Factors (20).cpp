#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int max=1, small=n; 
	for (int i = 2; i <= sqrt(n)+1; i++)
	{	
		int a, b = n;
		for (a = i; b%a == 0; b /= a, ++a)
			;
		if (a - i > max||(a-i==max&&i<small))
		{
			max = a - i;
			small = i;
		}
	}
	cout << max << endl;
	cout << small;
	for (int i = 1; i < max; i++)
		cout << "*" << small + i;
	return 0;
}