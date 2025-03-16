import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        int tap = 0;
        int consent = 1;
        while (consent < b) {
            consent = consent + a - 1;
            tap++;
        }
        System.out.println(tap);
    }
}

