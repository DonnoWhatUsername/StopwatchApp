#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
int main()
{
	int n=0,hour=0,minute=0,second=0,hour2=0,minute2=0,second2=0,wp=1;
	char tr[1005];
	string c;
	cout<<"Copyright 2020 Z 版权所有"<<endl<<"请输入密码:";
	wrongpassword:cin>>c;
	if(c!="I39B8-2AV8E-9RP7I-6ZWK1-U7B0V"){
		if(wp==5)
		{
			cout<<"已连续输入5次错误密码，不能使用该程序。"<<endl;
			system("pause");
			return 0;
		}
		cout<<"密码错误！请重新输入密码:";
		wp++;
		goto wrongpassword;
	}
	system("cls");
	cout<<"提示：如果输入非数字的字符，后果自负。"<<endl;
	system("pause");
	system("cls");
	cout<<"你想用秒表还是倒计时？"<<endl<<"0:秒表 1:倒计时"<<endl;
	cin>>n;
	while(n!=0&&n!=1)
	{
		cout<<"不符合要求！请输入0或1！"<<endl;
		cin>>n;
	}
	cout<<"请输入开始时的时、分、秒。"<<endl;
	cin>>hour>>minute>>second;
	while(hour<0||minute<0||second<0)
	{
		cout<<"不符合要求！请输入非负数！"<<endl;
		cin>>hour>>minute>>second;
	}
	if(second>59)minute+=second/60,second%=60;
	if(minute>59)hour+=minute/60,minute%=60;
	if(!n)
	{
		cout<<"提示：该秒表准确性依靠系统性能，每分钟约有4秒误差"<<endl<<"若结束计时请按Ctrl+C。"<<endl;
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
		cout<<"提示：该计时器准确性依靠系统性能，每分钟约有4秒误差，请谅解。:)"<<endl<<"若结束计时请按Ctrl+C"<<endl;
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
