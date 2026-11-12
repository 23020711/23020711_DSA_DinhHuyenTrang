#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
template <typename T>
void siftDown(vector<T>& a, size_t n, size_t i) {
    while (true) {
        size_t l = 2 * i + 1, r = l + 1, m = i;
        if (l < n && a[l] > a[m]) m = l;
        if (r < n && a[r] > a[m]) m = r;
        if (m == i) break;
        swap(a[i], a[m]);
        i = m;
    }
}
template <typename T>
void heapSort(vector<T>& a) {
    size_t n = a.size();
    if (n < 2) return;
    for (int i = (int)n / 2 - 1; i >= 0; i--) siftDown(a, n, i);
    for (size_t end = n - 1; end > 0; end--) {
        swap(a[0], a[end]);
        siftDown(a, end, 0);
    }
}
int main() {
    vector<int> a = {5, 3, 17, 10, 84, 19, 6, 22, 9};
    heapSort(a);
    for (int x : a) cout << x << " "<< endl;
    mt19937 rng(12345);
    uniform_int_distribution<int> dist(-500000, 499999);
    vector<int> b(100000);
    for (int& x : b) x = dist(rng);
    heapSort(b);
    cout << "random n=" << b.size() << " sorted=" << (is_sorted(b.begin(), b.end()) ? "OK" : "FAIL") << "\n";
    return 0;
}
//Do phuc tap O(nlogn)