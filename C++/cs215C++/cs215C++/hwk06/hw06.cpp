#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}

void reverse_vector(vector<int> &v) // REC'D & P'BACK
{
    int temp = 0;
    // count to halfway
    for(size_t i = 0; i < v.size() / 2; i++)
    {
        // swap the ith value wit hthe ith from the end value
        temp = v[v.size() - 1 - i]; // ith item from the end
        v[v.size() - 1 - i] = v[i];
        v[i] = temp;

        /* OR:
        temp = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = temp;
        */
    }
}

vector<int> reverse_vector2(const vector<int> &v) // REC'D only
{
    vector<int> new_v;

    // count backwards
    for(int i = v.size() - 1; i >= 0; i--)
        new_v.push_back(v[i]);

    return new_v;
}

int main()
{
    vector<int> intVector = {19, 13, 7, 12, 16};
    vector<int> v1, v2;

    cout << "intVector\n";
    print_vector(intVector);

    v1 = intVector; // make a copy.
    reverse_vector(v1);
    cout << "vector after reversing\n";
    print_vector(v1);

    v2 = reverse_vector2(intVector);
    cout << "new vector returned reversed\n";
    print_vector(v2);


    return 0;
}