import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Taking input from the user
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Initializing left and right pointers for binary search
        int l = 1;
        int r = n;

        // Performing binary search to find the largest integer 'l' such that the sum of the first 'l' integers is less than or equal to 'n'
        while (l < r) {
            // Calculating the midpoint of the current range
            int mid = l + (r - l) / 2;

            // Calculating the sum of the first 'mid' integers using the formula: sum = mid * (mid + 1) / 2
            long idxcnt = (long) mid * (mid + 1) / 2;

            // If the sum is less than 'n', move the left pointer up to search in the right half
            if (idxcnt < n) {
                l = mid + 1;
            } 
            // Otherwise, move the right pointer down to search in the left half
            else {
                r = mid;
            }
        }

        // Adjusting 'l' to get the largest valid integer
        l -= 1;

        // Calculating the sum of the first 'l' integers
        long idxcnt = (long) l * (l + 1) / 2;

        // Printing the difference between 'n' and the sum of the first 'l' integers
        System.out.println(n - idxcnt);
        
        scanner.close();
    }
}
// <END-OF-CODE>
