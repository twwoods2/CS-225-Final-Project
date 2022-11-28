#pragma once 
#include <string>
using namespace std;
class Airport {
    public: 
    Airport(double lat, double longit, string airport_name, string id) {
        lat_ = lat;
        longit_ = longit;
        airport_name_ = airport_name;
        id_ = id;
    }
    Airport() {
        lat_ = 0;
        longit_ = 0;
        airport_name_ = "";
        string id_ = "";
    }
    string get_id() {return id_;}
    string get_name() {return airport_name_;}
    pair<double, double> get_lat_long() {return pair<double,double>(lat_, longit_);}
    //friend std::ostream& operator<<(std::ostream& os, const Airport& node);

    private: 
    double lat_;
    double longit_;
    string airport_name_;
    string id_;
};