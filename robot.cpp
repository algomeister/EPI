#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
    {
    int n;
    cin >> n;
    int x[n], y[n], z[n];
    float max, min, cap;
    for(int i=0;i<n;i++)
        {
        cin >> x[i] >> y[i] >> z[i];
        if(i==0)
            {
            min = z[i];
            max = z[i];
        }
        if(i>0)
            {
            if(z[i]>max)
                max = z[i];
            if(z[i]<min)
                min = z[i];
        }
    }
    cap = max - min;
    cout << cap << endl;
}
