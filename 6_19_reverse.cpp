#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main()
    {
    string a;
    getline(cin,a);
    int start=0, end=a.size()-1, x=a.find_first_of(" ",start), y=a.find_last_of(" ",end);
    while(x<=y)
        {
        char c;
        int l = x - start;
        int m = end - y;
        if(l>m)
            {
            for(int i=start;i<(start+m);i++)
                {
                c = a[i];
                a[i] = a[y+(i-start)+1];
                a[y+(i-start)+1] = c;
            }
            for(int i=0;i<(l-m);i++)
                {
                int k = start+m;
                c = a[k];
                for(int j=k;j<end;j++)
                    {
                    a[j] = a[j+1];
                }
                a[end] = c;
            }
        }
        else if(l<m)
            {
            for(int i=end;i>(end-l);i--)
                {
                c = a[i];
                a[i] = a[x+(i-end)-1];
                a[x+(i-end)-1] = c;
            }
            for(int i=0;i<(m-l);i++)
                {
                int k = end-l;
                c = a[k];
                for(int j=k;j>start;j--)
                    {
                    a[j] = a[j-1];
                }
                a[start] = c;
            }
        }
        else
            {
            for(int i=start;i<(start+m);i++)
                {
                c = a[i];
                a[i] = a[y+(i-start)+1];
                a[y+(i-start)+1] = c;
            }
        }
        int temp = start;
        start += end-y+1;
        end -= x-temp+1;
        x = a.find_first_of(" ",start+1);
        y = a.find_last_of(" ",end-1);
    }
    cout << a << endl;
}
