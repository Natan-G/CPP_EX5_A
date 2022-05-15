#include "doctest.h"
#include "OrgChart.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace ariel;
using namespace std;

TEST_CASE("full scenario organizatoin build"){
    /* end tree
                natan
                  |
        |---------|-------|
        yossi   yosef   yair
        |         |  
        mor     meir
    */
    
    OrgChart org;
    CHECK_THROWS(org.add_root(""));
    CHECK_THROWS(org.add_sub("Natan" ,"Yossi"));   //no father

    org.add_root("Natan");
    CHECK_THROWS(org.add_sub("Moran" , "Yossi"));//no such father
    CHECK_NOTHROW(org.add_sub("Natan" , "Yossi")); //yossi son of natan
    CHECK_NOTHROW(org.add_sub("Natan" , "Yosef")); //yosef son of natan
    CHECK_NOTHROW(org.add_sub("Natan" , "Yair")); //yair son of natan

    CHECK_NOTHROW(org.add_sub("Yossi" , "mor")); //mor son of yossi
    CHECK_NOTHROW(org.add_sub("Yosef" , "meir")); //meir son of yosef

    vector<string> names = {"Natan","Yossi","Yosef","Yair","Mor","Meir"};    
    vector<string> level_order = {names[0],names[1],names[2],names[3],names[4],names[5]};
    vector<string> reverse_order = {names[5],names[4],names[3],names[2],names[1],names[0]};
    vector<string> preorder = {names[0],names[1],names[4],names[2],names[5],names[3]};

    size_t i=0;
    //check level order
    for(auto it=org.begin_level_order() ; it!= org.end_level_order() ; it++){
        CHECK_EQ(*it , level_order[i++]);
    }
    i=0;

    //check rverese level order
    for(auto it=org.begin_reverse_order() ; it!= org.reverse_order() ; it++){
        CHECK_EQ(*it , level_order[i++]);
    }
    i=0;
    
    //check preorder
    for(auto it=org.begin_preorder() ; it!= org.end_preorder() ; it++){
        CHECK_EQ(*it , level_order[i++]);
    }
    i=0;
    //check for each
    for(auto element : org){
        CHECK_EQ(names[i++] , element);
    }
   
    for(int i=0 ; i<20 ; i++){
        CHECK_THROWS(org.add_sub("Natan" , "some1"));
    }

}