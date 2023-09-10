# include "inc.hpp"


int searchInsert(vector<int>& nums, int target) {
    if (nums.empty())
        return 0;
    
    std::vector<int>::iterator it = nums.begin();

    for (; it != nums.end() and *it <= target; it++) {}

    if (it == nums.end())
        return static_cast<int>(std::distance(nums.begin(), nums.end()));
    else if (*it == target)
        return static_cast<int>(std::distance(nums.begin(), it));

    return static_cast<int>(std::distance(nums.begin(), it));
    
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


    std::cout << ": " << searchInsert(ret, 1) << endl;
}