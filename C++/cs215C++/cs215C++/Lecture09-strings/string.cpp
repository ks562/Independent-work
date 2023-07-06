#include <iostream>
#include <string>   // C++ string library

int main()
{
    using namespace std;
    string word1; // Type is 'string' and it's in the std namespace
                  // Default construction for a string is empty string
    string word2("Hello"); // creates a string initialized to "Hello"
    string word3 = "Hello"; // alternate syntax for construction

    // Assignment
    word1 = "hot";
    word2 = "dog";

    // Output using << - print out the string
    cout << "word1 = " << word1 << endl;
    cout << "word2 = " << word2 << endl;
    cout << "word3 = " << word3 << endl;

    // Concatenation
    word3 = word1 + word2;

    cout << "After Concatenation" << endl;
    cout << "word1 = " << word1 << endl;
    cout << "word2 = " << word2 << endl;
    cout << "word3 = " << word3 << endl;

    // Indexing and length
    for(int i = 0; i < word3.length(); i++)
        cout << word3[i] << " ";

    cout << endl;

    // Input >> operator only reads one "word"
    cout << "Enter a word: ";
    cin >> word1;
    cout << "Enter another word: ";
    cin >> word2;
    cout << "word1 = " << word1 << endl;
    cout << "word2 = " << word2 << endl;

    // Comparison - dictionary order where uppercase < lowercase
    if(word1 < word2)
        cout << word1 << " < " << word2 << endl;
    else if(word1 > word2)
        cout << word1 << " > " << word2 << endl;
    else
        cout << word1 << " = " << word2 << endl;

    // Inputing lines
    cout << "Enter a line: ";
    cin.ignore(); // gets rid of the current character in the stream
                  // i.e., the trailing newline from previous <<
    getline(cin, word1); // all chars upto and including the newline
    cout << "Echo: " << word1 << endl;

    // Find - search
    cout << "Enter a word: ";
    cin >> word2;
    size_t position = word1.find(word2);// returns the index of word2 in word1
    if(position == string::npos) // string::npos means: not found
        cout << word2 << " is not contained in " << word1 << endl;

    else
        cout << word2 << " starts at index " << position << " in "
             << word1 << endl;

    // Create a substring
    word3 = word1.substr(position, 2); // index of the first char
                                       // # of chars in the substring
    cout << "Substring at index " << position << " is " << word3 << endl;
    
    return 0;
}