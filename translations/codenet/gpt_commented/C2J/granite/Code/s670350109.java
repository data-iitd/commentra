
import java.util.Scanner;

public class s670350109{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();

        int i, j = 0, t;

        // Check if the lengths of the two strings are different
        if(str1.length()!= str2.length())
        {
            // If lengths are different, they cannot be anagrams
            System.out.println("NO");
        }
        else
        {
            // Reverse the first string and store it in the temporary array
            char[] temp = str1.toCharArray();
            for(i = 0; i < temp.length / 2; i++)
            {
                char tempChar = temp[i];
                temp[i] = temp[temp.length - 1 - i];
                temp[temp.length - 1 - i] = tempChar;
            }

            // Reset counters for comparison
            t = 0;
            i = 0;

            // Compare the reversed string with the second string
            while(temp[i]!= '\0')
            {
                if(temp[i] == str2.charAt(i))
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
