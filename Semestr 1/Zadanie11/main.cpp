#include <iostream>
#include <cassert>
#include "BinarySearchTree.h"

void test_find_min_max() {
    BinarySearchTree<int> tree;

    assert(tree.find_min() == nullptr);
    assert(tree.find_max() == nullptr);
    std::cout<<"Test 1 Passed"<<std::endl;

    tree.insert(10);
    assert(*tree.find_min() == 10);
    assert(*tree.find_max() == 10);
    std::cout<<"Test 2 Passed"<<std::endl;


    BinarySearchTree<int> tree2;
    tree2.insert(50);
    tree2.insert(30);
    tree2.insert(70);
    tree2.insert(20);
    tree2.insert(40);

    /* Struktura drzewa:
             50
            /  \
          30    70
         /  \
       20    40

    */
    assert(*tree2.find_min() == 20);
    assert(*tree2.find_max() == 70);
    std::cout<<"Test 3 Passed"<<std::endl;


    BinarySearchTree<int> tree3;
    tree3.insert(100);
    tree3.insert(50);
    tree3.insert(150);
    tree3.insert(25);
    tree3.insert(75);
    tree3.insert(125);
    tree3.insert(175);
    tree3.insert(10);
    tree3.insert(60);

    /* Struktura drzewa:
                   100
                 /    \
               50     150
             / \     /  \
            25  75  125  175
           /   /
         10   60
    */


    assert(*tree3.find_max() == 175);
    assert(*tree3.find_min() == 10);
    std::cout<<"Test 4 Passed"<<std::endl;

    std::cout << "All tests passed successfully!" << std::endl;
}

int main() {
    test_find_min_max();
    return 0;
}
