#include "makeup_item.h"
#include <iostream>
using namespace std;

MakeupItem::MakeupItem() {
    name = brand = type = shade = "";
    price = 0.0;
    owned = false;
}

MakeupItem::MakeupItem(string n, string b, string t, string s, float p, bool o) {
    name = n;
    brand = b;
    type = t;
    shade = s;
    price = p;
    owned = o;
}

void MakeupItem::display() const {
    cout << "Name: " << name
         << ", Brand: " << brand
         << ", Type: " << type
         << ", Shade: " << shade
         << ", Price: $" << price
         << ", Status: " << (owned ? "Owned" : "Wishlist") << endl;
}

string MakeupItem::getName() const {
    return name;
}

string MakeupItem::getBrand() const {
    return brand;
}

bool MakeupItem::isOwned() const {
    return owned;
}
