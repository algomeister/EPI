#include <iostream>
#include <vector>
using namespace std;

string M[10] = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void phone_helper(string num, int d, string ans)
{
	if(d == num.size())
		cout << ans <<endl;
	else
	{
		for(char c : M[num[d] - '0'])
		{
			ans[d] = c;
			phone_helper(num, d+1, ans);
		}
	}
}

void phone(string num)
{
	string ans(num.size(), 0);
	phone_helper(num, 0 , ans);
}

int main()
    {
    string num;
    cin >> num;
    phone(num);
}
