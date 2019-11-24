#include<stdio.h>
#include<stdlib.h>

char findTheDifference(char* s, char* t) {
	int a = 0;
	while (*s)
	{
		a ^= *s;
		s++;
	}
	while (*t)
	{
		a ^= *t;
		t++;
	}
	return (char)a;
	
}
int main()
{
	printf("%d",findTheDifference("abcd", "abcde"));
	return 0;
}