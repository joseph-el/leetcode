#include <ios>
# include <iostream>
# include <string>
# include <iterator>



using namespace std;

class Solution {
public:

    struct token {
        int l_braces;
        int r_braces;

        int l_parentheses;
        int r_parentheses;

        int  l_square_brackets;
        int  r_square_brackets;

    };

    bool isValid(string s) {
        
        if (s.find_first_not_of("({[]})") != -1)
            return false;
        
        struct token ret;
        memset(&ret, 0, sizeof(struct token));

        std::string::iterator it = s.begin();
        try {
            for (; it != s.end(); it ++) {

                (*it == '}' and it+1 != s.end() and *(it+1) == '{') ? throw -2 : 0;
                (*it == ')' and it+1 != s.end() and *(it+1) == '(') ? throw -2 : 0;
                (*it == ']' and it+1 != s.end() and *(it+1) == '[') ? throw -2 : 0;

                (it + 1 != s.end() and *it == '[' and ( *(it+1) == ')' or *(it+1) == '}')) ? throw -2 : 0;
                (it + 1 != s.end() and *it == '(' and (*(it+1) == ']' or *(it+1) == '}' ))  ? throw -2 : 0;
                (it + 1 != s.end() and *it == '{' and (*(it+1) == ']' or *(it+1) == ')' ))  ? throw -2 : 0;


                ret.l_braces += (*it == '{');
                ret.r_braces += (*it == '}');

                ret.r_parentheses += (*it == '(');
                ret.l_parentheses += (*it == ')');


                ret.r_square_brackets += (*it == '[');
                ret.l_square_brackets += (*it == ']');
            }
        }
        catch (...) {
            return false;
        }



        bool check =      ( (ret.r_braces % 2 != 0 and ret.l_braces % 2 != 0 ) or \
                            (ret.l_parentheses % 2 != 0 and ret.r_parentheses % 2 != 0 ) or \
                            (ret.r_square_brackets % 2 != 0 and ret.l_square_brackets % 2 != 0 ) );

        if (check )
            return false;


        std::cout << "check > " << ret.l_braces << ret.r_braces << endl;
        std::cout << "check > " << ret.r_parentheses << ret.l_parentheses << endl;
        std::cout << "check > " << ret.r_square_brackets << ret.l_square_brackets << endl;

        bool validet =  ( ( ret.r_braces + ret.l_braces ) % 2 == 0  ) and \

                        ( ( ret.r_parentheses + ret.l_parentheses ) % 2 == 0) and \

                        ( ( ret.r_square_brackets + ret.l_square_brackets) % 2 == 0 );

        return validet ? true : false;

    }

};

int main()
{
    Solution ret;

    std::cout << (ret.isValid("(){}") ? "true" : "false") << endl;
}