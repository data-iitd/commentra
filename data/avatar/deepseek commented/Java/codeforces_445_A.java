import java.io.*; // Importing the necessary classes for input/output operations

public class Main {
    public static void main(String[] args) throws IOException { // Main method to execute the program
        BufferedReader buf = new BufferedReader(new InputStreamReader(System.in)); // Creating a BufferedReader to read input from the console
        String[] inp = buf.readLine().split(""); // Reading the first line and splitting it into an array of characters
        int n = Integer.parseInt(inp[0]); // Extracting the integer n from the input array
        int m = Integer.parseInt(inp[1]); // Extracting the integer m from the input array

        String[] ans = new String[n]; // Initializing an array to store the resulting strings

        for (int i = 0; i < n; i++) { // Looping through each row
            String str = buf.readLine(); // Reading the current row as a string
            StringBuilder temp = new StringBuilder(""); // Creating a StringBuilder to build the resulting string for the current row

            for (int j = 0; j < m; j++) { // Looping through each character in the row
                if (str.charAt(j) == '-') { // Checking if the character is a '-'
                    temp.append("-"); // Appending '-' to the StringBuilder
                } else {
                    if ((i + j) % 2 == 1) { // Checking if the sum of indices is odd
                        temp.append("W"); // Appending 'W' if the sum is odd
                    } else {
                        temp.append("B"); // Appending 'B' if the sum is even
                    }
                }
            }
            ans[i] = temp.toString(); // Converting the StringBuilder to a string and storing it in the ans array
        }

        for (int i = 0; i < n; i++) { // Looping through each row again to print the results
            System.out.println(ans[i]); // Printing the resulting string for the current row
        }
    }
}
