#include <iostream>
#include <vector> // vector<T> class template
#include <string>
#include <fstream>

// Template can have a type parameter so that we only need to write a function once,
// and instantiate it multiple times for each type needed.

using namespace std;

template <typename T> // T is a type parameter, use it where the type is needed
void print_vector(const vector<T>& v) // REC'D: vector to print
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}

template <typename T>
void read_vector_from_stream (istream& instream,
                              vector<T>& v) // P'BACK
{
    v.clear(); // make sure the evector is empty

    T value; // a value for the vector
    while(instream >> value)
    {
        v.push_back(value);
    }
}

template <typename C> // T type parameter, use it where the type is needed
void print_collection(const C & c) // REC'D: collection to print
{
    // for(auto iter = c.begin(); // auto is an infered type by compiler
    //     // typename C::const_iterator iter = c.begin(); // begin() gives iterator to 1st element
    //  iter != c.end(); // end() gives iterator one past the last element
    //  iter++) // increment to next item

    // Range-based for-loop, "for each"
    for(auto item : c)
        cout << item << endl; // * dereferences iter to item
}


int main()
{
    // Syntax: vector<T> where T is the type of the elements
    vector<int> intVector;  // default construction is empty vectors
    vector<double> doubleVector;
    vector<string> stringVector;

    // The argument is the number of default constructed T values
    // For int T() is 0
    vector<int> intVector2 (5); // 5 elements of value 0
    vector<string> stringVector2 (3); // 3 elemets of empty string

    vector<int> intVector3 (7, -1); // 7 elements of value -1
    vector<int> intVector4 = {5, 3, 2, 0}; // initialization list
                                          // -std=c++11 flag is required

    vector<string> stringVector3 = {"hello", "goodbye", "thanks"};

    cout << "intVector2:" << endl;
    print_vector(intVector2);
    cout << "intVector3:" << endl;
    print_vector(intVector3);
    cout << "intVector4:" << endl;
    print_vector(intVector4);
    cout << "doubleVector" << endl;
    print_vector(doubleVector);
    cout << "stringVector2:" << endl;
    print_vector(stringVector2);
    cout << "stringVector3:" << endl;
    print_vector(stringVector3);

    cout << "First elements of stringVector3 is " << stringVector3.front() << endl;
    cout << "Last elements is " << stringVector3.back() << endl;

    if(intVector.empty())
        cout << "intVector is empty" << endl;
    else
        cout << "intVector is not empty" << endl;
    
    cout << "Enter an index: " << endl;
    int index;
    cin >> index;
    cout << "The value at that index is: " << stringVector3.at(index) << endl;
    cout << "The value at that index is: " << stringVector3[index] << endl;

    // Mutations
    // push_back - adds an element to the back of the vector
    stringVector3.push_back("Please");
    print_vector(stringVector3);

    ifstream inFile("input.txt");
    read_vector_from_stream(inFile, intVector);
    print_vector(intVector);

    intVector.front() = 10;
    intVector.back() = 99;
    print_vector(intVector);

    intVector2 = intVector; // assignment
    intVector2.resize(10); // if arguments is smaller than current size
                          // vector is truncated. if argument is larger
                          // new elements are filled with T().
    print_collection(intVector2);

    cout << "Use an algorithm to reverse intVector" << endl;
    reverse(intVector.begin(), intVector.end());    // iterators to beginning and one past the end of
                                                    // the range to reverse
    
    print_collection(intVector2);

    return 0;
}