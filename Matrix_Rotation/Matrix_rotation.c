#include "stdio.h"

#define MATRIX_SIZE 3

struct point
{
	int row;
	int column;
}source_point, target_point;

int matrix[3][3] = 
					{1, 2, 3, 
					4, 5, 6, 
					7, 8, 9};

int resultant_matrix[3][3] = 
					{4, 1, 2, 
					7, 5, 3, 
					8, 9, 6};

void TestIfOuterMatrixRotated();
void PrintMatrix();
void RotateOuterMatrix();
void SetTargetRotation();
void SetTargetRotationForFirstRow();
void SetTargetRotationForLastColumn();
void SetTargetRotationForLastRow();
void SetTargetRotationForFirstColumn();
void PrintPoints();

int main(int argc, char const *argv[])
{	
	RotateOuterMatrix();

	PrintMatrix();

	TestIfOuterMatrixRotated();

	return 0;
}

void RotateOuterMatrix()
{
	source_point.row = source_point.column = 0;

	do
	{
		SetTargetRotation();		
		PrintPoints();
		
		source_point.row = target_point.row;
		source_point.column = target_point.column;	
	}while( rotationNotCompleted() );
}

void SetTargetRotation()
{
	if (source_point.row == 0)
	{
		SetTargetRotationForFirstRow();
	}
	else if (source_point.column == MATRIX_SIZE - 1)
	{
		SetTargetRotationForLastColumn();		
	}
	else if(source_point.row == MATRIX_SIZE - 1)
	{
		SetTargetRotationForLastRow();
	}
	else if(source_point.column == 0)
	{
		SetTargetRotationForFirstColumn();
	}
}

void SetTargetRotationForFirstRow()
{
	if (source_point.column+1 == MATRIX_SIZE)
	{
		target_point.column = MATRIX_SIZE - 1;
		target_point.row = source_point.row + 1;
	}
	else
	{
		target_point.column = source_point.column + 1;
		target_point.row = source_point.row;	
	}
}

void SetTargetRotationForLastColumn()
{
	if (source_point.row+1 == MATRIX_SIZE)
	{
		target_point.row = source_point.row;
		target_point.column = source_point.column - 1;
	}
	else
	{
		target_point.column = source_point.column;
		target_point.row = source_point.row + 1;	
	}
}

void SetTargetRotationForLastRow()
{
	if (source_point.column == 0)
	{
		target_point.row = source_point.row - 1;
		target_point.column = source_point.column;
	}
	else
	{
		target_point.column = source_point.column - 1;
		target_point.row = source_point.row;	
	}
}

void SetTargetRotationForFirstColumn()
{
	if (source_point.row == 0)
	{
		target_point.row = source_point.row;
		target_point.column = source_point.column + 1;
	}
	else
	{
		target_point.column = source_point.column;
		target_point.row = source_point.row - 1;	
	}
}

void PrintPoints()
{
	printf("Source: (%d, %d) | Target: (%d, %d)\n", 
		source_point.row, source_point.column, target_point.row, target_point.column);
}

int rotationNotCompleted() 
{
	if ( target_point.row == 0 && target_point.column == 0 ) 
	{
		return 0;
	}
	return 1;
}


void RotateOuterMatrix_Old()
{
	int row = 0, column = 0;

	source_point.row = 0;
	for(column = 0; (column < MATRIX_SIZE); column++)
	{
		source_point.column = column;
		SetTargetRotation();		
		PrintPoints();
	}

	printf("\n");

	source_point.column = MATRIX_SIZE - 1;
	for(row = 0; (row < MATRIX_SIZE); row++)
	{
			source_point.row = row;
			SetTargetRotation();

			PrintPoints();
	}

	printf("\n");

	source_point.row = MATRIX_SIZE - 1;
	for(column = 0; (column < MATRIX_SIZE); column++)
	{
		source_point.column = column;
		SetTargetRotation();		
		PrintPoints();
	}

	printf("\n");

	source_point.column = 0;
	for(row = 0; (row < MATRIX_SIZE); row++)
	{
			source_point.row = row;
			SetTargetRotation();		
			PrintPoints();
	}
	
}

void TestIfOuterMatrixRotated()
{
	int row = 0, column = 0, flag = 1;

	for(row = 0; (row < MATRIX_SIZE) && (flag == 1); row++)
	{
		for(column = 0; (column < MATRIX_SIZE) && (flag == 1); column++)
		{
			if(matrix[row][column] != resultant_matrix[row][column])
			{
				flag = 0;
			}
		}
	}

	printf("%s\n", flag ? "OK" : "FAIL");
}

void PrintMatrix()
{
	int row = 0, column = 0, flag = 1;

	for(row = 0; (row < MATRIX_SIZE) && (flag == 1); row++)
	{
		for(column = 0; (column < MATRIX_SIZE) && (flag == 1); column++)
		{
			printf("%d\t",matrix[row][column]);
		}
		printf("\n");
	}
}