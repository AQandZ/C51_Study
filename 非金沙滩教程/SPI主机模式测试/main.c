#include<reg52.h>
typedef unsigned char uint8;
typedef unsigned int uint16;

extern void SPI_Init();		//SPI��ʼ��������ģʽʹ�ã�
extern void SPI_Write(uint8 dat);	//SPI��ģʽ�������ݣ�dat��Ҫ���͵����ݣ�
extern uint8 SPI_Read();	//SPI��ģʽ��ȡ���ݣ����ض�ȡ��������

void main()
{
	uint8 dat;
	SPI_Init();
	SPI_Write(0x96);
	while(1)
	{		
		dat=SPI_Read();
		SPI_Write(dat+1);		
	}		
}