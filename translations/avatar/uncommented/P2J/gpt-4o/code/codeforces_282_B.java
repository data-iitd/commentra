import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int firstline = Integer.parseInt(scanner.nextLine());
        int total = 0;
        List<String> memory = new ArrayList<>();

        for (int x = 0; x < firstline; x++) {
            String[] input = scanner.nextLine().split(" ");
            int A = Integer.parseInt(input[0]);
            int G = Integer.parseInt(input[1]);

            if (total + A <= 500) {
                total += A;
                memory.add("A");
            } else {
                total -= G;
                memory.add("G");
            }
        }

        // Join the memory list into a single string
        StringBuilder result = new StringBuilder();
        for (String s : memory) {
            result.append(s);
        }
        
        System.out.println(result.toString());
        scanner.close();
    }
}

// <END-OF-CODE>
