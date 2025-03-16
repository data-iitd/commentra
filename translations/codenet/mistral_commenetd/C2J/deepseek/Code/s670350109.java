import java.util.Scanner; // Import the Scanner class for input

public class StringComparison {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object

        // Declare character arrays of size 100
        char[] str1 = new char[100];
        char[] str2 = new char[100];
        char[] temp = new char[100];

        // Read the first string from the user
        String input = scanner.nextLine();
        System.out.println("First string: " + input); // Print the first string for verification
        for (int i = 0; i < input.length(); i++) {
            str1[i] = input.charAt(i);
        }

        // Read the second string from the user
        input = scanner.nextLine();
        System.out.println("Second string: " + input); // Print the second string for verification
        for (int i = 0; i < input.length(); i++) {
            str2[i] = input.charAt(i);
        }

        // Check if the lengths of the two strings are equal
        if (input.length() != str2.length) {
            System.out.println("NO"); // If the lengths are not equal, print "NO" and exit
            return;
        } else {
            // Reverse the first string and store it in temp array
            int j = 0;
            int t = str1.length - 1;
            while (j < str1.length) {
                temp[j] = str1[t]; // Swap the characters at the current indices of str1 and temp
                j++;              // Increment j
                t--;              // Decrement t
            }

            // Compare the reversed first string with the second string
            t = 0;
            int i = 0;
            while (i < temp.length) { // Iterate through the reversed first string
                if (temp[i] == str2[i]) { // Check if the corresponding characters are equal
                    t++; // Increment the counter if they are equal
                }
                i++; // Increment i
            }

            // Check if all characters are equal and print the result accordingly
            if (str2.length == t) {
                System.out.println("YES"); // If all characters are equal, print "YES"
            } else {
                System.out.println("NO"); // If any character is different, print "NO"
            }
        }
    }
}
