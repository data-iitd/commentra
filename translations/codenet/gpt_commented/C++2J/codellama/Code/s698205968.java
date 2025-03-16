import java.util.Scanner;

public class GradeCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Declare variables to hold marks for midterm, final, and retake
        int m, f, r;

        // Continuously read input until the termination condition is met
        while (sc.hasNextInt()) {
            // Read input for midterm, final, and retake
            m = sc.nextInt();
            f = sc.nextInt();
            r = sc.nextInt();

            // Check if either midterm or final score is -1, indicating failure
            if (m == -1 || f == -1) 
                System.out.println("F"); // Output "F" for failure
            // Check if the total score is 80 or more for grade A
            else if (m + f >= 80) 
                System.out.println("A"); // Output "A" for excellent performance
            // Check if the total score is between 65 and 79 for grade B
            else if (m + f >= 65) 
                System.out.println("B"); // Output "B" for good performance
            // Check if the total score is between 50 and 64 or retake score is 50 or more for grade C
            else if (m + f >= 50 || r >= 50) 
                System.out.println("C"); // Output "C" for satisfactory performance
            // Check if the total score is between 30 and 49 for grade D
            else if (m + f >= 30) 
                System.out.println("D"); // Output "D" for passing but needs improvement
            // If none of the above conditions are met, output "F"
            else 
                System.out.println("F"); // Output "F" for failure
        }

        sc.close(); // Close the scanner
    }
}

