#include<iostream>
using namespace std;

void finalMerge(int arr[], int l, int mid, int r) {
	int size1 = mid - l + 1; 
	int size2 = r - mid;
	int* arr1 = new int[size1];
	int *arr2 = new int[size2];
	 
	for (int i = 0; i < size1; i++) {
		arr1[i] = arr[l + i];
	}
	for (int j = 0; j < size2; j++) {
		arr2[j] = arr[mid + 1 + j];
	}
	int a1 = 0, a2 = 0;
	int k = l;
	while (a1 < size1 && a2 < size2) {
		if (arr1[a1] <= arr2[a2]) {
			arr[k] = arr1[a1];
			a1++;
		}
		else {
			arr[k] = arr2[a2];
			a2++;
		}

		k++;
	}
	while (a1 < size1) {
		arr[k] = arr1[a1];
		a1++;
		k++;
	}
	while (a2 < size2) {
		arr[k] = arr2[a2];
		a2++;
		k++;
	}

}
void mergeSort(int arr[], int l, int r) {
	if (r > l) {
		int mid = l + (r - l) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);

		finalMerge(arr, l, mid, r);
	}
}
void print(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);
	print(arr, n);
	return 0;
}