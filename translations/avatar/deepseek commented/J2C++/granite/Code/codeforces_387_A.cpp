

#include <iostream> 
#include <string> 
#include <sstream> 
#include <iomanip> 
#include <ctime> 

int main ( ) { 
    // Step 1: Read two times from the user, split by colon and convert to tm objects
    std::string s, t ; 
    std::cin >> s >> t ; 
    std::istringstream iss1 ( s ), iss2 ( t ) ; 
    int h1, m1, h2, m2 ; 
    char c ; 
    iss1 >> h1 >> c >> m1 ; 
    iss2 >> h2 >> c >> m2 ; 
    tm time1 = { 0, m1, h1 } ; 
    tm time2 = { 0, m2, h2 } ; 

    // Step 2: Calculate the difference between the two times
    time_t time1_t = mktime ( &time1 ) ; 
    time_t time2_t = mktime ( &time2 ) ; 
    double diff = difftime ( time1_t, time2_t ) ; 
    int hours = diff / 3600 ; 
    int minutes = ( diff - hours * 3600 ) / 60 ; 

    // Step 3: Print the difference in hours and minutes
    std::cout << std::setw ( 2 ) << std::setfill ( '0' ) << hours << ":" << std::setw ( 2 ) << std::setfill ( '0' ) << minutes << std::endl ; 

    return 0 ; 
}

