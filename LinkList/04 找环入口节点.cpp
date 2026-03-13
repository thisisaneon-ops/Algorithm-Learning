#include "LinkedList.h"
Node* detectCycle(Node* head) {
    if (!head || !head->m_next) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->m_next) {
        slow = slow->m_next;
        fast = fast->m_next->m_next;
        if (slow == fast) {
            fast = head;
            while (fast != slow) {
                fast = fast->m_next;
                slow = slow->m_next;
            }
            return fast;
        }
    }
    return nullptr;
}

int main() {
    Node n1(1), n2(2), n3(3), n4(4);
    n1.m_next = &n2; n2.m_next = &n3; n3.m_next = &n4; n4.m_next = &n2;

    Node* cycleEntry = detectCycle(&n1);
    if (cycleEntry) cout << "环的入口节点: " << cycleEntry->m_data << endl;
    else cout << "无环" << endl;

    return 0;
}
