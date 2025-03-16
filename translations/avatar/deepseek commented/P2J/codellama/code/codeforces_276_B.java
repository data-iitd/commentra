import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int[] dt = new int[26];
        int cnt = 0;
        boolean x = true;

        // Iterate over each character in the input string and update the frequency count in the array
        for (int i = 0; i < s.length(); i++) {
            dt[s.charAt(i) - 'a']++;
        }

        // Iterate over the items in the array to determine if there is more than one character with an odd frequency
        for (int i = 0; i < 26; i++) {
            if (dt[i] % 2 != 0 && cnt < 1) {
                cnt++;
            } else if (dt[i] % 2 != 0 && cnt >= 1) {
                x = false;
                break;
            }
        }

        // Determine the output based on the value of cnt and the length of the input string
        if (x) {
            System.out.println("First");
        } else if (!x && s.length() % 2 == 0) {
            System.out.println("Second");
        } else if (!x && s.length() % 2 != 0) {
            System.out.println("First");
        }
    }
}

