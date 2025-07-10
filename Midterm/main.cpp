#include <iostream>
#include <string>
#include "makeup_item.h"
#include "inventory.h"
using namespace std;

int main() {
    Inventory myInventory;

    cout << "💄 Welcome to Your Makeup Organizer 💄" << endl;

    // Sample items (you can add more later)
    MakeupItem item1("Gloss Bomb", "Fenty Beauty", "Lip Gloss", "Fenty Glow", 20.0, true);
    MakeupItem item2("Lash Princess", "Essence", "Mascara", "Black", 5.0, false);
    MakeupItem item3("Shape Tape", "Tarte", "Concealer", "Light Medium", 27.0, true);

    myInventory.addItem(item1);
    myInventory.addItem(item2);
    myInventory.addItem(item3);

    cout << "\n👜 Your Full Collection + Wishlist:" << endl;
    myInventory.displayAll();

    // Search for a product by name
    string searchName;
    cout << "\n🔍 Enter a makeup product name to search: ";
    getline(cin, searchName);

    int result = myInventory.binarySearchByName(searchName);
    if (result != -1) {
        cout << "✅ Found it in your collection!" << endl;
    } else {
        cout << "❌ Nope, not found." << endl;
    }

    // Save to file
    myInventory.saveToFile("makeup.txt");
    cout << "\n📁 Your collection was saved to makeup.txt" << endl;

    return 0;
}
