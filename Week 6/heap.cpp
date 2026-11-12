#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>
using namespace std;
template <typename T, typename Cmp = less<T>>
class Heap {
    vector<T> a;
    Cmp cmp;
    void siftUp(size_t i) {
        while (i > 0) {
            size_t p = (i - 1) / 2;
            if (!cmp(a[p], a[i])) break;
            swap(a[p], a[i]);
            i = p;
        }
    }
    void siftDown(size_t i) {
        size_t n = a.size();
        while (true) {
            size_t l = 2 * i + 1, r = l + 1, m = i;
            if (l < n && cmp(a[m], a[l])) m = l;
            if (r < n && cmp(a[m], a[r])) m = r;
            if (m == i) break;
            swap(a[i], a[m]);
            i = m;
        }
    }
public:
    Heap() = default;
    explicit Heap(vector<T> v) : a(move(v)) {
        for (int i = (int)a.size() / 2 - 1; i >= 0; i--) siftDown(i);
    }
    bool empty() const { return a.empty(); }
    size_t size() const { return a.size(); }
    void push(const T& x) {
        a.push_back(x);
        siftUp(a.size() - 1);
    }
    const T& top() const {
        if (a.empty()) throw runtime_error("Heap rong");
        return a.front();
    }
    T pop() {
        if (a.empty()) throw runtime_error("Heap rong");
        T v = a.front();
        a.front() = a.back();
        a.pop_back();
        if (!a.empty()) siftDown(0);
        return v;
    }
};
int main() {
    vector<int> d = {5, 3, 17, 10, 84, 19, 6, 22, 9};
    Heap<int> h;
    for (int x : d) h.push(x);
    cout << "size=" << h.size() << " top=" << h.top() << endl;
    while (!h.empty()) cout << h.pop() << " "<< endl;
    Heap<int> g(d);
    cout << "build: top=" << g.top() << endl;
    while (!g.empty()) cout << g.pop() << " "<< endl;
    Heap<int, greater<int>> mh(d);
    cout << "min-heap: ";
    while (!mh.empty()) cout << mh.pop() << " "<< endl;
    return 0;
}
// Do phuc tap: O(logn)
