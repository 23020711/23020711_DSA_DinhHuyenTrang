
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}
/*
 * Selection Sort (Sắp xếp chọn)
 * 
 * Độ phức tạp thời gian (Time Complexity):
 * - Best Case: O(n^2)
 * - Average Case: O(n^2)
 * - Worst Case: O(n^2)
 * 
 * Độ phức tạp không gian (Space Complexity):
 * - Auxiliary Space: O(1)
 */
void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
/*
 * Insertion Sort (Sắp xếp chèn)
 * 
 * Độ phức tạp thời gian (Time Complexity):
 * - Best Case: O(n) (Mảng đã được sắp xếp sẵn)
 * - Average Case: O(n^2)
 * - Worst Case: O(n^2) (Mảng ngược chiều)
 * 
 * Độ phức tạp không gian (Space Complexity):
 * - Auxiliary Space: O(1)
 */

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}
/*
 * Bubble Sort (Sắp xếp nổi bọt)
 * 
 * Độ phức tạp thời gian (Time Complexity):
 * - Best Case: O(n) (Tối ưu bằng biến swapped khi mảng đã sắp xếp)
 * - Average Case: O(n^2)
 * - Worst Case: O(n^2)
 * 
 * Độ phức tạp không gian (Space Complexity):
 * - Auxiliary Space: O(1)
 */
void merge(vector<int>& a, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= m)
        temp.push_back(a[i++]);

    while (j <= r)
        temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[l + k] = temp[k];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int partition(vector<int>& a, int l, int r) {
    int pivot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(vector<int>& a, int l, int r) {
    if (l >= r) return;

    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}
/*
 * Quick Sort (Sắp xếp nhanh)
 * 
 * Độ phức tạp thời gian (Time Complexity):
 * - Best Case: O(n log n)
 * - Average Case: O(n log n)
 * - Worst Case: O(n^2) (Xảy ra khi chọn Pivot không hợp lý, mảng đã được sắp xếp sẵn)
 * 
 * Độ phức tạp không gian (Space Complexity):
 * - Auxiliary Space: O(log n) (Chi phí bộ nhớ cho Call Stack đệ quy ở trường hợp trung bình)
 */
int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n - 1);

    for (int x : a)
        cout << x << " ";

    return 0;
}