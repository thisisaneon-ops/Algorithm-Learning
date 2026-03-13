#include "LinkedList.h"

// 合并两个有序链表
Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;
    while (l1 && l2) {
        if (l1->m_data < l2->m_data) {
            tail->m_next = l1;
            l1 = l1->m_next;
        } else {
            tail->m_next = l2;
            l2 = l2->m_next;
        }
        tail = tail->m_next;
    }
    tail->m_next = (l1 != nullptr) ? l1 : l2;
    return dummy.m_next;
}

int main() {
    LinkList list1, list2;
    list1.push_back(1); list1.push_back(3); list1.push_back(5);
    list2.push_back(2); list2.push_back(4); list2.push_back(6);

    Node* newHead = mergeTwoLists(list1.getHead(), list2.getHead());
    LinkList mergedList;
    mergedList.setHead(newHead);
    mergedList.print();

    return 0;
}
