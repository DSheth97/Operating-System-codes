#include<stdio.h>
#include<iostream>

using namespace std;

int np,fs;
int *pagesq,*fsq;
int top=-1;
int k=0;
int hit=0;





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




void insert(int a)
{
	if(top!=fs-1)
	{
		if(ispresent(a)==1)
		{
			hit++;
		}
		else
		{
			fsq[++top]=a;
		}
	}
	else
	{
		if(ispresent(a)==1)
		{
			hit++;
		}
		else
		{
			fsq[k]=a;
			k++;
			if(k==fs)
				k=0;
		}
	}
}






void input()
{
	cout<<"Enter no of pages and frame size"<<endl;
	cin>>np>>fs;
	fsq=new int[fs];
	pagesq=new int[np];
	
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