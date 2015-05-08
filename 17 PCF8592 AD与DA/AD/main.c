#include<reg51.h>
typedef unsigned char uint8;
typedef unsigned int uint16;

extern void LCD1602_Show(uint8 x,uint8 y,uint8 *dat,uint8 len); //LCD1602��ʾ�ַ�����x�������꣬y�������꣬dat��Ҫ��ʾ���ַ����飬len��Ҫ��ʾ�ĳ��ȣ�
extern void LCD1602_Init(); //LCD1602��ʼ������������������ͷ���á�

extern void IIC_Start();    //����IICͨ����ʼ�ź�
extern void IIC_Stop();     //����IICͨ����ֹ�ź�
extern bit IIC_Write(uint8 dat);    //IICͨ��д��һ��uint8�͵����ݣ�dat��Ҫд������ݣ����أ�1���ɹ���0��ʧ��
extern uint8 IIC_Read(bit ACK);     //IICͨ�Ŷ���һ��uint8�͵����ݣ�ACK��0����ĩλ���ݣ�1��ĩλ���ݣ������ض���������
extern uint8 PCF8591_Read(uint8 chanl);	//��ȡADת���õ���ֵ����ͨת�����ǲ�֣���chanl��ͨ���ţ����أ�ADֵ

void main()
{
	uint8 dat;
	uint16 temp;
	uint8 LcdBuff[6];
	LCD1602_Init();
	while(1)
	{
		dat=PCF8591_Read(0);
		temp=dat*125/64;
		LcdBuff[0]=temp/100+'0';
	    LcdBuff[1]='.';
		LcdBuff[2]=temp/10%10+'0';
		LcdBuff[3]=temp%10+'0';
		LcdBuff[4]='V';
		LcdBuff[5]='\0';
		LCD1602_Show(0,0,LcdBuff,5);		
	}
}