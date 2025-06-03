#include "Smartphone.h"

Smartphone::Smartphone() : model{""}, price{0} {}

Smartphone::Smartphone(string model, Price price, SmartphoneSpec spec)
    : model{model}, price{price}, spec{spec} {}

string Smartphone::getModel() const
{
    return model;
}

SmartphoneSpec Smartphone::getSpec() const
{
    return spec;
}

double Smartphone::getPrice(CURRENCY curr) const
{
    switch (curr)
    {
        case CURRENCY::RUB:
            return price.getprice() * DOLLAR_TO_RUB;
        case CURRENCY::EURO:
            return price.getprice() * DOLLAR_TO_EURO;
    }
    return price.getprice();
}
void Smartphone::setPrice(double price)
{
    this->price.setprice(price);
}

void Smartphone::print()
{
    cout << "Model: " << model << endl;

    for(const auto& pair : spec.getSpecMap())
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "Price in Dollar: " << getPrice(CURRENCY::DOLLAR) << " $" << endl;
    cout << "Price in Euro: " << getPrice(CURRENCY::EURO) << " E" << endl;
    cout << "Price in Rub: " << getPrice(CURRENCY::RUB) << " R" << endl;
}