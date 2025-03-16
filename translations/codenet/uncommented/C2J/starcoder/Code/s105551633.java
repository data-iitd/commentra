import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int64 n=sc.nextLong();
    int min=digit(n);
    int i;
    for(i=1;(int64)i*i<=n;i++){
      if(n%i!=0) continue;
      int64 a=i;
      int64 b=n/i;
      min=MIN(min,MAX(digit(a),digit(b)));
    }
    System.out.println(min);
  }

  public static int digit(int64 n){
    int res=0;
    while(n>0){
      res++;
      n/=10;
    }
    return res;
  }
}

