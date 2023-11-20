# include "leetcode.hpp"

int mySqrt(int x) {

    long i = 1;
    while ( i * i <= x and i <= 46340 )
        i++;
    if (i * i == x)
        return i;

    return i - 1;
}

// int main() {


//     cout << mySqrt(2147483647) << endl;

// }