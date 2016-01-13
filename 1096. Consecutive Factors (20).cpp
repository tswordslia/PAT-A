#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int max=1, small=n; //最长列，最小因数列头,如果是个质数，则最小因数就是自己本身
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
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int maxCnt = 1, first = n;
//	int b= sqrt(n) + 0.5;
//	for (int i = 2; i <= b; ++i) {
//		int cnt = 0, remain = n, j;
//		for (j = i; remain % j == 0; remain /= j, ++j)
//			;
//		if (j - i > maxCnt || (j - i == maxCnt && i < first)) {
//			maxCnt = j - i;
//			first = i;
//		}
//	}
//	cout << maxCnt << endl;
//	cout << first;
//	for (int i = 1; i < maxCnt; ++i) {
//		cout << '*' << first + i;
//	}
//	system("pause");
//	return 0;
//}
//#include <cstdio>
//#include <iostream>
//#include <vector>
//#include<algorithm>
//#include <functional>
//using  namespace std;
//#define test 1
//
//int main()
//{
//	//#if  test
//	//	ifstream fin("c:\\Users\\Tswords\\Desktop\\testData.txt"); 
//	//	if(fin.fail())
//	//		return 1;
//	//	streambuf *cinbackup; 
//	//	cinbackup=cin.rdbuf(fin.rdbuf());
//	//#endif
//	#if test
//		FILE *fin;	/*重定向stdin到一个文件*/
//		fin=freopen("c:\\Users\\Tswords\\Desktop\\testData.txt","r",stdin);
//		if(fin==NULL)
//			return 1;	/*打开文件失败*/
//	#endif
//
//	int b,a,a1=0,a2=0,a3=0,jud=-1;
//	bool ctrl1 = true;
//	float ave = 0;
//	vector<int> a4, a5;
//	scanf("%d", &b);
//	for (int c = 0;(c<b)&&scanf("%d", &a);c++)
//	{
//		if (((a % 5) == 0) && ((a % 2) == 0))
//			a1 += a;
//		else if((a%5)==1){
//			ctrl1 ? a2 += a : a2 -= a;
//			ctrl1 = ctrl1^true;
//			jud++;
//		}
//		else if ((a % 5) == 2) {
//			a3++;
//		}
//		else if ((a % 5) == 3) {
//			a4.push_back(a);
//		}
//		else if ((a % 5) == 4) {
//			a5.push_back(a);
//		}
//	}
//	for (int i = 0; i < a4.size(); i++)
//		ave += a4[i];
//	if(a5.size()!=0)
//		sort(a5.begin(), a5.end(), greater<int>());
//	//show result
//	(a1 == 0) ? printf("N") : printf("%d", a1);
//	(jud==-1) ? printf(" N") : printf(" %d", a2);
//	(a3 == 0) ? printf(" N") : printf(" %d", a3);
//	(a4.size() == 0) ? printf(" N") : printf(" %.1f", ave / a4.size());
//	(a5.size()== 0) ? printf(" N") : printf(" %d", a5[0]);
//	//printf("%d %d %d %.1lf %d",a1,a2,a3,ave/a4.size(),a5[0]);
//	return 0;
//}