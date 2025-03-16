import java.util.*;
public class HelloWorld {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a,b,c;
        a = in.nextInt();
        b = in.nextInt();
        c = in.nextInt();
        if(a<b&&b<c)
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
    }
}
