# include "includes/leetcode.hpp"


void findLen(vector< vector<char> >& matrix, int &len, int x, int y)
{
    vector< vector<char> >::iterator it = matrix.begin();
    vector<char>::iterator it2 = matrix[x].begin();

    if (it + x == matrix.end())
        return ;
    else if (it2 + y == matrix[x].end()) {
        return findLen(matrix, len, x + 1, 0);
    }

    if ()
    {
        
    }



    // cout << matrix[x][y] << " ";
    return findLen(matrix, len, x, y+1);
}

// int maximalRectangle(vector< vector<char> >& matrix) {
//     vector<vector<char>>::iterator it1 = matrix.begin();

//     if (it1 == matrix.end()) return 0;
//     int len = 0;
//     findLen(matrix, len , 0, 0);

//     return len ;
// }

int main(int ac, char **argv)
{
    vector< vector<char> > ret;

    vector<char> s1 = {'1' , '1' , '0', '0'};
    vector<char> s2 = {'1' , '1' , '0', '1'};
    vector<char> s3 = {'1' , '1' , '0', '1'};
    vector<char> s4 = {'1' , '1' , '1', '1'};

    ret.push_back(s1);
    ret.push_back(s2);
    ret.push_back(s3);
    ret.push_back(s4);
    int len = 0;
    findLen(ret, len, 0, 0);
}
