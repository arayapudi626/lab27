#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, string, string> villagerData;


int main() {
    // declarations
    map<string, villagerData> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = villagerData(5, "Anteater", "Woo!");
    villagers["Raymond"] = villagerData(9, "Dog", "Lets go");
    villagers["Raymond"] = villagerData(7, "Bird", "Fire");

    // access the map using a range-based for loop
    cout << "Villagers details: \n" << endl;
    for (auto pair : villagers) {
        cout << pair.first << "[ "
        << get<0>(pair.second) << ", "
        << get<1>(pair.second) << ", "
        << get<2>(pair.second) << ", " << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagers.begin(); 
                                               it != villagers.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}
