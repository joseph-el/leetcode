# include <string>
# include <iostream>
# include <iterator>
# include <algorithm>

using namespace std;

class Solution {
public:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
    int romanToInt(string s) {
        int result = 0;
        std::string::iterator it = s.begin();

        if (s.find_first_not_of("IVXLCDM") != std::string::npos or s.empty())
            return -1;

        for (; it != s.end(); it ++) {
            short find =    (*it == 'I') * 1 + \
                            (*it == 'V') * 2 + \
                            (*it == 'X') * 3 + \
                            (*it == 'L') * 4 + \
                            (*it == 'C') * 5 + \
                            (*it == 'D') * 6 + \
                            (*it == 'M') * 7;
            
            std::cout << "check find >" << find << std::endl;
            std::cout << "check it >" << *it << std::endl;

            switch (find) {
                case  1 : {
                    if (it + 1 != s.end() and strchr("VX", *(it + 1))) {
                        result += (*(it + 1) == 'V') ? 4 : 9;
                        it ++;
                    }
                    else
                        result += 1;
                }
                    break;
                case  2 :
                    result += 5;
                    break;
                case  3 : {
                    if (it + 1 != s.end() and strchr("LC", *(it + 1))) {
                        result += (*(it + 1) == 'L') ? 40 : 90;
                        it ++;
                    }
                    else
                        result += 10;
                }
                    break;
                case  4 :
                    result += 50;
                    break;
                case  5 : {
                    if (it + 1 != s.end() and strchr("DM", *(it + 1))) {
                        result += (*(it + 1) == 'D' ? 400 : 900);
                        it ++;
                    }
                    else
                        result += 100;
                }
                    break;
                case  6 :
                    result += 500;
                    break;
                case  7 :
                    result += 1000;
                    break;
                default : 
                    ;
            };
            std::cout << "check result >" << result << std::endl;
        }
        return (result > 3999 or result < 1 ? -1 : result);
    }
};


// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000


// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.

// IV + IX
// XL + XC
// CD + CM

int main()
{
    Solution ret;

    std::cout << ret.romanToInt("MMMXLV") << std::endl;
}