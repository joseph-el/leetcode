# include "leetcode.hpp"


int searchInsert(vector<int>& nums, int target) {
    if (nums.empty())
        return 0;
    
    int i = 0;
    for (; i < nums.size() and nums[i] <= target;i++) {}
    // cout << "check i " << i << endl;
    if (i)
        i -= nums[i-1] == target ? 1 : 0;
    if (i == nums.size())
        return nums.size();
    if (nums[i] == target and i == 0)
        return 0;
    return i;
}

// int main() {

//     vector<int> ret;


//     ret.push_back(1);
//     ret.push_back(3);
//     ret.push_back(5);
//     ret.push_back(6);


//     std::cout << ": " << searchInsert(ret,0) << endl;
// }