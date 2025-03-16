
import java.util.*;
import java.lang.*;
import java.io.*;

class Ideone
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s[] = new String[n];
        for(int i=0;i<n;i++)
        {
            s[i] = sc.next();
        }
        int flag = 0;
        String d1[] = new String[n];
        String d2[] = new String[n];
        HashSet<String> rem = new HashSet<String>();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    d1[i] = s[i].substring(j,j+1);
                }
                if(i==n-j-1)
                {
                    d2[i] = s[i].substring(j,j+1);
                }
                if(i!=j && i!=n-j-1)
                {
                    rem.add(s[i].substring(j,j+1));
                }
            }
        }
        if(rem.size()>1)
        {
            System.out.println("NO");
        }
        else if(!Arrays.equals(d1,d2))
        {
            System.out.println("NO");
        }
        else if(Arrays.stream(d1).distinct().count()>1)
        {
            System.out.println("NO");
        }
        else if(Arrays.stream(d1).boxed().collect(Collectors.toSet()).equals(rem))
        {
            System.out.println("NO");
        }
        else
        {
            System.out.println("YES");
        }
    }
}

