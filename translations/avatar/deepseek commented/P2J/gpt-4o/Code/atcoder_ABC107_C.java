import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading N and K from input
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Reading the list of integers
        List<Integer> lst = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            lst.add(scanner.nextInt());
        }
        
        List<Integer> lst_p = new ArrayList<>(); // List to store positive numbers
        List<Integer> lst_m = new ArrayList<>(); // List to store negative numbers

        // Separating positive and negative numbers
        for (int i = 0; i < N; i++) {
            if (lst.get(i) == 0) {
                K--; // Decrement K if the number is 0
            }
            if (lst.get(i) > 0) {
                lst_p.add(lst.get(i)); // Add positive numbers to lst_p
            } else if (lst.get(i) < 0) {
                lst_m.add(lst.get(i)); // Add negative numbers to lst_m
            }
        }

        // Initialization of pointers and variables
        int lastx = lst_p.size(); // Last index of lst_p
        int lasty = lst_m.size(); // Last index of lst_m

        // Function to check the minimum possible value
        System.out.println(check(lst_p, lst_m, K, lastx, lasty));
    }

    private static int check(List<Integer> lst_p, List<Integer> lst_m, int k, int lastx, int lasty) {
        int ans = (int) 1e9; // Initialize answer with a large number
        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) { // Check if indices are out of bounds
                continue;
            } else {
                int p = (j == 0) ? 0 : lst_p.get(j - 1); // Get the (j-1)th positive number
                int m = (k - j == 0) ? 0 : lst_m.get(lasty - (k - j)); // Get the (lasty - (k - j))th negative number
                ans = Math.min(ans, 2 * p + Math.abs(m)); // Calculate the minimum value
                ans = Math.min(ans, p + 2 * Math.abs(m)); // Calculate the minimum value
            }
        }
        return ans;
    }
}

// <END-OF-CODE>
