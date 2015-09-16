#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define theMaxUsers 10000
#define theMaxSubmittions 100000
#define theMaxProblems 5
#define Min(a,b) ((a)<(b)?(a):(b))
typedef struct {
	int id;
	int problemId;
	int score;
}submittion;
typedef struct {
	int userId;
	char problems[theMaxProblems];
	int perfect[theMaxProblems];
	int total;
	int numberOfPerfect;
	int rank;
}information;
submittion totalSubmittion[theMaxSubmittions];
information users[theMaxUsers];
int theFullMark[theMaxProblems];	//the highest score of each problems.
int comp(const void*a,const void*b)
{
	if((*(information*)a).total!=(*(information*)b).total)
		return (*(information*)b).total-(*(information*)a).total;
	else if((*(information*)a).numberOfPerfect!=(*(information*)b).numberOfPerfect)
		return (*(information*)b).numberOfPerfect-(*(information*)a).numberOfPerfect;
	else 
		return (*(information*)a).userId-(*(information*)b).userId;
}
int main()
{
	int n,k,m;/*the total number of users ; the number of problems ;  the total number of submittions*/
	int i,j,index=0,ranked=1000000,thePastNumber=0,flag=0;
	char tmp;
	scanf("%d %d %d",&n,&k,&m);
	for(i=0;i<k;i++)
		scanf("%d",&theFullMark[i]);
	for(i=0;i<n;i++){
		users[i].userId=i+1;	//id of user

		for(j=0;j<5;j++){
			users[i].problems[j]='-';	//inital to never submitted 
			users[i].perfect[i]=0;		//��ʼû�������÷�		
		}
	}
	for(i=0;i<m;i++){
		scanf("%d %d %d",&totalSubmittion[i].id,&totalSubmittion[i].problemId,&totalSubmittion[i].score);
		if(totalSubmittion[i].score!=-1){	//ͨ�������������ҵ÷ֲ�Ϊ0���ύ�÷�&&totalSubmittion[i].score!=0
			if(users[totalSubmittion[i].id-1].problems[totalSubmittion[i].problemId-1]!='-'){
				if(totalSubmittion[i].score>users[totalSubmittion[i].id-1].problems[totalSubmittion[i].problemId-1]){	//�����ǰ�Ѿ��ù��֣���Աȷ�����С
					users[totalSubmittion[i].id-1].problems[totalSubmittion[i].problemId-1]=totalSubmittion[i].score;		//�滻��ø��߷�
				}
			}else 	/*	��ʱ��δ�ù���,��һ�ε÷�*/
				users[totalSubmittion[i].id-1].problems[totalSubmittion[i].problemId-1]=totalSubmittion[i].score;
			if(users[totalSubmittion[i].id-1].problems[totalSubmittion[i].problemId-1]==theFullMark[totalSubmittion[i].problemId-1])	//perfect score
				users[totalSubmittion[i].id-1].perfect[totalSubmittion[i].problemId-1]=1;	//Ϊ1���ʾ������Ѿ�����
		}else if(totalSubmittion[i].score==-1&&users[totalSubmittion[i].id-1].problems[totalSubmittion[i].problemId-1]=='-')	//δͨ����������������ǰû�еù���
			users[totalSubmittion[i].id-1].problems[totalSubmittion[i].problemId-1]=-1;	//��¼��û��ͨ��������
		
	}
	for(i=0;i<n;i++){
		flag=0;
		for(j=0;j<k;j++){
			if(users[i].problems[j]=='-'||users[i].problems[j]==-1){
				//users[i].total+=0;
				flag++;
			}
			else
				users[i].total+=users[i].problems[j];
			if(users[i].perfect[j]==1)
				users[i].numberOfPerfect++;	//����
		}		
		if(flag==k)		//����û�ύ����û�б���ͨ��
			users[i].total=-100000;		//����һ���������
	}
	qsort(users,n,sizeof(information),comp);	//sorting for age in increasing
	for(i=0;i<n&&users[i].total>=0;i++){
		if(ranked>users[i].total){
			users[i].rank=i+1;
			ranked=users[i].total;
		}else
			users[i].rank=users[i-1].rank;
		printf("%d %.5d %d",users[i].rank,users[i].userId,users[i].total);
		for(j=0;j<k;j++){
			if(users[i].problems[j]!='-'&&users[i].problems[j]!=-1)
				printf(" %d",users[i].problems[j]);
			else if(users[i].problems[j]==-1)
				printf(" 0");
			else 
				printf(" %c",users[i].problems[j]);
			
		}
		printf("\n");
	}
	return 0;
}