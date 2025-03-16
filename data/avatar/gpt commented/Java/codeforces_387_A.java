import java.io.IOException; // Importing IOException for handling input/output exceptions
import java.time.LocalTime; // Importing LocalTime class to work with time
import java.util.*; // Importing utility classes for using Scanner

public class Main {
    public static void main(String[] args) throws IOException { // Main method that throws IOException
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input from the console
        
        // Reading two time inputs in "HH:MM" format and splitting them into hours and minutes
        String[] s = sc.next().split(":"); 
        String[] t = sc.next().split(":"); 
        
        // Creating LocalTime objects from the input strings for the first and second time
        LocalTime x = LocalTime.of(Integer.parseInt(s[0]), Integer.parseInt(s[1])); 
        LocalTime y = LocalTime.of(Integer.parseInt(t[0]), Integer.parseInt(t[1])); 
        
        // Calculating the difference between the two times and printing the result
        System.out.println(x.minusHours(y.getHour()).minusMinutes(y.getMinute())); 
    }
}
