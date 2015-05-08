#include<reg51.h>
typedef char int8;
typedef unsigned char uint8;
typedef unsigned int uint16;
typedef long int32;
sbit ADDR0=P1^0;
sbit ADDR1=P1^1;
sbit ADDR2=P1^2;
sbit ADDR3=P1^3;
sbit ENLED=P1^4;
sbit KEYOUT4=P2^0;
sbit KEYOUT3=P2^1;
sbit KEYOUT2=P2^2;
sbit KEYOUT1=P2^3;
sbit KEYIN1=P2^4;
sbit KEYIN2=P2^5;
sbit KEYIN3=P2^6;
sbit KEYIN4=P2^7;
uint8 p=0,p1=0,flag=0xff;
unsigned char code LedChar[]={
	0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
	0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E,
	0xff
	};
uint8 num[6]={0x00,0x00,0x00,0x00,0x00,0x00};
uint8 key[4][4]={{0xff,0xff,0xff,0xff},
				 {0xff,0xff,0xff,0xff},
				 {0xff,0xff,0xff,0xff},
				 {0xff,0xff,0xff,0xff}
				};
uint8 keycode[4][4]={ //���󰴼���ŵ���׼���̼����ӳ���
	{ 0x31, 0x32, 0x33, 0x26 }, //���ּ�1�����ּ�2�����ּ�3�����ϼ�
    { 0x34, 0x35, 0x36, 0x25 }, //���ּ�4�����ּ�5�����ּ�6�������
    { 0x37, 0x38, 0x39, 0x28 }  //���ּ�7�����ּ�8�����ּ�9�����¼�
    { 0x30, 0x1B, 0x0D, 0x27 }, //���ּ�0��ESC����  �س����� ���Ҽ�

};
uint8 keystatu[4][4]={{0xff,0xff,0xff,0xff},
				 {0xff,0xff,0xff,0xff},
				 {0xff,0xff,0xff,0xff},
				 {0xff,0xff,0xff,0xff}
				};
