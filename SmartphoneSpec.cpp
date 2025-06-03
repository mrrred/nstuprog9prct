#include "SmartphoneSpec.h"

SmartphoneSpec::SmartphoneSpec() : manufacturer{Manufacturer::UNDEFINED}, color{Color::UNDEFINED}, displaySize{0}, 
    ram{0}, storage{0}, cpu{CPU::UNDEFINED}, os{OS::UNDEFINED} {}

SmartphoneSpec::SmartphoneSpec(Manufacturer manufacturer, Color color, float displaySize, 
    int ram, int storage, CPU cpu, OS os)
    : manufacturer{manufacturer}, color{color}, displaySize{displaySize}, ram{ram}, 
    storage{storage}, cpu{cpu}, os{os} {}

Manufacturer SmartphoneSpec::getManufacturer() const
{
    return manufacturer;
}
Color SmartphoneSpec::getColor() const
{
    return color;
}
float SmartphoneSpec::getDisplay() const
{
    return displaySize;
}
int SmartphoneSpec::getRAM() const
{
    return ram;
}
int SmartphoneSpec::getStorage() const
{
    return storage;
}
CPU SmartphoneSpec::getCPU() const
{
    return cpu;
}
OS SmartphoneSpec::getOS() const
{
    return os;
}

std::string toString(Manufacturer manufacturer) {
    switch (manufacturer) {
        case Manufacturer::APPLE:       return "Apple";
        case Manufacturer::HTC:         return "HTC";
        case Manufacturer::SAMSUNG:     return "Samsung";
        case Manufacturer::UNDEFINED:   return "Undefined";
        case Manufacturer::XIAOMI:      return "Xiaomi";
        case Manufacturer::MOTOROLA:    return "Mororola";
        case Manufacturer::ONEPLUS:     return "OnePlus";
        default:                        return "UNKNOWN";
    }
}

std::string toString(Color color) {
    switch (color) {
        case Color::WHITE:      return "White";
        case Color::GRAY:       return "Gray";
        case Color::BLACK:      return "Black";
        case Color::BLUE:       return "Blue";
        case Color::RED:        return "Red";
        case Color::GOLD:       return "Gold";
        case Color::PINK:       return "Pink";
        case Color::PURPLE:     return "Purple";
        case Color::UNDEFINED:  return "Undefined";
        default:                return "Unknown";
    }
}

std::string toString(OS os) {
    switch (os) {
        case OS::ANDROID:       return "Android";
        case OS::IOS:           return "IOS";
        case OS::LINEAGEOS:     return "Lineageos";
        case OS::UNDEFINED:     return "Undefined";
        default:                return "Unknown";
    }
}

std::string toString(CPU cpu) {
    switch (cpu) {
        case CPU::SNAPDRAGON:   return "Snapdragon";
        case CPU::APPLE:        return "Apple";
        case CPU::MEDIATEK:     return "Mediatek";
        case CPU::UNDEFINED:    return "Undefined";
        default:                return "Unknown";
    }
}