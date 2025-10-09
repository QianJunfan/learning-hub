// We just faced our toughest challenge yet - a dynamic programming problem about monry counting.
// My baby worked with the DP table and I worked with AI :)
// These two methods are just so romantic.
//                                                                             from guaitan1st :)
//                                                                                    Fri Oct, 10 

#include <stdio.h>

// q1 - num eights
int num_eights(int n)
{
        // bdry
        if (n == 0)
                return 0;
        if (n % 10 == 8)
                return 1 + num_eights(n / 10);
        else
                return num_eights(n / 10);
}

// q2 - digit distance
static int abs(int a)
{
        if (a >= 0)
                return a;
        else
                return -a;
}

int digit_d(int n)
{
        // bdry
        if (n/10  == 0)
                return 0;
        return abs(n%10 - (n/10)%10) + digit_d(n/10);
}

// q3 - interleaved sum
static int square(int a)
{
        return a * a;
}

static int triple(int a)
{
        return 3 * a;
}

int interleaved(int n, int (*odd)(int), int (*even)(int))
{
        // bdry
        if (n == 0)
                return 0;

        if (n%2 == 0)
                return even(n) + interleaved(n-1, odd, even);
        else
                return odd(n) + interleaved(n-1 , odd, even);
}

// exp - so many stairs!
// [1] - [2] - [3] - [5] - [8] ........
int dy(int n)
{
        if (n == 1)
                return 1;
        if (n == 2)
                return 2;

        return dy(n-1) + dy(n-2);
}


// q4 - cont dollars
#include <string.h>
int count_dollars_forloop(int n, int coin[], int coin_size)
{
        // init dp table
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        // prog
        for (int i = 0; i < coin_size; i++) {
                int cur_coin = coin[i];
                for (int j = cur_coin; j <= n; j++) {
                        dp[j] += dp[j - cur_coin];
                }
        }

        return dp[n];
}

int dollar_type[6] = {100, 50, 10, 20, 5, 1}; 
int count_ways(int total, int idx)
{
        if (total == 0)
                return 1;
        if (total < 0)
                return 0;
        if (idx == 5)
                return 1;

        return count_ways(total-dollar_type[idx], idx) + count_ways(total, idx+1);
}


int main(void)
{
        printf("q1: %d\n", num_eights(86380));
        printf("q2: %d\n", digit_d(314));
        printf("q3: %d\n", interleaved(4, square, triple));
        printf("exp: %d\n", dy(10));

        int coin[6] = {1, 5, 10, 20, 50, 100};
        printf("q4: %d\n", count_dollars_forloop(100, coin, 6));
        printf("q4: %d\n", count_ways(100, 0));
        return 0;
}
