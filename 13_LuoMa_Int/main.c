#include<stdio.h>
#include<stdlib.h>

int romanToInt(char* s) {
	int val[8][2] = {
		{'I',1},
		{'V',5},
		{'X',10},
		{'L',50},
		{'C',100},
		{'D',500},
		{'M',1000},
		{0,0}
	};
	int sum = 0;
	int i = 0;
	while (*s)
	{
		i = 0;
		while (val[i][0])
		{
			if (*s == val[i][0])//对应到val表
			{
				printf("%d", sum);
				if (*s == 'I' && *(s + 1) == 'V')//判断特殊情况
				{
					sum += 4;
					s++; break;
				}
				else if (*s == 'I' && *(s + 1) == 'X')
				{
					sum += 9;
					s++; break;
				}
				else if (*s == 'X' && *(s + 1) == 'L')
				{
					sum += 40;
					s++; break;
				}
				else if (*s == 'X' && *(s + 1) == 'C')
				{
					sum += 90;
					s++; break;
				}
				else if (*s == 'C' && *(s + 1) == 'D')
				{
					sum += 400;
					s++; break;
				}
				else if (*s == 'C' && *(s + 1) == 'M')
				{
					sum += 900;
					s++; break;
				}
				else
				{
					sum += val[i][1];
					break;
				}
			}

			i++;
		}

		s++;
	}
	return sum;
}

int romanToInt(char* s) {
	int len = strlen(s); int* arr = (int*)malloc(sizeof(int) * len);
	int i = 0;
	while (*s)
	{
		arr[i] = *s;
		i++;
		s++;
	}
	int sum = 0;
	for (i = 0; i < len - 1; i++)
	{
		if (getValue(arr[i]) < getValue(arr[i + 1]))
		{
			sum += -getValue(arr[i]);
		}
		else
		{
			sum += getValue(arr[i]);
		}

	}
	sum = sum + getValue(arr[len - 1]);
	return sum;
}
int getValue(char ch)
{
	int num;
	switch (ch) {
	case 'I':num = 1;
		break;
	case 'V':num = 5;
		break;
	case 'X':num = 10;
		break;
	case 'L':num = 50;
		break;
	case 'C':num = 100;
		break;
	case 'D':num = 500;
		break;
	case 'M':num = 1000;
		break;
	}
	return num;
}
int main()
{
	printf("%d",romanToInt("MCMXCIV"));
	return 0;
}