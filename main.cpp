#include "Catalog.h"
#include "Smartphone.h"
#include <iostream>
using namespace std;

Catalog InitializeCatalog()
{
    Catalog catalog;
    catalog.addSmartphone("iPhone 12 Pro", Price(100, CURRENCY::DOLLAR), move(SmartphoneSpec{move(map<string, string>{
        {"Manufacturer", "Apple"},
        {"Color", "Black"},
        {"Ram", "6"},
        {"OS", "IOS"},
        {"CPU", "Apple"}
    })}));
    catalog.addSmartphone("SAMSUNG 9", Price(10000, CURRENCY::RUB), move(SmartphoneSpec{move(map<string, string>{
        {"Manufacturer", "Samsung"},
        {"Color", "Black"},
        {"Ram", "4"},
        {"OS", "Android"},
        {"CPU", "Snapdragon"}
    })}));
    
    return catalog;
}
int main(int argc, char *argv[])
{
    Catalog catalog = InitializeCatalog();

    
    Smartphone whatBuyerLikes{"", 0, move(SmartphoneSpec{move(map<string, string>{
        {"Color", "Black"},
    })})};
    
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