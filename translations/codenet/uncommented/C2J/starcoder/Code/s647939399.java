import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int a,b,c[]=new int[256];
    int i,j;
    for(i=0;i>-1;i++){
      a=sc.nextInt();
      char m=sc.next().charAt(0);
      b=sc.nextInt();
      if(m=='?'){
        break;
      }
      if(m=='+'){
        c[i]=a+b;
      }
      if(m=='-'){
        c[i]=a-b;
      }
      if(m=='*'){
        c[i]=a*b;
      }
      if(m=='/'){
        c[i]=a/b;
      }
    }
    for(j=0;j<i;j++){
      System.out.println(c[j]);
    }
  }
}
