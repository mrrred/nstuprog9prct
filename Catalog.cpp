#include "Catalog.h"
#include <algorithm>

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

        Manufacturer manufacturer = searchSmartphone.getSpec().getManufacturer();
        if (manufacturer != Manufacturer::UNDEFINED && manufacturer != s.getSpec().getManufacturer())
            continue;

        Color color = searchSmartphone.getSpec().getColor();
        if (color != Color::UNDEFINED && color != s.getSpec().getColor())
            continue;

        float displaySize = searchSmartphone.getSpec().getDisplay();
        if (displaySize > 0 && displaySize != s.getSpec().getDisplay())
            continue;

        int ram = searchSmartphone.getSpec().getRAM();
        if (ram > 0 && ram != s.getSpec().getRAM())
            continue;

        int storage = searchSmartphone.getSpec().getStorage();
        if (storage > 0 && storage != s.getSpec().getStorage())
            continue;

        CPU cpu = searchSmartphone.getSpec().getCPU();
        if (cpu != CPU::UNDEFINED && cpu != s.getSpec().getCPU())
            continue;

        OS os = searchSmartphone.getSpec().getOS();
        if (os != OS::UNDEFINED && os != s.getSpec().getOS())
            continue;

        results.push_back(s);
    }
    return results;
}
