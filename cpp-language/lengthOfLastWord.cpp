# include "leetcode.hpp"

int lengthOfLastWord(string s) {
    if(s.empty())
        return 0;
    
    std::string::iterator it = s.end();
    it --;
    for (;it != s.begin() and isspace(*it);it--) {}

    std::string::iterator it1 = it;

    for (;it1 != s.begin() and !isspace(*it1);it1--) {}
    if (isspace(*it1))
        it1++;
    
    // cout << "check it1 |" << *it1 << "|" << endl;
    // cout << "check substr |" << s.substr(std::distance(s.begin(), it1), abs(distance(s.begin(), it) - distance(s.begin(), it1)) + 1) << "|" << endl;
    
    return s.substr(std::distance(s.begin(), it1), abs(distance(s.begin(), it) - distance(s.begin(), it1)) + 1).length();
}

// int main() {
//     string s("hello");

//     cout << "check lenght : " << lengthOfLastWord(s) << endl;
// }