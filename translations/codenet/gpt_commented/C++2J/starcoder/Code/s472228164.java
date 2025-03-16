import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        System.out.println(check(x, y));
    }

    // Function to check certain conditions based on input values x and y
    public static String check(int x, int y)
    {
        // Check if y is an even number
        if(y % 2 == 0)
        {
            // Calculate t as half of y minus x
            int t = (int)(0.5*y) - x;
            
            // Check if t is non-negative and if (x - t) is also non-negative
            if(t >= 0 && (x-t) >= 0)
                return "Yes"; // Return "Yes" if both conditions are satisfied
        }
        return "No"; // Return "No" if y is odd or conditions are not satisfied
    }
}
