public class TimeDifference {
    public static void main(String[] args) {
        int h1, h2, m1, m2, k;
        
        // Input the values of hours and minutes for the first and second time
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        System.out.print("Enter hours and minutes for the first time: ");
        h1 = scanner.nextInt();
        m1 = scanner.nextInt();

        System.out.print("Enter hours and minutes for the second time: ");
        h2 = scanner.nextInt();
        m2 = scanner.nextInt();

        int ans = h2 * 60 + m2; // Calculate the total minutes of the second time
        System.out.println("The total minutes of the second time are: " + ans);

        ans -= (h1 * 60 + m1); // Subtract the total minutes of the first time from the total minutes of the second time
        System.out.println("The difference in minutes is: " + ans);

        System.out.print("Enter the difference in minutes: ");
        k = scanner.nextInt();
        ans -= k; // Subtract the given difference 'k' from the difference in minutes
        System.out.println("The difference in minutes after subtracting " + k + " is: " + ans);

        // Convert the difference in minutes to hours and minutes
        int hours = ans / 60;
        int minutes = ans % 60;

        System.out.println(hours + " hours and " + minutes + " minutes"); // Output the result
    }
}
