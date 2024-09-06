// frontend/src/App.js

import React, { Suspense, lazy } from 'react';
import { Route, Routes, useNavigate } from 'react-router-dom';
import { Container, Typography, AppBar, Toolbar, Button, Drawer, List, ListItem } from '@mui/material';
import { useState } from 'react';
import ErrorBoundary from './components/ErrorBoundary';
import './styles/App.css';

// Lazy load components
const TrafficDashboard = lazy(() => import('./components/TrafficDashboard'));
const Home = lazy(() => import('./components/Home'));

const App = () => {
    const [drawerOpen, setDrawerOpen] = useState(false);
    const navigate = useNavigate();

    const toggleDrawer = () => {
        setDrawerOpen(!drawerOpen);
    };

    return (
        <ErrorBoundary>
            <AppBar position="static">
                <Toolbar>
                    <Typography variant="h6" component="div" sx={{ flexGrow: 1 }}>
                        Automated Traffic Management System
                    </Typography>
                    <Button color="inherit" onClick={() => navigate('/')}>Home</Button>
                    <Button color="inherit" onClick={() => navigate('/dashboard')}>Dashboard</Button>
                    <Button color="inherit" onClick={toggleDrawer}>Menu</Button>
                </Toolbar>
            </AppBar>
            <Drawer anchor="right" open={drawerOpen} onClose={toggleDrawer}>
                <List>
                    <ListItem button onClick={() => navigate('/')}>Home</ListItem>
                    <ListItem button onClick={() => navigate('/dashboard')}>Dashboard</ListItem>
                </List>
            </Drawer>
            <Container maxWidth="lg" sx={{ mt: 2 }}>
                <Suspense fallback={<div>Loading...</div>}>
                    <Routes>
                        <Route path="/" element={<Home />} />
                        <Route path="/dashboard" element={<TrafficDashboard />} />
                    </Routes>
                </Suspense>
            </Container>
        </ErrorBoundary>
    );
};

export default App;
