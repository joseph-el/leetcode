# include "includes/leetcode.hpp"



// 1 1 1
// 2 1
// 1 2


//    1 1 1 1 1 1 1 1 1 1
//    2 2 2 2 2
//    2 2 2 2 1 1
//    2 1 1 1 1 1 1 1 1

//    2 2 2 2 2

/*
    n = 4:

    1 1 1 1

    res = res + old_res + 1
    1 + 1 = 2

    1 1 1 1



    res = 1 + 1 = 2
    res = 2 + 2 + 1  = 5
    res = 5 + 5 + 1
    res = 10 + 10 + 1
    

    res = old_res + res

    res = 1 + 1 = 2
    res = 2 + (2+1) = 5
    res = 5 + (5+1) = 11
    res = 11 + (11+1) = 23

    res = old_res + res

    res = 1 + 1 = 2
    res = 2 + 2 = 4
    res = 4 + 3 = 7
    res = 7 + 4 = 11



    res = old_res + res

    1 1 1 1

    res = old + res
    res = 1 + 1 = 2
    res = 2 + 2 = 4
    res = 4 + 4 = 8


    int temp = res;
    res = old + res;
    old = temp;
    res = 1 old = 1

    tmp = 1
    res = 1 + 1 = 2
    ols = 1

    tmp = 2
    res = 2 + 1
    old = 2

    tmp = 3
    res = 3 + 2
    ols = 3

    tmp = 5
    res = 5 + 3
    ols = 5






    5 * 4 = 20


    1 1 1 1
    1 1 2
    1 2 1
    2 1 1
    2 2


___________
    20 

    20 / n = 5 solution 


*/

/**
 * 
 *      1 1 1 1
 *      
 *  [1 1]
 *  res = 2
 * [1 1 2]
 * res = 3
 * [1 1 2 3]
 *      
 * 
*/

int climbStairs(int n) {
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(1);

    for (int i = 2; i <= n; ++i) {
        int next = dq.back() + dq.front();
        dq.push_back(next);
        if (dq.size() > 2) {
            dq.pop_front();
        }
    }
    return dq.back();
}



int main ()
{
    cout << climbStairs(10) << endl;
}