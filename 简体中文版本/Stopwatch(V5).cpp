#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h>
using namespace std;
int i,n=0,hour=0,minute=0,second=0,hour2=0,minute2=0,second2=0,yh,ym,ys;
char tr[1005];
bool ynply;
void pause()
{
	cout<<"\n\n����ͣ...\n��1�ı���ɫ\n��2��λ";
	printf("������Ŀ�ʼʱ����%02d:%02d:%02d",yh,ym,ys);
	if(ym>59||ys>59)cout<<"���Ѿ�ת��";cout<<"��";
	cout<<"\n��3���¿�ʼ\n������������\n";
	getch();
	char c=getch(),a,b;
	if(c=='2')hour=yh,minute=ym,second=ys;
	if(c=='3')ynply=1;
	if(c!='1')return;
	cout<<endl;
	system("color /?");
	cout<<"color ";
	cin>>a>>b;
	char tr[10]={'c','o','l','o','r',' ',a,b};
	system(tr);
}
int main()
{
	system("title Stopwatch");
	MessageBox(NULL,"���������ʱ��ʱ��������ֵ��ַ�������ִ��󣬺���Ը���","����",MB_OK);
	MessageBox(NULL,"�����׼ȷ������ϵͳ���ܣ�ÿ����Լ��2�������½�:)\n������ʱ�����ر�ռ��CPU���ڴ�ߵ�Ӧ�ã�������߾�׼��\n��������ʱ�밴Ctrl+C����ͣ��ʱ�밴�������","��ʾ",MB_OK);
	reply:system("cls");cout<<"����������ǵ���ʱ��"<<endl<<"0:��� 1:����ʱ"<<endl;
	cin>>n;
	while(n!=0&&n!=1)
	{
		cout<<"������Ҫ��������0��1��"<<endl;
		cin>>n;
	}
	cout<<"�����뿪ʼʱ��ʱ���֡��롣"<<endl;
	cin>>hour>>minute>>second;
	yh=hour,ym=minute,ys=second;
	while(hour<0||minute<0||second<0)
	{
		cout<<"������Ҫ��������Ǹ�����"<<endl;
		cin>>hour>>minute>>second;
	}
	if(second>59)minute+=second/60,second%=60;
	if(minute>59)hour+=minute/60,minute%=60;
	if(!n)
	{
		system("cls");
		printf("%02d:%02d:%02d",hour,minute,second);
		while(1)
		{
			second++;
			if(second>59)minute++,second=0;
			if(minute>59)hour++,minute=0;
			system("cls");
			printf("%02d:%02d:%02d",hour,minute,second);
			for(i=1;i<=5;i++)
			{
				Sleep(200);
				if(kbhit()){
					pause();
					if(ynply){ynply=0;goto reply;}
				}
			}
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
		system("cls");
		printf("%02d:%02d:%02d",hour,minute,second);
		while(1)
		{
			second--;
			if(second<0)minute--,second=59;
			if(minute<0)hour--,minute=59;
			system("cls");
			printf("%02d:%02d:%02d",hour,minute,second);
			for(i=1;i<=5;i++)
			{
				Sleep(200);
				if(kbhit()){
					pause();
					if(ynply){ynply=0;goto reply;}
				}
			}
			if(hour==hour2&&minute==minute2&&second==second2)break;
		}
	}
	cout<<endl<<"Time is over!";
	if(tr[0]=='1')Beep(1000,3000);
	else system(tr);
	system("pause");
	return 0;
}
