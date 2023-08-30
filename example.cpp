#include <iostream>
#include "microjson.h"

int main() {
    std::string jsonResponse = R"({
        "status": "success",
        "country": "Canada",
        "countryCode": "CA",
        "region": "ON",
        "regionName": "Ontario",
        "city": "Toronto",
        "zip": "M5V 2H1",
        "lat": 43.6532,
        "lon": -79.3832,
        "timezone": "America/Toronto",
        "isp": "Rogers Communications",
        "org": "Rogers Cable Communications",
        "as": "AS812 Rogers Communications Canada Inc.",
        "query": "8.8.8.8"
    })";
    std::map<std::string, std::string> decodedData = MicroJson::Decode(jsonResponse);
    std::cout << "Country Code: " << decodedData["countryCode"] << std::endl;
    std::cout << "Country: " << decodedData["country"] << std::endl;
    std::cout << "Region: " << decodedData["region"] << std::endl;
    std::cout << "City: " << decodedData["city"] << std::endl;
    std::cout << "Latitude: " << decodedData["lat"] << std::endl;
    std::cout << "Longitude: " << decodedData["lon"] << std::endl;
    std::cout << "Timezone: " << decodedData["timezone"] << std::endl;

    return 0;
}
