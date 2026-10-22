#include <iostream>
using namespace std;
class QueueList {
private:
    int* data;
    int capacity;
    int frontIndex;
    int rearIndex;
    int size;
    void resize() {
        int newCap = capacity * 2;
        int* newData = new int[newCap];
        for (int i = 0; i < size; i++) {
            newData[i] = data[(frontIndex + i) % capacity];
        }
        delete[] data;
        data = newData;
        frontIndex = 0;
        rearIndex = size - 1;
        capacity = newCap;
    }
public:
    QueueList(int initCap = 10) {
        capacity = initCap;
        data = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }
    ~QueueList() {
        delete[] data;
    }
    void push(int val) {
        if (size == capacity) {
            resize();
        }
        rearIndex = (rearIndex + 1) % capacity;
        data[rearIndex] = val;
        size++;
    }
    void pop() {
        if (size > 0) {
            frontIndex = (frontIndex + 1) % capacity;
            size--;
        }
    }
    int front() {
        if (size > 0) return data[frontIndex];
        return -1;
    }
    bool empty() {
        return size == 0;
    }
};
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class QueueLinkedList {
private:
    Node* head;
    Node* tail;
public:
    QueueLinkedList() : head(nullptr), tail(nullptr) {}
    ~QueueLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            if (head == nullptr) tail = nullptr;
            delete temp;
        }
    }
    int front() {
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
    QueueList qList;
    QueueLinkedList qLL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        qList.push(x);
        qLL.push(x);
    }
    while (!qList.empty()) {
        cout << qList.front() << " ";
        qList.pop();
    }
    cout << endl;
    while (!qLL.empty()) {
        cout << qLL.front() << " ";
        qLL.pop();
    }
    cout << endl;
    return 0;
}
//Do phuc tap: O(1)