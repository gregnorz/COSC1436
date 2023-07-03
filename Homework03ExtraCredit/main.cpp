// ----------------------------------------------------------------------------
// Gregory Norz – COSC 1436 – Summer 2023 (10-week session)
// Homework 03 Extra Credit – July 1, 2023
// 
// I put some comments below in main() - basically I left out the error checking
// that the string entered won't exceed any existing buffer or window size. I'm
// making the assumption that any entered data will be small and fit the size
// constraints of the running console window and buffer.
// 
// I also leave out any error checking when getting the console buffer or 
// setting the cursor's position. 
// 
// ----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

// ----------------------------------------------------------------------------

using namespace std;

// ----------------------------------------------------------------------------
//
// Lifted from the "Bells & Whistles" section of our class webpage
//
void gotoxy( SHORT x, SHORT y )
{
    COORD p = { x, y };
    ::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

// ----------------------------------------------------------------------------

int main()
{
    string outputStr; // ( "Hello, world!" );
    cout << "Please enter a short string: ";
    std::getline( std::cin, outputStr ); // This accounts for spaces in the string which cin doesn't do.

    // We are assuming at this point that the string isn't too long. A better
    // method would be to check the string's length against the max X minus
    // a few characters for the bounding box.

    // Get the current info off of the console window so we know where to start
    // drawing the text.
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    HANDLE stdOutputHandle = ::GetStdHandle( STD_OUTPUT_HANDLE );
    ::GetConsoleScreenBufferInfo( stdOutputHandle, &screenBufferInfo );

    // The actual buffer could be really long, so we want to limit to the 
    // size of the stdout's window handle. Also assuming that the string's length
    // never exceeds a short.
    short maxX = screenBufferInfo.srWindow.Right;
    short x = ( maxX / 2 ) - ( outputStr.length() / 2 ); // Might be off-center by a char if even length()
    gotoxy( x, screenBufferInfo.dwCursorPosition.Y ); // Position correctly before we draw any text

    // Add 4 to the top and bottom box lines to account for the "| " and it's reverse on the entered string.
    // Making an assumption that the length of those characters around the string itself are consistent.
    cout << string( outputStr.length() + 4, '-' ) << endl;

    ::GetConsoleScreenBufferInfo( stdOutputHandle, &screenBufferInfo );
    gotoxy( x, screenBufferInfo.dwCursorPosition.Y ); // Position correctly before we draw any text
    cout << "| " << outputStr << " |\n";

    ::GetConsoleScreenBufferInfo( stdOutputHandle, &screenBufferInfo );
    gotoxy( x, screenBufferInfo.dwCursorPosition.Y ); // Position correctly before we draw any text
    cout << string( outputStr.length() + 4, '-' ) << endl;
}