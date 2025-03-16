import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline left-over

        String[] input = scanner.nextLine().split(" ");
        List<Integer> list = new ArrayList<>();

        for (String s : input) {
            int num = Integer.parseInt(s);
            list.add(num % 2);
        }

        if (list.stream().mapToInt(Integer::intValue).sum() == 1) {
            System.out.println("The first number with remainder 1 is: " + (list.indexOf(1) + 1));
        } else {
            System.out.println("The first number with remainder 0 is: " + (list.indexOf(0) + 1));
        }
    }
}

