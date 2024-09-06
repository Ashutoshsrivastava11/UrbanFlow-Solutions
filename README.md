# UrbanFlow Solutions

**UrbanFlow Solutions** is an advanced Automated Traffic Management System designed to optimize urban traffic flow and enhance mobility. The system integrates real-time data handling, sophisticated algorithms, and a user-friendly interface to improve traffic management.

## Project Overview

UrbanFlow Solutions comprises a backend developed in C++ using the Crow framework and a frontend built with ReactJS. This separation ensures efficient management of server-side operations and client-side interactions.

## Project Structure

### Backend

The backend handles the server-side logic, database management, and API interactions. It is organized as follows:

- **`controllers/`**: Contains the logic for processing HTTP requests.
  - **`trafficController.cpp`**: Implements the functionality to handle traffic data requests, including retrieving, updating, and deleting traffic data.
  - **`trafficController.h`**: Declares the functions implemented in `trafficController.cpp`, providing an interface for the controller's operations.

- **`db/`**: Contains SQL scripts for database schema and data management.
  - **`traffic_data.sql`**: Defines the schema for the `TrafficData` table and includes commands to insert initial data.

- **`models/`**: Contains data models that represent the structure of traffic data.
  - **`trafficModel.cpp`**: Implements the operations related to the traffic data model, such as data manipulation and validation.
  - **`trafficModel.h`**: Provides declarations for the data model operations, allowing other components to interact with the traffic data.

- **`routes/`**: Defines the API routes for the application.
  - **`trafficRoutes.cpp`**: Configures the HTTP routes for traffic-related endpoints, connecting requests to the appropriate controller functions.

- **`utils/`**: Utility files for supporting functionalities like database connections.
  - **`dbConnection.cpp`**: Implements the logic to establish and manage connections to the SQL database.
  - **`dbConnection.h`**: Declares the functions for database connection management used in `dbConnection.cpp`.

- **`main.cpp`**: The entry point of the backend application. It initializes the Crow application, sets up routes, and starts the server.
- **`crow_all.h`**: Includes necessary definitions and headers from the Crow framework.

### Frontend

The frontend, developed using ReactJS, handles the client-side logic and user interface. It is structured as follows:

- **`public/`**: Contains static files used by the React application.
  - **`index.html`**: The main HTML file that serves as the entry point for the frontend application.

- **`src/`**: Contains the source code for the React application.
  - **`components/`**: React components used in the application.
    - **`TrafficDashboard.js`**: The primary dashboard component displaying aggregated traffic data and analytics.
    - **`TrafficItem.js`**: Component for rendering individual traffic data items, providing detailed views.

  - **`services/`**: Contains files for interacting with backend services.
    - **`trafficService.js`**: Manages API calls to the backend for retrieving and updating traffic data.

  - **`styles/`**: CSS files for styling the application.
    - **`App.css`**: General styling applied to the entire application.
    - **`Dashboard.css`**: Specific styling for the dashboard component.

  - **`App.js`**: The root component that integrates routing and renders other components, setting up the main structure of the React application.

- **`package.json`**: Manages project dependencies and includes scripts for building and running the React application.

### Database Initialization

- **`init_db.sql`**: Script to set up the initial database schema, including table creation and data seeding. This script prepares the database for use with the application.

### Logging

- **`server.log`**: Log file that records server activities and errors. Useful for debugging and monitoring server performance.

## Getting Started

### Prerequisites

To get started with UrbanFlow Solutions, you need:

- **C++ Compiler**: For building the backend.
- **Crow Framework**: Required for the backend development.
- **SQL Server Management Studio (SSMS)**: For managing and querying the SQL database.
- **Node.js and npm**: For managing frontend dependencies and scripts.

### Installation

1. **Backend Setup:**
   - Navigate to the `backend/` directory.
   - Compile the C++ source files using your preferred build system (e.g., `g++` or `cmake`).
   - Run the `main.cpp` file to start the backend server.

2. **Frontend Setup:**
   - Navigate to the `frontend/` directory.
   - Install the necessary dependencies by running `npm install`.
   - Start the frontend development server with `npm start`.

### Usage

- **Backend API**: Access the API endpoints at `http://localhost:5000/api/traffic` to interact with the traffic data.
- **Frontend Application**: Open `http://localhost:3000` in your web browser to view the user interface and interact with the application.

## Contribution

We encourage contributions to improve UrbanFlow Solutions. To contribute, please fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
