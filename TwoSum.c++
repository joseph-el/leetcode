# include <iostream>
# include <iterator>
# include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ret;
        vector<int>::iterator it1 = nums.begin();
        vector<int>::iterator it2 = nums.begin();

        for (; it1 != nums.end(); it1++) {
            for (it2 = it1 + 1; it2 != nums.end(); it2++)
            {
                if (*it1 + *it2 == target) {
                    ret.push_back(std::abs(std::distance(it1, nums.begin())));
                    ret.push_back(std::abs(std::distance(it2, nums.begin())));
                    return ret;
                }
            }
            
        }
        throw std::out_of_range("i can`t find");
    }
};


int main( void ) {

Solution ret;

vector<int> ss;
// 2,7,11,15]
// [3,2,4], target = 6
ss.push_back(3);
ss.push_back(2);
ss.push_back(4);
// ss.push_back(15);
// ss.push_back(88);

try {
    std::vector<int> result = ret.twoSum(ss, 6);
    std::vector<int>::iterator it = result.begin();
    std::cout << "[ " << *it << ", " << *++it << "]" << std::endl;
}
catch (std::exception &e) {
    cout << e.what() << endl;
}

}