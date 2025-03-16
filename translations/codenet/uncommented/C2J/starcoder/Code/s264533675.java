
import java.util.*;
public class HelloWorld
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        str = str.substring(0,5) + " " + str.substring(5,13) + " " + str.substring(13,21);
        System.out.println(str);
    }
}
