

import java.util.Scanner;

public class codeforces_25_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input representing the number of elements
        int[] list = new int[n];  // Create an array to store the elements
        for (int i = 0; i < n; i++) {
            list[i] = scanner.nextInt() % 2;  // Read the input elements, calculate remainders modulo 2, and store in the array
        }

        int sum = 0;  // Initialize the sum variable
        for (int i = 0; i < n; i++) {
            sum += list[i];  // Calculate the sum of the array
        }

        if (sum == 1) {  // Check if the sum of the list is 1
            for (int i = 0; i < n; i++) {
                if (list[i] == 1) {  // If the sum is 1, print the index of the first occurrence of 1 (adjusted for 0-based indexing)
                    System.out.println(i + 1);
                    break;
                }
            }
        } else {  // If the sum is not 1, print the index of the first occurrence of 0 (adjusted for 0-based indexing)
            for (int i = 0; i < n; i++) {
                if (list[i] == 0) {
                    System.out.println(i + 1);
                    break;
                }
            }
        }
    }
}