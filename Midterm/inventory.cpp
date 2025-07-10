#include "inventory.h"
#include <iostream>
#include <fstream>
#include <algorithm> // for sorts
using namespace std;

Inventory::Inventory(int cap) {
    capacity = cap;
    size = 0;
    items = new MakeupItem[capacity];
}

Inventory::~Inventory() {
    delete[] items;
}

void Inventory::resize() {
    capacity *= 2;
    MakeupItem* newItems = new MakeupItem[capacity];
    for (int i = 0; i < size; i++) {
        newItems[i] = items[i];
    }
    delete[] items;
    items = newItems;
}

void Inventory::addItem(const MakeupItem& item) {
    if (size >= capacity) {
        resize();
    }
    items[size] = item;
    size++;
}

void Inventory::displayAll(bool showOwned, bool showWishlist) const {
    for (int i = 0; i < size; i++) {
        if ((showOwned && items[i].isOwned()) || (showWishlist && !items[i].isOwned())) {
            items[i].display();
        }
    }
}

int Inventory::binarySearchByName(string name) const {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (items[mid].getName() == name) {
            return mid;
        } else if (items[mid].getName() < name) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void Inventory::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    for (int i = 0; i < size; i++) {
        outFile << items[i].getName() << ","
                << items[i].getBrand() << ","
                << items[i].isOwned() << endl; // Just a basic save for now
    }
    outFile.close();
}

void Inventory::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    string name, brand, ownedStr;
    while (getline(inFile, name, ',') &&
           getline(inFile, brand, ',') &&
           getline(inFile, ownedStr)) {
        bool owned = (ownedStr == "1");
        MakeupItem item(name, brand, "type", "shade", 0.0, owned); // You can expand this!
        addItem(item);
    }
    inFile.close();
}
