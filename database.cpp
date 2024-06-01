#include "database.h"
#include <sqlite3.h>
#include <string>

Database::Database()
{
    char rs = sqlite3_open(database_name.c_str(), &db);
    if (rs)
    {
        std::cout << "I cant open database";
    }
    std::string sql;
    sql = "CREATE TABLE COMPANY("
          "ID INT PRIMARY KEY     NOT NULL,"
          "PRODUCT           TEXT    NOT NULL,"
          "TYPE        TEXT    NOT NULL,"
          "QUANTITY        INTEGER );";

    char *zErrMsg = nullptr;
    rs = sqlite3_exec(db, sql.c_str(), nullptr, 0, &zErrMsg);

    if (rs != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Table created successfully\n");
    }
}

void Database::insert_newdata(int id, const std::string &product, const std::string &type, int quantity)
{
    std::string sql = "INSERT INTO COMPANY (ID, PRODUCT, TYPE, QUANTITY) "
                      "VALUES (" +
                      std::to_string(id) + ", '" + product + "', '" + type + "', " + std::to_string(quantity) + ");";

    char *zErrMsg = nullptr;
    int rs = sqlite3_exec(db, sql.c_str(), nullptr, 0, &zErrMsg);

    if (rs != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Records inserted successfully\n");
    }
}

void Database::delete_data(int id)
{
    std::string sql = "DELETE FROM COMPANY WHERE ID = " + std::to_string(id) + ";";

    char *zErrMsg = nullptr;
    int rs = sqlite3_exec(db, sql.c_str(), nullptr, 0, &zErrMsg);

    if (rs != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Record deleted successfully\n");
    }
}

void Database::update_data(int id, const std::string &product, const std::string &type, int quantity)
{
    std::string sql = "UPDATE COMPANY SET PRODUCT = '" + product + "', TYPE = '" + type + "', QUANTITY = " + std::to_string(quantity) + " WHERE ID = " + std::to_string(id) + ";";

    char *zErrMsg = nullptr;
    int rs = sqlite3_exec(db, sql.c_str(), nullptr, 0, &zErrMsg);

    if (rs != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Record updated successfully\n");
    }
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for(int i = 0; i < argc; i++) {
        std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

void Database::show_information()
{
    char *zErrMsg = 0;
    const char *sql = "SELECT * FROM COMPANY;";
    int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if(rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Operation done successfully" << std::endl;
    }
}
