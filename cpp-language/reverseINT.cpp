# include "../includes/leetcode.hpp"
# include <limits.h>

using ss = long long;

ss __fill(ss,ss base = 0xa);

int reverse(int x) {
    if (!x)
        return x;

    bool _signed;
    x *= (_signed = (x < 0)) ? -1 : 1; 
    int res = {0};

    debut:
        res = (__fill(res, 0xa) + (x % 0xa));
        if (res > INT_MAX or res < INT_MIN)
            return 0;
        x /= 0xa;
        
        if (x) goto debut;
        

        // 3
        // 2
        // 1



        // res | 3
        // /*
        //     0000000101001000
             
        // */

// unsigned char t = 0xc2; // 11000010 
// unsigned char q = 0xa3; // 10100011

// unsigned short s = (((unsigned short)t)<<8) | q;
    return _signed ? -res : res; 
}

ss __fill(ss a, ss b ) {
    ss result = 0;
    while (b)             
    {
        if (b & 1)               
            result += a; 
        a <<= 1;                                     
        b >>= 1;                 
    }
    return result;
} 

int main() 
{
    cout << "res: " << reverse(1239999999) << endl;
}