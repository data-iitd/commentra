#include <stdbool.h>
#include <stdio.h>
public class Main {
	public static void main(String[] args) {
		int n, a[100000], cnt = 1;
		boolean isup;
		boolean issame = false;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		if (a[0] < a[1])
			isup = true;
		else if (a[0] > a[1])
			isup = false;
		else
			issame = true;
		for (int i = 1; i < n - 1; i++) {
			if (issame) {
				if (a[i] != a[i + 1]) {
					issame = false;
					if (a[i] < a[i + 1])
						isup = true;
					else
						isup = false;
				}
			} else {
				if (isup && a[i] <= a[i + 1]) {
					;
				} else if (!isup && a[i] >= a[i + 1]) {
					;
				} else {
					if (i + 2 < n) {
						if (a[i + 1] < a[i + 2])
							isup = true;
						else if (a[i + 1] > a[i + 2])
							isup = false;
						else
							issame = true;
						cnt++;
					} else {
						cnt++;
						break;
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
}
