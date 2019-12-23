给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。 示例:

输入: nums1 = [1,2,3,0,0,0], m = 3 nums2 = [2,5,6], n = 3

输出: [1,2,2,3,5,6]

来源：力扣（LeetCode） 链接：https://leetcode-cn.com/problems/merge-sorted-array 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/*
解法一：把第二个数组直接放在第一个数组后面，然后进行排序  
*/
int cmp(int * a,int * b)
{
    return *a>*b;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m;
    int j =0;
    while(i<nums1Size)
    {
        nums1[i] = nums2[j];
        i++;
        j++;
    }
    qsort(nums1,nums1Size,4,cmp);
    return nums1;
}
/*
解法二：从数组一的最后m+n位往里倒序插
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i = m - 1;
	int j = n - 1;
	int end = m + n - 1;
	while (i>=0&&j>=0)
	{
		if (nums1[i] > nums2[j])
		{
			nums1[end] = nums1[i];
			i--;
		
		}
		else
		{
			nums1[end] = nums2[j];
			j--;

		}
		end--;
	}
	while (j>=0)
	{
	    nums1[end--] = nums2[j--];
    }
}