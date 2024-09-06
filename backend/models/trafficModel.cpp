// backend/models/trafficModel.cpp

#include "trafficModel.h"
#include <sqlite3.h>
#include <iostream>

// Constructor implementation
TrafficData::TrafficData(int id, const std::string& laneName, int vehicleCount, const std::string& timestamp)
    : id(id), laneName(laneName), vehicleCount(vehicleCount), timestamp(timestamp) {}

// Getters
int TrafficData::getId() const { return id; }
std::string TrafficData::getLaneName() const { return laneName; }
int TrafficData::getVehicleCount() const { return vehicleCount; }
std::string TrafficData::getTimestamp() const { return timestamp; }

// Setters
void TrafficData::setLaneName(const std::string& laneName) { this->laneName = laneName; }
void TrafficData::setVehicleCount(int vehicleCount) { this->vehicleCount = vehicleCount; }
void TrafficData::setTimestamp(const std::string& timestamp) { this->timestamp = timestamp; }

// Save the TrafficData to the database
bool TrafficData::save() const {
    const char* sql = "INSERT INTO TrafficData (laneName, vehicleCount, timestamp) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(getDatabaseConnection(), sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(getDatabaseConnection()) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, laneName.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, vehicleCount);
    sqlite3_bind_text(stmt, 3, timestamp.c_str(), -1, SQLITE_TRANSIENT);

    bool result = executeQuery(sql, stmt);
    sqlite3_finalize(stmt);
    return result;
}

// Fetch TrafficData by ID from the database
TrafficData TrafficData::fetchById(int id) {
    const char* sql = "SELECT * FROM TrafficData WHERE id = ?;";
    sqlite3_stmt* stmt;
    TrafficData trafficData(id, "", 0, "");

    if (sqlite3_prepare_v2(getDatabaseConnection(), sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(getDatabaseConnection()) << std::endl;
        return trafficData;
    }

    sqlite3_bind_int(stmt, 1, id);
    
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        trafficData.laneName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        trafficData.vehicleCount = sqlite3_column_int(stmt, 2);
        trafficData.timestamp = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
    } else {
        std::cerr << "No data found for ID: " << id << std::endl;
    }

    sqlite3_finalize(stmt);
    return trafficData;
}

// Helper method to execute SQL queries
bool TrafficData::executeQuery(const std::string& sql, sqlite3_stmt* stmt) {
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Failed to execute query: " << sqlite3_errmsg(getDatabaseConnection()) << std::endl;
        return false;
    }
    return true;
}
