import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    String[] t=new String[n];
    String[] h=new String[n];
    for(int i=0;i<n;i++){
      t[i]=sc.next();
      h[i]=sc.next();
      if(t[i].compareTo(h[i])<0) System.out.println(3);
      if(t[i].compareTo(h[i])>0) System.out.println(3);
      if(t[i].compareTo(h[i])==0) System.out.println(1);
    }
  }
}
