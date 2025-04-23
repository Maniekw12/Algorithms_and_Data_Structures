#include <iostream>
#include "setSimple.h"
#include <cassert>
#include "setLinked.h"
#include "dictionarySimple.h"

void testCreateNewSet();
void testInsertElement();
void testRemoveElement();
void testContainsElement();
void testSumSets();
void testIntersectionSets();
void testSubtractSets();
void testEqualsSets();

void testInsertLinkedElement();
void testRemoveLinkedElement();
void testContainsLinkedElement();
void testSumLinkedSets();
void testIntersectionLinkedSets();
void testSubtractLinkedSets();
void testEqualsLinkedSets();

void testInsertElementDictionary();
void testRemoveElementDictionary();
void testContainsElementDictionary();
void testInsertDuplicateElement();
void testInsertStringLengthValidation();

int main() {
    testCreateNewSet();
    testInsertElement();
    testRemoveElement();
    testContainsElement();
    testSumSets();
    testIntersectionSets();
    testSubtractSets();
    testEqualsSets();
    std::cout<<"all setSimple tests passed"<< std::endl;

    testInsertLinkedElement();
    testRemoveLinkedElement();
    testContainsLinkedElement();
    testSumLinkedSets();
    testIntersectionLinkedSets();
    testSubtractLinkedSets();
    testEqualsLinkedSets();
    std::cout<<"all setLinked tests passed"<< std::endl;

    testInsertElementDictionary();
    testRemoveElementDictionary();
    testContainsElementDictionary();
    testInsertDuplicateElement();
    testInsertStringLengthValidation();
    std::cout << "All dictionarySimple tests passed" << std::endl;

    setLinked<int> set1;
    setLinked<int> set2;

    set1.insert(10);
    set1.insert(30);
    set1.insert(5);
    set2.insert(30);
    set2.insert(5);
    set2.insert(30);
    set2.insert(1);
    setLinked<int> set3 = set1 + set2;
    set3.show();

    setLinked<int> set4 = set1 - set2;
    set4.show();

    setLinked<int> set5 = set1 * set2;
    set5.show();
    set1.show();
    set2.show();
    return 0;
}

void testCreateNewSet(){
    setSimple set1(10);
    assert(set1.capacity == 10);

    for(int i=0; i < 10; i++){
        assert(set1.getElement(i) == false);
    }
}

void testInsertElement() {
    setSimple set1(10);
    set1.insert(3);
    assert(set1.getElement(3) == true);

    bool exceptionThrown = false;
    try {
        set1.insert(15);
    } catch (const std::out_of_range& e) {
        exceptionThrown = true;
    }
    assert(exceptionThrown == true);
}

void testRemoveElement() {
    setSimple set1(10);
    set1.insert(3);
    set1.remove(3);
    assert(set1.getElement(3) == false);

    bool exceptionThrown = false;
    try {
        set1.remove(15);
    } catch (const std::out_of_range& e) {
        exceptionThrown = true;
    }
    assert(exceptionThrown == true);

}
void testContainsElement() {
    setSimple set1(10);
    set1.insert(3);
    assert(set1.contains(3) == true);
    assert(set1.contains(5) == false);

    bool exceptionThrown = false;
    try {
        set1.contains(900);
    }catch(const std::out_of_range& e){
        exceptionThrown = true;
    }
    assert(exceptionThrown == true);
}

void testSumSets() {
    setSimple set1(10);
    set1.insert(3);
    set1.insert(7);

    setSimple set2(10);
    set2.insert(7);
    set2.insert(8);

    setSimple sumSet = set1 + set2;  // Suma zbiorów set1 i set2
    assert(sumSet.contains(3) == true);  // Element 3 z set1
    assert(sumSet.contains(7) == true);  // Element 7 z obu zbiorów
    assert(sumSet.contains(8) == true);  // Element 8 z set2
    assert(sumSet.contains(5) == false); // Element 5 nie znajduje się w żadnym ze zbiorów
}

void testIntersectionSets() {
    setSimple set1(10);
    set1.insert(3);
    set1.insert(7);

    setSimple set2(10);
    set2.insert(7);
    set2.insert(8);

    setSimple intersectionSet = set1 | set2;
    assert(intersectionSet.contains(7) == true);
    assert(intersectionSet.contains(3) == false);
    assert(intersectionSet.contains(8) == false);
}

