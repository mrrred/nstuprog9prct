#include "Catalog.h"
#include <algorithm>

#define UNDEFINGED -1

static int in_vector(string model, vector<Smartphone> smartphones)
{
    int index = 0;

    for(const auto& s : smartphones)
    {
        if(s.getModel() == model)
            return index;
        index++;
    }

    return UNDEFINGED;
}

void Catalog::addchangeSpecSmartphone(string model, const string &field, const string &meaning)
{
    int index = in_vector(model, smartphones);

    if (index != UNDEFINGED)
    {
        smartphones[index].addchangeSpec(field, meaning);
    }
}

void Catalog::delSpecSmartphone(string model, const string &field)
{
    int index = in_vector(model, smartphones);

    if (index != UNDEFINGED)
    {
        smartphones[index].delSpec(field);
    }
}

void Catalog::addSmartphone(string model, Price price, SmartphoneSpec spec)
{
    smartphones.push_back(Smartphone{model, price, spec});
}
Smartphone Catalog::getSmartphone(string model)
{
    transform(model.begin(), model.end(), model.begin(), ::tolower);
    for (Smartphone s : smartphones)
    {
        string currModel = s.getModel();
        transform(currModel.begin(), currModel.end(), currModel.begin(), ::tolower);
        if (currModel == model)
            return s;
    }
    return Smartphone();
}

static bool contains(string find_key, string find_el, map<string, string> spec_map)
{
    for (const auto& pair : spec_map)
    {
        if (find_key == pair.first && find_el == pair.second)
            return true;
        
        if (pair.first[0] > find_key[0])
            break;
    }

    return false;
}

vector<Smartphone> Catalog::search(const Smartphone &searchSmartphone)
{
    vector<Smartphone> results;
    for (Smartphone s : smartphones)
    {

        string model = searchSmartphone.getModel();
        transform(model.begin(), model.end(), model.begin(), ::tolower);
        string model2 = s.getModel();
        transform(model2.begin(), model2.end(), model2.begin(), ::tolower);

        if (!model.empty() && model != model2)
            continue;

        bool flag = true;

        for (const auto& pair : searchSmartphone.getSpec().getSpecMap())
        {
            if (!(contains(pair.first, pair.second, s.getSpec().getSpecMap())))
            {
                flag = false;
                break;
            }
        }
        
        if (flag == true)
            results.push_back(s);
    }
    return results;
}
