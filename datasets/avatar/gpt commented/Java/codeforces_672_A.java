import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    
    // Method to generate a character array from the concatenation of numbers 1 to 1000
    static char[] generateString() {
        StringBuilder sb = new StringBuilder(); // Creating a StringBuilder to efficiently build the string
        
        // Looping through numbers 1 to 1000 and appending them to the StringBuilder
        for (int i = 1; i <= 1000; i++) {
            sb.append(i); // Appending the current number to the StringBuilder
        }
        
        // Converting the built string to a character array and returning it
        return sb.toString().toCharArray();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input from the user
        
        // Reading an integer input from the user
        int n = sc.nextInt();
        
        // Printing the character at the (n-1)th index of the generated character array
        System.out.println(generateString()[n - 1]);
        
        sc.close(); // Closing the Scanner to prevent resource leaks
    }
}
