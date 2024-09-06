// frontend/src/services/trafficService.js

import axios from 'axios';

// Base URL for the API (update with your actual backend API URL)
const API_BASE_URL = 'http://localhost:5000/api'; 

// Create an instance of axios with default settings
const apiClient = axios.create({
    baseURL: API_BASE_URL,
    headers: {
        'Content-Type': 'application/json',
    },
});

// Function to fetch traffic data
export const fetchTrafficData = async () => {
    try {
        const response = await apiClient.get('/traffic');
        return response.data;
    } catch (error) {
        handleApiError(error);
        throw error;
    }
};

// Function to fetch specific traffic data by ID
export const fetchTrafficDataById = async (id) => {
    try {
        const response = await apiClient.get(`/traffic/${id}`);
        return response.data;
    } catch (error) {
        handleApiError(error);
        throw error;
    }
};

// Function to post new traffic data
export const postTrafficData = async (data) => {
    try {
        const response = await apiClient.post('/traffic', data);
        return response.data;
    } catch (error) {
        handleApiError(error);
        throw error;
    }
};

// Function to handle API errors
const handleApiError = (error) => {
    // Log the error or send it to a monitoring service like Sentry
    console.error('API Error:', error.message);
    // Optional: Show a user-friendly message or notification
};

// Export all functions for use in components
export default {
    fetchTrafficData,
    fetchTrafficDataById,
    postTrafficData,
};
