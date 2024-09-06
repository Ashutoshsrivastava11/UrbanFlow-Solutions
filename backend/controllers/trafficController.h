// backend/controllers/trafficController.h

#ifndef TRAFFIC_CONTROLLER_H
#define TRAFFIC_CONTROLLER_H

#include <crow_all.h>  // For Crow framework types
#include <cpprest/json.h>  // For JSON handling

// Function declarations for traffic data handling

/**
 * @brief Handler function to get all traffic data.
 * 
 * @param req The incoming HTTP request.
 * @param res The outgoing HTTP response.
 */
void getTrafficData(const crow::Request& req, crow::Response& res);

/**
 * @brief Handler function to insert new traffic data.
 * 
 * @param req The incoming HTTP request, containing JSON body with traffic data.
 * @param res The outgoing HTTP response.
 */
void insertTrafficData(const crow::Request& req, crow::Response& res);

/**
 * @brief Handler function to delete traffic data by ID.
 * 
 * @param req The incoming HTTP request, containing the ID of the traffic data to delete.
 * @param res The outgoing HTTP response.
 */
void deleteTrafficData(const crow::Request& req, crow::Response& res);

/**
 * @brief Register routes with the Crow application.
 * 
 * @param app The Crow application instance to register routes with.
 */
void trafficRoutes(crow::SimpleApp& app);

#endif // TRAFFIC_CONTROLLER_H
