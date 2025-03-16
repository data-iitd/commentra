
import java.util.*;

public class s628121241{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt(); // Read the rating from standard input

        // Determine the category based on the rating value
        if (R < 1200) 
            System.out.println("ABC"); // Output "ABC" for ratings less than 1200
        else if (R >= 2800) 
            System.out.println("AGC"); // Output "AGC" for ratings 2800 and above
        else 
            System.out.println("ARC"); // Output "ARC" for ratings between 1200 and 2800
    }
}
