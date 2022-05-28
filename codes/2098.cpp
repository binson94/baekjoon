#include<cstdio>
using namespace std;
#define INT_MAX 1000000 * 16

int N;
int cost[16][16];
int dp[16][1 << 16];

int min(const int& a, const int& b)
{
    return a < b ? a : b;
}

void GetInput()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &cost[i][j]);
}
int GetCost(int currCity, int bitmask)
{
    if(bitmask == (1 << N) - 1)
        return cost[currCity][0] != 0 ? cost[currCity][0] : INT_MAX;
    
    if(dp[currCity][bitmask] != INT_MAX)
        return dp[currCity][bitmask];

    for(int i = 0;i < N;i++)
    {
        if(cost[currCity][i] != 0 && ((bitmask & (1 << i)) == 0))
            dp[currCity][bitmask] = min(dp[currCity][bitmask], GetCost(i, bitmask | (1 << i)) + cost[currCity][i]);
    }

    return dp[currCity][bitmask];
}

int main(void)
{
   GetInput();

    for(int i = 0;i<N;i++)
        for(int j = 0;j < (1 << N);j++)
            dp[i][j] = INT_MAX;

    printf("%d\n", GetCost(0, 1));
}