
#include "inc.hpp"

string getPrefix(std::string s1, std::string s2) {
    std::string::iterator it1 = s1.begin();
    std::string                 prefix("");
    int                         x = 1;

    for (;it1 != s1.end();it1++) {
        std::string::iterator it2 = s2.begin();
        for (; it2 != s2.end(); it2++) {
            if (*it1 == *it2) {
                while (  s2.substr(std::distance(s2.begin(), it2), x) ==  s1.substr(std::distance(s1.begin(), it1), x)  and (it1 + x) != s1.end())
                    x++;
                if (prefix.length() < s1.substr(std::distance(s1.begin(), it1), x).length()) {
                    prefix = s1.substr(std::distance(s1.begin(), it1), x-1);
                }
                x = 1;
            }
        }
    }
    return (prefix);
}

string longestCommonPrefix(vector<string>& strs) {

    if (strs.empty())
        return "";
    if (strs.size() == 1)
        return strs[0];
    std::string prefix = getPrefix(strs[0], strs[1]);
    std::vector<string>::iterator it = strs.begin();
    it += 2;
    for (; it != strs.end() ; it++)
    {
        prefix = getPrefix(prefix, *it);
        if (prefix.empty())
            return "";
    }
    return prefix;
}

int main ( void ) 
{   
    std::vector<string> ret;

    ret.push_back("");
    std::cout << "The result : " << longestCommonPrefix(ret) << endl;
}