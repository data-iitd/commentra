import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking two inputs from the user and converting them into integers
        int v1 = scanner.nextInt();
        int v2 = scanner.nextInt();
        int t = scanner.nextInt();
        int d = scanner.nextInt();
        
        // Initializing variables
        int a = 1;
        int v = v1;
        int distance = 0;

        // Entering a loop that runs `t` times
        for (int i = 0; i < t; i++) {
            // Checking if the current speed `v` minus `v2` is greater than `(t - i - 1) * d`
            if (v - v2 > (t - i - 1) * d) {
                a *= -1;
                v = (t - i - 1) * d + v2;
            }
            // Adding the current speed `v` to `distance`
            distance += v;
            // Updating the speed by adding `a * d` to it
            v += a * d;
        }

        // Printing the total `distance`
        System.out.println(distance);
        
        scanner.close();
    }
}

// <END-OF-CODE>
