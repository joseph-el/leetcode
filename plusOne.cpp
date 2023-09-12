# include "includes/leetcode.hpp"


// solution one
vector<int> plusOne___(vector<int>& digits) {
    
    if (digits.empty())
        throw "else";
    std::vector<int>::iterator it = digits.begin();
    long long nums = 0;
    for (; it != digits.end(); it++){
        nums*= 10;
        nums+= *it;
    }
    nums+=1;
    cout << "check nums : " << nums << endl; 
    std::vector<int> ret;
    while (nums) {
        ret.push_back(nums % 10); 
        nums /= 10;
    }
    return ret;
}

vector<int> plusOne(vector<int>& digits) {

    if (digits.empty())
        throw "else";

    std::vector<int> ret;
    std::vector<int>::iterator it = digits.end();
    it--;
    bool rem = (*it == 9) ? true : false;
    int  num = rem ? 0 : *it + 1;
    for (; it != digits.begin() ;) {
        ret.push_back(num); //    100
        it--;
        if (*it == 9 and rem)
            num = 0, rem = true;
        else if (rem)
            num = *it + 1, rem = false;
        else
            num = *it;
    }
    if (*it == 9 and rem)
        ret.push_back(0), ret.push_back(1);
    else 
        ret.push_back(num);
    
    std::vector<int> convert;
    std::vector<int>::iterator cn = ret.end();
    cn--;
    for (; true ; cn--){
        convert.push_back(*cn);
        if (cn == ret.begin())
            break;
    }
    ret.clear();
    return convert;
}


int main() {

    vector<int> ret;

    // ret.push_back(1);
    // ret.push_back(9);
    // ret.push_back(9);

    // array<int, 39> arr = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
    array<int, 10> arr = {9,8,7,6,5,4,3,2,1,0};
    // array<int, 4> arr = {2,0,9,9};

    for (size_t i = 0; i < arr.size(); i++)
    {
        ret.push_back(arr[i]);
        // cout << "check : [" << ret[i] << "]" << endl; 
    }
    
    std::vector<int>::iterator it = ret.begin();

    for(;it != ret.end(); it++) {
        cout << "[" << *it << "]";
    }
    cout << endl;

    vector<int> ii = plusOne(ret);
    it = ii.begin();

    for (; it != ii.end(); it++){
        cout << "[" << *it << "]";
    }
    cout << endl;
    
}