// C++ program to evaluate all possible values of
// a expression
#include<bits/stdc++.h>
using namespace std;

// Utility function to evaluate a simple expression
// with one operator only.
int eval(int a, char op, int b)
{
    if (op=='+') return a+b;
    if (op=='-') return a-b;
    if (op == '*') return a*b;
}

// This function evaluates all possible values and
// returns a list of evaluated values.
vector<int> evaluateAll(string expr, int low, int high)
{
    // To store result (all possible evaluations of
    // given expression 'expr')
    vector<int> res;

    // If there is only one character, it must
    // be a digit (or operand), return it.
    if (low == high)
    {
        res.push_back(expr[low] - '0');
        return res;
    }

    // If there are only three characters, middle
    // one must be operator and corner ones must be
    // operand
    if (low == (high-2))
    {
        int num = eval(expr[low]-'0', expr[low+1],
                       expr[low+2]-'0');

        res.push_back(num);
        return res;
    }

    // every i refers to an operator
    for (int i=low+1; i<=high; i+=2)
    {
        // l refers to all the possible values
        // in the left of operator 'expr[i]'
        vector<int> l = evaluateAll(expr, low, i-1);

        // r refers to all the possible values
        // in the right of operator 'expr[i]'
        vector<int> r = evaluateAll(expr, i+1, high);

        // Take above evaluated all possible
        // values in left side of 'i'
        for (int s1=0; s1<l.size(); s1++)
        {
            // Take above evaluated all possible
            // values in right side of 'i'
            for (int s2=0; s2<r.size(); s2++)
            {
                // Calculate value for every pair
                // and add the value to result.
                int val = eval(l[s1], expr[i], r[s2]);
                res.push_back(val);
            }
        }
    }
    return res;
}

// Driver program
int main()
{
    string expr = "1*2+3*4";
    int len = expr.length();
    vector<int> ans = evaluateAll(expr, 0, len-1);

    for (int i=0; i< ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}
