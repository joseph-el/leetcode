# include "leetcode.hpp"


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    if (nums1.empty() and nums2.empty())
        return ;

    std::vector<int>::iterator it = nums2.begin();
    
    while (nums1.size() != m )
        nums1.pop_back();
    
    for (int i = 0;it != nums2.end() and i < n ;it++, i++)
        nums1.push_back(*it);

    std::sort(nums1.begin(), nums1.end());
}