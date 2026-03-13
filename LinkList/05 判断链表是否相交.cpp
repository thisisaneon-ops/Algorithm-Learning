#include "LinkedList.h"

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB) return nullptr;
    Node* pA = headA;
    Node* pB = headB;
    while (pA != pB) {
        pA = (pA == nullptr) ? headB : pA->m_next;
        pB = (pB == nullptr) ? headA : pB->m_next;
    }
    return pA;
}

int main() {
    Node a1(1), a2(2), c1(3);
    Node b1(4), b2(5);
    a1.m_next = &a2; a2.m_next = &c1;
    b1.m_next = &b2; b2.m_next = &c1;

    Node* inter = getIntersectionNode(&a1, &b1);
    if (inter) cout << "相交节点值: " << inter->m_data << endl;
    else cout << "不相交" << endl;
    return 0;
}
