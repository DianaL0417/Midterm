#ifndef MAKEUP_ITEM_H
#define MAKEUP_ITEM_H

#include <string>
using namespace std;

class MakeupItem {
private:
    string name;
    string brand;
    string type;
    string shade;
    float price;
    bool owned;

public:
    MakeupItem();
    MakeupItem(string n, string b, string t, string s, float p, bool o);
    
    void display() const;

    string getName() const;
    string getBrand() const;
    bool isOwned() const;
};

#endif
