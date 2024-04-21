



//////////// Libraries //////////// 

#include "Generic_station_parser.hpp"
// To avoid the uint64_t is not defined the library stdint.h is included
#include <stdint.h>

// In order to use the flows 
#include <iostream>
#include <fstream>
//////////// Constants /////////// 
#define SCREAMING SNAKE CASE 5;


// Specifying the namespaces used in the code
using namespace std;

using namespace travel;



/////////// Class definition //////////


// Note to myself : namespace acts like a container that holds all 
// the code related to travel, keeping it separate from code related to
// other things



// Defining a New class who inherits from Generic_station_parser


// /!\ TIPS : std::ifstream, prenant en argument le nom du fichier `a lire
// Une des diff´erentes m´ethodes pour lire une ligne est
//d’utiliser la fonction std::getline d´efinie dans <string>.




    class Station_parser: public Generic_station_parser{ 
        public:
            // Station_parser's constructor
            Station_parser(): Generic_station_parser(){};

            // Creating a derived method of "read_stations" belonging to Generic_station_parser
            // this method uses the read_station one since it's declared as 
            // protected 

            void derived_read_stations(const std::string& _filename){
                read_stations(_filename);
            }
            
            // Overriding the "read_stations" method

            virtual void read_stations (const std::string& _filename) override{
                
            /////// Variables definition ///////    
            
            
                ifstream input_file;  //Define an input flow to read the file later on   
                Station station;
                string header;      //The first line of the file is a header describing the data types
                string line;
                
                char delimiter=',';  // Delimiter separating the data between each other
                
                // "index" used after the variable uint32_s_id is converted from a string
                // to a uint64_t to assign the stations to the hashmap 
                uint64_t index;      

            /////// Reading the file ///////
                input_file.open(_filename);
                // Throwing an exception should there be a problem with the 
                // current file
                if (input_file.fail())throw string("Error: Impossible to open the file");

                
                //Read the header and discard it, in this case the delimiter is \n since the 
                // header is delimited from the others line
                getline(input_file,header,'\n');

                //Use a loop that would go through all of the lines and
                //through all the parameters which are separated with a comma 
                // As such : 
                //     string_name_station,
                //     uint32_s_id,
                //     string_short_line,
                //     string_adress_station,
                //     string_desc_line

                // The stop condition for the while loop is 
                // the one in which the files has no strings to be read
                // Since the first element of each line is the name of station
                // the latter attributed to the "name" member of the station structure
                while(getline(input_file,station.name,delimiter)){

                    getline(input_file,station.line_id,delimiter);
                    
                    //In the next line the header is used as throw away variable
                    //Since the Station structure doesn't have a specific member for short_line 
                    getline(input_file,header,delimiter);
                    
                    getline(input_file,station.address,delimiter);
                    
                    // The delimiter is '\n' since the line_name is the last word in the line
                    getline(input_file,station.line_name,'\n');
                    
                    // Convert line_id into a uint64_t 
                    index = std::stoull(station.line_id);
                    
                    // Update the hash table
                    this->stations_hashmap[index]=station;
                
                }
                input_file.close();

                
            }

    };




////////////////////////// Main program ///////////////////// 
int main() {

    //Instantiating an object of the class Station_parser
    // After overriding the virtual read_stations 
    // for without it the code won't compile
    Station_parser my_parser;

        my_parser.derived_read_stations("./s.csv");
    std::unordered_map<uint64_t, travel::Station> hash = my_parser.get_stations_hashmap();
    // for (auto x : hash)
    //   std::cout <<"station id :" <<x.first << " " << x.second << std::endl;



    return 0;
}