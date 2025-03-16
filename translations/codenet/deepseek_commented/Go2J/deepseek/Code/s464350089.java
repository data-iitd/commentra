import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the initial height `h` and the number of attacks `n`
        int h = scanner.nextInt();
        int n = scanner.nextInt();

        // Initialize a variable to keep track of the total damage dealt
        int a = 0;

        // Read each attack's damage and accumulate the total damage
        for (int i = 0; i < n; i++) {
            a += scanner.nextInt();
        }

        // Check if the total damage is greater than or equal to the initial height
        if (h > a) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}

