import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] input = scanner.nextLine().split(" ");
        int[] arr = new int[n];
        
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        
        if (arr[0] > 15) {
            System.out.println(15);
        } else {
            for (int i = 1; i < arr.length; i++) {
                if (arr[i] - arr[i - 1] > 15) {
                    System.out.println(arr[i - 1] + 15);
                    break;
                }
            }
            if (arr[arr.length - 1] == 90 || arr[arr.length - 1] + 15 >= 90) {
                System.out.println(90);
            } else {
                System.out.println(arr[arr.length - 1] + 15);
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
