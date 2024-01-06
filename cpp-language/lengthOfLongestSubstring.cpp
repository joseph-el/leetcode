#include "leetcode.hpp"

const char *s = "abcabcbb";

int lengthOfLongestSubstring(string s) {

    string ret("");
    int result = 0;

    for (char ch : s) {
        if (ret.find(ch) == string::npos) {
            ret += ch;
        }
        else {
            if (result < ret.length())
                result = ret.length();
            ret = ret.substr(ret.find(ch) + 1);
            ret += ch;
        }
    }

    if (result < ret.length())
        result = ret.length();

    return result;
}