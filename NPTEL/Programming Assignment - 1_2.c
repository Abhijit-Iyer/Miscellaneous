/*
You are given two integers, say M and N.

You must check whether M is an exact multiple of N, without using
loops.
You have to output 0 if M is not a multiple of N.
You have to output M/N if M is a multiple of N.

Input-----
Two integers, say M and N.

Output------
You have to output 0 if M is not a multiple of N.
You have to output M/N if M is a multiple of N.

SAMPLE TEST CASES :

Test Case 1:-

Input:
3
2

Output:
0


Test Case 2:-

Input:
100
5

Output:
20

*/

#include <stdio.h>

void main()
{
	int m,n;
	scanf("%d%d",&m,&n);

	if(m%n == 0)
		printf("\n%d",m/n);
	else
		printf("\n0");
}