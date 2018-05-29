#include<iostream>
using namespace std;

void bubbleSort(int* arr, int len)
{
	for(int i=len-1; i>0; i--)
		for(int j=0; j<i; j++)
			if(arr[j]>arr[j+1])
			{
				arr[j] += arr[j+1];
				arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
			}
}

int main()
{
	int arr[10] = {3,2,4,2,2,1,7,8,3,10};
	bubbleSort(arr, 10);
	for(int i=0; i<10; i++)
		cout<<arr[i]<<endl;
	return 0;
}
