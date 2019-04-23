#include <iostream>
#include <algorithm>
using namespace std;

int partition(int a[], int start, int end)
{
    int pivot, j = start, i, pivotIndex;
    pivot = a[end];

    for (i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[j++], a[i]);
        }
        if (i == end - 1)
        {
            pivotIndex = j;
            swap(a[end], a[j]);
        }
    }

    return pivotIndex;
}

void QSORT(int a[], int start, int end)
{
    int pivot;
    if (start < end)
    {
        pivot = partition(a, start, end);
        QSORT(a, start, pivot - 1);
        QSORT(a, pivot + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    int a[12] = {5, 7, 2, 0, 8, 9, 6, 0, 5, 4, 3, 7};
    int size = sizeof(a);
    size = size / 4;
    QSORT(a, 0, size - 1);
    int i, count = size;
    for (i = 0; i < count; ++i)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}
