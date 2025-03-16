import java.util.*; // Importing the necessary classes from the java.util package

public class Main {
    public static void main(String[] args) throws Exception {
        // Creating a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Reading a string input from the user
        String str = sc.next();
        
        // Converting the string to a character array for easier manipulation
        char[] c = str.toCharArray();
        
        // Reading a long integer input from the user
        long k = sc.nextLong();
        
        // Getting the length of the input string
        int n = str.length();
        
        // Looping through the first k characters of the character array
        for (int i = 0; i < k; i++) {
            // Checking if the current character is '1'
            if (c[i] == '1') {
                // If it's the last character in the range, print 1 and exit
                if (i == k - 1) {
                    System.out.println(1);
                    return; // Exit the program
                }
            } else {
                // If the current character is not '1', print it and exit
                System.out.println(c[i]);
                return; // Exit the program
            }
        }
    }
}
