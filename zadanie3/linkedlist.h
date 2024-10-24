
#ifndef UNTITLED_LISTA_H
#define UNTITLED_LISTA_H

#include <iostream>
#include <cassert>

template <typename T>
struct SingleNode {
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} // konstruktor domyslny
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {} // destruktor
};

template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList();

    SingleList(const SingleList& other){
        if (this == &other) return; // self-assignment check

        SingleNode<T> *current = other.head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }; // copy constructor

    SingleList& operator=(const SingleList& other){
        if (this == &other) {  // Sprawdzamy, czy przypisujemy do samego siebie
            return *this;  // Jeśli tak, zwracamy *this
        }
        clear();

        SingleNode<T> *current = other.head;
        while(current != nullptr){
            push_back(current->value);
            current=current->next;
        }
        return  *this;
    }; // copy assignment operator, return *this
    // usage:   list2 = list1;

    bool empty() const { return head == nullptr; }
    std::size_t size() const{
        if(head == nullptr){
            return 0;
        }

        SingleNode<T> *current = head;
        size_t len = 0;
        while (current != nullptr){
            current = current->next;
            len = len +1;
        }
        return len;
    }


    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa


    void clear(){
        SingleNode<T> *current = head;
        SingleNode<T> *next_node = head;
        while (current != nullptr){
            next_node = current->next;
            delete current;
            current = next_node;
        }
        head = nullptr;
        tail = nullptr;


    } // czyszczenie listy z elementow O(n)

    void reverse(){
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        SingleNode<T> *prev = nullptr;
        SingleNode<T> *current = head;
        SingleNode<T> *next_node = nullptr;

        while (current != nullptr){
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        head = prev;
    }// O(n)

    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(n)
    void display(); // O(n)
    void push_front(const T& item); // O(1), L.push_front(item)
    void push_back(const T& item); // O(1), L.push_back(item)
};

template <typename T>
SingleList<T>::~SingleList() {
    for (SingleNode<T> *node; !empty(); ) {
        node = head->next; // zapamietujemy
        delete head;
        head = node; // kopiowanie wskaznika
    }
}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new SingleNode<T>(item, head);
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::display() {
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        // Szukamy poprzednika ogona.
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}

#endif //UNTITLED_LISTA_H
