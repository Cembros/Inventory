#include <iostream>
#include <string>
#include "database.h"

class Communication
{

public:
    Communication();
    void data_manager();

private:
    Database db;
    std::string Product_name;
    int Quantity;
    std::string Product_type;
};