#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ----------------------------------------------------------------------------

void printElephant();
void printSumAndProduct();
void geometryFun();

// ----------------------------------------------------------------------------

int main()
{
	std::cout << "--------------------\n";
	std::cout << "Step 1, ASCII art elephant!\n";
	std::cout << "--------------------\n";
	printElephant();
	std::cout << std::endl;

	std::cout << "--------------------\n";
	std::cout << "Step 2, calculate sum and product!\n";
	std::cout << "--------------------\n";
	printSumAndProduct();
	std::cout << std::endl;

	std::cout << "--------------------\n";
	std::cout << "Step 3, do some geometry fun!\n";
	std::cout << "--------------------\n";
	geometryFun();
	std::cout << std::endl;

	std::cout << "-------------------\n";
	std::cout << "That's all folks!" << std::endl;
}

// ----------------------------------------------------------------------------

void printElephant()
{
	std::cout << "You wanted an elephant? Well here's an elephant: \n\n";
	std::cout << "           /  \\~~~/  \\ \n";
	std::cout << "     ,----(     ..    ) \n";
	std::cout << "    /      \\__     __/ \n";
	std::cout << "   /|         (\\  |( \n";
	std::cout << "  ^ \\   /___\\  /\\ |   hjw \n";
	std::cout << "     |__|   |__|-\"    `97 " << std::endl;

	// I only use std::endl on the last statement to get an I/O flush. 
}

// ----------------------------------------------------------------------------

void printSumAndProduct()
{
	float first = 0.0;
	float second = 0.0;
	float third = 0.0;

	std::cout << "This calculates the sum and product of three numbers.\n\n";

	std::cout << "Enter the first number: ";
	std::cin >> first;

	std::cout << "Enter the second number: ";
	std::cin >> second;

	std::cout << "Enter the third number: ";
	std::cin >> third;
	std::cout << std::endl;

	std::cout << "The sum of these three numbers is " << (first + second + third) << std::endl;
	std::cout << "The product of these three numbers is " << (first * second * third) << std::endl;
}

// ----------------------------------------------------------------------------

void geometryFun()
{
	const double pi = 3.14159;
	float radiusInInches = 0.0;
	const double fourThirds = (4.0 / 3.0);

	std::cout << "This calculates the area of a circle, volume of a sphere, and surface area of a sphere.\n\n";

	std::cout << "Enter a radius in inches: ";
	std::cin >> radiusInInches;
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Area of a circle is " << (pi * pow(radiusInInches, 2)) << " square inches\n";
	std::cout << "Volume of a sphere is " << (fourThirds * pi * pow(radiusInInches, 3)) << " cubic inches\n";
	std::cout << "Surface area of a sphere is " << (4 * pi * pow(radiusInInches, 2)) << " square inches" << std::endl;
}

// ----------------------------------------------------------------------------