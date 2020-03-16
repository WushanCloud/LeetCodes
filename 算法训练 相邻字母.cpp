
//【问题描述】
//从键盘输入一个英文字母，要求按字母的顺序打印出3个相邻的字母，指定的字母在中间。
//若指定的字母为Z，则打印YZA，若为A则打印ZAB。注意：需要区分大小写。
//
//【输入格式】
//一行，仅包含一个英文字母。
//
//【输出格式】
//一行，包含三个字母。
//
//【样例输入1】
//a
//
//【样例输出1】
//zab
//
//【样例输入2】
//B
//
//【样例输出2】
//ABC
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	char ch;
	cin >> ch;

	if (ch == 'a' || ch == 'A')
	{
		cout << (char)(ch + 25);
	}
	else
	{
		cout << (char)(ch - 1);
	}
	cout << ch;
	if (ch == 'z' || ch == 'Z')
	{
		cout << (char)(ch - 25);
	}
	else
	{
		cout << (char)(ch + 1);
	}
	return 0;
}



