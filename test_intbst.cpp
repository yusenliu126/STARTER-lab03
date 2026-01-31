// test_intbst.cpp
// Comprehensive test for IntBST implementation

#include "intbst.h"
#include <iostream>
#include <cassert>
using namespace std;

void testConstructorDestructor() {
    cout << "Testing constructor/destructor... ";
    IntBST bst;
    assert(bst.count() == 0);
    assert(bst.sum() == 0);
    cout << "PASS" << endl;
}

void testInsert() {
    cout << "Testing insert... ";
    IntBST bst;
    assert(bst.insert(10));
    assert(bst.insert(5));
    assert(bst.insert(15));
    assert(bst.insert(3));
    assert(bst.insert(7));
    assert(!bst.insert(5));  // duplicate
    assert(bst.count() == 5);
    cout << "PASS" << endl;
}

void testTraversals() {
    cout << "Testing traversals... ";
    IntBST bst;
    bst.insert(64); bst.insert(128); bst.insert(8); bst.insert(512);
    bst.insert(256); bst.insert(32); bst.insert(16); bst.insert(4);
    
    // In-order should be sorted: 4 8 16 32 64 128 256 512
    cout << "In-order: "; bst.printInOrder(); cout << endl;
    cout << "Pre-order: "; bst.printPreOrder(); cout << endl;
    cout << "Post-order: "; bst.printPostOrder(); cout << endl;
    cout << "PASS" << endl;
}

void testSumCount() {
    cout << "Testing sum/count... ";
    IntBST bst;
    bst.insert(1); bst.insert(2); bst.insert(3);
    assert(bst.sum() == 6);
    assert(bst.count() == 3);
    cout << "PASS" << endl;
}

void testContains() {
    cout << "Testing contains... ";
    IntBST bst;
    bst.insert(64); bst.insert(8); bst.insert(512);
    
    assert(bst.contains(64));
    assert(bst.contains(8));
    assert(bst.contains(512));
    assert(!bst.contains(100));
    assert(!bst.contains(0));
    cout << "PASS" << endl;
}

void testPredecessorSuccessor() {
    cout << "Testing predecessor/successor... ";
    IntBST bst;
    bst.insert(64); bst.insert(128); bst.insert(8);
    bst.insert(512); bst.insert(256); bst.insert(32);
    bst.insert(16); bst.insert(4);
    
    assert(bst.getPredecessor(64) == 32);
    assert(bst.getPredecessor(4) == 0);
    assert(bst.getPredecessor(512) == 256);
    
    assert(bst.getSuccessor(64) == 128);
    assert(bst.getSuccessor(512) == 0);
    assert(bst.getSuccessor(4) == 8);
    cout << "PASS" << endl;
    
    cout << "Pred(64)=" << bst.getPredecessor(64) << endl;
    cout << "Pred(4)=" << bst.getPredecessor(4) << endl;
    cout << "Succ(64)=" << bst.getSuccessor(64) << endl;
}

void testRemove() {
    cout << "Testing remove... ";
    IntBST bst;
    bst.insert(64); bst.insert(128); bst.insert(8);
    bst.insert(512); bst.insert(256); bst.insert(32);
    bst.insert(16); bst.insert(4);
    
    assert(bst.remove(4));
    assert(!bst.contains(4));
    assert(bst.contains(8));
    
    assert(bst.remove(64));
    assert(!bst.contains(64));
    assert(bst.contains(128));
    
    assert(bst.remove(128));
    assert(!bst.contains(128));
    assert(bst.contains(512));
    
    cout << "Count after removals: " << bst.count() << endl;
    cout << "Final tree in-order: "; bst.printInOrder(); cout << endl;
    cout << "PASS" << endl;
}

int main() {
    cout << "=== Comprehensive IntBST Test Suite ===" << endl;
    
    testConstructorDestructor();
    testInsert();
    testTraversals();
    testSumCount();
    testContains();
    testPredecessorSuccessor();
    testRemove();
    
    cout << "\n*** ALL TESTS PASSED! ***" << endl;
    return 0;
}
