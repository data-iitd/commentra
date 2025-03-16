import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int c = 0;
        
        for (int i = 0; i < n; i++) {
            String[] input = scanner.nextLine().split(" ");
            int[] l1 = new int[input.length];
            for (int j = 0; j < input.length; j++) {
                l1[j] = Integer.parseInt(input[j]);
            }
            if (sumArray(l1) > 1) {
                c++;
            }
        }
        System.out.println(c);
    }

    public static int sumArray(int[] array) {
        int sum = 0;
        for (int num : array) {
            sum += num;
        }
        return sum;
    }
}
