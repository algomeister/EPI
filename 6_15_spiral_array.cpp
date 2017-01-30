#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

template <class T>
void print(T a)
    {
    cout << a << " ";
}

int main()
    {
    int arr[6][6];
    for(int i=0;i<6;i++)
        {
        for(int j=0;j<6;j++)
            {
            arr[i][j] = 6*i+j+1;
        }
    }
    int n = (sizeof arr/sizeof arr[0]), k = n, l = n, i = 0, j = 0, x = 0;
    while(x<n*n)
        {
        while((j<l) && (i==(n-k)) && x<n*n)
            {
            print(arr[i][j]);
            x++;
            if(j!=(l-1))
                j++;
            else
                i++;
        }
        while((i<k) && (j==l-1) && x<n*n)
            {
            print(arr[i][j]);
            x++;
            if(i!=(k-1))
                i++;
            else
                j--;
        }
        k--;
        while((j>(n-l-1)) && (i==k) && x<n*n)
            {
            print(arr[i][j]);
            x++;
            if(j!=(n-l))
                j--;
            else
                i--;
        }
        while((i>(n-k-1)) && (j==(n-l)) && x<n*n)
            {
            print(arr[i][j]);
            x++;
            if(i!=(n-k))
                i--;
            else
                j++;
        }
        l--;
    }
}
