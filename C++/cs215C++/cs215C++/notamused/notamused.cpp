#include <iostream>
#include <string>
#include <map> // map<K,V>

using namespace std;

int main()
{
    string command, name;
    int time, day_number = 1;

    while(cin >> command) // must be OPEN, i.e. for each day
    {
        // By putting the declaration inside the body,
        // they are constructed anew each time through the loop
        map <string, int> log; // log of the time of entry
        map <string, double> receipts; // how much each patron owes

        while(cin >> command)
        {
            if(command == "ENTER")
            {
                // add an entry to the log
                cin >> name >> time;
                log[name] = time;
            }
            else if(command == "EXIT")
            {
                // compute how much they owe and put it in the receipts
                cin >> name >> time;
                // exit - enter
                int num_minutes = time - log[name];
                double amount_owed = num_minutes * 0.10;
                receipts[name] += amount_owed;
            }
            else // must be CLOSE
            {
                // print out receipts for the day
                cout << "Day " << day_number << endl;

                // type of item will be pair<string, double>
                // pair has two parts, first and second
                for(auto item: receipts) 
                    cout << item.first << " $" << item.second << endl;
                day_number++;
                break; // exits the inner loop
            }
        }
    
    }

    return 0;
}