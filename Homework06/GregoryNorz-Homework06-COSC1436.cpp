// ----------------------------------------------------------------------------
//
// System includes
//
#include <iostream>

// ----------------------------------------------------------------------------
//
// Local includes
//
#include "geometry.hpp"
#include "program1.hpp"
#include "program2.hpp"

// ----------------------------------------------------------------------------

int main()
{
    Program1();

    std::cout << "****************************************" << std::endl;
    std::cout << std::endl;

    // std::cin can have garbage hanging out in there, including \n. This strips it out
    // so future calls to std::getline() will work!
    //
    // Program1() uses std::cin, and Program2() uses std::getline()
    std::cin.ignore( 100, '\n' );
    
    Program2();
}
