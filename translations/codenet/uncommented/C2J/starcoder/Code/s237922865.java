
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int cnt4=0,cnt2=0;
		//4の倍数
		//4の倍数出ないが、2の倍数/2
		//の合計がn/2より大きい
		for(int i=0;i<n;i++){
			int wk = sc.nextInt();
			if(wk%4==0)
				cnt4++;
			else if(wk%2==0)
				cnt2++;
		}

		if(cnt4+cnt2/2>=n/2)
			System.out.println("Yes");
		else 
			System.out.println("No");

	}

}

