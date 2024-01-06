# include "../includes/leetcode.hpp"


#include <iostream>
using namespace std;

std::uint64_t concat1(const std::uint32_t& leftHalf, const std::uint32_t& rightHalf){
    std::uint64_t concatenated = leftHalf;
    concatenated <<= 32;
    concatenated |= rightHalf;
    
    return concatenated;
}

std::uint64_t concat2(const std::uint32_t& leftHalf, const std::uint32_t& rightHalf){
    std::uint64_t concatenated = (static_cast<std::uint64_t>(leftHalf) << 32) | rightHalf;
    
    return concatenated;
}

int main(__unused int ac, const char *atgv[]) {
    // int nb = 67;

    // while (nb) {
    //     if (nb & 1)
    //      cout << nb << endl;
    //     nb >>= 1;
    // }
    // return 1;
    unsigned char t = 0xc2; // 11000010 
    unsigned char q = 0xa3; // 10100011
    unsigned short s = (((unsigned short)t) << 8) | q;



    int x = 3;
    int y = 4;
    
    // 0000000000000011
    // 0000000000000100

    //  0000000000100010

    // 234

    // 4  
    // 3  
    // 2  

    // 4 << 1
    // 3 << 1
    // 2 << 1

    int32_t bitst = (4<<1) | (3<<1) << (2<<1);
    int num = 323;
    bitst = (num >> 4) | (num<< 4);

    cout << bitst << endl;


    // int res = (x << 8) | y;

    // cout << "check res :" << res << endl;

}