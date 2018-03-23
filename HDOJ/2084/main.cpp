#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int main()
{
	int c;
	cin>>c;
	int maxn[101][101];
	while(c--)
	{
		int n;
		cin>>n;
		memset(maxn, 0, sizeof(maxn));
		
		for(int i=1; i<=n; i++)
			for(int j=1; j<=i; j++)
				cin>>maxn[i][j];
				
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=i; j++)
			{
				if(maxn[i-1][j] > maxn[i-1][j-1])
					maxn[i][j] = maxn[i][j]+maxn[i-1][j];
				else
					maxn[i][j] = maxn[i][j]+maxn[i-1][j-1];
			}
		}
		int MAX = 0;
		for(int i = 1; i<=n; i++)
			if(maxn[n][i]>MAX)
				MAX = maxn[n][i];
		cout<<MAX<<endl;
	}
	return 0;
}
