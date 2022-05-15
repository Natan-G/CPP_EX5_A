#include <OrgChart.hpp>
#include <iostream>

using namespace std;

namespace ariel {

    OrgChart& OrgChart::add_root(const string role){
        return *this;
    }
    OrgChart& OrgChart::add_sub(const string father, const string role) {
        return *this;
    }
    string* OrgChart::begin_level_order(){
        return NULL;
    }
    string *OrgChart::end_level_order(){
        return NULL;
    }
    string* OrgChart::begin_reverse_order(){
        return NULL;}
    
    string* OrgChart::begin_preorder(){
        return NULL;
    }
    string* OrgChart::end_preorder(){
        return NULL;
    }
    string* OrgChart::reverse_order(){
        return NULL;
    }
    string* OrgChart::begin(){
        return begin_level_order();
    }
    string* OrgChart::end(){
        return end_level_order();
    }
    
    ostream &operator<<(ostream &output, OrgChart &oc){
        for (auto i = oc.begin_level_order(); i != oc.end_level_order(); i++)
            output << *i << ",";
        return output;
    }







}

