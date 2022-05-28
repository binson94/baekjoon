#include<cstdio>
using namespace std;

long long binomial[1001][1001];

void Binomial(int n, int k)
{
    for(int i = 0;i <= n;i++)
    {
        int min = i < k ? i : k;
        for(int j = 0;j<= min;j++)
        {
            if(j == 0 || i == j)
                binomial[i][j] = 1;
            else
                binomial[i][j] = (binomial[i - 1][j - 1] + binomial[i - 1][j]) % 10007;
        }
    }
}

int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);

    Binomial(N, K);

    printf("%d\n", binomial[N][K]);

    return 0;
}