void testSubtractSets() {
    setSimple set1(10);
    set1.insert(3);
    set1.insert(7);

    setSimple set2(10);
    set2.insert(7);
    set2.insert(8);

    setSimple subtractSet = set1 - set2;
    assert(subtractSet.contains(3) == true);
    assert(subtractSet.contains(7) == false);
    assert(subtractSet.contains(8) == false);
}

void testEqualsSets() {
    setSimple set1(10);
    set1.insert(3);
    set1.insert(7);

    setSimple set2(10);
    set2.insert(3);
    set2.insert(7);
    assert((set1 == set2) == true);

    setSimple set3(10);
    set3.insert(7);
    assert((set1 == set3) == false);

    setSimple set4(5);
    assert((set1==set4) == false);
}
// ----------------------
void testInsertLinkedElement() {
    setLinked<int> set1;
    set1.insert(3);
    assert(set1.contains(3) == true);

    set1.insert(15);
    assert(set1.contains(15) == true);
}

void testRemoveLinkedElement() {
    setLinked<int> set1;
    set1.insert(3);
    set1.remove(3);
    assert(set1.contains(3) == false);

}

void testContainsLinkedElement() {
    setLinked<int> set1;
    set1.insert(3);
    assert(set1.contains(3) == true);
    assert(set1.contains(5) == false);

}

void testSumLinkedSets() {
    setLinked<int> set1;
    set1.insert(3);
    set1.insert(7);

    setLinked<int> set2;
    set2.insert(7);
    set2.insert(8);

    setLinked<int> sumSet = set1 + set2;
    assert(sumSet.contains(3) == true);
    assert(sumSet.contains(7) == true);
    assert(sumSet.contains(8) == true);
    assert(sumSet.contains(5) == false);
}

void testIntersectionLinkedSets() {
    setLinked<int> set1;
    set1.insert(3);
    set1.insert(7);

    setLinked<int> set2;
    set2.insert(7);
    set2.insert(8);

    setLinked<int> intersectionSet = set1 * set2;
    assert(intersectionSet.contains(7) == true);
    assert(intersectionSet.contains(3) == false);
    assert(intersectionSet.contains(8) == false);
}

void testSubtractLinkedSets() {
    setLinked<int> set1;
    set1.insert(3);
    set1.insert(7);

    setLinked<int> set2;
    set2.insert(7);
    set2.insert(8);

    setLinked<int> subtractSet = set1 - set2;
    assert(subtractSet.contains(3) == true);
    assert(subtractSet.contains(7) == false);
    assert(subtractSet.contains(8) == false);
}

void testEqualsLinkedSets() {
    setLinked<int> set1;
    set1.insert(3);
    set1.insert(7);

    setLinked<int> set2;
    set2.insert(3);
    set2.insert(7);
    assert((set1 == set2) == true);

    setLinked<int> set3;
    set3.insert(7);
    assert((set1 == set3) == false);

    setLinked<int> set4; // Zbiór pusty
    assert((set1 == set4) == false);
}

void testInsertElementDictionary() {
    dictionarySimple dict;
    dict.insert(std::string(50, 'a')); // Poprawny ciąg o długości 50
    assert(dict.contains(std::string(50, 'a')) == true);

    dict.insert(std::string(50, 'b'));
    assert(dict.contains(std::string(50, 'b')) == true);

    // Test dodawania większej liczby elementów
    for (int i = 0; i < 100; ++i) {
        std::string element = std::string(46, 'e') + std::to_string(i); // Ciągi o długości 50
        dict.insert(element);
        assert(dict.contains(element) == true);
    }

}

void testRemoveElementDictionary() {
    dictionarySimple dict;
    dict.insert("applexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); // 42 znaki
    dict.insert("bananaxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

    assert(dict.contains("applexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx") == true);

    dict.remove("nonexistentxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    assert(dict.contains("nonexistentxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx") == false);

    dict.remove("bananaxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    assert(dict.contains("bananaxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx") == false);

}

void testContainsElementDictionary() {
    dictionarySimple dict;
    dict.insert("applexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    dict.insert("bananaxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddd");

    assert(dict.contains("applexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx") == true);
    assert(dict.contains("bananaxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdddddd") == true);
    assert(dict.contains("cherryxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx") == false);

}

void testInsertDuplicateElement() {
    dictionarySimple dict;
    dict.insert("applexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    dict.insert("applexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); // Duplikat

    dict.remove("applexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    assert(dict.contains("applexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx") == false);
}

void testInsertStringLengthValidation() {
    dictionarySimple dict;

    // Test poprawnego ciągu (50 znaków)
    dict.insert(std::string(50, 'a'));
    assert(dict.contains(std::string(50, 'a')) == true);
}
