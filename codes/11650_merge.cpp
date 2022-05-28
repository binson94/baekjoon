#include<cstdio>
using namespace std;

class Point
{
public:
    int x, y;
    bool operator<(const Point& p)
    {
        if (x == p.x)
            return y < p.y;
        return x < p.x;
    }
    Point& operator=(const Point& p)
    {
        x = p.x;
        y = p.y;
        return *this;
    }
};

Point points[100000];
Point tmp[100000];

void Merge(int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right)
    {
        if(points[i] < points[j])
            tmp[k++] = points[i++];
        else
            tmp[k++] = points[j++];
    }

    while(i <= mid)
        tmp[k++] = points[i++];
    while(j <= right)
        tmp[k++] = points[j++];

    for(int l = left;l <= right;l++)
        points[l] = tmp[l];
}

void MergeSort(int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = (left + right) / 2;
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
    {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    MergeSort(0, N - 1);

    for(int i = 0;i < N;i++)
        printf("%d %d\n", points[i].x, points[i].y);

    return 0;
}