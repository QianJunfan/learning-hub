// We just faced our toughest challenge yet - a dynamic programming problem about monry counting.
// My baby worked with the DP table and I worked with AI :)
// These two methods are just so romantic.
//                                                                             from guaitan1st :)
//                                                                                    Fri Oct, 10 

#include <stdio.h>
#include <wctype.h>

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

// q5 - count dollars upward
static int next_larger_dollar(int b)
{
        if (b == 1)  return 5;
        if (b == 5)  return 10;
        if (b == 10) return 20;
        if (b == 20) return 50;
        if (b == 50) return 100;
        return -1;
}

int count_dollars_upward(int total, int b)
{
        if (total == 0)
                return 1;
        if (total < 0)
                return 0;
        if (b == -1)
                return 0;
        return  count_dollars_upward(total-b, b) +
                count_dollars_upward(total, next_larger_dollar(b));  
}

// q6 - knapsack
int max = 0;
int weight[4] = {2, 6, 3, 3};
int value[4] = {1, 5, 3, 3};

int knapsack(int c, int v, int idx)
{
        if (c < 0)
                return 0;
        if (idx > 3)
                return 0;
        if (c >= 0 && v > max)
                max = v;
        return knapsack(c-weight[idx], v+value[idx], idx+1) + knapsack(c, v, idx+1); 
}

int main(void)
{
        printf("q1: %d\n", num_eights(86380));
        printf("q2: %d\n", digit_d(314));
        printf("q3: %d\n", interleaved(4, square, triple));
        printf("exp: %d\n", dy(10));

        int coin[6] = {1, 5, 10, 20, 50, 100};
        printf("q4: %d\n", count_dollars_forloop(200, coin, 6));
        printf("q4: %d\n", count_ways(200, 0));
        printf("q5: %d\n", count_dollars_upward(200, 1));
        knapsack(6, 0, 0);
        printf("q6: %d\n", max);
        return 0;
}
