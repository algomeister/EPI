#include <iostream>
#include <stdexcept>
#include <stack>
using namespace std;
using std::length_error;

template <typename T>
class Stack{

    public:
    T pop(){
        if(s.top())
            {
            T temp = s.top();
            s.pop();
            if(temp==m.top().first)
                {
                if(m.top().second>1)
                    m.top().second--;
                else
                    m.pop();
            }
            return temp;
        }
        else
            throw length_error("empty stack");
    }
    void push(const T &a){
        s.emplace(a);
        if(!m.empty())
            {
            if(a>m.top().first)
                m.emplace(a,1);
            else if(a==m.top().first)
                m.top().second++;
        }
        else
            m.emplace(a,1);

    }
    int max(){
        if(!m.empty())
            return m.top().first;
        else
            throw length_error("empty stack");
    }

    private:
    stack<int> s;
    stack<pair<T, int>> m;
};



int main(){
    Stack<int> s;
    s.push(2);
    s.push(3);
    s.push(7);
    s.push(5);
    s.push(9);

    cout << s.max() << endl;
    s.pop();
    cout << s.max() << endl;
    s.pop();
    cout << s.max() << endl;
    s.pop();
    cout << s.max() << endl;
    s.pop();
    cout << s.max() << endl;
    return 0;
}
