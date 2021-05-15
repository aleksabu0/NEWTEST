/**
 * @file main.c
 * @brief glavni fajl
 * @author ABYU
 * @date 15.05.2021.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include"../usart/usart.h"
#include"../timer0/timer0.h"
#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>
#include"../matrix/matrix.h"

/**
 * Funkcija ispisuje broj
 * @param broj_sam broj koji se ispisuje
 * @return nista
 */
void put_broj(int16_t broj_sam);

/**
 * Funkcija pretvara string u broj
 * @param broj_sam[] string koji je unesen
 * @param broj_cif broj cifara
 * @return konvertovan broj
 */
uint16_t get_broj(uint8_t broj_sam[],uint8_t broj_cif);

/**
 * Funkcija ispisuje matricu
 * @param a[][] matrica koja se ispisuje
 * @return nista
 */
void print_matrix(int8_t a[DIM][DIM]);

/**
 * Funkcija za unos matrice
 * @param a[][] matrica u koju se upisuje
 * @return nista
 */
void input_matrix(int8_t a[DIM][DIM]);

int main()
{
	usartInit(9600);
	uint8_t izl_broj=0; //broj koji se ispisuje
	uint8_t prov[64] ={0};
	uint8_t cnter=0;
	uint8_t str_cnt[64]={0};
	uint8_t lex=0;
	int8_t broj=0;
	int32_t res1=0;
	int32_t res2=0;

	int8_t x[DIM][DIM] = {0};
	int8_t y[DIM][DIM] = {0};
	int8_t z[DIM][DIM] = {0};

	while(1)
	{

		input_matrix(x);
		print_matrix(x);

		input_matrix(y);
		print_matrix(y);

		usartPutString("SABIRANJE \r\n");
		Add(x,y,z);
		print_matrix(z);

		usartPutString("KRAJ \r\n");
		while(!usartAvailable());
	}
	return 0;
}

/*****************************************************************************************************************************/

void put_broj(int16_t broj_sam)
{
	uint16_t tens=1;
	uint8_t broj_sam_konv[64];
	uint8_t broj_cif=0;
	uint8_t i=0;
	if(broj_sam<0)
	{
		broj_sam_konv[0]='-';
		i++;
		broj_cif++;
		broj_sam = broj_sam * (-1);
	}

	int16_t temp=broj_sam;
	while(temp>0)
	{
		temp=temp/10;
		broj_cif++;
	}

	while(i<broj_cif)
	{
		for(uint8_t k=0;k<(broj_cif-i-1);k++)
		{
			tens=tens*10;
		}
		broj_sam_konv[i]=broj_sam/tens;
		broj_sam=broj_sam-broj_sam_konv[i]*tens;
		broj_sam_konv[i]=broj_sam_konv[i]+48;
		tens=1;
		i++;
	}
	broj_sam_konv[broj_cif]='\0';
	usartPutString(broj_sam_konv);
}

/*****************************************************************************************************************************/

uint16_t get_broj(uint8_t broj_sam[],uint8_t broj_cif)
{
	uint16_t tens=1;
	uint16_t broj_sam_konv=0;

	for(uint8_t i=0;i<broj_cif;i++)
	{
		for(uint8_t k=0;k<(broj_cif-i-1);k++)
		{
			tens=tens*10;
		}
		broj_sam_konv+=(broj_sam[i]-48)*tens;
		//broj_sam[i]=broj_sam[i]-broj_sam_konv*tens;
		//broj_sam_konv[i]=broj_sam_konv[i]+48;
		tens=1;
	}
	return broj_sam_konv;
}

/*****************************************************************************************************************************/

void print_matrix(int8_t a[DIM][DIM])
{
	for(uint8_t i=0;i<DIM;i++)
	{
		for(uint8_t j=0;j<DIM;j++)
		{
			put_broj(a[i][j]);
			usartPutString(" ");
		}
		usartPutString("\r\n");
	}
}

/*****************************************************************************************************************************/

void input_matrix(int8_t a[DIM][DIM])
{
	uint8_t str[64];
	uint8_t new_str[8];
	uint8_t new_size=0;
	uint8_t pok=0;
	usartPutString("Uneti matricu \r\n");
	while(!usartAvailable());
	_delay_ms(100);
	uint8_t size=usartAvailable();
	_delay_ms(100);
	usartGetString(str);
	for(uint8_t i=0;i<DIM;i++)
	{
		for(uint8_t j=0;j<DIM;j++)
		{
			while(str[pok]>=48 && str[pok]<=57)
			{
				new_str[new_size]=str[pok];
				new_size++;
				pok++;
			}
			while(str[pok]<48 || str[pok]>57)
			{
				pok++;
			}
			a[i][j]=get_broj(new_str,new_size);
			new_size=0;
		}
	}
}
