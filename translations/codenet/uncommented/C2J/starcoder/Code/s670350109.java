import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String str1=sc.next();
        String str2=sc.next();
        int i,j=0,t;
        i=str1.length();
        t=i-1;
        if(str1.length()!=str2.length())
        {
            System.out.println("NO");
        }
        else
        {
            while(j<str1.length())
            {
                System.out.print(str1.charAt(t));
                j++;
                t--;
            }
            t=0;
            i=0;
            while(i<str2.length())
            {
                if(str1.charAt(i)==str2.charAt(i))
                {
                    t++;
                }
                i++;
            }
            if(str2.length()==t)
            {
                System.out.println("YES");
            }
            else if(str2.length()!=t)
            {
                System.out.println("NO");
            }
        }
    }
}
