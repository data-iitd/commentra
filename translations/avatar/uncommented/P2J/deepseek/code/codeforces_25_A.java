import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        String[] input = scanner.nextLine().split(" ");
        int[] list = new int[n];
        
        for (int i = 0; i < n; i++) {
            list[i] = Integer.parseInt(input[i]) % 2;
        }
        
        if (sum(list) == 1) {
            for (int i = 0; i < n; i++) {
                if (list[i] == 1) {
                    System.out.println(i + 1);
                    break;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (list[i] == 0) {
                    System.out.println(i + 1);
                    break;
                }
            }
        }
    }
    
    public static int sum(int[] arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        return sum;
    }
}
