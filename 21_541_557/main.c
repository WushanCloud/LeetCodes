#include<stdio.h>

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//
//
//
//	typedef struct ListNode  ListNode;
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
//	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
//	head->next = NULL;
//	ListNode* tail = head;
//	// tail->next=NULL;
//	if (l1 == NULL)return l2;
//	if (l2 == NULL)return l1;
//	while ((l1) && (l2))
//	{
//		if (l1->val < l2->val)
//		{
//			tail->next = l1;
//			tail = tail->next;
//			l1 = l1->next;
//
//		}
//		else
//		{
//			tail->next = l2;
//			tail = tail->next;
//			l2 = l2->next;
//		}
//	}
//	if (l1 == NULL)
//	{
//		tail->next = l2;
//	}
//	else
//		tail->next = l1;
//
//	return head->next;
//
//}

//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//
//示例 1 :
//
//输入: "Let's take LeetCode contest"
//输出 : "s'teL ekat edoCteeL tsetnoc"
//注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
//
//void reverseString(char* left, char* right) {
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//
//		left++;
//		right--;
//	}
//}
//char* reverseWords(char* s) {
//	char* head = s;//保存字符串首地址
//	int len = strlen(s);
//	int size = 0;//判断字符串是否结束
//	while (size < len)
//	{
//		int count = 0;
//		char* s1 = s;//保存单词第一个字母位置；
//		while (*s != ' ' && *s != '\0')
//		{
//			s++;
//			count++;
//		}
//		reverseString(s1, s - 1);
//		s++;
//		size += count + 1;
//	}
//	return head;
//}

//给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。
//
//示例 :
//
//输入: s = "abcdefg", k = 2
//输出 : "bacdfeg"
//要求 :
//
//	该字符串只包含小写的英文字母。
//	给定字符串的长度和 k 在[1, 10000]范围内。


void reverseString(char* s, int sSize) {
	char* right;
	char* left;

	right = s + sSize - 1;
	left = s;
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;

		left++;
		right--;
	}
}

char* reverseStr(char* s, int k) {
	char* ss = s;
	int location = 0;
	int len = strlen(s);
	location = len < k ? len : k;
	while (location <= 2 * k)
	{
		reverseString(s, location);
		s += 2 * location;
		len -= k;
		if (len < k)
			break;
		else
		{
			len -= k;
			location = len < k ? len : k;
		}
	}
	return ss;
}

