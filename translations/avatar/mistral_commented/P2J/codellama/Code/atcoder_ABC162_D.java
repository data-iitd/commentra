
// Import the java.util.Scanner class to use the Scanner class
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        // Create a Scanner object to read input from stdin
        Scanner scan = new Scanner(System.in);

        // Read an integer input N and a string input S from stdin
        int N = scan.nextInt();
        String S = scan.next();

        // Define a function calculate that takes two arguments: an integer n and a string s
        calculate(N, S);
    }

    public static void calculate(int n, String s) {
        // Create a char array arr from the string s
        char[] arr = s.toCharArray();

        // Count the number of occurrences of each color in the array arr and store them in variables rNum, gNum, and bNum
        int rNum = 0;
        int gNum = 0;
        int bNum = 0;
        for (char c : arr) {
            if (c == 'R') {
                rNum++;
            } else if (c == 'G') {
                gNum++;
            } else if (c == 'B') {
                bNum++;
            }
        }

        // Initialize a variable sum to 0
        int sum = 0;

        // Use a for loop to iterate through each step from 1 to the ceiling of N/2
        for (int step = 1; step <= (int) Math.ceil(n / 2.0); step++) {
            // Inside the inner for loop, join three consecutive elements of the array arr to form a string s
            String s = "";
            for (int i = 0; i < 3; i++) {
                s += arr[i];
            }

            // Check if the string s is equal to any of the six possible color combinations: "RGB", "RBG", "BGR", "BRG", "GBR", or "GRB"
            if (s.equals("RGB") || s.equals("RBG") || s.equals("BGR") || s.equals("BRG") || s.equals("GBR") || s.equals("GRB")) {
                sum++;
            }
        }

        // After the inner for loop, print the result of the calculation: rNum * gNum * bNum - sum
        System.out.println(rNum * gNum * bNum - sum);
    }
}

