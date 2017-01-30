#include <iostream>
using namespace std;

int main()
{
	int arr[9][9];
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin >> arr[i][j];
		}
	}
	int check[90];
	for(int i=0;i<90;i++)
		check[i]= 0;
	int m, flag = 0;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(arr[i][j])
			{
				m = (i/3)*3 + j/3;
				check[arr[i][j] + m*10] += 1;
				if(check[arr[i][j] + m*10] > 1)
				{
					cout << "Oops1111!" << " i= " << i << " j= " << j << endl;
					flag = 1;
				}
			}
		}
	}
	for(int i=0;i<90;i++)
		check[i]= 0;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(arr[i][j])
			{
				check[arr[i][j] + i*10] += 1;
				if(check[arr[i][j] + i*10] > 1)
				{
					cout << "Oops2222222!" << " i= " << i << " j= " << j << endl;
					flag = 1;
				}
			}
		}
	}
	for(int i=0;i<90;i++)
		check[i]= 0;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(arr[j][i])
			{
				check[arr[j][i] + i*10] += 1;
				if(check[arr[j][i] + i*10] > 1)
				{
					cout << "Oops33333333!" << " i= " << i << " j= " << j << endl;
					flag = 1;
				}
			}
		}
	}
	if(!flag)
		cout << "Everything's Perfect";
}
