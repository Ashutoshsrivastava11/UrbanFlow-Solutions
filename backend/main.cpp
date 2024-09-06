// backend/main.cpp

#include <crow_all.h>
#include "dbConnection.h"
#include "trafficRoutes.h" // Include route definitions header
#include "logging.h"
#include <iostream>
#include <exception>

int main() {
    // Initialize the logger
    initLogger("server.log");

    // Log server startup
    logInfo("Server starting...");

    // Initialize the Crow application
    crow::SimpleApp app;

    // Initialize database connection
    try {
        if (!initDatabase()) {
            logError("Database connection failed.");
            closeLogger();
            return 1; // Exit with error code
        }
        logInfo("Database connection successful.");
    } catch (const std::exception &e) {
        logError("Exception during database initialization: " + std::string(e.what()));
        closeLogger();
        return 1; // Exit with error code
    }

    // Define routes
    try {
        trafficRoutes(app);
        logInfo("Routes defined successfully.");
    } catch (const std::exception &e) {
        logError("Exception during route definition: " + std::string(e.what()));
        closeLogger();
        return 1; // Exit with error code
    }

    // Start the server
    try {
        app.port(5000).multithreaded().run();
        logInfo("Server running on port 5000.");
    } catch (const std::exception &e) {
        logError("Exception during server initialization: " + std::string(e.what()));
        closeLogger();
        return 1; // Exit with error code
    }

    // Close logger before exiting
    closeLogger();

    return 0; // Successful exit
}
