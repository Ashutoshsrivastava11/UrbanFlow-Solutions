// frontend/src/index.js

import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import './styles/App.css'; // Global CSS import
import { CssBaseline } from '@mui/material'; // Material-UI baseline for consistent styling
import { BrowserRouter as Router } from 'react-router-dom'; // Router for client-side routing
import * as serviceWorker from './serviceWorker'; // Service worker for PWA functionality
import { Sentry } from '@sentry/react'; // Error tracking with Sentry (optional)

// Initialize Sentry (if used)
Sentry.init({ 
    dsn: 'YOUR_SENTRY_DSN', // Replace with your Sentry DSN
    integrations: [new Sentry.Integrations.BrowserTracing()],
    tracesSampleRate: 1.0,
});

ReactDOM.render(
    <React.StrictMode>
        <Router>
            <CssBaseline /> {/* Reset CSS for consistent look */}
            <App />
        </Router>
    </React.StrictMode>,
    document.getElementById('root')
);

// Register the service worker for offline support
serviceWorker.register();
