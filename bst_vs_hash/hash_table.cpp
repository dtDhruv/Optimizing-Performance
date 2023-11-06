#include <iostream>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    cout << "-----------------------------------------------------------" << endl;
    cout << "Insertion and Searching in Hash Table Starting Now: " << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;

    const int numElements = 100001;

    // Hash Table
    unordered_map<int, bool> hashTable;

    // Insertion
    auto startInsert = high_resolution_clock::now();

    for (int i = 0; i < numElements; ++i) {
        hashTable[i] = true;
    }

    auto stopInsert = high_resolution_clock::now();
    auto durationInsert = duration_cast<microseconds>(stopInsert - startInsert);

    cout << "-----------------------------------------------------------" << endl;
    cout << "Time taken to insert " << numElements << " elements: " << durationInsert.count() << " microseconds" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;

    // Searching
    int keyToSearch = 100000;
    std::cout << "-----------------------------------------------------------" << std::endl;
    cout << "Searching for 100000"<< endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

    auto startSearch = high_resolution_clock::now();
    auto found = hashTable.find(keyToSearch);
    auto stopSearch = high_resolution_clock::now();
    auto durationSearch = duration_cast<microseconds>(stopSearch - startSearch);

    if (found != hashTable.end())
        cout << keyToSearch << " found" << endl;
    else
        cout << keyToSearch << " not found" << endl;

    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Time taken to search: " << durationSearch.count() << " microseconds" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Hash Table Implementation Over" << endl;
    
    int buff;
    cin >> buff;

    return 0;
}