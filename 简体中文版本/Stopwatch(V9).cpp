#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h>
using namespace std;
short ret,hour,minute,second,yh=0,ym=0,ys=0,refresh=1000,millis,n;
bool ynply,RunTimeStop=1;
struct a
{
	short hour,minu,sec,mil;
}record[101];
void exitt()
{
	for(int i=3;i>=1;i--){
		system("cls");
		cout<<"�ü�ʱ����zym����\n��ǰ�汾Version 8\n��Ȩ���У���Ȩ�ؾ�\n\n��"<<i<<"����˳�";
		Sleep(1000);
	}
	exit(0);
}
void file()
{
	cout<<"\n1\t��������\n2\t��������\n3\t��������\n4\t��������\n��������ʱ�벻Ҫ����ԭ�������\n";
	char c=getch();
	if(c>='1'&&c<='4')cout<<"�������ļ�·����";
	char tr[302];
	gets(tr);gets(tr);
	if(c=='1'||c=='3')freopen(tr,"w",stdout);
	if(c=='2'||c=='4')freopen(tr,"r",stdin);
	if(c=='1'){
	cout<<"Total Time:"<<hour<<':'<<minute<<':'<<second<<'.'<<millis<<"\n";
	cout<<"The number of data:"<<ret;
	if(ret>0){
		cout<<"record:\nnum.\ttime\n";
		for(short i=ret;i>0;i--)printf("%d\t%02d:%02d:%02d.%02d\n",i,record[i].hour,record[i].minu,record[i].sec,record[i].mil);
	}
	}
	if(c=='2'){
	scanf("Total Time:%d:%d:%d.%d",&hour,&minute,&second,&millis);
	scanf("The number of data:%d",&ret);
	if(ret>0){
		scanf("record:\num.\ttime\n");
		short a;
		for(short i=ret;i>0;i--)scanf("%d\t%d:%d:%d.%d",&a,&record[i].hour,&record[i].minu,&record[i].sec,&record[i].mil);
	}
	}
	if(c=='3')cout<<refresh<<endl<<RunTimeStop;
	if(c=='4')cin>>refresh>>RunTimeStop;
	if(c=='1'||c=='3')fclose(stdout);
	if(c=='2'||c=='4')fclose(stdin);
}
void exterior()
{
	cout<<"\n��\tѡ��\n1\t��ɫ\n2\t���ڴ�С\n3\t��ʱ����ʽ\n";
	char c=getch();
	if(c=='1'){
		system("color /?");
		char tr[10];
		gets(tr);
		system(tr);
	}
	if(c=='2'){
		short h,a;
		cout<<"������";cin>>h;
		cout<<"������";cin>>a;
		system("");
	}
}
void settings()
{
	cout<<"\n��\tѡ��\n1\t���\n2\tˢ��Ƶ��\n3\t��ʾ�˵�ʱ�Ƿ�ֹͣ��ʱ\n4\t��ռ�¼\n";
	char c=getch();
	if(c=='1')exterior();
	if(c=='2'){
		cout<<"\n������ˢ��Ƶ�ʣ��Ժ���Ϊ��λ��1��=1000���룩��";
		cin>>refresh;
	} 
	if(c=='3'){
		cout<<'\n';
		if(RunTimeStop)cout<<"��";
		else cout<<"  ";
		cout<<"��ʾ�˵�ʱֹͣ��ʱ\n��1��ѡ";
		c=getch();
		if(c=='1')RunTimeStop=!RunTimeStop;
		cout<<'\n';
	}
	if(c=='4')ret=0;
	if(c<'1'||c>'4')return;
	cout<<"���óɹ���";
	Sleep(1000);
}
void pause()
{
//	system("cls");
//	printf("%02d:%02d:%02d.%02d",hour,minute,second,millis);
	if(RunTimeStop)cout<<"\n\n����ͣ...";
	else cout<<"\n\n�˵�";
	cout<<"\n��\tѡ��\n1\t��λ";
	printf("����ʼʱ����%02d:%02d:%02d.00��",yh,ym,ys);
	cout<<"\n2\t���¿�ʼ\n3\t����\n4\t�ļ�\n5\t�˳�\n������\t����\n";
	char c=getch();
	if(c=='1')hour=yh,minute=ym,second=ys,ret=0;
	if(c=='2')ynply=1;
	if(c=='3')settings();
	if(c=='4')file();
	if(c=='5')exitt();
	return;
}
int main()
{
	short i;
	char tr[305];
	system("title Stopwatch");
	cout<<"��ӭʹ�ü�ʱ��\nVersion 8\n��zym����\n��Ȩ���У���Ȩ�ؾ�";
//	system("pause");
	MessageBox(NULL,"���������ʱ��ʱ��������ֵ��ַ�������ִ��󣬺���Ը���","����",MB_OK);
	reply:ret=0;
	system("cls");cout<<"����������ǵ���ʱ��"<<endl<<"0:��� 1:����ʱ"<<endl;
	cin>>n;
	while(n!=0&&n!=1)
	{
		cout<<"������Ҫ��������0��1��"<<endl;
		cin>>n;
	}
	int now,last;
	if(n==0){
		hour=0,minute=0,second=0,millis=0;
		system("cls");
		printf("%02d:%02d:%02d.%02d",hour,minute,second,millis);
		last=clock()/10;
		while(1)
		{
			now=clock()/10;
			millis+=now-last;
			if(millis>99)second+=millis/100,millis%=100;
			if(second>59)minute++,second-=60;
			if(minute>59)hour++,minute-=60;
			system("cls");
			printf("%02d:%02d:%02d.%02d\n",hour,minute,second,millis);
			if(ret==0){
				cout<<"���ո����¼����������";
				if(RunTimeStop)cout<<"��ͣ";
				else cout<<"��ʾ�˵�";
			}
			else cout<<"���\tʱ��\n";
			for(i=ret;i>0;i--)printf("%d\t%02d:%02d:%02d.%02d\n",i,record[i].hour,record[i].minu,record[i].sec,record[i].mil);
			last=now;
			for(i=1;i<=5;i++)
			{
				Sleep(refresh/5.0);
				if(kbhit()){
					if(getch()==' ')
						if(ret==100)MessageBox(NULL,"���ֻ�ܼ�¼100�Σ�","��ʾ",MB_OK);
						else{
							now=clock()/10;
							millis+=now-last;
							if(millis>100)second+=millis/100,millis%=100;
							if(second>59)minute++,second-=60;
							if(minute>59)hour++,minute-=60;
							record[++ret].hour=hour,record[ret].minu=minute,record[ret].sec=second,record[ret].mil=millis;
						}
					else pause();
					if(ynply){ynply=0;goto reply;}
					if(RunTimeStop)last=clock()/10;
				}
			}
		}
	}
	else{
		cout<<"���������ʱ��ʱ���֡��롣���ÿո��':'������"<<endl;
		cin>>hour>>minute>>second;
		if(second>59)minute+=second/60,second%=60;
		if(minute>59)hour+=minute/60,minute%=60;
		while(hour<0||minute<0||second<0)
		{
			cout<<"������Ҫ��������Ǹ�����"<<endl;
			cin>>hour>>minute>>second;
			if(second>59)minute+=second/60,second%=60;
			if(minute>59)hour+=minute/60,minute%=60;
		}
		yh=hour,ym=minute,ys=second;
		cout<<"��������Ϊ����������ļ�·��(�300���ַ�����C:\\Windows\\media\\Alarm01.wav������1������1000Hz3�롣"<<endl;
		gets(tr);gets(tr);
		system("cls");
		millis=0;
		printf("%02d:%02d:%02d.%02d",hour,minute,second,millis);
		last=clock()/10;
		while(1)
		{
			now=clock()/10;
			millis-=now-last;
			if(millis<0)second+=millis/1000-1,millis=100+millis%100;
			if(second<0)minute--,second+=60;
			if(minute<0)hour--,minute+=60;
			if(hour<0)break;
			system("cls");
			printf("%02d:%02d:%02d.%02d\n",hour,minute,second,millis);
			if(ret==0){
				cout<<"���ո����¼����������";
				if(RunTimeStop)cout<<"��ͣ";
				else cout<<"��ʾ�˵�";
			}
			else cout<<"���\tʱ��\n";
			for(i=ret;i>0;i--)printf("%d\t%02d:%02d:%02d.%02d\n",i,record[i].hour,record[i].minu,record[i].sec,record[i].mil);
			for(i=1;i<=5;i++)
			{
				Sleep(refresh/5.0);
				if(kbhit()){
					if(getch()==' ')
						if(ret==100)MessageBox(NULL,"���ֻ�ܼ�¼100�Σ�","��ʾ",MB_OK);
						else{
							now=clock()/10;
							millis-=now-last;
							if(millis<0)second+=millis/1000-1,millis=100+millis%100;
							if(second<0)minute--,second+=60;
							if(minute<0)hour--,minute+=60;
							record[++ret].hour=hour,record[ret].minu=minute,record[ret].sec=second,record[ret].mil=millis;
						}
					else pause();
					if(ynply){ynply=0;goto reply;}
					if(RunTimeStop)last=clock()/10;
				}
			}
		}
	}
	cout<<"\nTime is over!\n";
	if(tr[0]=='1')Beep(1000,3000);
	else system(tr);
	cout<<"��������(Y/N)";
	char c;
	cin>>c;
	if(c=='Y'||c=='y')goto reply;
	else exitt();
	return 0;
}
