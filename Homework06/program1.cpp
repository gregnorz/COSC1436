// ----------------------------------------------------------------------------
//
// System includes
//
#include <iostream>
#include <iomanip>

// ----------------------------------------------------------------------------
//
// Local includes
//
#include "program1.hpp"
#include "geometry.hpp"

// ----------------------------------------------------------------------------

std::pair<float, float> CalculateApple()
{
	float radius		= APPLE_DIAMETER / 2;
	float vol			= VolSphere( radius );
	float surfaceArea	= SurfaceAreaSphere( radius );

	return std::make_pair( vol, surfaceArea );
}

// ----------------------------------------------------------------------------

std::pair<float, float> CalculatePizza()
{
	float radius		= PIZZA_DIAMETER / 2;
	float vol			= VolCylinder( radius, PIZZA_HEIGHT );
	float surfaceArea	= SurfaceAreaCylinder( radius, PIZZA_HEIGHT );

	return std::make_pair( vol, surfaceArea );
}

// ----------------------------------------------------------------------------

std::pair<float, float> CalculateDonut()
{
	float innerRadius	= DONUT_INNER_DIAMETER / 2;
	float outerRadius	= DONUT_OUTER_DIAMETER / 2;
	float vol			= VolDonut( innerRadius, outerRadius );
	float surfaceArea	= SurfaceAreaDonut( innerRadius, outerRadius );

	return std::make_pair( vol, surfaceArea );
}

// ----------------------------------------------------------------------------

std::pair<float, float> CalculateIceCreamCone()
{
	float coneRadius		= ICE_CREAM_CONE_DIAMETER / 2;
	float coneVol			= VolCone( coneRadius, ICE_CREAM_CONE_HEIGHT );
	float coneSurfaceArea	= SurfaceAreaCone( coneRadius, ICE_CREAM_CONE_HEIGHT );

	return std::make_pair( coneVol, coneSurfaceArea );
}

// ----------------------------------------------------------------------------

std::pair<float, float> CalculateIceCreamScoop()
{
	float radius		= ICE_CREAM_SCOOP_DIAMETER / 2;
	float vol			= VolSphere( radius );
	float surfaceArea	= SurfaceAreaSphere( radius );

	return std::make_pair( vol, surfaceArea );
}

// ----------------------------------------------------------------------------

