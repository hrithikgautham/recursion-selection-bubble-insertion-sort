#include<iostream>
//Recursion Sorts
using namespace std;

/* 
	using recursion to sort doesn't have any
 	impact on time complexity,
	Rather helps you understand recursion
*/


void bubble(int arr[], int n){/*Recursive bubble sort*/
	if(n == 1)	return;
	for(int i = 0 ; i < n-1 ; i++){
		if(arr[i] > arr[i+1]){
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
	
	bubble(arr, n-1);
}

void selSort(int arr[], int n){/*Recursive selection sort*/
	if(n == 1)	return;
	int j = 0, temp;
	for(int i = 0 ; i < n - 1 ; i++){
		if(arr[j] < arr[i+1]){
			j = i+1;
		}
	}
	temp = arr[n - 1];
	arr[n - 1] = arr[j];
	arr[j] = temp;
	
	selSort(arr, n - 1);
}

void inSort(int arr[], int n){/*Recursive insertion sort sort*/
	if(n == 1) return;
	inSort(arr, n - 1);
	int j = n - 2, temp = arr[n - 1], index;
	for(int i = n - 1 ; i > 0 && j >= 0 ; i--, j--){
		index = i;
		if(arr[j] > temp){//we can also use arr[i] here
			arr[i] = arr[j];
			index = j;
		}
		else break;
	}
	arr[index] = temp;
}

//Main function begins here
int main(void){
	int arr[10] = {10,90,8,7,0,5,4,3,2,1};
	bubble(arr, 10);
//	selSort(arr, 10);
//	inSort(arr, 10);
	cout<<"Sorted array : ";
	for(int i = 0 ; i < 10 ; i++) //this is for printing sorted array
		cout<<arr[i]<<" ";
	return 0;
}
