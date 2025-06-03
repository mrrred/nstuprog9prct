#pragma once 

#include <map>
#include <string>

using namespace std;


class SmartphoneSpec 
{ 
private: 
    map<string, string> spec_map;
public:
    SmartphoneSpec(); 
    SmartphoneSpec(const map<string, string> &spec_map); 
    map<string, string> getSpecMap() const;
    void addchangeSpec(const string &field, const string &meaning);
    void delSpec(const string &field);
}; 