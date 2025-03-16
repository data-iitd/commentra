import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Declaring variables to hold input values and a counter
        long pandu, vundu, urdu, c = 0;
        
        // Reading three long integer values from user input
        pandu = sc.nextLong(); // The first input value
        vundu = sc.nextLong(); // The second input value
        urdu = sc.nextLong();  // The third input value
        
        // Calculating the cumulative sum of 'pandu' multiplied by each integer from 1 to 'urdu'
        for (int i = 1; i <= urdu; i++) {
            c += i * pandu; // Incrementing 'c' by the product of 'i' and 'pandu'
        }
        
        // Checking if the calculated sum 'c' is less than 'vundu'
        if (c < vundu) {
            System.out.print("0"); // If true, print "0"
        } else {
            // If 'c' is greater than or equal to 'vundu', print the difference
            System.out.print(c - vundu);
        }
    }
}
