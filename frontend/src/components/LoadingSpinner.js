// frontend/src/components/LoadingSpinner.js

import React from 'react';
import { CircularProgress, Box, Typography } from '@mui/material';

const LoadingSpinner = ({ message = 'Loading...' }) => {
    return (
        <Box
            sx={{
                display: 'flex',
                flexDirection: 'column',
                justifyContent: 'center',
                alignItems: 'center',
                height: '100vh',
                width: '100%',
                textAlign: 'center'
            }}
        >
            <CircularProgress size={60} color="primary" sx={{ mb: 2 }} />
            <Typography variant="h6" color="textSecondary">
                {message}
            </Typography>
        </Box>
    );
};

export default LoadingSpinner;
