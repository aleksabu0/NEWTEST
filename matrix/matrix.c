#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include"matrix.h"


int8_t CheckEquality(int8_t a[DIM][DIM], int8_t b[DIM][DIM])
{
	for(uint8_t i=0;i<DIM;i++)
	{
		for(uint8_t j=0;j<DIM;j++)
		{
		   if(a[i][j]!=b[i][j])
		   {
			   return 0;
		   }
		}
	}
	return 1;
}

void Add(int8_t a[DIM][DIM], int8_t b[DIM][DIM], int8_t c[DIM][DIM])
{
	for(uint8_t i=0;i<DIM;i++)
	{
		for(uint8_t j=0;j<DIM;j++)
		{
		   c[i][j]=a[i][j]+b[i][j];
		}
	}
}

void Subtract(int8_t a[DIM][DIM], int8_t b[DIM][DIM], int8_t c[DIM][DIM])
{
	for(uint8_t i=0;i<DIM;i++)
	{
		for(uint8_t j=0;j<DIM;j++)
		{
		   c[i][j]=a[i][j]-b[i][j];
		}
	}
}

void Multiply(int8_t a[DIM][DIM], int8_t b[DIM][DIM], int8_t c[DIM][DIM])
{
	for(uint8_t i=0;i<DIM;i++)
	{
		for(uint8_t j=0;j<DIM;j++)
		{
		   c[i][j]=a[i][j]*b[i][j];
		}
	}
}

void Transpose(int8_t a[DIM][DIM], int8_t a_tran[DIM][DIM])
{
	for(uint8_t i=0;i<DIM;i++)
	{
		for(uint8_t j=0;j<DIM;j++)
		{
		  a_tran[j][i]=a[i][j];
		}
	}
}

int8_t SumMainDiagonal(int8_t a[DIM][DIM])
{
	int8_t suma=0;
	for(uint8_t i=0;i<DIM;i++)
		{
			for(uint8_t j=0;j<DIM;j++)
			{
			  if(i==j)
			  {
				  suma+=a[i][j];
			  }
			}
		}
	return suma;
}

int8_t SumMinorDiagonal(int8_t a[DIM][DIM])
{
	int8_t suma=0;
	for(uint8_t i=0;i<DIM;i++)
		{
			for(uint8_t j=0;j<DIM;j++)
			{
			  if(i+j==DIM+1)
			  {
				  suma+=a[i][j];
			  }
			}
		}
	return suma;
}
