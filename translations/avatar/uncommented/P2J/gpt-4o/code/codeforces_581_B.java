import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = Integer.parseInt(scanner.nextLine());
        String[] input = scanner.nextLine().strip().split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        
        int[] ans = new int[n];
        int mx = arr[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = Math.max(0, mx - arr[i] + 1);
            if (arr[i] > mx) {
                mx = arr[i];
            }
        }
        
        for (int i = 0; i < n; i++) {
            System.out.print(ans[i] + " ");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
