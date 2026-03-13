#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
    Node(int data = 0) : m_data(data), m_next(nullptr) {};
    int m_data;
    Node* m_next;
};

class LinkList {
public:
    LinkList() { m_head = new Node(); }  // 虚拟头节点
    ~LinkList() {
        Node* p = m_head;
        while (p != nullptr) {
            Node* tmp = p;
            p = p->m_next;
            delete tmp;
        }
    }

    void push_back(int val) {
        Node* p = m_head;
        while (p->m_next != nullptr) p = p->m_next;
        p->m_next = new Node(val);
    }

    void print() {
        Node* p = m_head->m_next;
        while (p) {
            cout << p->m_data << " ";
            p = p->m_next;
        }
        cout << endl;
    }

    Node* getHead() { return m_head->m_next; }
    void setHead(Node* newHead) { m_head->m_next = newHead; }

private:
    Node* m_head;
};

#endif
