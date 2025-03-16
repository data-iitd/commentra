
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
    // Create BufferedReader to read input from System.in
    FILE *br = fopen ( "input.txt" , "r" ) ;
    // Create PrintWriter to write output to System.out
    FILE *pw = fopen ( "output.txt" , "w" ) ;
    
    // Read the first train's details
    char *a = ( char * ) malloc ( 100 * sizeof ( char ) ) ;
    char *tA = ( char * ) malloc ( 100 * sizeof ( char ) ) ;
    fscanf ( br , "%s %s" , a , tA ) ;
    
    // Read the second train's details
    char *b = ( char * ) malloc ( 100 * sizeof ( char ) ) ;
    char *tB = ( char * ) malloc ( 100 * sizeof ( char ) ) ;
    fscanf ( br , "%s %s" , b , tB ) ;
    
    // Read the current timing
    char *timing = ( char * ) malloc ( 100 * sizeof ( char ) ) ;
    fscanf ( br , "%s" , timing ) ;
    
    // Calculate the simulated departure and arrival times for train a
    int simDeparture = atoi ( timing ) ;
    int simArrival = simDeparture + atoi ( tA ) ;
    
    // Initialize counter to keep track of conflicts
    int counter = 0 ;
    
    // Iterate through the bus schedule, checking for conflicts
    for ( int i = 300 ; i < 1440 ; i += atoi ( b ) ) {
        int busDeparture = i ; // Bus departure time
        int busArrival = i + atoi ( tB ) ; // Bus arrival time
        
        // Check if there's a conflict (bus and train schedules overlap)
        if ( busDeparture >= simArrival || simDeparture >= busArrival ) continue ;
        
        // Increment counter if a conflict is found
        counter ++ ;
    }
    
    // Print the number of conflicts found
    fprintf ( pw , "%d\n" , counter ) ;
    fflush ( pw ) ;
    fclose ( pw ) ;
    fclose ( br ) ;
    
    return 0 ;
}

