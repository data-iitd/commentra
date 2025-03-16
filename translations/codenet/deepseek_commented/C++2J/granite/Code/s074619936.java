
import java.util.Scanner; // Import the Scanner class for user input

public class s074619936{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read user input
        String str; // Declare a string variable to store user input
        String tmp; // Declare a temporary string variable for character conversion
        int sum; // Declare an integer variable to store the sum of digits

        // Infinite loop that continues until the user inputs "0"
        while(true)
        {
            str = scanner.nextLine(); // Read a string from the user
            if(str.equals("0")) break; // If the input string is "0", break the loop
            sum = 0; // Initialize sum to 0
            for(int i=0;i<str.length();i++) // Loop through each character in the string
            {
                tmp = String.valueOf(str.charAt(i)); // Convert the character to a string
                int num = Integer.parseInt(tmp); // Convert the string to an integer
                sum += num; // Add the integer to the sum
            }
            
            System.out.println(sum); // Print the sum
        }
    }
}
