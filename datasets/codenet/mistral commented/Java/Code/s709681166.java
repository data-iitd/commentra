import java.util.Scanner; // Importing the Scanner class from the java.util package

public class Main { // Defining the main class named Main
    public static void main(String[] args) { // Defining the main method that is the entry point of the program
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the standard input stream
        
        String s = sc.nextLine(); // Reading a single line of input from the user using the nextLine() method of the Scanner class and storing it in the String variable 's'

        for(int i = 0;i<s.length();i++){ // Starting a for loop that iterates through each character in the String 's'
            char c = s.charAt(i); // Assigning the character at the current index 'i' of the String 's' to the char variable 'c'

            if(Character.isUpperCase(c)){ // Checking if the character is an uppercase letter using the isUpperCase() method of the Character class
                c += 32; // If it is, adding 32 to its Unicode value to convert it to its lowercase equivalent
                System.out.print(c); // Printing the converted character to the console
            }else if(Character.isLowerCase(c)){ // Checking if the character is a lowercase letter using the isLowerCase() method of the Character class
                c -= 32; // If it is, subtracting 32 from its Unicode value to convert it to its uppercase equivalent
                System.out.print(c); // Printing the converted character to the console
            }
            else
                System.out.print(c); // If the character is neither uppercase nor lowercase, just printing it as it is
        }
        System.out.println(); // Printing a newline character after processing the entire String
        sc.close(); // Closing the Scanner object to release the system resources
    }
}
