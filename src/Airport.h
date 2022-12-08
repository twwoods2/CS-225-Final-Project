#pragma once 
#include <string>
using namespace std;
class Airport {
    public: 
    Airport(double lat, double longit, string airport_name, string id, int sourceid) {
        lat_ = lat;
        longit_ = longit;
        airport_name_ = airport_name;
        id_ = id;
        sourceid_ = sourceid;
    }
    Airport() {
        lat_ = 0;
        longit_ = 0;
        airport_name_ = "";
        string id_ = "";
        sourceid_ = -1;
    }
    int get_sourceid() const {return sourceid_;}
    string get_id() const {return id_;}
    string get_name() const {return airport_name_;}
    pair<double, double> get_lat_long() {return pair<double,double>(lat_, longit_);}
    bool operator<(const Airport other) const {
        return airport_name_ < other.get_id();
    }
    bool operator==(const Airport other) const {
        if (airport_name_ != other.get_name()) return false;
        if (id_ != other.get_id()) return false;
        return true;
    }
    //friend std::ostream& operator<<(std::ostream& os, const Airport& node);

    private: 
    double lat_;
    double longit_;
    string airport_name_;
    string id_;
    int sourceid_;
};