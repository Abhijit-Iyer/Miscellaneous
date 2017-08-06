/*You will be given 3 integers as input. The inputs may or may not be
 different from each other. 

You have to output 1 if all three inputs
 are different from each other, 
and 0 if any input is repeated more
 than once.


Input
-----
Three integers on three lines.


Output
------
1 if the three inputs are different from each other
, 0 if some input is repeated more than once

SAMPLE TEST CASES :

Test Case 1	
Input:
3
2
1
Output:
1


Test Case 2	
Input:
3
1
3
Output:
0
*/

#include <stdio.h>

void main()
{
	int a, b, c;

	scanf("%d%d%d",&a,&b,&c);

	if(a != b && a != c && b != c)
		printf("\n1");
	else
		printf("\n0");
}