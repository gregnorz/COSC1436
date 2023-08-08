// ----------------------------------------------------------------------------
//
// System includes
//
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>

// ----------------------------------------------------------------------------
//
// Local includes
//
#include "program2.hpp"

// ----------------------------------------------------------------------------

// std::map<std::string, std::string> replacementMap{  {"lol", "laughing out loud"},
//                                                     {"u", "you"},
//                                                     {"brb", "be right back"},
//                                                     {"wyd", "what are you doing"},
//                                                     {"rn", "right now"},
//                                                     {"fr", "for real"},
//                                                     {"atm", "at the moment"},
//                                                     {"btw", "by the way"}
//                                                };

// Not a fan of this being a global, but since we aren't doing classes yet, this will have to do.
std::map<std::string, std::string> replacementMap;

// ----------------------------------------------------------------------------

void LoadAbbreviationMap()
{
    // Assumes the .txt file is in the local directory with the executable.
    std::ifstream abbrFile( "abbreviations.txt" );

    if ( !abbrFile.is_open() )
    {
        std::cerr << "Could not open the abbreviations file. This is bad." << std::endl;
    }
    else
    {
        std::string csvLine{ '\0' };
        while( std::getline(abbrFile, csvLine) )
        {
            // Get each line to a stream, then break that into a temp vector.
            // The temp vector will then have 2 values, the abbreviation and the replacement string.
            std::istringstream csvStream( csvLine );
            std::string token{ '\0' };
            std::vector<std::string> tokenizedValues{ '\0' };
            while ( std::getline(csvStream, token, ',') )
            {
                tokenizedValues.push_back( token );   
            }

            // Each line should be "abbr, replacement", meaning tokenizedValue[0] and [1] for the map
            std::pair<std::string,std::string> keyValPair( tokenizedValues[0], tokenizedValues[1] );
            replacementMap.insert( keyValPair );
        }
    }
}

// ----------------------------------------------------------------------------
//
// Modifying the function signature here so we pull from a file instead, building a
// dictionary of replacement pairs.
//
std::string LOLSpeak( const std::string& sentence )
{
    std::string correctedSentence( sentence );

    LoadAbbreviationMap(); // Populate our global up above; would be nicer in a class...
    
    for ( const auto& [abbreviation, replacement] : replacementMap )
    {
        // Note: this is probably cheating a bit because I'm not writing code that uses
        // traditional string replacement and search methods. The way I'd do it:
        //
        // 1) Keep the std::map loop
        // 2) Create 3 search strings for "<abbreviation> ", " <abbreviation>", and " <abbreviation> "
        // 3) Look for each of those strings in sequence, operating on the string itself so
        //    I get an in-place replacement.
        // 4) Send that string back as below.
        // 5) I'd probably do a tolower() on everthing for the matching, just to be safe? Would
        //    have to think about that.
        //
        // The regular expression is how I mentioned in class that I would solve the problem normally,
        // since that pattern matcher is probably a bit faster than string manipulation.

        // This will match on word boundaries, including at the beginning and end of the sentence.
        // It will skip matches which occur inside of a word. It also allows for punctuation.
        // The bitmask at the end uses a case-insensitive match. Might make it a bit funky
        // if the abbreviation is at the start of a sentence. I'm not accounting for that here.
        
        std::regex expression( "\\b" + abbreviation + "\\b", std::regex::icase );
        correctedSentence = std::regex_replace( correctedSentence, expression, replacement );
    }
    
    return correctedSentence;
}

// ----------------------------------------------------------------------------

void Program2()
{
    std::cout << "This program will correct ur lolspeak abrreviations." << std::endl;
    std::cout << "Enter a sentence: ";

    std::string sentence;
    std::getline( std::cin, sentence );
    
    std::cout << "The corrected sentence: \n";

    std::string correctedSentence( LOLSpeak(sentence) );
    std::cout << correctedSentence << std::endl;
}