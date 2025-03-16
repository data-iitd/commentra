import java.util.Scanner;

public class Main {
    public static int nextInt() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    public static int[] nextInts() {
        Scanner scanner = new Scanner(System.in);
        String[] parts = scanner.nextLine().split(" ");
        int[] numbers = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            numbers[i] = Integer.parseInt(parts[i]);
        }
        return numbers;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = nextInt();
        int t = 0;
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 2 == 1) {
                t += 1;
            }
        }
        System.out.println((double) t / n);
    }
}
