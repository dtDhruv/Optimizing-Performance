#include <iostream>
#include <windows.h>
#include <process.h>
#include <time.h>

#define MAX 100000

#define THREAD_MAX 4

using namespace std;

int a[MAX];
int part = 0;

void merge(int low, int mid, int high)
{
    int* left = new int[mid - low + 1];
    int* right = new int[high - mid];

    int n1 = mid - low + 1, n2 = high - mid, i, j;

    for (i = 0; i < n1; i++)
        left[i] = a[i + low];

    for (i = 0; i < n2; i++)
        right[i] = a[i + mid + 1];

    int k = low;
    i = j = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while (i < n1) {
        a[k++] = left[i++];
    }

    while (j < n2) {
        a[k++] = right[j++];
    }
}

void merge_sort(int low, int high)
{
    int mid = low + (high - low) / 2;
    if (low < high) {

        merge_sort(low, mid);

        merge_sort(mid + 1, high);

        merge(low, mid, high);
    }
}

unsigned __stdcall merge_sort_thread(void* arg)
{
    int thread_part = part++;

    int low = thread_part * (MAX / 4);
    int high = (thread_part + 1) * (MAX / 4) - 1;

    int mid = low + (high - low) / 2;
    if (low < high) {
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }

    _endthreadex(0);
    return 0;
}

int main()
{
    for (int i = 0; i < MAX; i++)
        a[i] = rand() % 100000;

    clock_t t1, t2;

    t1 = clock();
    HANDLE threads[THREAD_MAX];

    for (int i = 0; i < THREAD_MAX; i++)
        threads[i] = (HANDLE)_beginthreadex(NULL, 0, merge_sort_thread, (void*)NULL, 0, NULL);

    WaitForMultipleObjects(THREAD_MAX, threads, TRUE, INFINITE);

    merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1);
    merge(MAX / 2, MAX / 2 + (MAX - 1 - MAX / 2) / 2, MAX - 1);
    merge(0, (MAX - 1) / 2, MAX - 1);

    t2 = clock();

    cout << "Sorted array: ";
    for (int i = 0; i < MAX; i++)
        cout << a[i] << " ";

    cout << "Time taken: " << (t2 - t1) /
        (double)CLOCKS_PER_SEC << endl;
    int buff;
    std::cin >> buff;
    return 0;
}
