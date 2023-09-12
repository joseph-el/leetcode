# include "includes/leetcode.hpp"


string getPrefix(std::string s1, std::string s2) {
    std::string::iterator it1 = s1.begin();
    std::string::iterator it2 = s2.begin();
    int                   x   = 1;

    if (s1.empty() or s2.empty())
        return ("");

    while (*it1 == *it2 and ( it2 != s2.end() and it1 != s1.end()) ) {
        it2++;
        it1++;
    }
    return (s1.substr(0, std::distance(s1.begin(), it1)));
}

string longestCommonPrefix(vector<string>& strs) {

    if (strs.empty())
        return "";
    if (strs.size() == 1)
        return strs[0];
    std::string prefix = getPrefix(strs[0], strs[1]);
    if (prefix.empty())
        return ("");
    // cout << "check prefix = " << prefix << endl;
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

    ret.push_back("flower");
    ret.push_back("flower");
    ret.push_back("flower");
    ret.push_back("flower");
// ","","
    // ret.push_back("flower");
    // ret.push_back("flow");
    // ret.push_back("flight");
    // ret.push_back("flight");


    std::cout << "The result : " << longestCommonPrefix(ret) << endl;
}