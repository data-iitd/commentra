import java.util.*;
import java.lang.*;
import java.io.*;
class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc=new Scanner(System.in);
        long a=sc.nextLong();
        long b=sc.nextLong();
        long x=sc.nextLong();
        long s=(b/x-a/x);
        if(a%x==0)s++;
        System.out.println(s);
    }
}
