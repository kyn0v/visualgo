#include <algorithm>
#include <iostream>
using namespace std;

void BubbleSort(int a[], int N) {
    bool flag;
    for (int i = 0; i < N - 1; i++) {
        flag = 0;
        for (int j = 0; j < N - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (!flag) break;
    }
}

void SelectionSort(int a[], int N) {
    int min_index;
    for (int i = 0; i < N - 1; i++) {
        min_index = i;
        for (int j = i; j < N; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
}

void InsertionSort_1(int a[], int N) {
    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0 && a[j] > a[j + 1]; j--) {
            swap(a[j], a[j + 1]);
        }
    }
}

void InsertionSort_2(int a[], int N) {
    for (int i = 1; i < N; i++) {
        int x = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > x; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = x;
    }
}

void Merge(int a[], int low, int mid, int high) {
    int *b = new int[high - low + 1];
    int i = low, j = mid + 1, bIdx = 0;
    while (i <= mid && j <= high) {
        b[bIdx++] = a[i] < a[j] ? a[i++] : a[j++];
    }
    while (i <= mid) {
        b[bIdx++] = a[i++];
    }
    while (j <= high) {
        b[bIdx++] = a[j++];
    }
    for (int k = 0; k <= (high - low); k++) {
        a[low + k] = b[k];
    }
    delete[] b;
}

void MergeSort(
    int a[], int low,
    int high) {  // 区间选择左闭右闭方式，而非左闭右开，否则递归过程会有问题
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int Partition(int a[], int low, int high) {
    int pivot = a[low];
    int pivotIdx = low;
    for (int k = low + 1; k <= high; k++) {
        if (a[k] < pivot) {
            pivotIdx++;
            swap(a[k], a[pivotIdx]);
        }
    }
    swap(a[low], a[pivotIdx]);
    return pivotIdx;
}

void QuickSort(int a[], int low, int high) {
    if (low < high) {
        int pivot = Partition(a, low, high);
        QuickSort(a, low, pivot - 1);
        QuickSort(a, pivot + 1, high);
    }
}

int main() {
    int a[5] = {5, 4, 3, 2, 1};
    QuickSort(a, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}