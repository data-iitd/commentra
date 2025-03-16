
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  int a[]=new int[1000];
  int n,i,j,d=0;
  Scanner sc=new Scanner(System.in);
  n=sc.nextInt();
  for(i=0;i<n;i++)
   a[i]=sc.nextInt();
  for (i = 0;i<n;i++)
  {   
     for (j = n-1;j>= i+1;j--)
     {
        if (a[j] < a[j-1])
        {
          int temp=a[j];
          a[j]=a[j-1];
          a[j-1]=temp;
          d++;
        }
     }
  }
  System.out.print(a[0]);
  for(i=1;i<n;i++)
  {
   System.out.print(" "+a[i]);
  }
  System.out.println();
  System.out.println(d);
 }
}
