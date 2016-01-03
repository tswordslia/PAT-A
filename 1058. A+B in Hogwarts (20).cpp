#include <iostream>
#include <fstream>
#include <string>
#define test 1
using namespace std;
/*原始代码留着...我都搞不懂我自己搞得那么复杂干什么....*/
//void calculator(long a[],string sub)
//{
//	int rear = 0,front=0;
//	for (int i = 0; i < 2; i++) {
//		rear =sub.find('.', front);
//		a[i] = stoi(sub.substr(front, rear));
//		front = rear+1;
//	}
//	a[2] = stoi(sub.substr(front, sub.size()));
//}
int main() {

	#if  test
		ifstream fin("c:\\Users\\Tswords\\Desktop\\testData.txt"); 
		if(fin.fail())
			return 1;
		streambuf *cinbackup; 
		cinbackup=cin.rdbuf(fin.rdbuf());
	#endif
	string num,getNumA, getNumB;
	long finall1[3] = {0}, finall2[3] = { 0 };
	char c;
	//int i = -1;
	//getline(cin, num);
	//i=num.find(' ', 0);
	//getNumA = num.substr(0, i);
	//getNumB = num.substr(i+1, num.size());
	//calculator(finall1, getNumA);
	//calculator(finall2, getNumB);
	cin >> finall1[0] >> c >> finall1[1] >> c >> finall1[2];
	cin >> finall2[0] >> c >> finall2[1] >> c >> finall2[2];
	for (int i = 2; i >=0; i--){
		switch (i)
		{
		case 2:
			finall1[i - 1] += (finall1[i] + finall2[i]) / 29;
			finall1[i] = (finall1[i] + finall2[i]) % 29;
			break;
		case 1:
			finall1[i - 1] += (finall1[i] + finall2[i]) / 17;
			finall1[i] = (finall1[i] + finall2[i]) % 17;
			break;
		case 0:
			finall1[i] = (finall1[i] + finall2[i]);
			break;
		default:
			break;
		}
	}
	cout << finall1[0] << '.' << finall1[1] << '.' << finall1[2];
	return 0;
}