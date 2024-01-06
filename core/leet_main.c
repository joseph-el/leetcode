# include "leetcode.h"

static void run_func_test(void)
{
    char* ret = "abcracecarxyz";

 
    char * res = longestPalindrome(ret);
    printf("out : |%s|\n", res);
}

int leetcode_main(int argc, char *argv[], char *envs[]) {

    signal(SIGINT, SIG_HOLD);

    run_func_test();

    exit(EXIT_SUCCESS);
}