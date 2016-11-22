//
// Created by Amit on 11/3/2016.
//
#include<iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void nextGreater(char *s) {
    int l = strlen(s);
    int i;
    int idx;
    for (int i = l - 2; i >= 0; i--) {
        if (s[i] < s[i + 1]) {
            idx = i;
            break;
        }
    }
    int small = idx + 1;
    for (int j = idx + 1; j < l; j++) {
        if (s[j] > s[idx] && s[j] < s[small])
            small = j;
    }
    int t = s[idx];
    s[idx] = s[small];
    s[small] = t;

    sort(s + idx + 1, s + l);

    cout << s;
}

int main() {

    char s[] = "534976";
    nextGreater(s);
}

