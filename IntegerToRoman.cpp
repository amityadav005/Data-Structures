#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char *huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int   size[] = { 0,   1,    2,     3,    2,   1,    2,     3,      4,    2};
    char  res[100];
    int index = 0;
    int val = 600;
    while (val >= 1000) {
        res[index] = 'M';
        val -= 1000;
        index++;
    }



    strcpy (res+index, huns[val/100]); index += size[val/100]; val = val % 100;
    strcpy (res+index, tens[val/10]);  index += size[val/10];  val = val % 10;
    strcpy (res+index, ones[val]);     index += size[val];



    res[index] = '\0';
    cout<<res;
}