void led(int32 n)
{
	int8 i;
	if(n<0){n=-n;flag=0;}
	else flag=0xff;
	for(i=0;i<6;i++)
	{
		num[i]=n%10;
		n=n/10;
	}
}
void operate(uint8 keycode)
{
	static int32 temp=0,answer=0;
	static last=0x00;
	if(keycode>=0x30&&keycode<=0x39)//����
	{
		temp=temp*10+keycode-0x30;
		led(temp);
	}
	if(keycode==0x26) //���� ��
	{
		 if(last==0x26)answer+=temp;
		 else if(last==0x28)answer-=temp;
		 else if(last==0x25)answer*=temp;
		 else if(last==0x27)answer/=temp;
		 else answer=temp;
		 temp=0;
		 led(answer);
		 last=0x26;
	}
	if(keycode==0x28) //���� ��
	{
		 if(last==0x26)answer+=temp;
		 else if(last==0x28)answer-=temp;
		 else if(last==0x25)answer*=temp;
		 else if(last==0x27)answer/=temp;
		 else answer=temp;
		 temp=0;
		 led(answer);
		 last=0x28;
	}
	if(keycode==0x25) //���� ��
	{
		 if(last==0x26)answer+=temp;
		 else if(last==0x28)answer-=temp;
		 else if(last==0x25)answer*=temp;
		 else if(last==0x27)answer/=temp;
		 else answer=temp;
		 temp=0;
		 led(answer);
		 last=0x25;
	}
	if(keycode==0x27) //����  ��
	{
		 if(last==0x26)answer+=temp;
		 else if(last==0x28)answer-=temp;
		 else if(last==0x25)answer*=temp;
		 else if(last==0x27)answer/=temp;
		 else answer=temp;
		 temp=0;
		 led(answer);
		 last=0x27;
	}
	if(keycode==0x1B)  //ESC
	{
		 answer=0;
		 temp=0;
		 last=0;
		 led(0);
	}
	if(keycode==0x0D)	//�س�
	{
		 if(last==0x26)answer+=temp;
		 else if(last==0x28)answer-=temp;
		 else if(last==0x25)answer*=temp;
		 else if(last==0x27)answer/=temp;
		 else answer=temp;
		 temp=0;
		 led(answer);
	}
}
void refreshled()
{
	 int8 i,j;
	 for(i=0;i<4;i++)
	 	for(j=0;j<4;j++)
			if(keystatu[i][j]==0)
				{
					keystatu[i][j]=0xff;
					operate(keycode[i][j]);
				}
	 for(i=5;i>=1;i--)
	 	{
			if(num[i]!=0)break;
			else num[i]=16;
		}
	 P0=0Xff;
	 switch(p)
	 {
	 	case 0:ADDR1=0;ADDR2=0;P0=LedChar[num[p]];break;
		case 1:ADDR0=1;P0=LedChar[num[p]];break;
		case 2:ADDR0=0;ADDR1=1;P0=LedChar[num[p]];break;
		case 3:ADDR0=1;P0=LedChar[num[p]];break;
		case 4:ADDR0=0;ADDR1=0;ADDR2=1;P0=LedChar[num[p]];break;
		case 5:ADDR0=1;P0=LedChar[num[p]];break;
		case 6:ADDR0=0;ADDR1=1;P0=flag;break;
	 }
	 p++;
	 if(p>=7)p=0;
}
void main()
{
	ADDR3=1;
	ENLED=0;
	ADDR1=0;
	TH0=0XFC;
	TL0=0X67;
	TMOD=0X01;
	KEYOUT1=0;
	EA=1;
	ET0=1;
	TR0=1;
	while(1)
	{
		refreshled();
	}
}
void scan() interrupt 1
{
	TH0=0XFC;
	TL0=0X67;
	key[p1][0]=(key[p1][0]<<1)|KEYIN1;
	key[p1][1]=(key[p1][1]<<1)|KEYIN2;
	key[p1][2]=(key[p1][2]<<1)|KEYIN3;
	key[p1][3]=(key[p1][3]<<1)|KEYIN4;
	if((key[p1][0]&0x0f)==0x00)
	{
		if(key[p1][0])
			keystatu[p1][0]=0;
		key[p1][0]=0x00;
	}
	else if((key[p1][0]&0x0f)==0x0f)
	{
		if(!key[p1][0])
			keystatu[p1][0]=1;
		key[p1][0]=0xff;
	}

	if((key[p1][1]&0x0f)==0x00)
	{
		if(key[p1][1])
			keystatu[p1][1]=0;
		key[p1][1]=0x00;
	}
	else if((key[p1][1]&0x0f)==0x0f)
	{
		if(!key[p1][1])
			keystatu[p1][1]=1;
		key[p1][1]=0xff;
	}

	if((key[p1][2]&0x0f)==0x00)
	{
		if(key[p1][2])
			keystatu[p1][2]=0;
		key[p1][2]=0x00;
	}
	else if((key[p1][2]&0x0f)==0x0f)
	{
		if(!key[p1][2])
			keystatu[p1][2]=1;
		key[p1][2]=0xff;
	}

	if((key[p1][3]&0x0f)==0x00)
	{
		if(key[p1][3])
			keystatu[p1][3]=0;
		key[p1][3]=0x00;
	}
	else if((key[p1][3]&0x0f)==0x0f)
	{
		if(!key[p1][3])
			keystatu[p1][3]=1;
		key[p1][3]=0xff;
	}
	switch(p1)
	{
		case 0: KEYOUT4=1;KEYOUT1=0;break;
		case 1: KEYOUT1=1;KEYOUT2=0;break;
		case 2: KEYOUT2=1;KEYOUT3=0;break;
		case 3: KEYOUT3=1;KEYOUT4=0;break;
	}
	p1++;
	if(p1>=4)p1=0;
}
