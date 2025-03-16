
import java.util.* ; // Importing the Scanner class

public class Main { // Defining the Main class

    public static void main ( String [ ] args ) { // Defining the main method as the entry point of the program
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input
        int n = sc.nextInt ( ) ; // Reading the number of test cases

        int [ ] FfriendPerDay = new int [ 367 ] ; // Initializing an array of size 367 to store the number of friends of type F for each day
        int [ ] MfriendPerDay = new int [ 367 ] ; // Initializing an array of size 367 to store the number of friends of type M for each day
        int answer = 0 ; // Initializing an integer variable to store the maximum difference between the number of friends of type F and M for any day

        for ( int i = 0 ; i < n ; i ++ ) { // Iterating through each test case
            char c = sc.next ( ).charAt ( 0 ) ; // Reading the character representing the gender of the friend
            int a = sc.nextInt ( ) ; // Reading the starting day of the range
            int b = sc.nextInt ( ) ; // Reading the ending day of the range

            for ( int j = a ; j <= b ; j ++ ) { // Iterating through each day in the range
                if ( c == 'M' ) MfriendPerDay [ j ] ++ ; // Incrementing the counter in the MfriendPerDay array for the day if the friend is of type M
                else FfriendPerDay [ j ] ++ ; // Incrementing the counter in the FfriendPerDay array for the day if the friend is of type F

                if ( MfriendPerDay [ j ] < FfriendPerDay [ j ] ) { // Checking if the number of friends of type M is less than the number of friends of type F for the current day
                    if ( MfriendPerDay [ j ] > answer ) answer = MfriendPerDay [ j ] ; // Updating the value of answer if the current difference is greater than the previous maximum difference
                } else { // Repeating the same check for the number of friends of type F
                    if ( FfriendPerDay [ j ] > answer ) answer = FfriendPerDay [ j ] ;
                }
            }
        }

        System.out.println ( answer * 2 ) ; // Printing the answer, which is twice the maximum difference between the number of friends of type F and M for any day.