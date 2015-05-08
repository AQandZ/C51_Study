#ifndef _CONFIG_H_
#define _CONFIG_H_

#include<reg52.h>
#include<intrins.h>

typedef unsigned char uint8;
typedef unsigned int uint16;

#define KEYTIMELIMIT 1000	//���°���������ʱ�佫�ᴥ������ģʽ����0��ʾ�رգ���λ��ms
#define KEYTIMEINC 200		//����ģʽ�У�ÿ��ʱ�䴥��һ�ΰ�����Ӧ����λ��ms

sbit BUZZ=P1^6;
#define LCD1602_DB P0
sbit LCD1602_RS=P1^0;  
sbit LCD1602_RW=P1^1;
sbit LCD1602_E=P1^5;

sbit ADDR3=P1^3;
sbit ENLED=P1^4;

sbit DS1302_CE=P1^7;
sbit DS1302_IO=P3^4;
sbit DS1302_CK=P3^5;

sbit KEYOUT1=P2^3; 
sbit KEYOUT2=P2^2;
sbit KEYOUT3=P2^1;
sbit KEYOUT4=P2^0;
sbit KEYIN1=P2^4;
sbit KEYIN2=P2^5;
sbit KEYIN3=P2^6;
sbit KEYIN4=P2^7;

sbit DS18B20_IO=P3^2;

sbit IIC_SDA=P3^6;
sbit IIC_SCL=P3^7;

#endif
