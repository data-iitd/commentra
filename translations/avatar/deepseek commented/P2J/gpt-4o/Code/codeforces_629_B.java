import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Define the maximum number of time slots
        final int N = 368;

        // Initialize arrays to store changes for males and females
        int[] m = new int[N];
        int[] f = new int[N];

        // Read the number of operations
        int operations = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < operations; i++) {
            // Read each line and split into gender, start time, and end time
            String[] input = scanner.nextLine().trim().split(" ");
            String x = input[0];
            int a = Integer.parseInt(input[1]);
            int b = Integer.parseInt(input[2]) + 1;

            // Update the changes in the arrays based on gender
            if (x.equals("M")) {
                m[a] += 2;
                m[b] -= 2;
            } else {
                f[a] += 2;
                f[b] -= 2;
            }
        }

        // Initialize variables to store the maximum number of people and the current number of people
        int a = 0, b = 0, c = 0;

        // Calculate the cumulative sum of changes and find the maximum number of people at any time slot
        for (int i = 0; i < N; i++) {
            a += m[i];
            b += f[i];
            if (Math.min(a, b) > c) {
                c = Math.min(a, b);
            }
        }

        // Print the maximum number of people at any time slot
        System.out.println(c);
        
        scanner.close();
    }
}

// <END-OF-CODE>
