// ----------------------------------------------------------------------------
// Gregory Norz – COSC 1436 – Summer 2023 (10-week session)
// Homework 04 – July 8, 2023
// ----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

// ----------------------------------------------------------------------------
//
// PrintFlowerBox - just gives a nice little division between the various
// program parts which are going to execute.
//

void PrintFlowerBox( const std::string& boxMessage )
{
	std::cout << std::string( 80, '*') << std::endl;
	std::cout << "*\n" << "* " << boxMessage << std::endl;
	std::cout << "*\n";
	std::cout << std::string( 80, '*' ) << std::endl << std::endl ; // Mostrously inefficient but looks clean!
}

// ----------------------------------------------------------------------------
//
// This ended up being a bit of a waste, but I started out stubbing code into functions
// so I decided to leave it.
//
unsigned short PrintProgram1Menu()
{
	unsigned short menuChoice{ 0 };
	bool validMenuChoice{ false };

	do
	{
		std::cout << "1 - Convert Fahrenheit to Celsius\n";
		std::cout << "2 - Convert Miles to Kilometers\n";
		std::cout << "3 - Convert Pounds to Kilgrams\n";
		std::cout << "4 - Exit\n";
		std::cout << "\n";
		std::cout << "Enter your choice: ";
		std::cin >> menuChoice; // We are relying on the user to not do something stupid and overflow the ushort
		std::cout << std::endl;

		validMenuChoice = ( menuChoice >= 1 ) && ( menuChoice <= 4 );

		if ( !validMenuChoice )
		{
			std::cout << "Please enter a valid value.\n";
		}
	}
	while ( !validMenuChoice );

	return menuChoice;
}

// ----------------------------------------------------------------------------

void Program1()
{
	unsigned short menuChoice{ 0 };
	do
	{
		menuChoice = PrintProgram1Menu();

		// Below we are making an assumption that the user won't over/underflow the double var
		switch ( menuChoice )
		{
		case 1:
		{
			double tempInF{ 0.0 };
			std::cout << "Enter the temperature in Fahrenheit: ";
			std::cin >> tempInF;

			double tempInC{ ( tempInF - 32 ) * ( 5.0 / 9.0 ) };

			std::cout << tempInF << " degrees Fahrenheit is " << tempInC << " degrees Celsius." << std::endl;
			break;
		}

		case 2:
		{
			// Probably could use an unsigned double here as negative miles are typically used.
			double miles{ 0.0 };
			std::cout << "Enter the number of miles: ";
			std::cin >> miles;

			double kilometers{ miles * 1.609344 }; // Could be a const at the top of the file

			std::cout << miles << " miles is " << kilometers << " kilometers." << std::endl;
			break;
		}

		case 3:
		{
			// Probably could use an unsigned double here as negative pounds are typically used.
			double pounds{ 0.0 };
			std::cout << "Enter the number of pounds: ";
			std::cin >> pounds;

			double kilograms{ pounds * 0.45359237 };

			std::cout << pounds << " pounds is " << kilograms << " kilograms." << std::endl;
			break;
		}

		case 4:
			std::cout << "Exiting.\n";
			break;

		default:
			std::cout << "We got an invalid value for the menu choice. Exiting." << std::endl;
			break;
		}

		std::cout << std::endl;
	} 
	while ( 4 != menuChoice ); // We establish in PrintProgramMenu1() that 4 == Exit
}

// ----------------------------------------------------------------------------

void Program2()
{
	unsigned short pennies{ 0 }, nickels{ 0 }, dimes{ 0 }, quarters{ 0 };
	std::cout << "How many pennies do you have? ";
	std::cin >> pennies;
	std::cout << "How many nickels do you have? ";
	std::cin >> nickels;
	std::cout << "How many dimes do you have? ";
	std::cin >> dimes;
	std::cout << "How many quarters do you have? ";
	std::cin >> quarters;

	// Not the most ideal as we're susceptible down the road to division/precision/rounding errors from the CPU.
	double dollarValue{ (pennies * .01) + (nickels * .05) + (dimes * .10) + (quarters * .25) };
	std::cout << std::endl << "The dollar value is $" << std::fixed << std::setprecision(2) << dollarValue << std::endl;

	if ( dollarValue < .50 )
	{
		std::cout << "You need to search for some pennies!\n";
	}
	else if ( (dollarValue >= .50) && (dollarValue < 2.00) )
	{
		std::cout << "You can barely buy a soda!\n";
	}
	else if ( (dollarValue >= 2.00) && (dollarValue < 5.00) )
	{
		std::cout << "You can eat at McDonald's!\n";
	}
	else // Assume we are >= $5.00 here
	{
		std::cout << "All those coins must be heavy!\n";
	}

	std::cout << "\nBy the way, you might be able to condense your money to the following coins:\n\n";

	// There is a small chance that we get some errors messing with the float-to-int conversion below,
	// in addition to multiplying by 100. I've run several tests on my machine (which is a VM for what it's worth),
	// and so far the rounding has been just fine. I opted not to do a Money object since the class
	// hasn't progressed to that point!

	int totalCents{ static_cast<int>((dollarValue * 100)) }, newPennies{ 0 }, newNickels{ 0 }, newDimes{ 0 }, newQuarters{ 0 };

	newQuarters = totalCents * 4;
	newQuarters = totalCents / 25; totalCents %= 25;
	newDimes = totalCents / 10; totalCents %= 10;
	newNickels = totalCents / 5; totalCents %= 5;
	newPennies = totalCents;

	std::cout << newPennies << " pennies\n";
	std::cout << newNickels << " nickels\n";
	std::cout << newDimes << " dimes\n";
	std::cout << newQuarters << " quarters\n";
}

// ----------------------------------------------------------------------------

void Program3()
{
	std::cout << "~~ Pattern 1~~\n";
	for ( unsigned short i = 105; i <= 500; ++i )
	{
		if ( (i % 5) == 0 )
		{
			std::cout << i << " ";
		}

		if ( ( i % 100 ) == 0 )
		{
			std::cout << std::endl;
		}
	}

	std::cout << "\n~~ Pattern 2~~\n";
	for ( unsigned short i = 1; i <= 10; ++i )
	{
		for ( unsigned short j = 1; j <= i; j++ )
		{
			std::cout << "* ";
		}

		std::cout << std::endl;
	}
	
	std::cout << "\n~~ Pattern 3~~\n";
	for ( unsigned short i = 1; i <= 10; ++i )
	{
		for ( unsigned short j = 10; j >= i; --j )
		{
			std::cout << "$ ";
		}

		std::cout << std::endl;
	}
}

// ----------------------------------------------------------------------------

int main()
{
	PrintFlowerBox( "Program 1" );
	Program1();
	std::cout << std::endl;

	PrintFlowerBox( "Program 2" );
	Program2();
	std::cout << std::endl;

	PrintFlowerBox( "Program 3" );
	Program3();
	std::cout << std::endl;
}
