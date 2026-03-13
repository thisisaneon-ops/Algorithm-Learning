#include <iostream>
using namespace std;

class Node {
public:
    Node(int data = 0) : m_data(data), m_next(NULL) {};
    int m_data;
    Node* m_next;
};

class LinkList {
public:
    LinkList() {
        m_head = new Node();  // 虚拟头节点
    }

    ~LinkList() {
        Node* p = this->m_head;
        while (p != NULL) {
            this->m_head = this->m_head->m_next;
            delete p;
            p = this->m_head;
        }
        m_head = NULL;
    }

    void push_back(int val) {
        Node* p = this->m_head;
        while (p->m_next != NULL) {
            p = p->m_next;
        }
        Node* node = new Node(val);
        p->m_next = node;
    }

    void push_front(int val) {
        Node* node = new Node(val);
        node->m_next = this->m_head->m_next;
        this->m_head->m_next = node;
    }

    void Remove(int val) {
        Node* p = this->m_head->m_next;
        Node* q = this->m_head;
        while (p != nullptr) {
            if (p->m_data == val) {
                q->m_next = p->m_next;
                delete p;
                return;
            }
            else {
                q = p;
                p = p->m_next;
            }
        }
    }

    void RemoveAll(int val) {
        Node* p = this->m_head->m_next;
        Node* q = this->m_head;
        while (p != NULL) {
            if (p->m_data == val) {
                q->m_next = p->m_next;
                delete p;
                p = q->m_next;
            }
            else {
                q = p;
                p = p->m_next;
            }
        }
    }

    bool IsExist(int val) {
        Node* p = this->m_head->m_next;
        while (p != NULL) {
            if (p->m_data == val)
                return true;
            p = p->m_next;
        }
        return false;
    }

    void print() {
        Node* p = this->m_head->m_next;
        while (p != NULL) {
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

