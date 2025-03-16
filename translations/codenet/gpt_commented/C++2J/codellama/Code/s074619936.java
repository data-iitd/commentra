import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold input string, temporary string for individual characters, and the sum of digits
        String str;
        String tmp;
        int sum;

        // Infinite loop to continuously accept input until "0" is entered
        while(true) {
            // Read input from the user
            Scanner sc = new Scanner(System.in);
            str = sc.nextLine();

            // Check if the input is "0", if so, exit the loop
            if(str.equals("0")) break;

            // Initialize sum to 0 for the new input string
            sum = 0;

            // Loop through each character in the input string
            for(int i = 0; i < str.length(); i++) {
                // Convert the character to a string
                tmp = str.substring(i, i+1);

                // Convert the string character to an integer
                int num = Integer.parseInt(tmp);

                // Add the integer value to the sum
                sum += num;
            }
            
            // Output the sum of the digits for the current input string
            System.out.println(sum);
        }

        // Return 0 to indicate successful completion of the program
        return 0;
    }
}

