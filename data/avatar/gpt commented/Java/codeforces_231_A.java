import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input from the console
        
        int t = sc.nextInt(); // Reading the number of test cases
        int count = 0; // Initializing a counter to keep track of valid cases
        
        // Looping through each test case
        while (t-- > 0) {
            int a = sc.nextInt(); // Reading the first integer
            int b = sc.nextInt(); // Reading the second integer
            int c = sc.nextInt(); // Reading the third integer
            
            // Checking if at least one of the integers is equal to 1
            if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
                count++; // Incrementing the count if the condition is met
            }
        }
        
        // Outputting the total count of valid cases
        System.out.println(count);
    }
}
