#include "json_decoder.h"

std::map<std::string, std::string> JsonDecoder::Decode(const std::string& json) {
    std::map<std::string, std::string> result;

    size_t pos = 0;
    while (pos < json.size()) {
        size_t keyStart = json.find('"', pos);
        if (keyStart == std::string::npos) {
            break;
        }
        size_t keyEnd = json.find('"', keyStart + 1);
        if (keyEnd == std::string::npos) {
            break;
        }
        std::string key = json.substr(keyStart + 1, keyEnd - keyStart - 1);
        size_t valueStart = json.find(':', keyEnd);
        if (valueStart == std::string::npos) {
            break;
        }
        size_t valueEnd = json.find_first_of(",}", valueStart + 1);
        if (valueEnd == std::string::npos) {
            break;
        }
        std::string value = json.substr(valueStart + 1, valueEnd - valueStart - 1);
        if (value.front() == '"' && value.back() == '"') {
            value = value.substr(1, value.size() - 2);
        }

        result[key] = value;
        pos = valueEnd + 1;
    }

    return result;
}
