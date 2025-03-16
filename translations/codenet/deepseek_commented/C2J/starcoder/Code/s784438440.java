import java.util.*;
public class HelloWorld {

    public static void main(String[] args) {
        // Read two integers a and b from the user
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        // Compute a value based on these inputs
        int c = (b-1)+(a-2);
        int d = a-1;
        int e = c/d;
        
        // Print the computed value
        System.out.println(e);
    }
}
