#include "SmartphoneSpec.h"

SmartphoneSpec::SmartphoneSpec() {}

SmartphoneSpec::SmartphoneSpec(const map<string, string> &spec_map) : spec_map{spec_map} {}

map<string, string> SmartphoneSpec::getSpecMap() const { return spec_map; }

void SmartphoneSpec::addchangeSpec(const string &field, const string &meaning) { spec_map[field] = meaning; }

void SmartphoneSpec::delSpec(const string &field) { spec_map.erase(field); }