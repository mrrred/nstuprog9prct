#pragma once
#include "Smartphone.h"
#include <string>
#include <vector>
using namespace std;
class Catalog
{
  private:
    vector<Smartphone> smartphones;

  public:
    void addSmartphone(string model, Price price, SmartphoneSpec spec);
    Smartphone getSmartphone(string model);
    vector<Smartphone> search(const Smartphone &searchSmartphone);
};