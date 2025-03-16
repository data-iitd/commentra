
import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        System.out.print(s.charAt(0)+s.substring(1,s.length()-1).length()+s.charAt(s.length()-1));
    }
}

