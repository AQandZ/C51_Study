#include<reg52.h>
typedef unsigned char uint8;
typedef unsigned int uint16;
extern void IIC_Start();    //����IICͨ����ʼ�ź�
extern void IIC_Stop();     //����IICͨ����ֹ�ź�
extern bit IIC_Write(uint8 dat);    //IICͨ��д��һ��uint8�͵����ݣ�dat��Ҫд������ݣ����أ�1���ɹ���0��ʧ��
extern uint8 IIC_Read(bit ACK);     //IICͨ�Ŷ���һ��uint8�͵����ݣ�ACK��0����ĩλ���ݣ�1��ĩλ���ݣ������ض���������
void UART_Init(uint16 baud)
{
	uint16 temp;
	temp=256-11059200/32/12/baud;
	TH1=TL1=baud;
	TMOD=0X20;
	EA=1;
	ES=1;
	TR1=1;
}
void main()
{
	UART_Init(9600);
	while(1);
}
void IIC_Send(uint8 dat)
{
	IIC_Start();
	IIC_Write(0x50);
	IIC_Write(dat);
	IIC_Stop();
}
uint8 IIC_Resive()
{
	
}
void Interrupt_UART() interrupt 4
{
	if(RI)
	{
		RI=0;
		IIC_Sned(SBUF);
		SBUF=IIC_Resive();
	}
	else TI=0;
}
