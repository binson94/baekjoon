#include<cstdio>
using namespace std;
#define INT_MAX 0x7fffffff

int mat[501][501];
int d[501];

int main(void)
{
    int N;
    scanf("%d", &N);

    for(int i = 0;i < N;i++)
        scanf("%d %d", &d[i], &d[i + 1]);

    for(int i = 0;i <= N;i++)
        mat[i][i] = 0;

    for(int dia = 1;dia < N;dia++)
    {
        for(int i = 1;i <= N - dia;i++)
        {
            int j = i + dia;
            int min = INT_MAX;

            for(int k = i;k <=j - 1;k++)
            {
                int calc = mat[i][k] + mat[k + 1][j] + d[i-1]*d[k]*d[j];
                if(calc < min)
                    min = calc;
            }
            mat[i][j] = min;
        }
    }

    printf("%d\n", mat[1][N]);

    return 0;
}