#include <iostream>
using namespace std;
int delay[20][2];//this will give adjeascent routers and there delay
int table[20][20];//[router] [distance router path]
int target,total,adj;
int R1[20];//distance
int R2[20];//line or router to use
void input()
{
	cout <<"Enter Total Number of Routers::";
	cin>>total;
	cout<<endl;
	cout<<"Note:: Router Id start from 0 till "<<(total-1)<<" "<<endl;
	cout <<"Enter Number of Target Router (whose table need to be formed)::";
	cin>>target;
	cout<<endl;
	
	cout <<"Enter number of routers adjascent to " <<target<< " router::";
	cin>>adj;
	cout<<endl;
	
	int i,j;
	for (i=0;i<adj;i++)
	{
		cout <<"Enter Id (Integer) of Router "<<i+1<<" adjascent to "<<target<<" router::";
		cin>>delay[i][0];
		cout <<endl;
		cout <<"Enter Estimated Delay of "<<delay[i][0]<<" router from "<<target<<" router::";
		cin>>delay[i][1];
		cout <<endl;
		cout<<"Enter Routing Table of "<<delay[i][0] <<":"<<endl;
		for (j=0;j<total;j++)
		{
			cout<<j<<"--> \t";
			if (j==delay[i][0])
			{
				table[delay[i][0]][j]=0;
				cout<<table[delay[i][0]][j]<<endl;
				continue;
			}
			cin>>table[delay[i][0]][j];
			cout<<endl;
		}
    }
}

void DVR()
{
	int i,j,min,min_point;
	for (i=0;i<total;i++)
	{
		R1[i]=-1;
		R2[i]=-1;
	}
	for (i=0;i<adj;i++)
	{
		R2[delay[i][0]]=delay[i][0];
		R1[delay[i][0]]=delay[i][1];
	}
	
	R1[target]=0;
	R2[target]=target;
	
	for (i=0;i<total;i++)
	{
		if (R1[i]==-1)
		{
			min=99999,min_point;
			for (j=0;j<adj;j++)
			{
				if (min> (table[delay[j][0]][i] + delay[j][1]) )
				{
					min=table[delay[j][0]][i] + delay[j][1];
					min_point=delay[j][0];
				}
			}
			R1[i]=min;
			R2[i]=min_point;
		}
	}
}

void display()
{
	int i,j;
	cout<<endl;
	cout<<"Routing table of "<<target<<" is::"<<endl;
	cout <<"Estimated Time\t\t" <<"Router to use"<<endl;
	for (i=0;i<total;i++)
	{
		cout<<R1[i]<<"\t\t"<<R2[i]<<endl;
	}
 } 
 
 int main()
 {
 	input();
 	DVR();
 	display();
 	return 0;
 }
