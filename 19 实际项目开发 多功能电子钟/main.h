#ifndef _MAIN_H_
#define _MAIN_H_
#include"config.h"
extern int DS18B20_GetTemp(uint8 *addr);    //��ȡ18B20������¶ȡ���addr��64�ֽڵ�������ţ�skip ROM��addr[0]=0x00�������¶�ֵ��
extern void DS18B20_Start(uint8 *addr);     //����18B20�¶�ת������addr��64�ֽڵ�������ţ�skip ROM��addr[0]=0x00����ÿ�ζ����¶Ⱥ�������������¶�ת����
extern bit DS18B20_Init();  //��ʼ��18B20��Ҳ�����ڼ�������Ƿ���ڡ�����ֵ1��������2���쳣��

extern void LCD1602_Clear();    //LCD1602����
extern void LCD1602_AreaClear(uint8 x,uint8 y,uint8 len);   //LCD1602��Χ������x�������꣬y�������꣬len���������ַ�����
extern void LCD1602_Show(uint8 x,uint8 y,uint8 *dat,uint8 len); //LCD1602��ʾ�ַ�����x�������꣬y�������꣬dat��Ҫ��ʾ���ַ����飬len��Ҫ��ʾ�ĳ��ȣ�
extern void LCD1602_Init(); //LCD1602��ʼ������������������ͷ���á�
extern void LCD1602_CloseCursor();	//�ر�LCD1602���
extern void LCD1602_ShowCursor();	//��LCD1602���
extern void LCD1602_SetLocation(uint8 x,uint8 y);	//����LCD1602���λ��

extern void KeyScan(uint8 ms);	//�ڶ�ʱ���ж��е��ã���ȡ������Ϣ��ms����ʱ����ʱʱ������
extern void KeyDriver();	//����ѭ���е��ã�������������

extern void DS1302_Init(uint8 *dat);  //DS1302��ʼ������������������ͷ���ã�dat�����õ�ʱ��
extern uint8 DS1302_SingleRead(uint8 addr); //DS1302���ֽڶ�ȡ��datΪ��ȡ���ݴ洢λ�ã�addrΪ�Ĵ�����ַ����������ֲ�
extern void DS1302_SingleWrite(uint8 addr,uint8 dat);   //DS1302���ֽ�д�룬datΪд�����ݣ�addrΪ�Ĵ�����ַ����������ֲ�
extern void DS1302_BrustWrite(uint8 *dat);  //DS1302Brustģʽд�룬datΪuint8�͵�ӵ��8��Ԫ�ص�����
extern void DS1302_BrustRead(uint8 *dat);   //DS1302Brustģʽ��ȡ��datΪuint8�͵�ӵ��8��Ԫ�ص�����

extern int DS18B20_GetTemp(uint8 *addr);    //��ȡ18B20������¶ȡ���addr��64�ֽڵ�������ţ�skip ROM��addr[0]=0x00�������¶�ֵ��
extern void DS18B20_Start(uint8 *addr);     //����18B20�¶�ת������addr��64�ֽڵ�������ţ�skip ROM��addr[0]=0x00����ÿ�ζ����¶Ⱥ�������������¶�ת����
extern bit DS18B20_Init();  //��ʼ��18B20��Ҳ�����ڼ�������Ƿ���ڡ�����ֵ1��������2���쳣��

extern void INT0_Init();
extern void Timer1_Init();

struct StructTime{
	uint8 sec;
	uint8 min;
	uint8 hour;
	uint8 day;
	uint8 month;
	uint8 week;
	uint8 year;
}; 
struct StructAlarm{
	uint8 sec;
	uint8 min;
	uint8 hour;
	uint8 run;
};
extern struct StructAlarm alarm;
extern struct StructTime time;
extern bit Flag_200ms,Flag_2s,LED_Refresh;
extern bit Flag_IR;
extern uint8 IRBuff[4];

void Timer0_Init(uint8 ms);
void Timer2_Init(uint8 ms);
void DS1302_Set();
void ToBCD(uint8 *dat);
void ToUint8(uint8 *dat);
void TimeRefresh(bit flag);
void LCD1602_Refresh();
void ExitTimeSet(bit flag);
void RefreshCursor();
void IR_Action(uint8 IRCode);
void KeyAction(uint8 keyc,uint8 statu);

#endif