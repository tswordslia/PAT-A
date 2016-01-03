#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n,length;
	bool flag=true;
	string s,end,s1;
	vector<string> svec;
	cin>>n;
	cin.get();
	while(n--){
		getline(cin,s);
        reverse(s.begin(), s.end());  
        svec.push_back(s); 
	}
	s1=svec[0];
	length=s1.size();
	for(int i=1;i<svec.size();i++){
		for(int j=0;j<length;j++){
			if(s1[j]==svec[i][j]){
				continue;
			}else{
				length=j;
				break;
			}
		}
	}
	if(length==0)
		cout<< "nai" << endl; 
	else{
		for(int i=length-1;i>=0;i--)
			cout<<s1[i];
		cout<<endl;
	}
	return 0;
}