import java.util.*;
public class Main{
  public static void main(String args[]){
    int i,n,s[],q,t,count=0;
    Scanner sc=new Scanner(System.in);
    n=sc.nextInt();
    s=new int[n];
    for(i=0;i<n;i++){
      s[i]=sc.nextInt();
    }
    q=sc.nextInt();
    for(i=0;i<q;i++){
      t=sc.nextInt();
      if( linersearch(s,n,t) ) count++;
    }
    System.out.println(count);
  }
  public static boolean linersearch(int a[],int n,int key){
    int i=0;
    a[n]=key;
    while(a[i]!=key){
      i++;
    }
    return i!=n;
  }
}
