import java.util.Scanner;

public class HeightHistogram {
    public static void main(String[] args) {
        // Declare variables
        int n, i, j; // n: number of heights, i, j: loop counters
        int[] fd = new int[6]; // fd: array to store counts
        double height; // height: variable to store each height input

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read the number of heights
        n = scanner.nextInt();
        
        // Loop to read each height and categorize it
        while (n-- > 0) {
            height = scanner.nextDouble();
            if (height >= 185.0) fd[5]++;
            else if (height >= 180.0) fd[4]++;
            else if (height >= 175.0) fd[3]++;
            else if (height >= 170.0) fd[2]++;
            else if (height >= 165.0) fd[1]++;
            else fd[0]++;
        }

        // Loop to print the histogram
        for (i = 0; i < 6; i++) {
            System.out.print((i + 1) + ":");
            for (j = 0; j < fd[i]; j++)
                System.out.print('*');
            System.out.println();
        }

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
