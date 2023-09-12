# include "includes/leetcode.hpp"
#include <vector>

int removeDuplicates(vector<int>& nums) {
    
    std::vector<int> ret;
    std::vector<int>::iterator it = nums.begin();
    if (nums.empty())
        return 0;
    if (it + 1 == nums.end())
        return 1;
    int actual = *it++;
    while (it != nums.end()) {
        if (*it==actual) {
            nums.erase(it);
            continue;
        }
        else {
            actual = *it++;
        }
    }
    return static_cast<int>(std::distance(nums.begin(), nums.end())) ;    
}

int main( void ) {

    vector<int> nums ;

    nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(1);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(3);
    // nums.push_back(4);
    // nums.push_back(3);
    // nums.push_back(5);
    // nums.push_back(7);

    int k = removeDuplicates(nums);
    std::cout << "show K >" << k << endl;



    // std::vector<int>::iterator it = nums.begin();

    // while (it != nums.end()) {
    //     if (*it == 2) {
    //         std::cout << "the current is > " << std::distance(nums.begin(), it) << endl;
    //         nums.erase(it);
    //         std::cout << "after earse <" << *it << endl;
    //         continue;
    //     }
    //     std::cout << "something else >" << *it << endl;
    //     it ++;
    // }

    std::vector<int>::iterator itr = nums.begin();

    for (;itr != nums.end(); itr++) {
        std::cout << "It = " << *itr << endl;
    }
    // int result = removeDuplicates(nums);





}

