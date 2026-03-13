#include "LinkedList.h"

// 反转链表
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->m_next;
        curr->m_next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    LinkList list;
    for (int i = 1; i <= 5; i++) list.push_back(i);
    cout << "原链表: ";
    list.print();

    Node* newHead = reverseList(list.getHead());
    list.setHead(newHead);
    cout << "反转后: ";
    list.print();

    return 0;
}
