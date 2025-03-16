import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the main class named Main
    public static void main(String[] args){ // Defining the main method
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object for user input
        while(true){ // Starting an infinite loop
            int sum = 0; // Initializing the sum variable to 0
            
            String s = sc.next(); // Reading a string input from the user
            if(s.equals("0")) break; // If the user inputs "0", break the loop

            for(int i=0;i<s.length();i++){ // Starting a for loop to iterate through each character in the string
                char a = s.charAt(i); // Assigning the character at the current index to the 'a' variable
                sum += a - '0'; // Adding the ASCII value of the character (subtracting '0') to the sum variable
            }
            System.out.printf("%d\n", sum); // Printing the sum of the digits in the string to the console
        }
    }
}