#pragma once 

#include <string>

using namespace std;

enum class Manufacturer
{
    APPLE,
    SAMSUNG,
    XIAOMI,
    HTC,
    MOTOROLA,
    ONEPLUS,
    UNDEFINED
};

enum class Color
{
    WHITE,
    GRAY,
    BLACK,
    BLUE,
    RED,
    GOLD,
    PINK,
    PURPLE,
    UNDEFINED
};

enum class OS
{
    ANDROID,
    IOS,
    LINEAGEOS,
    UNDEFINED
};

enum class CPU
{
    SNAPDRAGON,
    APPLE,
    MEDIATEK,
    UNDEFINED
};

class SmartphoneSpec 
{ 
private: 
    Manufacturer manufacturer;  Color color; 
    float displaySize;  int ram,  storage; 
    CPU cpu;  OS os; 
public: 
    SmartphoneSpec(); 
    SmartphoneSpec(Manufacturer manufacturer, 
    Color color, float displaySize, int ram, 
    int storage, CPU cpu, OS os); 
    Manufacturer getManufacturer() const; 
    Color getColor() const;  float getDisplay() const; 
    int getRAM() const;      
    int getStorage() const; 
    CPU getCPU() const;    
    OS getOS() const;  
}; 

std::string toString(Manufacturer manufacturer);
std::string toString(Color color);
std::string toString(OS os);
std::string toString(CPU cpu);