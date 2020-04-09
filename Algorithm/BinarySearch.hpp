#include <iostream>

int binarySearch(int arr[], int n, int value)
{
	int left = 0, right = n - 1, mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (value == mid) {
			return mid;
		}
		else if (value < mid) {
			right = mid - 1;
		} 
		else if (value > mid) {
			left = mid + 1;
		}
	}

	return -1;
}