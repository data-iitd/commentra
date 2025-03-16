import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n and x
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int x = Integer.parseInt(input[1]);
        
        // Read the array and sort it
        int[] a = new int[n];
        String[] arrayInput = scanner.nextLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(arrayInput[i]);
        }
        Arrays.sort(a);
        
        int ans = 0;
        
        if (a[0] > x) {
            System.out.println(0);
            return;
        }
        
        for (int i : a) {
            if (i > x) {
                x = 0;
                break;
            }
            x -= i;
            ans++;
        }
        
        if (x != 0) {
            ans--;
        }
        
        System.out.println(ans);
    }
}
// <END-OF-CODE>
