// ----------------------------------------------------------------------------
// Gregory Norz – COSC 1436 – Summer 2023 (10-week session)
// Homework 05 – July 15, 2023
// ----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <numeric>
#include <random>
#include <algorithm>

// ----------------------------------------------------------------------------

const char* lottoNumberFile = "lotto.txt";

const std::vector<std::string> randomStatements{ "Gambling is a tax on people bad at math!",
												 "Surely you'll win this time!",
												 "Wait a minute, did you steal MY winning numbers?",
												 "These numbers are only good for jackpots in excess of ONE MILLION DOLLARS. <raises pinky>",
												 "I think these might be the numbers from the TV show \"Lost\"..." };

// ----------------------------------------------------------------------------
//
// We can't pass by reference becase we need copies to call the non-const erase() method.
//
// This function is making a LOT of assumptions. It's also relying on the fact that iterators
// are supposed to be close in efficiency to actual pointers. I've had to do this in an interview
// before, and I ended up doing the std::transform method (erase() and std::remove_if weren't in the
// Standard at this point!). They chuckled and asked what std::transform with std::reverse was doing.
// I said "I don't really care. I'm always going to assume C++ STL authors are way more efficient
// than anything I could write. But here's how I would do it with pointers." 
// 
// I still got the job. :-P
//
bool IsPalindrome( std::string lhs, std::string rhs )
{
	// We want to compare lowercase strings so we don't run afoul of case in the == below.
	// Also, below is likely only to work for basic ASCII.
	// This will modify only the temp copies of the two param strings.
	std::transform( lhs.begin(), lhs.end(), lhs.begin(), std::tolower );
	lhs.erase( std::remove_if(lhs.begin(), lhs.end(), std::ispunct), lhs.end() );
	lhs.erase( std::remove_if(lhs.begin(), lhs.end(), std::isspace), lhs.end() );

	std::transform( rhs.begin(), rhs.end(), rhs.begin(), std::tolower );
	rhs.erase( std::remove_if(rhs.begin(), rhs.end(), std::ispunct), rhs.end() );
	rhs.erase( std::remove_if(rhs.begin(), rhs.end(), std::isspace), rhs.end() );

	return ( lhs == rhs );
}

// ----------------------------------------------------------------------------

unsigned short GetRandomNumber( unsigned short rangeStart, unsigned short rangeEnd )
{
	// OK, this was a lot of fun! C++11 has pulled in some of the old Boost
	// RNG code and added it to the <random> header. Admitedly I had to crib
	// some of this from both cppreference.com and Stack Overflow, but it
	// was a fun learning experience.
	std::random_device randomDevice;
	std::uniform_int_distribution<unsigned short> numberDistribution( rangeStart, rangeEnd );

	// I opted not to get crazy with the seed. I think in the real world I'd use the <chrono> library and grab nanoseconds off
	// the CPU clock and XOR it with the number from randomDevice a few times in a loop.
	std::seed_seq seedSequence{ randomDevice(), randomDevice(), randomDevice(), randomDevice(), randomDevice(), randomDevice() };
	std::mt19937 rng( seedSequence ); // A little Mersene Twister in here for giggles. I picked it out of all the algos because why not?

	return numberDistribution( rng );
}

// ----------------------------------------------------------------------------

std::string GetRandomStatement()
{
	return randomStatements[ GetRandomNumber(0, 4) ];
}

// ----------------------------------------------------------------------------

void Program1()
{
	std::ifstream lottoFile( lottoNumberFile );

	if ( !lottoFile.is_open() )
	{
		std::cerr << "Could not find or open the file of Lotto Numbers." << std::endl;
	}
	else
	{
		std::string			lineOfNumbers{ '\0' };
		std::vector<short>	lottoNumbersVec( 55, 0 ); // Accounting for zero which isn't a real lotto number
		unsigned long		sumOfNumbers{ 0 }, totalNumbersCount{ 0 };

		while ( std::getline(lottoFile, lineOfNumbers) )
		{
			std::istringstream winningNumStream{ lineOfNumbers };
			std::string token{ '\0' };
			std::vector<std::string> tokenizedValues{ '\0' };
			
			while ( std::getline(winningNumStream, token, ',') )
			{
				tokenizedValues.push_back( token );
			}

			for (unsigned short i = 4; i <=9; ++i )
			{
				unsigned long selectedNum = std::stoul( tokenizedValues[i] );
				lottoNumbersVec[selectedNum]++;
				sumOfNumbers += selectedNum;
				++totalNumbersCount;
			}
		}

		std::cout << "Statistics for Lotto Texas (1992 - Present)\n";
		std::cout << "Note: this does not account for the Bonus Ball era correctly!\n";
		std::cout << "-------------------------------------------------------------\n";
		std::cout << "Total numbers: " << totalNumbersCount << std::endl;
		std::cout << "Sum of these numbers: " << sumOfNumbers << std::endl;
		std::cout << "Average of these numbers: " << (sumOfNumbers / static_cast<float>(totalNumbersCount)) << std::endl;
		std::cout << std::endl;
		std::cout << "Frequency of Numbers:\n";
		std::cout << "---------------------\n";
		std::cout << "#\tFrequency\n";

		for ( unsigned short i = 1; i <= 54; ++i )
		{
			std::cout << i << "\t" << lottoNumbersVec[i] <<  std::endl;
		}
	}
}

// ----------------------------------------------------------------------------

void Program2()
{
	std::vector<unsigned short> chosenNumbers( 0 );
	for ( unsigned short i = 1; i <= 6; ++i )
	{
		unsigned short lottoNumber = 0;
		do
		{
			lottoNumber = GetRandomNumber( 1, 54 ); // Lotto Texas numbers range from 1 to 54 currently
		}
		while ( chosenNumbers.end() != std::find(chosenNumbers.begin(), chosenNumbers.end(), lottoNumber) );

		chosenNumbers.push_back( lottoNumber );
	}

	std::sort( chosenNumbers.begin(), chosenNumbers.end() );

	std::cout << "Here is your Lotto Texas quick pick: ";
	for ( auto num : chosenNumbers )
	{
		std::cout << num << " ";
	}

	std::cout << std::endl;
	std::cout << GetRandomStatement() << std::endl;
}

// ----------------------------------------------------------------------------

void Program3()
{
	std::cout << "This program is used to detect a palindrome.\n";
	std::cout << "Please enter a word: ";

	std::string inputString{ '\0' };
	std::getline( std::cin, inputString );

	std::string reversedString( inputString );
	std::reverse_copy( inputString.begin(), inputString.end(), reversedString.begin() ); // Modifies reversedString

	// Here I'm just outputting the actual reversed string and not lowered or stripped of punctuation/spaces.
	std::cout << "Your string in reverse: " << reversedString << std::endl;
	std::cout << "This string is " << (IsPalindrome(reversedString, inputString) ? "" : "not " ) << "a palindrome.\n";
}

// ----------------------------------------------------------------------------

int main()
{
	std::cout << "****************************************\n" << std::endl;
	std::cout << "Program 1 Output:\n\n";
	std::cout << "****************************************\n" << std::endl;
	Program1();
	std::cout << std::endl;

	std::cout << "****************************************\n" << std::endl;
	std::cout << "Program 2 Output:\n\n";
	std::cout << "****************************************\n" << std::endl;
	Program2();
	std::cout << std::endl;

	std::cout << "****************************************\n" << std::endl;
	std::cout << "Program 3 Output:\n\n";
	std::cout << "****************************************\n" << std::endl;
	Program3();
	std::cout << std::endl;

	std::cout << "****************************************\n" << std::endl;
	std::cout << "Fin." << std::endl;
}
