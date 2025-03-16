import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.next();
        String str2 = scanner.next();

        // Sort the first string in ascending order
        char[] arr1 = str1.toCharArray();
        Arrays.sort(arr1);
        str1 = new String(arr1);

        // Sort the second string in descending order
        char[] arr2 = str2.toCharArray();
        Arrays.sort(arr2);
        String str2Desc = new String(arr2);
        StringBuilder sb = new StringBuilder(str2Desc);
        str2Desc = sb.reverse().toString();

        // Determine the loop limit based on the length of the shorter string
        int loop = Math.min(str1.length(), str2Desc.length());
        boolean flag = false;

        // Compare characters of the two sorted strings
        for (int i = 0; i < loop; i++) {
            char ch1 = str1.charAt(i);
            char ch2 = str2Desc.charAt(i);

            // If characters match, continue to the next character
            if (ch1 == ch2) {
                if (i == loop - 1 && str1.length() < str2Desc.length()) {
                    flag = true;
                    break;
                }
            } else {
                // If characters do not match, check if the character from the second string is greater
                if (ch2 > ch1) {
                    flag = true;
                    break;
                } else {
                    break;
                }
            }
        }

        // Check the flag and print the result
        if (flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
