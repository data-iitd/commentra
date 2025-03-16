import java.util.Scanner; // Importing the Scanner class for reading input from the console

class Main {
    public static void main(String[] args) { // Main method where the execution of the program starts
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the console
        int n = sc.nextInt(); // Reading the number of strings to be processed and storing it in the variable 'n'

        String[] s = ".,!? :abc:def:ghi:jkl:mno:pqrs:tuv:wxyz".split(":"); // Splitting the string into an array of substrings using ':' as the delimiter and storing it in the variable 's'
        char[][] k = new char[9][]; // Creating a 2D character array 'k' of size 9xN where N is the length of the longest substring in the 's' array

        for (int i = 0; i < 9; i++) { // Loop to initialize the 'k' array with the characters of each substring in 's'
            k[i] = s[i].toCharArray();
        }

        while (n-- > 0) { // Loop to process each string
            char[] c = sc.next().toCharArray(); // Reading the next string from the console and converting it to a character array

            int l = -1, a = 0; // Initializing the index variables 'l' and 'a'

            for (int i = 0; i < c.length; i++) { // Loop to process each character in the character array 'c'
                if (c[i] != '0') { // Checking if the character is not '0'
                    a = c[i] - '1'; // Finding the index of the corresponding character in the 'k' array based on the ASCII value of the character
                    l = (l + 1) % k[a].length; // Incrementing the index 'l' by 1 and taking the modulo with the length of the substring to cycle through it
                } else if (l >= 0) { // Checking if the index 'l' is not -1 (i.e., we have reached a non-zero character)
                    System.out.print(k[a][l]); // Printing the character at the index 'l' of the substring corresponding to the non-zero character
                    l = -1; // Resetting the index 'l' to -1 to prepare for the next non-zero character
                }
            }
            System.out.println(); // Printing a newline after processing each string
        }
    }
}
