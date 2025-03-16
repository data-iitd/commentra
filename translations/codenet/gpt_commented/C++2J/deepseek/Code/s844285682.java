public class TimeConverter {
    public static void main(String[] args) {
        int a; // Declare an integer variable a
        
        // Read an integer input from the user, which represents time in seconds
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        
        // Calculate and display the time in hours, minutes, and seconds
        // a/(60*60) calculates the number of hours
        // a%(60*60)/60 calculates the number of minutes
        // a%(60*60)%60 calculates the remaining seconds
        System.out.println(a/(60*60) + ":" + a%(60*60)/60 + ":" + a%(60*60)%60);
    }
}
