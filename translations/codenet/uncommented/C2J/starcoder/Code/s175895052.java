
import java.util.*;
public class HelloWorld {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String n = in.next();
        if(((n.charAt(0)==n.charAt(1))&&(n.charAt(1)==n.charAt(2)))||((n.charAt(1)==n.charAt(2))&&(n.charAt(2)==n.charAt(3))))
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
    }
}
