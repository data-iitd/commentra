
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String mes = sc.next();

        // Logic starts here

        System.out.println(mes.charAt(0) + (mes.length()-2) + mes.charAt(mes.length()-1));
    }
}

