#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

const float PI = 3.14159f;

// All of the constants below are in inches
const float APPLE_DIAMETER = 3.0;
const float PIZZA_DIAMETER = 12.0;
const float PIZZA_HEIGHT = 0.5;
const float DONUT_INNER_DIAMETER = 2.0;
const float DONUT_OUTER_DIAMETER = 4.0;
const float ICE_CREAM_CONE_DIAMETER = 2.0;
const float ICE_CREAM_CONE_HEIGHT = 5.0;
const float ICE_CREAM_SCOOP_DIAMETER = 2.5;

float VolSphere( float radius );
float SurfaceAreaSphere( float radius );
float VolCone( float radius, float height );
float SurfaceAreaCone( float radius, float height );
float VolCylinder( float radius, float height );
float SurfaceAreaCylinder( float radius, float height );
float VolDonut( float innerRadius, float outerRadius );
float SurfaceAreaDonut( float innerRadius, float outerRadius );

#endif GEOMETRY_HPP