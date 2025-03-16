import java.util.Scanner; // Import the Scanner class for input and output operations

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the user
        String s = sc.nextLine(); // Read input from the user and store it in a string variable 's'
        int a = -1, z = -1; // Declare two integer variables to store the positions of 'A' and 'Z'

        // The first for loop iterates through the string to find the position of the first occurrence of 'A'
        for(int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') {
                a = i; // Assign the position of 'A' to variable 'a' and break the loop
                break;
            }
        }

        // The second for loop iterates through the string in reverse to find the position of the last occurrence of 'Z'
        for(int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == 'Z') {
                z = i; // Assign the position of 'Z' to variable 'z' and break the loop
                break;
            }
        }

        // Calculate the length of the substring between the first 'A' and the last 'Z' and print it
        System.out.println(z - a + 1);
    }
}

