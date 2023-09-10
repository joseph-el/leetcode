# include "inc.hpp"


int removeElement(vector<int>& nums, int val) {

    if (nums.empty())
        return 0;
    std::vector<int>::iterator it = nums.begin();

    for (; it != nums.end(); ) {
        if (*it == val) {
            nums.erase(it);
            if (nums.empty())
                break;
            it = nums.begin();
            continue;
        }
        it++;
    }
    return static_cast<int>(nums.size());
}


int main () {

    std::vector<int> ret;

    ret.push_back(2);
    ret.push_back(2);
    // ret.push_back(33);
    // ret.push_back(55);
    // ret.push_back(99);
    // ret.push_back(2);
    // ret.push_back(2);
    // ret.push_back(4);
    // ret.push_back(1);
    // ret.push_back(2);

    removeElement(ret, 2);

for (int i = 0; i < ret.size(); i++)
{
    cout << ": " << ret[i] << endl; 
}


    
}