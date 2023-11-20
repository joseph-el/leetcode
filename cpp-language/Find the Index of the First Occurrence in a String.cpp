# include "leetcode.hpp"



int strStr(string haystack, string needle) {
    if (needle.empty() or needle.empty())
        return -1;
int i = 0;
    try {
        for (; haystack.substr(i, needle.length()) != needle ; i++);
    }
    catch (...) {
        return -1;
    }

    return i;
}
