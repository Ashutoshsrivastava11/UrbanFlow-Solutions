// backend/crow_all.h

#ifndef CROW_ALL_H
#define CROW_ALL_H

// Include Crow core headers
#include "crow/version.h"      // Version information
#include "crow/utility.h"      // Utility functions
#include "crow/http.h"         // HTTP handling
#include "crow/response.h"     // Response handling
#include "crow/requests.h"     // Request handling
#include "crow/route.h"        // Routing
#include "crow/middlewares.h"  // Middleware support

// Include other necessary headers or libraries
#include <iostream>  // For standard I/O
#include <stdexcept> // For standard exceptions

// Optional: Define custom error handling or logging
#define CROW_LOG_ERROR(msg) std::cerr << "ERROR: " << msg << std::endl

// Optional: Define custom configuration or settings
#define CROW_CONFIGURED_PORT 5000

// Documentation
// This header includes all necessary Crow framework headers and utility headers.
// Use this file to simplify inclusion of Crow components in your application.

#endif // CROW_ALL_H
