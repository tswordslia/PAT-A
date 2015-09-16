/* hi=(h(key)+i*i)％m 0≤i≤m-1 //即di=i^2,如果di=±i^2,则 0≤i≤m/2*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define theMaxSequence 10000
typedef struct 
{
	int Msize;
	int* table;
}hash;
int isPrime(int x){
	int i;
	if (x == 1) return 0;
	if (x == 2 || x == 3) return 1;
	for (int i = 2; i*i <= x; i++){
		if (x%i == 0)
			return 0;
	}
	return 1;
}
int insertHash(hash* t)
{
	int i,a,key,cNum,flag=0;
	scanf("%d",&a);
	key=a;//%t->Msize;
	for(i=0;i<t->Msize;i++){
		if(t->table[(key+i*i)%t->Msize]==0){
			t->table[(key+i*i)%t->Msize]=a;
			return (key+i*i)%t->Msize;
		}
	}
	return -1;
}
int main()
{
	int Msize,n,i=0,ctrl,flag=0;
	hash hashTable;
	scanf("%d %d",&Msize,&n);
	while(!isPrime(Msize))	//如果不是素数
		Msize++;
	hashTable.table=(int*)malloc(Msize*sizeof(int));
	memset(hashTable.table,0,Msize*sizeof(int));
	hashTable.Msize=Msize;
	for(i=0;i<n;i++){
		ctrl=insertHash(&hashTable);
		if(!flag)
			flag=1;
		else
			printf(" ");
		if(ctrl!=-1)
			printf("%d",ctrl);
		else
			printf("-");
	}
	return 0;
}