import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt();
        }
        sc.close();

        // Sort the list in ascending order
        java.util.Arrays.sort(l);

        // Iterate through each element in the sorted list
        for (int i = 0; i < n; i++) {
            // Check if both l[i] + 1 and l[i] + 2 exist in the list
            if (i + 1 < n && l[i] + 1 == l[i + 1] && i + 2 < n && l[i] + 2 == l[i + 2]) {
                // If the condition is met, print 'YES' and exit the loop
                System.out.println("YES");
                break;
            }
        }
        // If the loop completes without finding the condition, print 'NO'
        if (i == n) {
            System.out.println("NO");
        }
    }
}

