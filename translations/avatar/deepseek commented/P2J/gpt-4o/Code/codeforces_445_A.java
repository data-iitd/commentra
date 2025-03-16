import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        char[][] grid = new char[n][m];
        
        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();
            for (int j = 0; j < m; j++) {
                if (s.charAt(j) == '.') {
                    if ((i + j) % 2 == 1) {
                        grid[i][j] = 'W';
                    } else {
                        grid[i][j] = 'B';
                    }
                } else {
                    grid[i][j] = s.charAt(j); // Keep the original character if it's not a dot
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            System.out.println(new String(grid[i]));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
