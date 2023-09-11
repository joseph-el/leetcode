# include "inc.hpp"


int searchInsert(vector<int>& nums, int target) {
    if (nums.empty())
        return 0;
    
    // std::vector<int>::iterator it = nums.begin();
    int i = 0;
    for (; i < nums.size() and nums[i] <= target;i++) {
    }
    // cout << "check i " << i << endl;
    if (i)
        i -= nums[i-1] == target ? 1 : 0;
    if (i == nums.size())
        return nums.size();
    if (nums[i] == target and i == 0)
        return 0;
    return i;
}

// int searchInsert(vector<int>& nums, int target) {
//     if (nums.empty())
//         return 0;
    
//     std::vector<int>::iterator it = nums.end();
//     it --;
//     for (;  *it >= target and it != nums.begin() ;it--) {}

    
//     6 
//     [1 2 3 4 5 8 99]


//     if (*it != target) 
//         static_cast<int>(std::distance(nums.begin(), it)) + 1 ;
    

//     return static_cast<int>(std::distance(nums.begin(), it));
// }

int main() {

    vector<int> ret;


    ret.push_back(1);
    ret.push_back(3);
    ret.push_back(5);
    ret.push_back(6);


    std::cout << ": " << searchInsert(ret,0) << endl;
}