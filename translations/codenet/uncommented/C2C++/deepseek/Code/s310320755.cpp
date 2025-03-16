#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int r, c, n, flag, cnt;
	vector<vector<int>> arr(16, vector<int>(16, 0));

	while (true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		flag = 1;
		r = (n + 1) / 2 + 1;
		c = (n + 1) / 2;
		arr[r][c] = cnt = 1;

		while (cnt != n * n + 1)
		{
			++cnt;
			if (flag)
			{
				++r;
				++c;
				if (c > n)
				{
					c = 1;
				}

				if (r > n)
				{
					r = 1;
				}

				if (arr[r][c])
				{
					flag = 0;
					--cnt;
				}
				else
				{
					arr[r][c] = cnt;
				}
			}
			else
			{
				++r;
				--c;
				if (c < 1)
				{
					c = n;
				}

				if (r > n)
				{
					r = 1;
				}

				if (arr[r][c])
				{
					flag = 0;
				}
				else
				{
					arr[r][c] = cnt;
					flag = 1;
				}

			}

			//cout << "r=" << r << "  c=" << c << "   cnt=" << cnt << endl;
		}

		for (r = 1; r < n + 1; r++)
		{
			for (c = 1; c < n + 1; c++)
			{
				cout << arr[r][c] << " ";
				arr[r][c] = 0;
				if (c == n)
				{
					cout << endl;
				}
			}
		}
	}

	return 0;
}

