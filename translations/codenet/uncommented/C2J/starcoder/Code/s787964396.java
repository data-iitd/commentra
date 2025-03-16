import java.util.*;
public class CountingSort{
  public static void main(String[] args){
    int n,i,max=0;
    Scanner sc=new Scanner(System.in);
    n=sc.nextInt();
    int a[]=new int[n+1];
    int b[]=new int[n+1];
    for(i=0;i<n;i++)a[i+1]=sc.nextInt();
    CountingSort(a,b,n);
    System.out.print(b[1]);
    for(i=2;i<n+1;i++)System.out.print(" "+b[i]);
    System.out.println();
  }
  public static void CountingSort(int a[],int b[],int k){
    int c[]=new int[I],i,j;
    for(i=0;i<=I;i++)c[i]=0;
    for(j=0;j<k;j++)c[a[j+1]]++;
    for(i=1;i<I+1;i++)c[i]+=c[i-1];
    for(j=k;0<j;j--){
      b[c[a[j]]]=a[j];
      c[a[j]]--;
    }
  }
}
