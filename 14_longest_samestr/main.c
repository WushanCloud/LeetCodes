#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0) return "";
	if (strsSize == 1) return *(strs);
	int i = 0, j = 0, k = 0;
	while (i < strsSize)
	{
		if (strs[i][0] != '\0') i++;
		else return "";
	}
	i = 0;
	char* same = (char*)malloc(sizeof(char) * 128);
	while (strs[i][j])
	{
		while (i < strsSize - 1 && strs[i][j] == strs[i + 1][j])
		{
			i++;
		}
		if (i == strsSize - 1)
		{
			i = 0;
			same[k] = strs[i][j];
			j++;
			k++;
		}
		else
		{
			same[k] = '\0';
			return same;
		}
	}
	same[k] = '\0';
	return same;
}
int main()
{
	char *s[2] = { "c","c" };
	printf("%s",longestCommonPrefix(s,2));
	return 0;
}