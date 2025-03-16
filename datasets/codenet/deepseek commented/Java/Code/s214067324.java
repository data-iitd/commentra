
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Initialize Scanner to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read an integer input from the user
        int x = Integer.parseInt(sc.next());
        
        // Check if the input integer is less than 1200 and print "ABC" or "ARC" accordingly
        System.out.println(x < 1200 ? "ABC" : "ARC");
    }
}

