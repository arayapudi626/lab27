#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, string, string> villagerData;

//print function
void printVillagers(const map<string, villagerData>& villagers) {
  cout << "Villagers details: " << endl;
    for (map<string, villagerData>::const_iterator i = villagers.begin(); i != villagers.end(); ++i) {
        cout << i->first << "[ "
        << get<0>(i->second) << ", "
        << get<1>(i->second) << ", "
        << get<2>(i->second) << "] " << endl;
    }
}

int main() {
    // declarations
    map<string, villagerData> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = villagerData(5, "Anteater", "Woo!");
    villagers["Raymond"] = villagerData(9, "Dog", "Lets go");
    villagers["Josh"] = villagerData(7, "Bird", "Fire");
  
    //printVillagers(villagers);

    //menu
    while (true) {
        cout << "1. Increase Friendship \n";
        cout << "2. Increase Friendship \n";
        cout << "3. Increase Friendship \n";
        cout << "4. Decrease Friendship \n";
        cout << "5. Search for Villager \n";
        cout << "6. Exit \n";
        int c;
        cin >> c;

        if(c==1){
            string name;
            string animal;
            string phrase;
            int level;
            cout << "Villager name: ";
            cin >> name;
            cout << "Friendship level";
            cin >> level;
            cout << "Species: ";
            cin >> animal;
            cout << "Catchphrase: ";
            cin >> phrase;
            villagers
        }
        else if(c==3){
            string name;
            cout << "Villager: ";
            cin >> name;
            map<string, villagerData>::iterator it = villagers.find(name);
            if (it == villagers.end()){
                cout << name << " not found." << endl;
            }
            else {
                int level = get<0>(it->second);
                if (level < 10) level++;
                get<0>(it->second) = level;
                cout << name << " now level " << level << endl;
            }
            printVillagers(villagers);
        }
        else if(c==4){
            string name;
            cout << "Villager: ";
            cin >> name;
            map<string, villagerData>::iterator it = villagers.find(name);
            if (it == villagers.end()){
                cout << name << " not found." << endl;
            }
            else {
                int level = get<0>(it->second);
                if (level < 10) level--;
                get<0>(it->second) = level;
                cout << name << " now level " << level << endl;
            }
            printVillagers(villagers);
        }

        else if(c==5){
            string name;
            cout << "Search name: ";
            cin >> name;
            map<string, villagerData>::iterator it = villagers.find(name);
            if (it == villagers.end()){
                cout << name << " not found." << endl;
            }
            else {
                cout << "Found: " << name << "["
                << get<0>(it->second) << ", "
                << get<1>(it->second) << ", "
                << get<2>(it->second) << "] \n";

    }
     printVillagers(villagers);
}

else if(c==6){
    break;
}
    }


    /*// access the map using iterators
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
*/
    return 0;
}
