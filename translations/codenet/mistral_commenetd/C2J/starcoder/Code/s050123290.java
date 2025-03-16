import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		char[] su=new char[1000];
		int susum=0,j=0;
		while(true){
			for(j=0;j<1000;j++){
				su[j]=sc.next().charAt(0);
				if(su[j]=='\n')break;
				susum=susum+(su[j]-'0');
			}
			if(su[0]=='0')break;
			System.out.println(susum);
			susum=0;
		}
	}
}
