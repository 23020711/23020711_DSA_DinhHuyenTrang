#include <iostream>
using namespace std;
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() {
        DNode* curr = head;
        while (curr != nullptr) {
            DNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    void insertTail(int val) {
        DNode* newNode = new DNode(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void printForward() {
        DNode* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
int main() {
    int n;
    cin >> n;
    DoublyLinkedList dll;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dll.insertTail(x);
    }
    dll.printForward();
    return 0;
}
//Them cuoi danh sach: O(1)
//Duyet xuoi: O(N)