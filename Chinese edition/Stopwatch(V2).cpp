#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
int main()
{
	int n=0,hour=0,minute=0,second=0,hour2=0,minute2=0,second2=0,wp=1;
	char tr[1005];
	string c;
	cout<<"Copyright 2020 Z ��Ȩ����"<<endl<<"����������:";
	wrongpassword:cin>>c;
	if(c!="I39B8-2AV8E-9RP7I-6ZWK1-U7B0V"){
		if(wp==5)
		{
			cout<<"����������5�δ������룬����ʹ�øó���"<<endl;
			system("pause");
			return 0;
		}
		cout<<"���������������������:";
		wp++;
		goto wrongpassword;
	}
	system("cls");
	cout<<"��ʾ�������������ֵ��ַ�������Ը���"<<endl;
	system("pause");
	system("cls");
	cout<<"����������ǵ���ʱ��"<<endl<<"0:��� 1:����ʱ"<<endl;
	cin>>n;
	while(n!=0&&n!=1)
	{
		cout<<"������Ҫ��������0��1��"<<endl;
		cin>>n;
	}
	cout<<"�����뿪ʼʱ��ʱ���֡��롣"<<endl;
	cin>>hour>>minute>>second;
	while(hour<0||minute<0||second<0)
	{
		cout<<"������Ҫ��������Ǹ�����"<<endl;
		cin>>hour>>minute>>second;
	}
	if(second>59)minute+=second/60,second%=60;
	if(minute>59)hour+=minute/60,minute%=60;
	if(!n)
	{
		cout<<"��ʾ�������׼ȷ������ϵͳ���ܣ�ÿ����Լ��4�����"<<endl<<"��������ʱ�밴Ctrl+C��"<<endl;
		system("pause");
		system("cls");
		printf("%02d:%02d:%02d",hour,minute,second);
		while(1)
		{
			second++;
			if(second>59)minute++,second=0;
			if(minute>59)hour++,minute=0;
			system("cls");
			printf("%02d:%02d:%02d",hour,minute,second);
			Sleep(1000);
		}
	}
	else
	{
		cout<<"���������ʱ��ʱ���֡��롣"<<endl;
		cin>>hour2>>minute2>>second2;
		if(second2>59)minute2+=second2/60,second2%=60;
		if(minute2>59)hour2+=minute2/60,minute2%=60;
		while(hour2<0||minute2<0||second2<0||hour<hour2||(hour==hour2&&minute<minute2)||(hour==hour2&&minute==minute2&&second<second2))
		{
			cout<<"������Ҫ��������Ǹ��������ҽ���ʱ��<=��ʼʱ�䣡"<<endl;
			cin>>hour2>>minute2>>second2;
			if(second>59)minute+=second/60,second%=60;
			if(minute>59)hour+=minute/60,minute%=60;
		}
		cout<<"��������Ϊ����������ļ�·��(�500���ַ�)������1������1000Hz3�루�������ã���"<<endl;
		gets(tr);gets(tr);
		cout<<"��ʾ���ü�ʱ��׼ȷ������ϵͳ���ܣ�ÿ����Լ��4�������½⡣:)"<<endl<<"��������ʱ�밴Ctrl+C"<<endl;
		system("pause");
		system("cls");
		printf("%02d:%02d:%02d",hour,minute,second);
		while(1)
		{
			second--;
			if(second<0)minute--,second=59;
			if(minute<0)hour--,minute=59;
			system("cls");
			printf("%02d:%02d:%02d",hour,minute,second);
			Sleep(1000);
			if(hour==hour2&&minute==minute2&&second==second2)break;
		}
	}
	cout<<endl<<"Time is over!";
	if(tr[0]=='1')Beep(1000,3000);
	else system(tr);
	system("pause");
	return 0;
}
