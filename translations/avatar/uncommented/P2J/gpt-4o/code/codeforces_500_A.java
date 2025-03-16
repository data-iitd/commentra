import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int t = scanner.nextInt();
        int[] s = new int[n];
        
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }
        
        int currentCell = 1; // Start from cell 1 (1-based index)
        
        while (currentCell < t) {
            currentCell += s[currentCell - 1];
        }
        
        if (currentCell == t) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
