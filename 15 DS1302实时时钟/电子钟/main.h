#ifndef MAINH
#define MAINH
typedef unsigned char uint8;
typedef unsigned int uint16;

extern void KeyScan();	//�ڶ�ʱ���ж��е��ã���ȡ������Ϣ
extern void KeyDriver();	//����ѭ���е��ã�������������

extern void LCD1602_Clear();    //LCD1602����
extern void LCD1602_AreaClear(uint8 x,uint8 y,uint8 len);   //LCD1602��Χ������x�������꣬y�������꣬len���������ַ�����
extern void LCD1602_Show(uint8 x,uint8 y,uint8 *dat,uint8 len); //LCD1602��ʾ�ַ�����x�������꣬y�������꣬dat��Ҫ��ʾ���ַ����飬len��Ҫ��ʾ�ĳ��ȣ�
extern void LCD1602_Init(); //LCD1602��ʼ������������������ͷ���á�
extern void LCD1602_CloseCursor();	//�ر�LCD1602���
extern void LCD1602_ShowCursor();	//��LCD1602���
extern void LCD1602_SetLocation(uint8 x,uint8 y);	//����LCD1602���λ��

extern void DS1302_Init(uint8 *dat);  //DS1302��ʼ������������������ͷ���ã�dat�����õ�ʱ��
extern uint8 DS1302_SingleRead(uint8 addr); //DS1302���ֽڶ�ȡ��datΪ��ȡ���ݴ洢λ�ã�addrΪ�Ĵ�����ַ����������ֲ�
extern void DS1302_SingleWrite(uint8 addr,uint8 dat);   //DS1302���ֽ�д�룬datΪд�����ݣ�addrΪ�Ĵ�����ַ����������ֲ�
extern void DS1302_BrustWrite(uint8 *dat);  //DS1302Brustģʽд�룬datΪuint8�͵�ӵ��8��Ԫ�ص�����
extern void DS1302_BrustRead(uint8 *dat);   //DS1302Brustģʽ��ȡ��datΪuint8�͵�ӵ��8��Ԫ�ص�����

void Timer0_Init(uint8 ms);
void DS1302_Set();
void ToBCD(uint8 *dat);
void ToUint8(uint8 *dat);
void TimeRefresh();
void LCD1602_Refresh();
void ExitTimeSet(bit flag);
void RefreshCursor();

#endif