#ifndef MICROJSON_H
#define MICROJSON_H

#include <map>
#include <string>

class Microjson {
public:
    static std::map<std::string, std::string> Decode(const std::string& json);
};

#endif // MICROJSON_H
