#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<map>
#include<set>
#include<list>
#include<forward_list>
#include<vector>
#include<deque>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
	//OMG,i>j ? 
	
	long i,j;
	while(cin>>i>>j)
	{
		long aa=i,bb=j;
		if(i>j){
			i=i^j;
			j=i^j;
			i=i^j;
		}
		long cnt=0,max=0;
		long n;
		long tmp;
		for(n=i;n<=j;n++)
		{
			cnt=1;
			tmp=n;
			while(tmp!=1)
			{
				if(tmp%2==1)
					tmp=tmp*3+1;
				else
					tmp/=2;
				cnt++;
			}
			if(cnt>max)
				max=cnt;
		}
		cout<<aa<<" "<<bb<<" "<<max<<endl;
	}
	return 0;
}