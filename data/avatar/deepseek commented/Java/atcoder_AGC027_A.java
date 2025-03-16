
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        // Step 1: Read an integer N and a long integer x from the standard input
        Scanner sc = new Scanner ( System.in ) ; 
        int N = sc.nextInt ( ) ; 
        long x = sc.nextInt ( ) ; 

        // Step 2: Read N long integers and store them in a list called sweet
        List < Long > sweet = new ArrayList < Long > ( ) ; 
        for ( int i = 0 ; i < N ; i ++ ) { 
            long a = sc.nextInt ( ) ; 
            sweet.add ( a ) ; 
        } 

        // Step 3: Sort the list sweet
        Collections.sort ( sweet ) ; 

        // Step 4: Initialize a counter num to 0 and iterate through the sorted list sweet
        int num = 0 ; 
        for ( int i = 0 ; i < N ; i ++ ) { 
            // Step 5: Check if subtracting the element from x results in a non-negative value
            if ( x - sweet.get ( num ) >= 0 ) { 
                // Step 6: Subtract the element from x and increment the counter num
                x = x - sweet.get ( num ) ; 
                num ++ ; 
            } else { 
                // Step 7: Break out of the loop if the condition is not met
                break ; 
            } 
        } 

        // Step 8: After the loop, if num equals N and x is greater than 0, decrement num by 1
        if ( ( num == N ) && ( x > 0 ) ) { 
            num -= 1 ; 
        } 

        // Step 9: Print the value of num
        System.out.println ( num ) ; 
    } 
}

