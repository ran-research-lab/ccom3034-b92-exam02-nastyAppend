//
// Declaration of the ArrayList class
//


#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

#include <iostream>
using namespace std;
typedef int ElementType;

class ArrayList {
private:
    ElementType  *A;
    int length;
    int allocationSize;

    void resize(int newAllocationSize);

public:
    ArrayList(int allocSize = 4);
    void append(ElementType val);
    void prepend(ElementType val);
    void insertAfter(int idx, ElementType val);
    int search(ElementType key) const;
    void removeAt(int idx);

    int getLength() const;
    ElementType at(int idx) const;

    void display(ostream &out) const;

    void operator=(const ArrayList& L);
    ~ArrayList();
    ArrayList(const ArrayList& L);


};


#endif //ARRAYLIST_ARRAYLIST_H
