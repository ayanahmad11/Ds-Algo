#include<iostream>
using namespace std;

int partition(int arr[],int s,int e ){
	
	int pivot = arr[s];
	int cnt=0;
	for(int i=s+1;i<=e;i++){
		if(arr[i]<=pivot)
			cnt++;
		
	}
	
	// pivot ki right place is pivot index;
	int pivotIndex = s+cnt;
	// pivot ko right index pe daal diya
	swap(arr[pivotIndex],arr[s]);
	
	int i=s,j=e;
	while(i<pivotIndex && j>pivotIndex)
	{
		while(arr[i]<=pivot)
		{	
			i++;
		}
		while(arr[j]>pivot)
		{	
			j--;
		}
		
		if(i< pivotIndex && j> pivotIndex){
			swap(arr[i++],arr[j--]);
				
		}
		
	}
	return pivotIndex;
	
	
}



void QuickSort(int arr[],int s,int e){
// base case;
	if(s>=e) 
		return ;
	//partition karenge
	int p = partition(arr,s,e);
	
	// left part sort karo;
	QuickSort(arr,s,p-1);
	
	// right wala part sort karo
	QuickSort(arr,p+1,e);
	


}

int main(){
	
	int arr[11] = {3,3,3,2,4,1,6,9,22,32,1};
	int n = 11;
	
	QuickSort(arr,0,n-1);
	
	for(int i=0;i<n;i++){
	
	cout<<arr[i]<<" ";
		
	}
	cout<<endl;
	
	
	return 0;
	
	
}