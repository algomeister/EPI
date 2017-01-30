#include <iostream>
using namespace std;

int main()
{
    int a[10] = {3,112,2,332,22,121,35,654,23,432};
    int i = 1, b[10], c[10], d[10], x=0, y=0, z=0;
	for(int j=0;j<10;j++)
	{
		if(a[j]<a[i])
		{
			b[x] = a[j];
			x++;
		}
		else if(a[j]==a[i])
		{
			c[y] = a[j];
			y++;
		}
		else
		{
			d[z] = a[j];
			z++;
		}
	}
	for(int j=0;j<10;j++)
	{
		if(j<x)
			a[j] = b[j];
		else if((j==x || j>x) && (j<(x+y)))
			a[j] = c[j-x];
		else
			a[j] = d[j-x-y];
	}
    for(int j=0;j<10;j++)
    {
	    cout << a[j] << endl;
    }
}
