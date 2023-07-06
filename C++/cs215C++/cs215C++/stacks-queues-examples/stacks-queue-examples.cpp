#include <iostream>
#include <stack> // STL stack
#include <queue> // STL queue
#include <string>

using namespace std;

int main()
{
    stack<int> s; // only default constructor available; creats empty stack

    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    for(int i = 0; i < n; i++)
        s.push(i * 10); // adds element to the top of stack

    cout << "The stack size is: " << s.size() << endl;

    s.top() = 99; // top returns a reference to top (last) element

    cout << "Popping stack: " << endl;
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop(); // pops the top (last) element
    }

    queue<int> q;

    for(int i = 0; i < n; i++)
    q.push(i * 10); // adds element to the top of queue

    cout << "The queue size is: " << s.size() << endl;

    q.front() = 99; // front returns a reference to front (first) element

    cout << "Popping queue: " << endl;
    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop(); // pops the last element
    }
    
    // is a word a palindrome? same letter forwards and backwards
    string word;
    cin >> word;

    stack<char> cstack;
    queue<char> cqueue;

    for(int i = 0; i < word.length(); i++)
    {
        cstack.push(word[i]);
        cqueue.push(word[i]);
    }

    bool is_palindrome = true;
    while (!cstack.empty() && is_palindrome)
    {
        if(cstack.top() != cqueue.front()) // don't match, not a palindrom
            is_palindrome = false;
        // pop both stack and queue
        cstack.pop();
        cqueue.pop();
    }

    if(is_palindrome)
        cout << "The word is a palindrome" << endl;
    else
        cout << "The word is not a palindrome" << endl;
    return 0;
}