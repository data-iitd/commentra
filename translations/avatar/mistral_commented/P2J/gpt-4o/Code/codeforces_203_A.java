import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Input the string of numbers separated by spaces and split it into an array
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] xxs = input.split(" ");

        // Extract the first six numbers as integers and assign them to variables x, t, a, b, da, db respectively
        int x = Integer.parseInt(xxs[0]);
        int t = Integer.parseInt(xxs[1]);
        int a = Integer.parseInt(xxs[2]);
        int b = Integer.parseInt(xxs[3]);
        int da = Integer.parseInt(xxs[4]);
        int db = Integer.parseInt(xxs[5]);

        // Call the main function
        String result = main(x, t, a, b, da, db);

        // If the result is "Result Not Found", print "NO"
        if (result.equals("Result Not Found")) {
            System.out.println("NO");
        }
    }

    // Define the main function to perform the logic of the program
    public static String main(int x, int t, int a, int b, int da, int db) {
        // Check if x is equal to zero
        if (x == 0) {
            // If yes, print "YES" and return
            System.out.println("YES");
            return "Result Found";
        }

        // Calculate the minimum time it takes for a and b to reach x
        int a_time = Math.min(a / da, t - 1);
        int b_time = Math.min(b / db, t - 1);

        // Loop through all possible combinations of a_time and b_time
        for (int i = 0; i <= a_time; i++) {
            for (int j = 0; j <= b_time; j++) {
                // Check if x is equal to a after 'i' time steps or b after 'j' time steps
                if (a - da * i == x || b - db * j == x) {
                    // If yes, print "YES" and return
                    System.out.println("YES");
                    return "Result Found";
                }

                // Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
                if ((a - da * i) + (b - db * j) == x) {
                    // If yes, print "YES" and return
                    System.out.println("YES");
                    return "Result Found";
                }
            }
        }
        return "Result Not Found";
    }
}
// <END-OF-CODE>
