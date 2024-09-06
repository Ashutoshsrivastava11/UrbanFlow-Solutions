// frontend/src/components/TrafficItem.js

import React from 'react';
import { Card, CardContent, Typography, CardActions, Button, Grid } from '@mui/material';
import PropTypes from 'prop-types';

const TrafficItem = ({ laneName, vehicleCount, onViewDetails }) => {
    return (
        <Grid item xs={12} sm={6} md={4}>
            <Card sx={{ minWidth: 275, mb: 2, boxShadow: 3, borderRadius: 2 }}>
                <CardContent>
                    <Typography variant="h6" component="div" color="textPrimary">
                        {laneName}
                    </Typography>
                    <Typography variant="body2" color="textSecondary">
                        Vehicles Count: {vehicleCount}
                    </Typography>
                </CardContent>
                <CardActions>
                    <Button size="small" color="primary" onClick={onViewDetails}>
                        View Details
                    </Button>
                </CardActions>
            </Card>
        </Grid>
    );
};

TrafficItem.propTypes = {
    laneName: PropTypes.string.isRequired,
    vehicleCount: PropTypes.number.isRequired,
    onViewDetails: PropTypes.func.isRequired,
};

export default React.memo(TrafficItem);
