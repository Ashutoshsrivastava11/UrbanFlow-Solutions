// frontend/src/components/ErrorBoundary.js

import React, { Component } from 'react';
import { Typography, Button, Box } from '@mui/material';
import { Sentry } from '@sentry/react'; // Optional: Integrate with Sentry for error tracking (if used)

class ErrorBoundary extends Component {
    constructor(props) {
        super(props);
        this.state = {
            hasError: false,
        };
    }

    static getDerivedStateFromError() {
        // Update state so the next render will show the fallback UI
        return { hasError: true };
    }

    componentDidCatch(error, errorInfo) {
        // Log the error to an error reporting service (e.g., Sentry)
        if (process.env.NODE_ENV === 'production') {
            Sentry.captureException(error, { extra: errorInfo });
        }
        console.error("Uncaught error:", error, errorInfo); // Log error details in development
    }

    handleReload = () => {
        // Optionally reload the page
        window.location.reload();
    };

    render() {
        if (this.state.hasError) {
            return (
                <Box
                    sx={{
                        display: 'flex',
                        flexDirection: 'column',
                        justifyContent: 'center',
                        alignItems: 'center',
                        height: '100vh',
                        width: '100%',
                        textAlign: 'center',
                        p: 3
                    }}
                >
                    <Typography variant="h4" color="error" gutterBottom>
                        Something went wrong.
                    </Typography>
                    <Typography variant="body1" color="textSecondary" gutterBottom>
                        We encountered an error while processing your request. Please try again later.
                    </Typography>
                    <Button variant="contained" color="primary" onClick={this.handleReload}>
                        Refresh Page
                    </Button>
                </Box>
            );
        }

        return this.props.children;
    }
}

export default ErrorBoundary;
