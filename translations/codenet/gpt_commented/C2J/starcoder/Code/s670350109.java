
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1, str2, temp;
        int i, j = 0, t;

        // Read two strings from user input
        str1 = sc.next();
        str2 = sc.next();

        // Get the length of the first string and calculate the last index
        i = str1.length();
        t = i - 1;

        // Check if the lengths of the two strings are different
        if(str1.length()!= str2.length())
        {
            // If lengths are different, they cannot be anagrams
            System.out.println("NO");
        }
        else
        {
            // Reverse the first string and store it in the temporary array
            while(j < i)
            {
                temp = str1.charAt(j); // Copy characters from the end of str1 to temp
                j++;
                t--;
            }
            // Null-terminate the reversed string
            temp = temp + "\0"; // Ensure the reversed string is properly terminated

            // Reset counters for comparison
            t = 0;
            i = 0;

            // Compare the reversed string with the second string
            while(i < temp.length())
            {
                if(temp.charAt(i) == str2.charAt(i))
                {
                    t++; // Count matching characters
                }
                i++;
            }

            // Check if all characters matched
            if(str2.length() == t)
            {
                // If all characters match, the strings are anagrams
                System.out.println("YES");
            }
            else if(str2.length()!= t)
            {
                // If not all characters match, they are not anagrams
                System.out.println("NO");
            }
        }
    }
}

