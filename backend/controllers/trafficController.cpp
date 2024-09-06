// backend/controllers/trafficController.cpp

#include "trafficController.h"
#include "dbConnection.h"
#include <crow_all.h>
#include <cpprest/json.h> // For JSON handling

using namespace crow;
using json = web::json::value;

// Function to get traffic data
void getTrafficData(const Request& req, Response& res) {
    try {
        auto conn = getDbConnection();
        if (!conn) {
            res.code = 500;
            res.write("Failed to connect to the database");
            res.end();
            return;
        }

        // Query to fetch all traffic data
        const std::string query = "SELECT * FROM TrafficData";
        auto result = conn->execute(query);

        // Prepare JSON response
        json jsonResponse;
        jsonResponse[U("data")] = web::json::value::array();
        
        for (const auto& row : result) {
            web::json::value item;
            item[U("id")] = web::json::value::number(row["id"].as<int>());
            item[U("laneName")] = web::json::value::string(row["laneName"].as<std::string>());
            item[U("vehicleCount")] = web::json::value::number(row["vehicleCount"].as<int>());
            item[U("timestamp")] = web::json::value::string(row["timestamp"].as<std::string>());
            jsonResponse[U("data")].as_array().push_back(item);
        }

        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(jsonResponse.serialize());
        res.end();
    } catch (const std::exception& e) {
        res.code = 500;
        res.write("Error: " + std::string(e.what()));
        res.end();
    }
}

// Function to insert traffic data
void insertTrafficData(const Request& req, Response& res) {
    try {
        auto conn = getDbConnection();
        if (!conn) {
            res.code = 500;
            res.write("Failed to connect to the database");
            res.end();
            return;
        }

        auto jsonRequest = json::parse(req.body);
        std::string laneName = jsonRequest[U("laneName")].as_string();
        int vehicleCount = jsonRequest[U("vehicleCount")].as_integer();
        std::string timestamp = jsonRequest[U("timestamp")].as_string();

        // SQL query to insert data
        std::string query = "INSERT INTO TrafficData (laneName, vehicleCount, timestamp) VALUES (?, ?, ?)";
        auto result = conn->execute(query, laneName, vehicleCount, timestamp);

        if (result) {
            res.code = 201;
            res.write("Data inserted successfully");
        } else {
            res.code = 400;
            res.write("Failed to insert data");
        }
        res.end();
    } catch (const std::exception& e) {
        res.code = 500;
        res.write("Error: " + std::string(e.what()));
        res.end();
    }
}

// Function to delete traffic data
void deleteTrafficData(const Request& req, Response& res) {
    try {
        auto conn = getDbConnection();
        if (!conn) {
            res.code = 500;
            res.write("Failed to connect to the database");
            res.end();
            return;
        }

        int id = std::stoi(req.url_params.get("id"));

        // SQL query to delete data
        std::string query = "DELETE FROM TrafficData WHERE id = ?";
        auto result = conn->execute(query, id);

        if (result) {
            res.code = 200;
            res.write("Data deleted successfully");
        } else {
            res.code = 404;
            res.write("Data not found");
        }
        res.end();
    } catch (const std::exception& e) {
        res.code = 500;
        res.write("Error: " + std::string(e.what()));
        res.end();
    }
}

// Register routes with the Crow application
void trafficRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/api/traffic")
        .methods(crow::HTTPMethod::GET)(getTrafficData)
        .methods(crow::HTTPMethod::POST)(insertTrafficData);

    CROW_ROUTE(app, "/api/traffic/<int>")
        .methods(crow::HTTPMethod::DELETE)(deleteTrafficData);
}
