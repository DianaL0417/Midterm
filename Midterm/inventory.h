#ifndef INVENTORY_H
#define INVENTORY_H

#include "makeup_item.h"

class Inventory {
private:
    MakeupItem* items; // dynamic array of makeup items
    int size;
    int capacity;

    void resize(); // internal function to expand the array when full

public:
    Inventory(int cap = 10);
    ~Inventory();

    void addItem(const MakeupItem& item);
    void displayAll(bool showOwned = true, bool showWishlist = true) const;
    int binarySearchByName(string name) const;

    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
