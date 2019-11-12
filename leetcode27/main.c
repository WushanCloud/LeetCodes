#include<stdio.h>

#if 1
//给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
int removeElement(int* nums, int numsSize, int val) {
	int dst;//目标
	int src;//原数组
	//如果原不指向目标，那么把目标赋值给原
	dst = src = 0;
	while (dst<numsSize)
	{
		if (nums[dst] != val)
		{
			nums[src++]=nums[dst++];
		}
		else if (nums[dst] == val)
		{
			dst++;
		}
	}
	return src;
}
int main()
{
	int arr[] = { 3,2,2,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d", removeElement(arr, len, 3));
	return 0;
}
#endif

