// A C++ program to find floor(sqrt(x)
#include<bits/stdc++.h>
using namespace std;

// Returns floor of square root of x
float floorSqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
int count = 0;
    float start = 1, end = x, ans;
    float mid;
    while (start <= end)
    { count++;
        cout<<"count"<<count<<endl;
         mid = (start + end) / 2;

        if (mid*mid == x)
            return mid;

        if (mid*mid < x)
        {
            start = mid +0.0001;

        }
        else
            end = mid -0.0001;
    }
    cout<<"count"<<count<<endl;
    return mid;
}

// Driver program
int main()
{
    int x = 629;
    cout << floorSqrt(x) << endl;
    return 0;
}
