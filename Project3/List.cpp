#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
        Node(T val, Node* p = nullptr, Node* n = nullptr) : value(val), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() {
        clear();
    }

    void push_back(T value) {
        Node* new_node = new Node(value);
        if (tail) {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        else {
            head = tail = new_node;
        }
        ++size;
    }

    void push_front(T value) {
        Node* new_node = new Node(value);
        if (head) {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
        else {
            head = tail = new_node;
        }
        ++size;
    }

    void pop_back() {
        if (!tail) return;
        Node* to_delete = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete to_delete;
        --size;
    }

    void pop_front() {
        if (!head) return;
        Node* to_delete = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete to_delete;
        --size;
    }

    void clear() {
        while (head) {
            Node* to_delete = head;
            head = head->next;
            delete to_delete;
        }
        head = tail = nullptr;
        size = 0;
    }

    void show() const {
        Node* current = head;
        while (current) {
            cout << current->value << '\t';
            current = current->next;
        }
        cout << endl;
    }

    size_t get_size() const {
        return size;
    }

    T front() const {
        if (head) return head->value;
        throw out_of_range(" ");
    }

    T back() const {
        if (tail) return tail->value;
        throw out_of_range(" ");
    }

    List operator+(const List& other) const {
        List<T> result;
        Node* current = head;
        while (current) {
            result.push_back(current->value);
            current = current->next;
        }
        current = other.head;
        while (current) {
            result.push_back(current->value);
            current = current->next;
        }
        return result;
    }
};