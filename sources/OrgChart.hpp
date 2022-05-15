#pragma once
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


namespace ariel{
    class OrgChart{
        unordered_map<string , string> map;
        
        public:
            
            OrgChart& add_root(string role);
            OrgChart& add_sub(string father ,string role);
            
            string *begin_preorder();
            string *end_preorder();

            string *begin_level_order();
            string *end_level_order();
      
            string *begin_reverse_order();
            string *reverse_order();

            string *begin();
            string *end();

            friend ostream &operator<<(ostream &os,OrgChart &oc);


    };
}