#pragma once

#include <string>
#include <iostream>
// To avoid the uint64_t is not defined the library stdint.h is included
#include <stdint.h>
#include <unordered_map>

namespace travel{
  struct Station{
    std::string name;
    std::string line_id;
    std::string address;
    std::string line_name;
    friend std::ostream& operator<<(std::ostream& _os, const Station& _stop){
      _os << "Station: " << _stop.name << " (line " << _stop.line_id << ")";
      return _os;
    }
  };

  class Generic_station_parser{
  public:
 
  //stations_hashmap getter
    const std::unordered_map<uint64_t, Station>& get_stations_hashmap() const{
      return this->stations_hashmap;
    }

    

  protected:
    virtual void read_stations(const std::string& _filename) = 0;

  protected:
   // An ADS that links a given Station (i.e A structure)
   // and the ID of the staiton 
    std::unordered_map<uint64_t, Station> stations_hashmap;
  };
}
