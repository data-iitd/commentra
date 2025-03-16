import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String[] input = scanner.nextLine().split(" ");
        int k = Integer.parseInt(input[0]);
        int n = Integer.parseInt(input[1]);
        int w = Integer.parseInt(input[2]);
        
        if (1 <= k && w <= 1000) {
            int total = 0;
            for (int i = 1; i <= w; i++) {
                total += i * k;
            }
            if (total > n) {
                System.out.println(total - n);
            } else {
                System.out.println(0);
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
