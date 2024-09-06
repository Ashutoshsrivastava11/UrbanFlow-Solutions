// backend/utils/dbConnection.cpp

#include "dbConnection.h"
#include <sqlite3.h>
#include <iostream>

// Global database connection pointer
static sqlite3* db = nullptr;

// Function to initialize the database connection
bool initDatabase() {
    if (db != nullptr) {
        std::cerr << "Database connection already initialized." << std::endl;
        return false; // Connection already exists
    }

    // Open the database connection
    int result = sqlite3_open("traffic_data.db", &db);
    if (result != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // Example SQL to create tables (customize as needed)
    const char* createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS TrafficData (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            laneName TEXT NOT NULL,
            vehicleCount INTEGER NOT NULL,
            timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
        );
    )";

    char* errorMessage = nullptr;
    result = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errorMessage);
    if (result != SQLITE_OK) {
        std::cerr << "Failed to create table: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return false;
    }

    return true;
}

// Function to close the database connection
void closeDatabase() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

// Function to get the current database connection
sqlite3* getDatabaseConnection() {
    return db;
}
