#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h>
using namespace std;
int i,n=0,hour,minute,second,yh=0,ym=0,ys=0,refresh=1000,millis=0;
char tr[1005];
bool ynply;
void exitt()
{
	for(int i=3;i>=1;i--){
		system("cls");
		cout<<"�ü�ʱ����zym����\n2020��6��7��14:43:56���а汾Version6\n��Ȩ���У���Ȩ�ؾ�\n\n��"<<i<<"����˳�";
		Sleep(1000);
	}
	exit(0);
}
void donate()
{
	
}
void settings()
{
	cout<<"\n\n��1�ı���ɫ\n��2�ı�ˢ��Ƶ��";
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
	if(c<'1'||c>'2')goto back;
	cout<<"���óɹ���";
	Sleep(2000);
	back:return;
}
void pause()
{
	system("cls");
	printf("%02d:%02d:%02d.%02d",hour,minute,second,millis);
	cout<<"\n\n����ͣ...\n��1��λ";
	printf("����ʼʱ����%02d:%02d:%02d.00",yh,ym,ys);
	if(ym>59||ys>59)cout<<"���Ѿ�ת��";cout<<"��";
	cout<<"\n��2���¿�ʼ\n��3��������\n��4�˳�\n������������\n";
	getch();
	char c=getch();
	if(c=='1')hour=yh,minute=ym,second=ys;
	if(c=='2')ynply=1;
	if(c=='3')settings();
	if(c=='4')exitt();
	return;
}
int main()
{
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
	cout<<"Version 6\n��zym����\n��Ȩ���У���Ȩ�ؾ�\n��ӭת�أ���ע��������\n";
	system("pause");
	MessageBox(NULL,"���������ʱ��ʱ��������ֵ��ַ������趨ʱ�䳬��596ʱʱ������ִ��󣬺���Ը���","����",MB_OK);
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
			printf("%02d:%02d:%02d.%02d",hour,minute,second,millis);
			last=now;
			for(i=1;i<=5;i++)
			{
				Sleep(refresh/5.0);
				if(kbhit()){
					pause();
					if(ynply){ynply=0;goto reply;}
					last=clock()/10;
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
			printf("%02d:%02d:%02d.%02d",hour,minute,second,millis);
			for(i=1;i<=5;i++)
			{
				Sleep(refresh/5.0);
				if(kbhit()){
					pause();
					if(ynply){ynply=0;goto reply;}
					last=clock()/10;
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
