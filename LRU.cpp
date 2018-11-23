#include<stdio.h>
#include<iostream>

using namespace std;

int np,fs;
int *fsq;
int *pagesq;
int top=-1;
int *count;
int hit=0;


void printcount()
{
	for(int i =0;i<fs;i++)
		cout<<"count["<<i<<"] = "<<count[i]<<"\t";
	cout<<endl;
}




void increasecounttilltop(int m)
{
	for(int i=0;i<m+1;i++)
		count[i]+=1;
}

int ispresent(int a)
{
	int flag=0;
	for(int i=0;i<fs;i++)
	{
		if(fsq[i]==a)
			flag=1;
	}
	return flag;
	
}

int returnindex(int a)
{
	int flag=0,pos;
	for(int i=0;i<fs;i++)
	{
		if(fsq[i]==a)
		{
			flag=1;
			pos=i;
			break;
		}
	}
	return pos;
}

int returnmaxcountindex()
{
	int max=-1,pos;
	for(int i=0;i<fs;i++)
	{
		if(count[i]>max)
		{
			max=count[i];
			pos=i;
		}
	}
	return pos;
	
}

void insert(int a)
{
	if(top!=fs-1)
	{
		if(ispresent(a)==1)
		{
			hit++;
			increasecounttilltop(top);
			count[returnindex(a)]=1;
			
		}
		else
		{
			fsq[++top]=a;
			increasecounttilltop(top);
		}
	}
	else
	{
		if(ispresent(a)==1)
		{
			hit++;
			increasecounttilltop(top);
			count[returnindex(a)]=1;
		}
		else
		{
			int ind = returnmaxcountindex();
			fsq[ind]=a;
			increasecounttilltop(top);
			count[ind]=1;
		}
	}
}






void input()
{
	cout<<"Enter no of pages and frame size"<<endl;
	cin>>np>>fs;
	fsq=new int[fs];
	pagesq=new int[np];
	count=new int[fs];
	
	for(int j=0;j<fs;j++)
	{
		count[j]=0;
	}
	
	for(int k=0;k<np;k++)
	{
		cin>>pagesq[k];
	}
	
	
	for(int i=0;i<np;i++)
	{
		insert(pagesq[i]);
	}
}






int main()
{
	input();
	cout<<"Hits = "<<hit;
	return 0;
}