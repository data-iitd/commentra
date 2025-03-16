
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int ans = 0;
        ans += n*(n-1)/2;
        ans += m*(m-1)/2;
        System.out.println(ans);
    }
}

