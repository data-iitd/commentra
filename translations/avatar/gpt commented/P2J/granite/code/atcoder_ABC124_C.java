
import java.util.Scanner;  // Import the Scanner class for input
import java.util.HashMap;  // Import the HashMap class for counting elements

public class atcoder_ABC124_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input
        String s = scanner.nextLine();  // Read the input string

        HashMap<Character, Integer> even = new HashMap<>();  // Create a HashMap to count the occurrences of '0' and '1' at even indices
        HashMap<Character, Integer> odd = new HashMap<>();  // Create a HashMap to count the occurrences of '0' and '1' at odd indices

        for (int i = 0; i < s.length(); i++) {  // Iterate over each character in the input string
            char c = s.charAt(i);  // Get the current character
            if (i % 2 == 0) {  // If the index is even
                even.put(c, even.getOrDefault(c, 0) + 1);  // Increment the count of the current character in the even HashMap
            } else {  // If the index is odd
                odd.put(c, odd.getOrDefault(c, 0) + 1);  // Increment the count of the current character in the odd HashMap
            }
        }

        int option1 = s.length() - (even.getOrDefault('0', 0) + odd.getOrDefault('1', 0));  // Calculate the number of changes needed for Option 1
        int option2 = s.length() - (even.getOrDefault('1', 0) + odd.getOrDefault('0', 0));  // Calculate the number of changes needed for Option 2

        System.out.println(Math.min(option1, option2));  // Print the minimum of the two options
    }
}
