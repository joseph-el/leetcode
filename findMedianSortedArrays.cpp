# include "includes/leetcode.hpp"

/*
    [1,2,3,4,8]
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    if (nums1.empty() and nums2.empty())
        return 0;
    
    if (nums1.empty())
        nums1 = nums2;
    else {
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end();it++)
            nums1.push_back(*it);
    }
    std::sort(nums1.begin(), nums1.end());

    // for (int i = 0; i < nums1.size();i++)
    //     cout << "| " << nums1[i] << " |" ;

    double Median = 0;
    int sizeO2 = 0;
    if ( nums1.size() % 2 == 0)
    {
        sizeO2 = (nums1.size() / 2) - 1;
        Median = nums1[sizeO2] + nums1[sizeO2 + 1];
    }
    else {
        sizeO2 = (nums1.size() / 2) + 1;
    }
    return  nums1.size() % 2 != 0 ? nums1[(int)sizeO2] : (Median / 2);
}

int main()
{
    // [2,2,3,5,8]
    vector<int> ret;
    ret.push_back(2); ret.push_back(2);
    // ret.push_back(2); ret.push_back(2); ret.push_back(3); ret.push_back(5);ret.push_back(8);

    vector<int> qq;
    qq.push_back(9);

    double x = findMedianSortedArrays(ret, qq);
    cout << "the med is : " <<  x << endl;
}