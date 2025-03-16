
#include<iostream>
using namespace std;
int main()
{
	int input[4][4],tc;
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			cin>>input[i][j];
		}
	}
	cin>>tc;
	int testcase;
	for(int i = 0;i<tc;i++)
	{
		cin>>testcase;
		for(int i = 0;i<3;i++)
		{
			for(int j = 0;j<3;j++)
			{
				if(input[i][j] == testcase)
				{
					input[i][j] = 0;
				}
			}
		}
	}
	if(input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0)
	{
		cout<<"Yes"<<endl;
	}
	else if(input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0)
	{
		cout<<"Yes"<<endl;
	}
	else if(input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0)
	{
		cout<<"Yes"<<endl;
	}
	else if(input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0)
	{
		cout<<"Yes"<<endl;
	}
	else if(input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0)
	{
		cout<<"Yes"<<endl;
	}
	else if(input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0)
	{
		cout<<"Yes"<<endl;
	}
	else if(input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0)
	{
		cout<<"Yes"<<endl;
	}
	else if(input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;	
	}
	return 0;
}
