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
		cout<<"该计时器由zym制作\n2020年6月21日14:12:20发行版本Version7\n版权所有，侵权必究\n\n在"<<i<<"秒后退出";
		Sleep(1000);
	}
	exit(0);
}
void settings()
{
	cout<<"\n\n按\t选项\n1\t改变颜色\n2\t改变刷新频率\n3\t设置显示菜单时是否停止计时";
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
		cout<<"\n请输入刷新频率（以毫秒为单位，1秒=1000毫秒）：";
		cin>>refresh;
	} 
	if(c=='3'){
		cout<<'\n';
		if(RunTimeStop)cout<<"√";
		else cout<<"  ";
		cout<<"显示菜单时停止计时\n按1反选\n按其他键退出";
		c=getch();
		if(c=='1')RunTimeStop=!RunTimeStop;
		cout<<'\n';
	}
	if(c<'1'||c>'3')goto back;
	cout<<"设置成功！";
	Sleep(2000);
	back:return;
}
void pause()
{
//	system("cls");
//	printf("%02d:%02d:%02d.%02d",hour,minute,second,millis);
	if(RunTimeStop)cout<<"\n\n已暂停...";
	else cout<<"\n\n菜单";
	cout<<"\n按\t选项\n1\t复位";
	printf("（开始时间是%02d:%02d:%02d.00",yh,ym,ys);
	if(ym>59||ys>59)cout<<"，已经转换";cout<<"）";
	cout<<"\n2\t重新开始\n3\t进入设置\n4\t退出\n其他键\t继续\n";
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
	cout<<"Version 7\n由zym制作\n版权所有，侵权必究\n欢迎转载（请注明出处）\n";
//	system("pause");
	MessageBox(NULL,"如果在设置时间时输入非数字的字符，会出现错误，后果自负。","警告",MB_OK);
	MessageBox(NULL,"若暂停计时并显示选项请按任意键。","提示",MB_OK);
	reply:system("cls");cout<<"你想用秒表还是倒计时？"<<endl<<"0:秒表 1:倒计时"<<endl;
	cin>>n;
	while(n!=0&&n!=1)
	{
		cout<<"不符合要求！请输入0或1！"<<endl;
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
				cout<<"按空格键记录，按其他键";
				if(RunTimeStop)cout<<"暂停";
				else cout<<"显示菜单";
			}
			else cout<<"编号\t时间\n";
			for(i=ret;i>0;i--)printf("%d\t%02d:%02d:%02d.%02d\n",i,record[i].hour,record[i].minu,record[i].sec,record[i].mil);
			last=now;
			for(i=1;i<=5;i++)
			{
				Sleep(refresh/5.0);
				if(kbhit()){
					if(getch()==' ')
						if(ret==100)MessageBox(NULL,"最多只能记录100次！","提示",MB_OK);
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
		cout<<"请输入需计时的时、分、秒。"<<endl;
		cin>>hour>>minute>>second;
		if(second>59)minute+=second/60,second%=60;
		if(minute>59)hour+=minute/60,minute%=60;
		while(hour<0||minute<0||second<0)
		{
			cout<<"不符合要求，请输入非负数！"<<endl;
			cin>>hour>>minute>>second;
			if(second>59)minute+=second/60,second%=60;
			if(minute>59)hour+=minute/60,minute%=60;
		}
		yh=hour,ym=minute,ys=second;
		cout<<"请输入作为闹铃的音乐文件路径(最长500个字符)，输入1即播放1000Hz3秒。"<<endl;
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
				cout<<"按空格键记录，按其他键";
				if(RunTimeStop)cout<<"暂停";
				else cout<<"显示菜单";
			}
			else cout<<"编号\t时间\n";
			for(i=ret;i>0;i--)printf("%02d\t%02d:%02d:%02d.%02d\n",i,record[i].hour,record[i].minu,record[i].sec,record[i].mil);
			for(i=1;i<=5;i++)
			{
				Sleep(refresh/5.0);
				if(kbhit()){
					if(getch()==' ')
						if(ret==100)MessageBox(NULL,"最多只能记录100次！","提示",MB_OK);
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
