import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int[] ABC = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            ABC[i] = Integer.parseInt(input[i]);
        }

        // Check if the array contains exactly two 5s
        int count = 0;
        for (int num : ABC) {
            if (num == 5) {
                count++;
            }
        }

        // Check if the sum of the elements in ABC is 17
        int sum = 0;
        for (int num : ABC) {
            sum += num;
        }

        if (count == 2 && sum == 17) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
