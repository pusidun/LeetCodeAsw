#include<iostream>
using namespace std;



void selectSort(int* arr, int len)
{
	int max=0,index=0;
	for(int i=0; i<len; i++)
	{
		max = arr[i];index=i;
		for(int j=i;j<len;j++)
			if(max<arr[j])
			{
				max=arr[j];
				index=j;
			}
		arr[index]=arr[i];
		arr[i]=max;
	}
}

int main()
{
	int arr[10] = {3,2,4,2,2,1,7,8,3,10};
	selectSort(arr, 10);
	for(int i=0; i<10; i++)
		cout<<arr[i]<<endl;
	return 0;
}

