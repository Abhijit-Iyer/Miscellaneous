/*
A triple of numbers (a,b,c) is called a Pythagorean triple if
a*a+b*b=c*c.

In this question, you will be given three numbers. You have to output
1 if the three numbers form a Pythagorean triple. Otherwise, you have
to output 0.

Note that the inputs may not be given in order : you may have to try
all possible orderings of the three numbers to determine whether they
form a Pythagorean triple.

Input-----Three integers.

Output------1 if the three numbers are part of a Pythagorean triple
            0 otherwise

SAMPLE TEST CASES:

Test Case 1:-

Input:
3
4
5

Output:
1

Test Case 2:-

Input:
1
2
3

Output:
0
*/

#include <stdio.h>

void main()
{
	int a, b, c, arr[3], temp, i, j;

	scanf("%d%d%d",&arr[0],&arr[1],&arr[2]);



	for(i=0; i<3; i++)
		for(j=i; j<3; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}

	if( ((arr[0]*arr[0]) + (arr[1]*arr[1]) == (arr[2]*arr[2])) )
		printf("\n1");
	else
		printf("\n0");
}