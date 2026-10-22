#include <iostream>
using namespace std;
class StackList {
private:
    int* data;
    int capacity;
    int topIndex;
    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i <= topIndex; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
public:
    StackList(int initCap = 10) {
        capacity = initCap;
        topIndex = -1;
        data = new int[capacity];
    }
    ~StackList() {
        delete[] data;
    }
    void push(int val) {
        if (topIndex + 1 == capacity) {
            resize();
        }
        data[++topIndex] = val;
    }
    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        }
    }
    int top() {
        if (topIndex >= 0) return data[topIndex];
        return -1;
    }
    bool empty() {
        return topIndex == -1;
    }
};
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class StackLinkedList {
private:
    Node* head;
public:
    StackLinkedList() : head(nullptr) {}
    ~StackLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void pop() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    int top() {
        if (head != nullptr) return head->data;
        return -1;
    }
    bool empty() {
        return head == nullptr;
    }
};
int main() {
    int n;
    cin >> n;
    StackList stList;
    StackLinkedList stLL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stList.push(x);
        stLL.push(x);
    }
    while (!stList.empty()) {
        cout << stList.top() << " ";
        stList.pop();
    }
    cout << endl;
    while (!stLL.empty()) {
        cout << stLL.top() << " ";
        stLL.pop();
    }
    cout << endl;
    return 0;
}
//Do phuc tap: O(1)