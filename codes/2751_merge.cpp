#include<cstdio>
using namespace std;

int number[1000000];
int tmp[1000000];

void Merge(int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right)
    {
        if(number[i] < number[j])
            tmp[k++] = number[i++];
        else
            tmp[k++] = number[j++];
    }

    while(i <= mid)
        tmp[k++] = number[i++];
    while(j <= right)
        tmp[k++] = number[j++];

    for(int l = left;l <= right;l++)
        number[l] = tmp[l];
}

void MergeSort(int left, int right)
{
    int mid = (left + right) / 2;
    if(left < right)
    {
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, right);
    }
}


int main(void)
{
    int N;

    scanf("%d", &N);

    for(int i = 0;i < N;i++)
        scanf("%d", &number[i]);

    MergeSort(0, N - 1);

    for(int i = 0;i < N;i++)
        printf("%d\n", number[i]);
}