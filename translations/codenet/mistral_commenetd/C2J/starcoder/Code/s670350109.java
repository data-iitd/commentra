
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in); // Create a Scanner object

        String str1, str2, temp; // Declare three String variables
        int i, j = 0, t; // Declare integer variables i, j, and t

        str1 = sc.next(); // Read the first string from the user
        System.out.println("First string: " + str1); // Print the first string for verification

        str2 = sc.next(); // Read the second string from the user
        System.out.println("Second string: " + str2); // Print the second string for verification

        i = str1.length(); // Get the length of the first string
        t = i - 1; // Set the index variable t to the last index of the first string

        // Check if the lengths of the two strings are equal
        if (str1.length()!= str2.length())
        {
            System.out.println("NO"); // If the lengths are not equal, print "NO" and exit
        }
        else
        {
            // Reverse the first string and store it in temp String
            j = 0;
            while (j < i)
            {
                temp = str1.substring(j, j + 1); // Swap the characters at the current indices of str1 and temp
                j++; // Increment j
                t--; // Decrement t
            }
            // Compare the reversed first string with the second string
            t = 0;
            i = 0;
            while (i < i) // Iterate through the reversed first string
            {
                if (temp.charAt(i) == str2.charAt(i)) // Check if the corresponding characters are equal
                {
                    t++; // Increment the counter if they are equal
                }
                i++; // Increment i
            }

            // Check if all characters are equal and print the result accordingly
            if (str2.length() == t)
            {
                System.out.println("YES"); // If all characters are equal, print "YES"
            }
            else if (str2.length()!= t)
            {
                System.out.println("NO"); // If any character is different, print "NO"
            }
        }
    }
}

