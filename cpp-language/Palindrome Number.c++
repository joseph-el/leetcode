# include <iostream>
# include <iterator>
# include <vector>
# include <string>

class Solution {
public:

    bool isPalindrome(int x) {
        int save = x;
        std::string result;
        while (x) {
            result += std::to_string(x % 10);
            x /= 10;
        }
        if (atoi(result.c_str()) == save)
            return true;
        return false;
    }
};


// int main()
// {
//     Solution ret;

//     std::cout << (ret.isPalindrome(121) ? "true" : "false") << std::endl;



//     // int x  = 8;
//     // // x/= 10;
//     // std::cout << x % 10;
// }