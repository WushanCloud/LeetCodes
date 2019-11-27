#include<stdio.h>
#include<string.h>
#include<malloc.h>
//char* addBinary(char* a, char* b) {
//	int lena = strlen(a);
//	int lenb = strlen(b);
//	int max = lena > lenb ? lena : lenb;
//	char* ans = (char*)malloc(sizeof(char) * );
//	ans[max + 1] = '\0';
//	int temp = 0;//进一标志
//	int i, j;
//	int num = max;//新数位数，+1防止越界
//	//*ans = '0';
//	for (i = 0, j = 0; i < lena && j < lenb; lena--, lenb--,num--)
//	{
//		
//		if (a[lena-1] == '1' && b[lenb-1] == '1')
//		{
//			ans[num] = '0' + temp;
//			temp = 1;
//		}
//		else if (a[lena-1] == '1' || b[lenb-1] == '1')
//		{
//			if (temp == 1)
//			{
//				ans[num] = '0';
//				//  temp = 1;//不用重复更新；
//			}
//			else
//				ans[num] = '1';
//		}
//		else
//		{
//			ans[num] = '0' + temp;
//			temp = 0;
//		}
//	}
//	if(lena != 0)
//	for (i = 0; i <= lena; lena--, num--)
//	{
//		if (a[lena - 1] == '1')
//			ans[num] = '0';
//		else
//		{
//			ans[num] = '1';
//			temp = 0;
//		}
//	}
//	if(lenb != 0)
//	for (i = 0; i <= lenb; lenb--, num--)
//	{
//		if (a[lenb - 1] == '1')
//			ans[num] = '0';
//		else
//		{
//			ans[num] = '1';
//			temp = 0;
//		}
//	}
//	if (ans[0] != '1')
//	{
//		char* p1 = ans, * p2 = ans +1;
//		while (max)
//		{
//			*p1 = *p2;
//			p1++;
//			p2++;
//			max--;
//		}
//	}
//	return ans;
//}
void reseve(char* str)
{
	int len = strlen(str);
	char* left = str;
	char* right = str + len - 1;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;

		left++;
		right--;
	}
}

char* addBinary(char* a, char* b)
{
	reseve(a); reseve(b);//先逆置字符串
	int max = (strlen(a) > strlen(b) ? strlen(a) : strlen(b)) + 1;
	char* ans = (char*)malloc(sizeof(char) * (max + 1));
	int i= 0, j = 0;
	char temp = 0;
	while (a[i] && b[i])
	{
		if (a[i] == '1' && b[i] == '1')
		{
			if(ans+i) ans[i] = '0';//来自警告C6011
			temp = 1;
		}
		else if (a[i] == '1' || b[i] == '1')
		{
			if (temp == 1)
			{
				if (ans + i) ans[i] = '0';
				temp = 0;
			}
			else
			{
				if (ans + i) ans[i] = '0';
			}
		}
		else
		{
			if (ans + i) ans[i] = ('0' + temp);
		}
		i++;
	}
	while (a[i])
	{
		ans[i] = a[i];
		i++;
	}
	while (b[i])
	{
		ans[i] = b[i];
		i++;
	}
	ans[i] = '\0';
	reseve(ans);
	return ans;
}
int main()
{
	char * p = addBinary("123", "1");
	printf("%s", p);
	free(p);
	return 0;
}