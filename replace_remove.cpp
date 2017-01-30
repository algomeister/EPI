#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

void replace_remove(string str,int start,int a, int b)
    {
    int end = str.size();
    b = str.find_first_of("b",start);
    a = str.find_first_of("a",start);
    if((a<b) || ((a>0) && b==(-1)))
        {
        str[a] = 'd';
        for(int i=end-1;i>a;i--)
            {
            str[i] = str[i-1];
        }
        start = a+2;
        replace_remove(str, start, a, b);
    }
    else if((b<a) || ((b>0 || b==0) && (a==(-1))))
        {
        for(int i=b;i<end;i++)
            {
            str[i] = str[i+1];
        }
        start = b;
        replace_remove(str, start, a, b);
    }
    else
        cout << str << endl;
}
int main()
    {
    string str = "abrakadabra cobble stone board abroad      ";
    int start = 0, a = 0, b = 0, end = str.size();
    replace_remove(str, start, a, b);
}
