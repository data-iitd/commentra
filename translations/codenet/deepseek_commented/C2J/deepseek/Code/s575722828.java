public class TimeConverter {
    public static void main(String[] args) {
        int S; // Step 3: Declare an integer variable S

        java.util.Scanner scanner = new java.util.Scanner(System.in); // Step 4: Create a Scanner object to read input
        S = scanner.nextInt(); // Step 4: Read an integer value from the user and store it in S

        System.out.printf("%d:%d:%d\n", S / 3600, (S % 3600) / 60, S % 60); // Step 5: Calculate hours, minutes, and seconds from the total seconds S
                                                                          // Step 6: Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"
    }
}
