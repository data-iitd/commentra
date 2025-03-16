import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Reading N from input
        int K = scanner.nextInt();  // Reading K from input
        List<Integer> lst = new ArrayList<>();  // List to store integers
        for (int i = 0; i < N; i++) {
            lst.add(scanner.nextInt());  // Reading the list of integers
        }
        List<Integer> lst_p = new ArrayList<>();  // List to store positive numbers
        List<Integer> lst_m = new ArrayList<>();  // List to store negative numbers

        // Separating positive and negative numbers
        for (int i = 0; i < N; i++) {
            if (lst.get(i) == 0) {
                K--;  // Decrement K if the number is 0
            }
            if (lst.get(i) > 0) {
                lst_p.add(lst.get(i));  // Add positive numbers to lst_p
            } else if (lst.get(i) < 0) {
                lst_m.add(lst.get(i));  // Add negative numbers to lst_m
            }
        }

        // Initialization of pointers and variables
        int p = 0;  // Pointer for positive numbers
        int m = 0;  // Pointer for negative numbers
        int x = 0, y = lst_m.size() - 1;  // Pointers for traversing lists
        int lastx = lst_p.size();  // Last index of lst_p
        int lasty = lst_m.size();  // Last index of lst_m

        // Function to check the minimum possible value
        int check(int k) {
            int ans = (int) Math.pow(10, 9);  // Initialize answer with a large number
            for (int j = 0; j <= k; j++) {
                if (j > lastx || k - j > lasty) {  // Check if indices are out of bounds
                    continue;
                } else {
                    if (j == 0) {
                        p = 0;  // If no positive number is chosen, p is 0
                    } else {
                        p = lst_p.get(j - 1);  // Get the (j-1)th positive number
                    }
                    if (k - j == 0) {
                        m = 0;  // If no negative number is chosen, m is 0
                    } else {
                        m = lst_m.get(lasty - (k - j));  // Get the (lasty - (k - j))th negative number
                    }
                    ans = Math.min(ans, 2 * p + Math.abs(m), p + 2 * Math.abs(m));  // Calculate the minimum value
                }
            }
            return ans;
        }

        // Output the result of the check function with K as the argument
        System.out.println(check(K));
    }
}
