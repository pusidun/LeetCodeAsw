#include<iostream>
using namespace std;

void quickSort(int* arr, int lo, int hi)
{
	if(hi<=lo)
		return;
	int i=lo, j=hi;
	int pivot=arr[i];
	while(i<j)
	{
		while(i<j && arr[j]>=pivot)
			j--;
		arr[i]=arr[j];
		while(i<j && arr[i]<=pivot)
			i++;
		arr[j]=arr[i];
	}
	arr[i]=pivot;
	quickSort(arr,lo,i-1);
	quickSort(arr,i+1, hi);
}

int main()
{
	int arr[6] = {3,2,4,8,3,10};
	quickSort(arr, 0, 5);
	for(int i=0; i<6; i++)
		cout<<arr[i]<<endl;
	return 0;
}
