// #include "leetcode.hpp"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

const char *Mstx = "abcracecarxyz";
const char *Mext = "racecar";


int _match(const char *_current, int _end) {
    int _idx, _lenght;
    char *_stx;

    _stx = strdup(_current);
    _stx[_end] = 0;
    _idx = 0;

    _lenght = strlen(_stx) - 1;

    printf("check sub |%s|\n", _stx);

    while (_lenght >= 0 && _idx != _lenght && _stx[_idx] == _stx[_lenght])
        _idx++, _lenght--;

    return (_idx + 1);
}

const char* the_next_move(const char *stx, int c) {
    char* ret = NULL;
    while ((ret = strchr(stx, c)) != NULL);
    return ret;
}

char* longestPalindrome(char* s) {
    char *res, *tmp, *stx;

    int idx, save, t_idx, i;

    idx = save = t_idx = i = 0;
    res = tmp = 0x0;

    stx = strdup(s);

    while (stx[i]) {
        save = stx[i];
        stx[i] = 0;

        if ((tmp = strchr(stx, save)) != 0x0) {
            printf("the tmp founded |%s|\n", tmp);
            
            stx[i] = save;

        
            t_idx = _match(tmp, i + 1);

            printf("t_idx : |%d|\n", t_idx);

            if (idx < t_idx) {
                idx = t_idx;
                if (res) free(res);
                res = strndup(tmp, i);
                printf("the res = |%s|\n", res);
            }
        } else {
            stx[i] = save;
        }
        i ++;
    }

    return (res);
}