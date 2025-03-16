import java.util.Scanner; // We import the Scanner class to read input from the user

public class Main { // We define the Main class
    public static void main(String[] args) { // The main method where the program execution begins
        Scanner scanner = new Scanner(System.in); // We create a Scanner object to read input
        int n; // We declare an integer variable 'n' to store the number of elements in the strings
        String a, b, c; // We declare three string variables 'a', 'b', and 'c' to store the input strings
        int ans = 0; // We initialize an integer variable 'ans' to 0 to store the answer

        n = scanner.nextInt(); // We read the number of elements in the strings from the standard input
        a = scanner.next(); // We read the first string 'a' from the standard input
        b = scanner.next(); // We read the second string 'b' from the standard input
        c = scanner.next(); // We read the third string 'c' from the standard input

        for (int i = 0; i < n; i++) { // We start a for loop that iterates from 0 to 'n'-1
            if (a.charAt(i) == b.charAt(i) && b.charAt(i) == c.charAt(i)) { // We check if all three characters at the current index are equal
                // Do nothing
            } else if (a.charAt(i) == b.charAt(i) || b.charAt(i) == c.charAt(i) || a.charAt(i) == c.charAt(i)) { // We check if any two of the three characters are equal
                ans++; // If so, we increment the answer by 1
            } else { // If none of the above conditions are met, we increment the answer by 2
                ans += 2;
            }
        }
        System.out.println(ans); // We print the answer to the standard output
        scanner.close(); // We close the scanner to free up resources
    }
}

// <END-OF-CODE>