void Program1()
{
    unsigned short appleCount			= 0;
	unsigned short pizzaCount			= 0;
	unsigned short donutCount			= 0;
	unsigned short iceCreamConeCount	= 0;

	float totalIceCreamVolume		= 0.0;
	float totalIceCreamSurfaceArea	= 0.0;
	float totalFoodVolume			= 0.0;
	float totalFoodSurfaceArea		= 0.0;

	std::cout << "How many apples will you have? ";
	std::cin >> appleCount;

	std::cout << "How many pizzas will you have? ";
	std::cin >> pizzaCount;

	std::cout << "How many donuts will you have? ";
	std::cin >> donutCount;

	std::cout << "How many ice cream cones will you have? ";
	std::cin >> iceCreamConeCount;

	auto [appleVol, appleSurfaceArea] = CalculateApple();
	totalFoodVolume += (appleVol * appleCount);
	totalFoodSurfaceArea += (appleSurfaceArea * appleCount);
	std::cout << std::endl;
	
	std::cout << "The volume of each apple = " << appleVol << " cubic inches\n";
	std::cout << "The surface area of each apple = " << appleSurfaceArea << " square inches.\n";
	std::cout << "The total volume of " << appleCount << ( appleCount == 1 ? " apple" : " apples" ) << " = " << ( appleVol * appleCount ) << " cubic inches\n";
	std::cout << "The total surface area of " << appleCount << ( appleCount == 1 ? " apple" : " apples" ) << " = " << (appleSurfaceArea * appleCount) << " square inches.\n";
	std::cout << std::endl;

	auto [pizzaVol, pizzaSurfaceArea] = CalculatePizza();
	totalFoodVolume += (pizzaVol * pizzaCount);
	totalFoodSurfaceArea += (pizzaSurfaceArea * pizzaCount);
	
	std::cout << "The volume of each pizza = " << pizzaVol << " cubic inches\n";
	std::cout << "The surface area of each pizza = " << pizzaSurfaceArea << " square inches.\n";
	std::cout << "The total volume of " << pizzaCount<< (pizzaCount == 1 ? " pizza" : " pizzas") << " = " << (pizzaVol * pizzaCount) << " cubic inches\n";
	std::cout << "The total surface area of " << pizzaCount << (pizzaCount == 1 ? " pizza" : " pizzas") << " = " << (pizzaSurfaceArea * pizzaCount) << " square inches.\n";
	std::cout << std::endl;

	auto [donutVol, donutSurfaceArea] = CalculateDonut();
	totalFoodVolume += (donutVol * donutCount);
	totalFoodSurfaceArea += (donutSurfaceArea * donutCount);
	
	std::cout << "The volume of each donut = " << donutVol << " cubic inches\n";
	std::cout << "The surface area of each donut = " << donutSurfaceArea << " square inches.\n";
	std::cout << "The total volume of " << donutCount << (donutCount == 1 ? " donut" : " donuts") << " = " << (donutVol * donutCount) << " cubic inches\n";
	std::cout << "The total surface area of " << donutCount << (donutCount == 1 ? " donut" : " donuts") << " = " << (donutSurfaceArea * donutCount) << " square inches.\n";
	std::cout << std::endl;

	auto [coneVol, coneSurfaceArea] = CalculateIceCreamCone();
	auto [scoopVol, scoopSurfaceArea] = CalculateIceCreamScoop();
	totalIceCreamVolume = (coneVol + scoopVol) * iceCreamConeCount;
	totalIceCreamSurfaceArea = (coneSurfaceArea + scoopSurfaceArea) * iceCreamConeCount;
	totalFoodVolume += totalIceCreamVolume;
	totalFoodSurfaceArea += totalIceCreamSurfaceArea;
	
	std::cout << "The volume of each ice cream cone itself = " << coneVol << " cubic inches\n";
	std::cout << "The surface area of each ice cream cone itself = " << coneSurfaceArea << " square inches.\n";
	std::cout << "The volume of each ice cream scoop itself = " << scoopVol << " cubic inches\n";
	std::cout << "The surface area of each ice cream scoop itself = " << scoopSurfaceArea << " square inches.\n";

	std::cout << "The total volume of the "
		      << (iceCreamConeCount == 1 ? "cone" : "cones") << " = "
		      << (coneVol * iceCreamConeCount) << " cubic inches\n";
	std::cout << "The total surface area of the "
			  << (iceCreamConeCount == 1 ? "cone" : "cones") << " = "
			  << (coneSurfaceArea * iceCreamConeCount) << " square inches.\n";
	
	std::cout << "The total volume of the "
		      << (iceCreamConeCount == 1 ? "scoop" : "scoops") << " = "
			  << (scoopVol * iceCreamConeCount) << " cubic inches\n";
	std::cout << "The total surface area of the "
			  << (iceCreamConeCount == 1 ? "scoop" : "scoops") << " = "
			  << (scoopSurfaceArea * iceCreamConeCount) << " square inches.\n";

	std::cout << "The total volume of " << iceCreamConeCount << " full ice cream " 
			  << (iceCreamConeCount == 1 ? "cone" : "cones") << " with "
			  << (iceCreamConeCount == 1 ? "scoop" : "scoops") << " = "
			  << totalIceCreamVolume << " cubic inches\n";
	std::cout << "The total surface area of " << iceCreamConeCount << " full ice cream " 
			  << (iceCreamConeCount == 1 ? "cone" : "cones") << " with "
			  << (iceCreamConeCount == 1 ? "scoop" : "scoops") << " = "
			  << totalIceCreamSurfaceArea << " square inches.\n";

	std::cout << std::endl;

	std::cout << "The total volume of food you are about to consume is " << std::fixed << totalFoodVolume << " cubic inches.\n";
	std::cout << "The total suface area of food you are about to consume is " << std::fixed << totalFoodSurfaceArea << " square inches.\n";
	std::cout << std::endl;
}