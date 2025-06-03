#pragma once
#include <string>
#include <iostream>
#include "SmartphoneSpec.h"

using namespace std;

#define DOLLAR_TO_RUB 78.4
#define DOLLAR_TO_EURO 0.88

enum class CURRENCY
{
    RUB,
    EURO,
    DOLLAR
};

class Price
{
private:
    double price; // in dollar
public:
    Price(double price = 0, CURRENCY curr = CURRENCY::DOLLAR) // ПРОТЕСТИТЬ, ЧЁ БУДЕТ ПРИ ПРИВЕДЕНИИ ТИПА
    {
        if (price < 0)
            throw invalid_argument("Price must be positive.");

        switch (curr)
        {
            case CURRENCY::DOLLAR:
                this->price = price;
                break;
            case CURRENCY::RUB:
                this->price = price / DOLLAR_TO_RUB;
                break;
            case CURRENCY::EURO:
                this->price = price / DOLLAR_TO_EURO;
                break;
        }
    }

    double getprice() const { return price; }
    void setprice(double price) 
    {
        if (price < 0)
            throw invalid_argument("Price must be positive.");
        this->price = price;
    }

};

class Smartphone
{
  private:
    string model;
    Price price;
    SmartphoneSpec spec;

  public:
    Smartphone(); 
    Smartphone(string model, Price price, SmartphoneSpec spec); 
    string getModel() const; 
    SmartphoneSpec getSpec() const; 
    double getPrice(CURRENCY curr) const; 
    void setPrice(double price); 

    void print();
};