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
    void addchangeSpecSmartphone(string model, const string &field, const string &meaning);
    void delSpecSmartphone(string model, const string &field);
    Smartphone getSmartphone(string model);
    vector<Smartphone> search(const Smartphone &searchSmartphone);
};