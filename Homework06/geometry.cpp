#include "geometry.hpp"
#include <cmath>

// ----------------------------------------------------------------------------

float VolSphere( float radius )
{
	return ( (4.0/3.0) * PI * std::pow(radius, 3) );
}

// ----------------------------------------------------------------------------

float SurfaceAreaSphere( float radius )
{
	float radiusSquared = std::pow( radius, 2 );
	return ( 4.0 * PI * radiusSquared );
}

// ----------------------------------------------------------------------------

float VolCone( float radius, float height )
{
	float radiusSquared = std::pow( radius, 2 );
	return ( (1.0/3.0) * PI * radiusSquared * height );
}

// ----------------------------------------------------------------------------

float SurfaceAreaCone( float radius, float height )
{
	float radiusSquared = std::pow( radius, 2 );
	float heightSquared = std::pow( height, 2 );
	float squareRoot	= std::sqrt( (radiusSquared + heightSquared) );

	return ( PI * radius * squareRoot );
}

// ----------------------------------------------------------------------------

float VolCylinder( float radius, float height )
{
	float radiusSquared = std::pow( radius, 2 );
	return ( PI * radiusSquared * height );
}

// ----------------------------------------------------------------------------
//
// Assumes a fully solid cylinder (no open ends)
//

float SurfaceAreaCylinder( float radius, float height )
{
	float radiusSquared = std::pow( radius, 2 );
	float baseArea = PI * radiusSquared;
	float sideArea = 2 * PI * radius * height;

	return ( sideArea + (2 * baseArea) );
}

// ----------------------------------------------------------------------------
//
// https://www.vcalc.com/wiki/vCalc/Torus+-+Volume
//

float VolDonut( float innerRadius, float outerRadius )
{
	float innerPlusOuter = innerRadius + outerRadius;
	float outerMinusInner = outerRadius - innerRadius;

	return ( .25 * std::pow(PI, 2) * innerPlusOuter * std::pow(outerMinusInner, 2) );
}

// ----------------------------------------------------------------------------
//
// https://www.vcalc.com/wiki/vCalc/Torus+-+Surface+Area
//

float SurfaceAreaDonut( float innerRadius, float outerRadius )
{
	float outerMinusInner = std::pow(outerRadius, 2) - std::pow(innerRadius, 2);
	return ( std::pow(PI, 2) * outerMinusInner );
}

// ----------------------------------------------------------------------------