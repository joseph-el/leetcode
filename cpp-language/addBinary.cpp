# include "leetcode.hpp"

int toInt(string binary) {
    int res = 0;

    std::string::iterator it = binary.end();
    it --;
    int power = 0;

    for (; true ; it--, power++) {
        // cout << "check it : " << *it << endl;
        // cout << "check pow : " << (int)pow(power, 2) << endl;
        // cout << "check : " << static_cast<int>( pow(power, 2) * (*it - 48) ) << endl;
        res += pow(2, power) * (*it - 48);
        if (it == binary.begin())
            break;
    }
    return res;
}

// solution 1

string addBinary___(string a, string b) {
    string ret("");
    if (a.empty() or b.empty())
        return "";
    int int_of_a = toInt(a), int_of_b = toInt(b);
    int_of_a += int_of_b;
    if (!int_of_a)
        return "0";
    while (int_of_a) {
        char c = "01"[int_of_a%2];
        ret.push_back(c);
        cout << c;
        int_of_a/= 2;
    }
    return "conver";
}


string addBinary(string a, string b) {
    
    if (a.empty() or b.empty())
        return "";

    if (a.length() < b.length()) {
        std::string ret;
        size_t i = 0;
        for (; i < ( b.length() - a.length() ) ; i++)
            ret.push_back('0');
        for (i = 0; i < a.length(); i++)
            ret.push_back(a[i]);
        a.clear(), a = ret;  
    }
    else if (a.length() > b.length()) {
        std::string ret;
        size_t i = 0;
        for (; i < ( a.length() - b.length() ) ; i++)
            ret.push_back('0');
        for (i = 0; i < b.length(); i++)
            ret.push_back(b[i]);
        b.clear(), b = ret;  
    }
    // std::string::iterator it1 = a.begin();
    // std::string::iterator it2 = b.begin();

    // for (;it1 != a.end();it1++)
    // cout << *it1 << " ";
    // cout <<endl;
    // for (;it2 != b.end();it2++)
    // cout << *it2 << " ";
    // cout <<endl;
    std::string::iterator it1 = a.end();
    std::string::iterator it2 = b.end();
    string ret("");
    bool rem = false;

    it2--,it1--;
    for (; true ; it1--, it2--) {

        if (*it1 == '1' and *it2 == '1') {
            ret.push_back(rem ? '1' : '0');
            rem = true;
        }
        else if (*it1 == '0' and *it2 == '0') {
            ret.push_back(rem ? '1':'0');
            rem = false;
        }
        else {
            ret.push_back(rem ? '0' : '1');
        }
        if (it1 == a.begin() or it2 == b.begin())
            break;
    }

    if (rem)
        ret.push_back('1');
    
    string conver("");
    std::string::iterator it = ret.end();
    it--;
    for ( ; true ; it--) {
        conver.push_back(*it);
        if (it == ret.begin())
            break;
    }
    ret.clear();
    return conver;
}


// int main() {
//     // cout << "101010\n";
//     // cout << toInt("101010") << endl;

    
//     cout << addBinary("0", "0") << endl;
// }