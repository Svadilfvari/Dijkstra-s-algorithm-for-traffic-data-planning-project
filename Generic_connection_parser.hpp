#pragma once

#include "Generic_station_parser.hpp"
// To avoid the uint64_t is not defined the library stdint.h is included 
#include <stdint.h>
namespace travel{
  class Generic_connection_parser: public Generic_station_parser{
  public:

    const std::unordered_map<uint64_t,std::unordered_map<uint64_t,uint64_t> >& get_connections_hashmap() const{
      return this->connections_hashmap;
    }

  protected:
    virtual void read_connections(const std::string& _filename) = 0;

  protected:
    std::unordered_map<uint64_t,std::unordered_map<uint64_t,uint64_t> > connections_hashmap;
  };
}
