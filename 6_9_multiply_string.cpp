#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main()
    {
    string a = "-123456789012345678901234567890", b = "-123456789";
    int len1, len2, f1 = 0, f2 = 0;
    if(a[0] == '-')
        {
        len1 = a.size() - 1;
        f1 = 1;
    }
    else
        len1 = a.size();
    if(b[0] == '-')
        {
        len2 = b.size() - 1;
        f2 = 1;
    }
    else
        len2 = b.size();
    int ans[len1+len2], carry = 0;
    if((a[0]-'0' == 0) || (b[0]-'0' == 0))
        cout << "zero" << endl;
    else
        {
        for(int i=0;i<len1+len2;i++)
            ans[i] = 0;
        int m = a.size() - len1 - 1, n = b.size() - len2;

        for(int i=(a.size()-1);i>m;i--)
            {
            for(int j=(b.size()-1);j>=n || carry;j--)
                {
                int x = ans[i+j-m-n] + carry;
                if(j>=f2){
                    x += (a[i] - '0')*(b[j]-'0');
                }
                ans[i+j-m-n] = x%10;
                carry = x/10;
            }
        }
        int flag = 0;
        for(int i=0;i<(len1+len2);i++)
            {
        	if(!flag)
        		flag += ans[i];
            if(((f1+f2)==1) && i==0)
                cout << '-';
            else if(flag)
                cout << ans[i];
        }
    }
}
