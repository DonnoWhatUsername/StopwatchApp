#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h>
using namespace std;
int i,n=0,refresh=1000,millis=0;
short hour,minute,second,yh=0,ym=0,ys=0;
char tr[1005];
bool ynply,RunTimeStop=1;
struct a
{
	short hour,minu,sec,mil;
}record[101];
void exitt()
{
	for(int i=3;i>=1;i--){
		system("cls");
		cout<<"�ü�ʱ����zym����\n2020��6��21��14:12:20���а汾Version7\n��Ȩ���У���Ȩ�ؾ�\n\n��"<<i<<"����˳�";
		Sleep(1000);
	}
	exit(0);
}
void settings()
{
	cout<<"\n\n��\tѡ��\n1\t�ı���ɫ\n2\t�ı�ˢ��Ƶ��\n3\t������ʾ�˵�ʱ�Ƿ�ֹͣ��ʱ";
	char c=getch();
	if(c=='1'){
		system("color /?");
		cout<<"color ";
		char a,b;
		cin>>a>>b;
		char tr[10]={'c','o','l','o','r',' ',a,b};
		system(tr);
	}
	if(c=='2'){
		cout<<"\n������ˢ��Ƶ�ʣ��Ժ���Ϊ��λ��1��=1000���룩��";
		cin>>refresh;
	} 
	if(c=='3'){
		cout<<'\n';
		if(RunTimeStop)cout<<"��";
		else cout<<"  ";
		cout<<"��ʾ�˵�ʱֹͣ��ʱ\n��1��ѡ\n���������˳�";
		c=getch();
		if(c=='1')RunTimeStop=!RunTimeStop;
		cout<<'\n';
	}
	if(c<'1'||c>'3')goto back;
	cout<<"���óɹ���";
	Sleep(2000);
	back:return;
}
void pause()
{
//	system("cls");
//	printf("%02d:%02d:%02d.%02d",hour,minute,second,millis);
	if(RunTimeStop)cout<<"\n\n����ͣ...";
	else cout<<"\n\n�˵�";
	cout<<"\n��\tѡ��\n1\t��λ";
	printf("����ʼʱ����%02d:%02d:%02d.00",yh,ym,ys);
	if(ym>59||ys>59)cout<<"���Ѿ�ת��";cout<<"��";
	cout<<"\n2\t���¿�ʼ\n3\t��������\n4\t�˳�\n������\t����\n";
	char c=getch();
	if(c=='1')hour=yh,minute=ym,second=ys;
	if(c=='2')ynply=1;
	if(c=='3')settings();
	if(c=='4')exitt();
	return;
}
int main()
{
	short ret=0;
	system("title Stopwatch");
	cout<<"  *****      *               *\n";
	cout<<"    *      * * *       ************\n";
	cout<<"********  *  *  *            *\n";
	cout<<"   ***   *   *    *    ************\n";
	cout<<"  * * *      *   *           *\n";
	cout<<" *  *  *     *  *      ************\n";
	cout<<"*   *   *      *            * *\n";
	cout<<"*   *   *    **           **   **\n";
	cout<<"    *       *            * * *   *\n";
	cout<<"    *      *            *  **     *\n";
	cout<<"Version 7\n��zym����\n��Ȩ���У���Ȩ�ؾ�\n��ӭת�أ���ע��������\n";
//	system("pause");
	MessageBox(NULL,"���������ʱ��ʱ��������ֵ��ַ�������ִ��󣬺���Ը���","����",MB_OK);
	MessageBox(NULL,"����ͣ��ʱ����ʾѡ���밴�������","��ʾ",MB_OK);
	reply:system("cls");cout<<"����������ǵ���ʱ��"<<endl<<"0:��� 1:����ʱ"<<endl;
	cin>>n;
	while(n!=0&&n!=1)
	{
		cout<<"������Ҫ��������0��1��"<<endl;
		cin>>n;
	}
	int now,last;
	if(!n)
	{
		hour=0,minute=0,second=0;
		system("cls");
		printf("%02d:%02d:%02d.%02d",hour,minute,second,millis);
		last=clock()/10;
		while(1)
		{
			now=clock()/10;
			millis+=now-last;
			if(millis>100)second+=millis/100,millis%=100;
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
	else
	{
		cout<<"���������ʱ��ʱ���֡��롣"<<endl;
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
		cout<<"��������Ϊ����������ļ�·��(�500���ַ�)������1������1000Hz3�롣"<<endl;
		gets(tr);gets(tr);
		system("cls");
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
			for(i=ret;i>0;i--)printf("%02d\t%02d:%02d:%02d.%02d\n",i,record[i].hour,record[i].minu,record[i].sec,record[i].mil);
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
	cout<<"\nTime is over!\n";
	if(tr[0]=='1')Beep(1000,3000);
	else system(tr);
	system("pause");
	return 0;
}
