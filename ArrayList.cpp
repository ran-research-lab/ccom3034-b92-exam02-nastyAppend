//
// Implementation of the member functions of the ArrayList class
//

#include "ArrayList.h"
#include <algorithm>

ostream& operator<<(ostream &out, const ArrayList &AL);

//
// Constructor. The allocsize parameter has a default value of 4.
//

ArrayList::ArrayList(int allocSize): allocationSize(allocSize) {
    A = new ElementType[allocationSize];
    length = 0;
}

//
// resize(): changes the capacity of the dynamic array to the
//           specified allocationSize.
//

void ArrayList::resize(int newAllocationSize) {
    int *newA = new ElementType[newAllocationSize];

    for (int i = 0; i < length && i < newAllocationSize; i++)
        newA[i] = A[i];

    delete A;
    A = newA;
    allocationSize = newAllocationSize;
    length = min(allocationSize, length);
}

//
// append(): given val, inserts it at the end of the list
//

void ArrayList::append(ElementType val) {
    if (length == allocationSize -1)
        resize(allocationSize * 2);

    A[length] = val;
    length++;
}

//
// prepend(): given val, inserts it at the start of the list
//

void ArrayList::prepend(ElementType val) {
    if (length == allocationSize -1)
        resize(allocationSize * 2);

    for (int i = length; i > 0; i--)
        A[i] = A[i-1];

    A[0] = val;
    length++;
}

//
// insertAfter(): given val inserts it after the index provided
//                idx = -1 means the same as prepend.
//

void ArrayList::insertAfter(int idx, ElementType val) {
    if (idx < -1 || idx >= length)
        cout << "Invalid index for insertion: " << idx << endl;
    else {
        if (length == allocationSize -1)
            resize(allocationSize * 2);

        for (int i = length; i > idx + 1; i--)
            A[i] = A[i-1];

        A[idx+1] = val;
        length++;
    }
}

//
// search() : given a key, linear search through the list, returns the
//            index if found, -1 if not found
//

int ArrayList::search(ElementType key) const {
    for (int i = 0; i < length; i++) {
        if (A[i] == key) return i;
    }
    return -1;
}

//
// removeAt(): given idx, remove that element at that position
//

void ArrayList::removeAt(int idx) {
    if (idx < 0 || idx >= length)
        cout << "Invalid index in removeAt: " << idx << endl;
    else {
        for (int i = idx; i < length - 1; i++)
            A[i] = A[i + 1];

        length--;
    }
}

//
// display(): helper function for display the contents of the list
//

void ArrayList::display(ostream &out) const{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
}

//
// Overload of the operator<<, so that cout << L works!
//

ostream& operator<<(ostream &out, const ArrayList &AL) {
    AL.display(out);
    return out;
}

//
// Overload of the assignment operator.
//

void ArrayList::operator=(const ArrayList& L) {
    if (this != &L) {
        length = L.length;
        allocationSize = L.allocationSize;
        delete [] A;
        A = new int[allocationSize];
        for (int i = 0; i < length; i++) {
            A[i] = L.A[i];
        }
    }
}

//
// Destructor
//

ArrayList::~ArrayList(){
    delete [] A;
}

//
// Overload of the copy constructor.
//

ArrayList::ArrayList(const ArrayList& L){
    if (this == &L) {
        length = 0;
        allocationSize = 4;
        A = new int[allocationSize];
    }
    else {
        length = L.length;
        allocationSize = L.allocationSize;
        A = new int[allocationSize];
        for (int i = 0; i < length; i++) {
            A[i] = L.A[i];
        }
    }
}

//
// getLength: just a getter for the length data member
//

int ArrayList::getLength() const { return length;}

//
// at: given an index returns the content of that element of A.
//     is the given index is not valid, returns a 0
//

ElementType ArrayList::at(int idx) const {
    if (idx < 0 || idx >= length) return 0;
    else return A[idx];
}
