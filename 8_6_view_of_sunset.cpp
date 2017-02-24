#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
class Stack
{
    private:
    stack<T> s;

    public:

    void viewOfSunset(vector<T>& vec)
        {
    	int i = 0;
        while(i<vec.size())
            {
            if(!s.empty())
                {
                if(vec[i]>=s.top())
                    {
                    s.pop();
                }
                else
                    {
                    s.push(vec[i]);
                    i++;
                }
            }
            else
                {
                s.push(vec[i]);
                i++;
            }
        }
    }

    void printBuildingHeights()
        {
        while(!s.empty())
            {
            cout << s.top() << endl;
            s.pop();
        }
    }
};

int main()
{
    Stack<int> S;
    vector<int> vec;
    vec.push_back(15);
    vec.push_back(13);
    vec.push_back(18);
    vec.push_back(14);
    vec.push_back(16);
    vec.push_back(15);
    vec.push_back(17);
    vec.push_back(18);
    vec.push_back(13);
    vec.push_back(10);
    S.viewOfSunset(vec);
    S.printBuildingHeights();
    return 0;
}
