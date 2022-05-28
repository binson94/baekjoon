//시간초과 뜸, W(N) = O(N^2)이라
#include<cstdio>
using namespace std;

class Point
{
public:
    int x, y;
    bool operator<(const Point& p)
    {
        if(x == p.x)
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

int SetPivot(int left, int right)
{
    int i;
    int j = left;
    int pivotIdx = left;
    Point tmp;

    for(i = left + 1;i <= right;i++)
    {
        if(points[i] < points[pivotIdx])
        {
            tmp = points[++j];
            points[j] = points[i];
            points[i] = tmp;
        }
    }

    tmp = points[j];
    points[j] = points[left];
    points[left] = tmp;

    return j;
}

void QuickSort(int left, int right)
{
    int pivot;

    if (left < right)
    {
        pivot = SetPivot(left, right);
        QuickSort(left, pivot);
        QuickSort(pivot + 1, right);
    }
}

int main(void)
{
    int N;

    scanf("%d", &N);

    for(int i = 0;i < N;i++)
    {
        scanf("%d", &points[i].x);
        scanf("%d", &points[i].y);
    }

    QuickSort(0, N-1);

    for(int i = 0;i < N;i++)
        printf("%d %d\n", points[i].x, points[i].y);

    return 0;
}
