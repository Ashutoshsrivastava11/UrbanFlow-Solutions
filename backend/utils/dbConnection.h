// backend/utils/dbConnection.h

#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <sqlite3.h> // Or your database library

// Function declarations for database connection and management

/**
 * @brief Initializes the database connection.
 * 
 * This function sets up a connection to the database and prepares any necessary
 * database schema or initial data.
 * 
 * @return true if the connection and setup were successful, false otherwise.
 */
bool initDatabase();

/**
 * @brief Closes the database connection.
 * 
 * This function closes the connection to the database and performs any necessary
 * cleanup.
 */
void closeDatabase();

/**
 * @brief Retrieves the current database connection.
 * 
 * This function provides access to the current database connection object.
 * 
 * @return A pointer to the sqlite3 database connection object.
 */
sqlite3* getDatabaseConnection();

#endif // DBCONNECTION_H
