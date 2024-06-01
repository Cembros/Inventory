#define DATABASE_H

#include <sqlite3.h>
#include <iostream>
#include <string>

class Database
{

public:
    Database();

    void insert_newdata(int id, const std::string &product, const std::string &type, int quantity);

    void delete_data(int id);

    void update_data(int id, const std::string &product, const std::string &type, int quantity);

    void show_information();

private:
    sqlite3 *db;

    std::string database_name = "database.db";
};