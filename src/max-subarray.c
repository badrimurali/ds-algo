#include <stdio.h>
#include <curses.h>
#include <limits.h>
struct tuple
{
	int leftMax;
	int sum;
	int rightMax;

};
struct tuple maxCrossingSubArray(int* array, int low, int mid, int high);
struct tuple maxSubArray(int * array, int low, int high);
int main() {
	int n;
	scanf("%d", &n);
	int array[n];
	int i =0;
	for (i =0; i< n; i++) {
		scanf("%d", &array[i]);
	}
	struct tuple maxSum = maxSubArray(array, 0, n - 1);
	printf("%d %d %d ", maxSum.leftMax, maxSum.rightMax, maxSum.sum);

	return 0;
}

struct tuple maxCrossingSubArray(int* array, int low, int mid, int high) {
	int leftSum = INT_MIN;
	int sum =0;
	int i =0, j=0;
	struct tuple t1;
	for(i = mid; i>=low; i--) {
		sum = sum + array[i];
		if(sum > leftSum) {
			leftSum = sum;
			t1.leftMax = i;
		}
	}
	int rightSum = INT_MIN;
	sum =0;
	for (j = mid +1; j<=high; j++) {
		sum = sum + array[j];
		if(sum > rightSum) {
			rightSum = sum;
			t1.rightMax = j;
		}
	}
	t1.sum = leftSum + rightSum;
	return t1;
}

struct tuple maxSubArray(int* array, int low, int high) {
	if(low == high) {
		struct tuple t1;
		t1.leftMax = low;
		t1.rightMax = high;
		t1.sum = array[low];
		return t1;
	}
	int mid = (low + high) / 2;

	struct tuple left = maxSubArray(array, low, mid);
	struct tuple right = maxSubArray(array, mid + 1, high);
	struct tuple cross = maxCrossingSubArray(array, low, mid, high);
	if(left.sum >= right.sum && left.sum >= cross.sum) {
		return left;
	} else if (right.sum >= left.sum && right.sum >= cross.sum) {
		return right;
	}
	return cross;
}
