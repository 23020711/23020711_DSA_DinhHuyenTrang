#include <iostream>
using namespace std;
class ArrayList {
private:
    int* data;
    int capacity;
    int currentSize;
    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
public:
    ArrayList(int initCapacity = 10) {
        capacity = initCapacity;
        currentSize = 0;
        data = new int[capacity];
    }
    ~ArrayList() {
        delete[] data;
    }
    void pushBack(int val) {
        if (currentSize == capacity) {
            resize();
        }
        data[currentSize++] = val;
    }
    void popBack() {
        if (currentSize > 0) {
            currentSize--;
        }
    }
    int get(int index) {
        if (index >= 0 && index < currentSize) {
            return data[index];
        }
        return -1;
    }
    int getSize() {
        return currentSize;
    }
    void print() {
        for (int i = 0; i < currentSize; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int n;
    cin >> n;
    ArrayList list;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.pushBack(x);
    }
    list.print();
    return 0;
}
//Them cuoi/dau va xoa danh sach: O(1)
//In danh sach: O(N)