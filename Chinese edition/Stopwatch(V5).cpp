#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h>
using namespace std;
int i,n=0,hour=0,minute=0,second=0,hour2=0,minute2=0,second2=0,yh,ym,ys;
char tr[1005];
bool ynply;
void pause()
{
	cout<<"\n\n已暂停...\n按1改变颜色\n按2复位";
	printf("（输入的开始时间是%02d:%02d:%02d",yh,ym,ys);
	if(ym>59||ys>59)cout<<"，已经转换";cout<<"）";
	cout<<"\n按3重新开始\n按其他键继续\n";
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
	MessageBox(NULL,"如果在设置时间时输入非数字的字符，会出现错误，后果自负。","警告",MB_OK);
	MessageBox(NULL,"该秒表准确性依靠系统性能，每分钟约有2秒误差，请谅解:)\n在运行时尽量关闭占用CPU和内存高的应用，可以提高精准度\n若结束计时请按Ctrl+C，暂停计时请按任意键。","提示",MB_OK);
	reply:system("cls");cout<<"你想用秒表还是倒计时？"<<endl<<"0:秒表 1:倒计时"<<endl;
	cin>>n;
	while(n!=0&&n!=1)
	{
		cout<<"不符合要求！请输入0或1！"<<endl;
		cin>>n;
	}
	cout<<"请输入开始时的时、分、秒。"<<endl;
	cin>>hour>>minute>>second;
	yh=hour,ym=minute,ys=second;
	while(hour<0||minute<0||second<0)
	{
		cout<<"不符合要求！请输入非负数！"<<endl;
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
		cout<<"请输入结束时的时、分、秒。"<<endl;
		cin>>hour2>>minute2>>second2;
		if(second2>59)minute2+=second2/60,second2%=60;
		if(minute2>59)hour2+=minute2/60,minute2%=60;
		while(hour2<0||minute2<0||second2<0||hour<hour2||(hour==hour2&&minute<minute2)||(hour==hour2&&minute==minute2&&second<second2))
		{
			cout<<"不符合要求！请输入非负数，而且结束时间<=开始时间！"<<endl;
			cin>>hour2>>minute2>>second2;
			if(second>59)minute+=second/60,second%=60;
			if(minute>59)hour+=minute/60,minute%=60;
		}
		cout<<"请输入作为闹铃的音乐文件路径(最长500个字符)，输入1即播放1000Hz3秒（尽量少用）。"<<endl;
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
