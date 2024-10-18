#ifndef ALGOSY3_ARRAYLIST_H
#define ALGOSY3_ARRAYLIST_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;


template<typename T>
class ArrayList{
private:
    T* tab;
    size_t last;
    size_t msize;
    unsigned long long int min_size;

    void resizeUp(){
        msize = (1.5 * msize);
        T* new_data = new T[msize];

        for(size_t i =0; i < last; ++i){
            new_data[i] = tab[i];
        }
        delete[] tab;
        tab = new_data;
    }

    void resizeDown(){
        if (last <= msize / 4 && msize > 2) {
            msize /= 2;
            T* new_data = new T[msize];

            for (size_t i = 0; i < last; ++i) {
                new_data[i] = tab[i];
            }
            delete[] tab;
            tab = new_data;
        }

    }

    void check_size(){
        if(last <= msize / 2){
            resizeDown();
        }
    }



public:

    ArrayList(){
        msize = 2;
        last = 0;

        tab = new T[msize];
    }

    ArrayList& operator=(const ArrayList& other){
        if( this != &other){
            delete[] tab;

            msize = other.msize;
            last = other.last;

            tab = new T[msize];


            for(int i= 0; i< last; ++i){
                tab[i] = other.tab[i];
            }
        }
        return *this;
    }


    ~ArrayList(){
        delete[] tab;
    }

    size_t get_size(){
        return last;
    }

    size_t get_capacity() {
        return msize;
    }

    // zwracany ostatni element - nie usuwany
    T& back(){
        if (empty()) {
            throw out_of_range("List is empty.");
        }

        return tab[last - 1];
    }
    // zwracany 1 element - nie usuwany

    T& front(){
        if (empty()) {
            throw out_of_range("List is empty.");
        }

        return tab[0];
    }

    // zmienilem, ze zwraca element
    T pop_front(){
        if (empty()) {
            throw out_of_range("List is empty.");
        }

        T front_elemnet = tab[0];

        for (size_t i = 1; i < last; ++i) {
            tab[i - 1] = tab[i];
        }
        last--;
        check_size();
        return front_elemnet;
    }

    // zmienilem, ze zwraca element
    T pop_back() {
        if (empty()) {
            throw out_of_range("List is empty.");
        }
        T tail_element = tab[last - 1];
        last--;
        check_size();
        return tail_element;
    }

    bool empty(){
        return last == 0;
    }
    bool full() const { return last == msize; } // checks if the container is full
    int size(){
        return last;
    }
    int max_size() const { return msize; } // najwieksza mozliwa liczba elementow


    T get(size_t index) {
        if (index >= last) {
            throw out_of_range("Index out of range.");
        }
        return tab[index];
    }

    // dodawanie elementu na koniec
    void push_back(const T& value){
        if (last == msize){
            resizeUp();
        }
        tab[last] = value;
        last++;
    }

    // dodawanie elemntu una poczatek
    void push_front(const T& value) {
        if (last == msize) {
            resizeUp();
        }
        for (int i = last; i > 0; --i) {
            tab[i] = tab[i - 1];
        }
        tab[0] = value;
        last++;
    }


    // pozornie usuwamy ostatni element
    void removeLast(){
        if (empty()){
            throw out_of_range("empty list");
        }
        last--;
        check_size();

    }

    // usiwanie elemntu o podanym indexie
    void erase(size_t index) {
        if (index >= last) {
            throw out_of_range("Index out of range");
        }
        for (size_t i = index; i < last - 1; ++i) {
            tab[i] = tab[i + 1];
        }
        last--;
        check_size();
    }

    void set(size_t index, T& value){
        if(index >= last){
            throw out_of_range("Index out of range.");
        }
        tab[index] = value;

    }

    void display() const {

        for (size_t i = 0; i < last; ++i) {
            cout << "->" << tab[i] << " ";
        }
        cout << endl;
    }

    void reverse(){
        size_t start = 0;
        size_t end = last-1;
        while (start < end){
            T temp = tab[start];
            tab[start] = tab[end];
            tab[end] = temp;

            start++;
            end--;
        }
    }


    void clear(){
        last = 4;
        resizeDown();
        last = 0;
    }

    void sort(int *pInt, int *pInt1) {
        if (last > 1) {
            sort(tab, tab + last);
        }
    }



    friend ostream& operator<<(ostream& os, const ArrayList& L) {
        for (int i = 0; i < L.last; ++i) {
            os << L.tab[i] << " ";
        }
        return os;
    }

};






#endif
