
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a new Scanner object to read input from the standard input stream
        Scanner sc = new Scanner(System.in);

        // Initialize two integer variables A and B with the values read from the user
        int A = sc.nextInt();
        int B = sc.nextInt();

        // Define a conditional statement to check if any of the given conditions are met
        if(A%3==0 || B%3==0 || (A+B)%3==0){
            // If any of the conditions are met, print "Possible" to the standard output
            System.out.println("Possible");
        }else{
            // If none of the conditions are met, print "Impossible" to the standard output
            System.out.println("Impossible");
        }
    }
}