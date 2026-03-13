#include "LinkedList.h"

// 找倒数第k个节点
Node* getKthFromEnd(Node* head, int k) {
    Node* fast = head;
    Node* slow = head;
    for (int i = 0; i < k; i++) {
        if (!fast) return nullptr;
        fast = fast->m_next;
    }
    while (fast) {
        fast = fast->m_next;
        slow = slow->m_next;
    }
    return slow;
}

int main() {
    LinkList list;
    for (int i = 1; i <= 5; i++) list.push_back(i);

    Node* node = getKthFromEnd(list.getHead(), 2);
    if (node) cout << "倒数第2个节点: " << node->m_data << endl;

    return 0;
}
