#include<iostream>
using namespace std;


/*从小到大排序，将arr[i]插入到arr[0...i-1]中*/
void insertSort(int* arr, int len)
{
	for(int i=1; i<len; i++)
	{
		int key = arr[i];
		int j = i-1;
		while(key<arr[j]&&j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main()
{
	int arr[10] = {3,2,4,2,2,1,7,8,3,10};
	insertSort(arr, 10);
	for(int i=0; i<10; i++)
		cout<<arr[i]<<endl;
	return 0;
}

