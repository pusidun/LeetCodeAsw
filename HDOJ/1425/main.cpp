#include<cstdio>
#include<cstring>
using namespace std;
const int offset = 500000;
bool hash[offset+500001]; 


int main()
{
    int m, n;
    while(scanf("%d%d", &m, &n)!=EOF)
    {
        memset(hash, false, sizeof(hash));
        for(int i=0; i<m; i++){
            int num;
            scanf("%d", &num);
            hash[offset+num] = true;
        }
        for(int i=offset+500001; i>=0&&n>0; i--)
        {
            if(hash[i])
            {
                if(n==1)
                    printf("%d\n", i-offset);
                else
                    printf("%d ", i-offset);
                n--;
            }
        }
    }
    return 0;
 }