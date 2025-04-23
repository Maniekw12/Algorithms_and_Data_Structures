#include <iostream>
#include <algorithm>  // For std::max
#include <cstring>    // For std::copy

class setSimple{
private:
    bool* elements = nullptr;
public:
    int capacity = 0;

    setSimple(int n){
        capacity = n;
        elements = new bool[capacity];
        std::fill(elements,elements+ capacity, false);
    }

    ~setSimple() {
        delete[] elements;
    }

    bool getElement(int i) const {
        if (i >= 0 && i < capacity) {
            return elements[i];
        }
        throw std::out_of_range("Index out of range");
    }

    void insert(int index){
        if(index < capacity && index >= 0){
            elements[index] = true;
        }
        else{
            throw std::out_of_range("Index out of range");
        }
    }

    void remove(int index){
        if(index < capacity && index >=0){
            elements[index] = false;
        }
        else{
            throw std::out_of_range("Index out of range");
        }
    }

    bool contains(int index){
        if(index < capacity && index >=0){
            return index < capacity && index >=0 && elements[index];
        }
        else{
            throw std::out_of_range("Index out of range");
        }
    }

    setSimple operator+(setSimple& otherSet) {
        int maxSize = std::max(capacity, otherSet.capacity);
        setSimple sumSet(maxSize);

        for (int i = 0; i < maxSize; ++i) {
            if (this->contains(i) || otherSet.contains(i)) {
                sumSet.insert(i);
            }
        }

        return sumSet;
    }

    setSimple operator|(setSimple& otherSet) {
        int maxSize = std::max(capacity, otherSet.capacity);
        setSimple inSet(maxSize);

        for (int i = 0; i < maxSize; ++i) {
            if (this->contains(i) && otherSet.contains(i)) {
                inSet.insert(i);
            }
        }
        return inSet;
    }

    setSimple operator-(setSimple& otherSet){
        int maxSize = std::max(capacity, otherSet.capacity);
        setSimple resultSet(maxSize);

        for(int i=0; i < maxSize; i++){
            if(this->contains(i) && !otherSet.contains(i)){
                resultSet.insert(i);
            }
        }
        return resultSet;
    }

    bool operator==(setSimple& otherSet){

        if(this->capacity != otherSet.capacity){
            return false;
        }

        for (int i = 0; i < this->capacity; ++i) {
            if(this->getElement(i) != otherSet.getElement(i)){
                return false;
            }
        }
        return true;
    }

    void print(){
        for (int i = 0; i < capacity; i++) {
            if (elements[i]) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }

};


