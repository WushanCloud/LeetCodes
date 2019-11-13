#include<stdio.h>
int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int max = 0;
	int tmp = 0;
	int src = 0;
	while (src < numsSize)
	{
		tmp = 0;
		while (nums[src] == 1)
		{
			tmp++;
			src++;
		}
		while (nums[src] == 0)
		{
			src++;
		}
		if (tmp > max)
		{
			max = tmp;
		}
	}
	return max;
}
int main()
{
	int arr[] = { 1,0,1,1,0,1 };
	int len = sizeof(arr) / sizeof(arr[0]);

	printf("%d", findMaxConsecutiveOnes(arr, len));
	return 0;
}