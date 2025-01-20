#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numElements;

    cout << "Enter the number of elements: ";
    cin >> numElements;


    vector<int> myVector;

    cout << "Enter the elements: ";
    for (int i = 0; i < numElements; ++i) {
        int element;
        cin >> element;
        myVector.push_back(element); 
    }

    cout << "Elements of the vector: ";
    for (int i = 0; i < myVector.size(); ++i) {
        cout << myVector[i] << " ";
    }
    cout << endl;

    int newElement;
    cout << "Enter a new element to add: ";
    cin >> newElement;
    myVector.push_back(newElement); 

    
    cout << "Updated elements of the vector: ";
    for (int i = 0; i < myVector.size(); ++i) {
        cout << myVector[i] << " ";
    }
    cout << endl;

    return 0;
}
