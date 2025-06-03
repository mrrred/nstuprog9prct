#include "Catalog.h"
#include "Smartphone.h"
#include <iostream>
using namespace std;

Catalog InitializeCatalog()
{
    Catalog catalog;
    catalog.addSmartphone("iPhone 12 Pro", Price(100, CURRENCY::DOLLAR), move(SmartphoneSpec{Manufacturer::APPLE, Color::WHITE, 6, 3, 64, CPU::APPLE, OS::IOS}));
    catalog.addSmartphone("iPhone 12 Pro", Price(200, CURRENCY::EURO),  move(SmartphoneSpec{Manufacturer::APPLE, Color::WHITE, 6, 3, 128, CPU::APPLE, OS::IOS}));
    catalog.addSmartphone("iPhone 12 Pro", Price(9800, CURRENCY::RUB), move(SmartphoneSpec{Manufacturer::APPLE, Color::BLUE, 6, 3, 64, CPU::APPLE, OS::IOS}));
    catalog.addSmartphone("Samsung 9", Price(10000, CURRENCY::RUB), move(SmartphoneSpec{Manufacturer::SAMSUNG, Color::BLUE, 6, 3, 64, CPU::SNAPDRAGON, OS::ANDROID}));
    
    return catalog;
}
int main(int argc, char *argv[])
{
    Catalog catalog = InitializeCatalog();
    Smartphone whatBuyerLikes{"Samsung 9", 0, move(SmartphoneSpec{Manufacturer::SAMSUNG, Color::BLUE, 0, 0, 0, CPU::UNDEFINED,
                              OS::UNDEFINED})};
    vector<Smartphone> results = catalog.search(whatBuyerLikes);
    if (!results.empty())
    {
        cout << "You might like this:" << endl;
        for (Smartphone s : results)
        {
            s.print();
            cout << endl;
        }
    }
    else
        cout << "Sorry, we have nothing for you.";

    return 0;
}