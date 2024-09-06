import React, { useState, useEffect } from 'react';
import TrafficItem from './TrafficItem';
import LoadingSpinner from './LoadingSpinner';
import { fetchTrafficData } from '../services/trafficService';
import './Dashboard.css';
import ErrorBoundary from './ErrorBoundary';

const TrafficDashboard = () => {
    const [trafficData, setTrafficData] = useState([]);
    const [loading, setLoading] = useState(true);
    const [error, setError] = useState(null);

    useEffect(() => {
        fetchTrafficData()
            .then(data => {
                setTrafficData(data);
                setLoading(false);
            })
            .catch(error => {
                console.error('Error fetching traffic data:', error);
                setError(error);
                setLoading(false);
            });
    }, []);

    if (loading) return <LoadingSpinner />;
    if (error) return <div>Error fetching data</div>;

    return (
        <div className="dashboard">
            <h2>Real-time Traffic Dashboard</h2>
            <ul className="traffic-list">
                {trafficData.map((lane) => (
                    <TrafficItem key={lane.id} lane={lane.lane} vehicles={lane.vehicles} />
                ))}
            </ul>
        </div>
    );
};

const WrappedTrafficDashboard = () => (
    <ErrorBoundary>
        <TrafficDashboard />
    </ErrorBoundary>
);

export default WrappedTrafficDashboard;
