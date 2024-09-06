-- Create the database if it does not exist
IF NOT EXISTS (SELECT * FROM sys.databases WHERE name = 'TrafficManagement')
BEGIN
    CREATE DATABASE TrafficManagement;
END;
GO

-- Switch to the TrafficManagement database
USE TrafficManagement;
GO

-- Drop existing tables if they exist (for fresh setup)
IF OBJECT_ID('dbo.TrafficData', 'U') IS NOT NULL
BEGIN
    DROP TABLE dbo.TrafficData;
END;
GO

-- Create the TrafficData table
CREATE TABLE dbo.TrafficData (
    id INT IDENTITY(1,1) PRIMARY KEY,          -- Auto-incremented primary key
    laneName NVARCHAR(255) NOT NULL,           -- Traffic lane name
    vehicleCount INT NOT NULL CHECK (vehicleCount >= 0), -- Non-negative vehicle count
    timestamp DATETIME NOT NULL DEFAULT GETDATE(), -- Record timestamp, defaults to current time
    CONSTRAINT UQ_LaneName_Timestamp UNIQUE (laneName, timestamp) -- Unique combination constraint
);
GO

-- Create indices for performance optimization
CREATE INDEX idx_vehicleCount ON dbo.TrafficData(vehicleCount);
GO

CREATE INDEX idx_timestamp ON dbo.TrafficData(timestamp);
GO

-- Insert example data (optional)
INSERT INTO dbo.TrafficData (laneName, vehicleCount, timestamp)
VALUES
    ('Lane 1', 15, '2024-09-06T10:00:00'),
    ('Lane 2', 30, '2024-09-06T10:05:00'),
    ('Lane 3', 22, '2024-09-06T10:10:00');
GO

-- Example queries to verify the setup
-- Retrieve all records
SELECT * FROM dbo.TrafficData;
GO

-- Retrieve records for a specific lane
SELECT * FROM dbo.TrafficData WHERE laneName = 'Lane 1';
GO

-- Retrieve records within a specific time range
SELECT * FROM dbo.TrafficData
WHERE timestamp BETWEEN '2024-09-06T10:00:00' AND '2024-09-06T11:00:00';
GO

-- Aggregate vehicle count by lane
SELECT laneName, SUM(vehicleCount) AS totalVehicles
FROM dbo.TrafficData
GROUP BY laneName;
GO

-- Average vehicle count per hour
SELECT DATEPART(hour, timestamp) AS hour, AVG(vehicleCount) AS avgVehicleCount
FROM dbo.TrafficData
GROUP BY DATEPART(hour, timestamp);
GO
