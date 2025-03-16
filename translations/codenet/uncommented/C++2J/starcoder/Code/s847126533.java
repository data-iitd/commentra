import java.util.*;
public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    while(true)
      {
	int m=cin.nextInt();
	int n=cin.nextInt();
	if(m==0)
	  break;
	int[] book=new int[n];
	for(int i=0;i<n;i++)
	  book[i]=cin.nextInt();
	int l=0;
	int r=1500000;
	int ans;
	while(l<r)
	  {
	    //	    System.out.println(l+" "+r);
	    //	    System.out.println((l+r)/2);
	    if(check(m,(l+r)/2,book))
	      {
		ans=(l+r)/2;
		if(r==(l+r)/2)
		  break;
		r=(l+r)/2;

	      }
	    else
	      {
		if(l==(l+r)/2)
		  break;
		l=(l+r)/2;
	      }
	  }
	System.out.println(ans);
      }
  }
  public static boolean check(int m,int wei,int[] book)
  {
    int tmp=wei;
    m--;
    for(int i=0;i<book.length;i++)
      {
	if(tmp<book[i])
	  {
	    if(m>0)
	      {
		m--;
		tmp=wei;
		if(tmp<book[i])
		  return false;
	      }
	    else
	      return false;
	  }
	//	System.out.println(m+" "+tmp+" "+book[i]);
	tmp-=book[i];
      }
    return true;
  }
}
