// backend/models/trafficModel.h

#ifndef TRAFFIC_MODEL_H
#define TRAFFIC_MODEL_H

#include <string>
#include <sqlite3.h> // Ensure sqlite3 is included for database operations

// Represents a traffic data entry
class TrafficData {
public:
    // Constructor to initialize TrafficData with all required fields
    TrafficData(int id, const std::string& laneName, int vehicleCount, const std::string& timestamp);

    // Getters
    int getId() const;
    std::string getLaneName() const;
    int getVehicleCount() const;
    std::string getTimestamp() const;

    // Setters
    void setLaneName(const std::string& laneName);
    void setVehicleCount(int vehicleCount);
    void setTimestamp(const std::string& timestamp);

    // Method to save the current TrafficData to the database
    bool save() const;

    // Static method to fetch traffic data by ID from the database
    static TrafficData fetchById(int id);

private:
    int id; // Unique identifier for traffic data
    std::string laneName;
    int vehicleCount;
    std::string timestamp;

    // Helper method to execute SQL queries
    static bool executeQuery(const std::string& sql, sqlite3_stmt* stmt);
};

#endif // TRAFFIC_MODEL_H
