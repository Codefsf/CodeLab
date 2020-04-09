#include <iostream>
#include "BinarySearch.hpp"

using namespace std;

int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	int ret = binarySearch(arr, 6, 3);

	cout << ret << endl;
}