#include<iostream>
#include<cstdio>
#include<Windows.h>
#include<conio.h>
#include<time.h>
using namespace std;
short ret,hour,minute,second,yh=0,ym=0,ys=0,refresh=1000,millis,n,k=2;
bool ynply,RunTimeStop=1,theme=0;
struct a
{
	short hour,minu,sec,mil;
}record[101];
void exitt()
{
	for(int i=3;i>=1;i--){
		system("cls");
		cout<<"该计时器由zym制作\n当前版本Version 9\n发行时间:2020年7月7日11:09:35\n版权所有，侵权必究\n\n在"<<i<<"秒后退出";
		Sleep(1000);
	}
	exit(0);
}
void file()
{
	cout<<"\n1\t保存数据\n2\t载入数据\n3\t保存设置（除颜色）\n4\t载入设置\n导入数据时请不要更改原输出数据\n";
	char c=getch(),tr[302];
	if(c>='1'&&c<='2'){
		cout<<"请输入文件路径：";
	gets(tr);gets(tr);
	}
	if(c=='1'){freopen(tr,"w",stdout);
	printf("Total Time:%02d:%02d:%02d.%02d\n",hour,minute,second,millis);
	cout<<"The number of data:"<<ret;
	if(ret>0){
		cout<<"\nrecord:\nnum.\ttime\n";
		for(short i=ret;i>0;i--)printf("%d\t%02d:%02d:%02d.%02d\n",i,record[i].hour,record[i].minu,record[i].sec,record[i].mil);
	}
	}
	if(c=='2'){freopen(tr,"r",stdin);
	scanf("Total Time:%d:%d:%d.%d\n",&hour,&minute,&second,&millis);
	scanf("The number of data:%d\n",&ret);
	if(ret>0){
		scanf("record:\nnum.\ttime\n");
		short a;
		for(short i=ret;i>0;i--)scanf("%d\t%d:%d:%d.%d",&a,&record[i].hour,&record[i].minu,&record[i].sec,&record[i].mil);
	}
	}
	if(c=='3'){
	freopen("StopwatchData.dll","w",stdout);
	cout<<ynply<<endl<<RunTimeStop<<endl<<refresh<<endl<<theme<<endl<<k;/*save(tr);*/
	}
	if(c=='4'){
	freopen("StopwatchData.dll","r",stdin);
	cin>>ynply>>RunTimeStop>>refresh>>theme>>k;/*load(tr);*/
	}
	if(c=='1'||c=='3')fclose(stdout);
	if(c=='2'||c=='4')fclose(stdin);
}
void exterior()
{
	cout<<"\n按\t选项\n1\t颜色\n2\t窗口大小\n3\t计时器样式\n";
	char c=getch();
	if(c=='1'){
		system("color /?");
		char tr[10];
		gets(tr);
		system(tr);
	}
	if(c=='2'){
		cout<<"右击标题栏，选择\"默认值\"或\"属性\"，在\"布局\"选项卡下更改。";
		cout<<"或在cmd中输入\"mode con cols=_ lines=_\"";
		system("pause");
	}
	if(c=='3'){
		cout<<"当前样式：";
		if(theme)cout<<"不";
		cout<<"正常样式\n按1反选\n";
		c=getch();
		if(c=='1')theme=!theme;
		if(theme){
			cout<<"大小：";
			cin>>k;
		}
	}
}
void settings()
{
	cout<<"\n按\t选项\n1\t外观\n2\t刷新频率\n3\t显示菜单时是否停止计时\n4\t清空记录\n";
	char c=getch();
	if(c=='1')exterior();
	if(c=='2'){
		cout<<"\n请输入刷新频率（以毫秒为单位，1秒=1000毫秒）：";
		cin>>refresh;
	} 
	if(c=='3'){
		cout<<'\n';
		if(RunTimeStop)cout<<"√";
		else cout<<"  ";
		cout<<"显示菜单时停止计时\n按1反选";
		c=getch();
		if(c=='1')RunTimeStop=!RunTimeStop;
		cout<<'\n';
	}
	if(c=='4')ret=0;
	if(c<'1'||c>'4')return;
	cout<<"设置成功！";
	Sleep(1000);
}
void pause()
{
	if(RunTimeStop)cout<<"\n\n已暂停...";
	else cout<<"\n\n菜单";
	cout<<"\n按\t选项\n1\t复位";
	printf("（开始时间是%02d:%02d:%02d.00）",yh,ym,ys);
	cout<<"\n2\t重新开始\n3\t设置\n4\t文件\n5\t退出\n其他键\t继续\n";
	char c=getch();
	if(c=='1')hour=yh,minute=ym,second=ys,ret=0;
	if(c=='2')ynply=1;
	if(c=='3')settings();
	if(c=='4')file();
	if(c=='5')exitt();
	return;
}
void ec(short a,short b,short c,short d)
{
	char s[13];
    string m[10]={"-|| ||-","  |  | ","- |-| -","- |- |-"," ||- | ","-| - |-","-| -||-","- |  | ","-||-||-","-||- |-"};
//	itoa(a,s,10);
s[0]='0'+a/100;s[1]='0'+a/10;s[2]='0'+a%10;s[3]='0'+b/10;s[4]='0'+b%10;s[5]='0'+c/10;s[6]='0'+c%10;
s[7]='0'+d/10;s[8]='0'+d%10;
    for(int p=0;p<7;p++){
        if(p==2||p==5)continue;
        if(p%3==0){
            for(int i=0;i<strlen(s);i++){
                cout<<' ';
                for(int j=0;j<k;j++)cout<<m[s[i]-48][p];
                cout<<"  ";
            }
            cout<<endl;        
        }else for(int q=0;q<k;q++){
            for(int i=0;i<strlen(s);i++){
                cout<<m[s[i]-48][p];
                for(int j=0;j<k;j++)cout<<' ';
                cout<<m[s[i]-48][p+1]<<' ';
            }
            cout<<endl;
        }
    }
}
int main()
{
	short i;
	system("title Stopwatch");
	cout<<"欢迎使用计时器\nVersion 9\n由zym制作\n版权所有，侵权必究";
	MessageBox(NULL,"如果在设置时间时输入非数字的字符，会出现错误，后果自负。","警告",MB_OK);
	reply:ret=0;
	system("cls");cout<<"你想用秒表还是倒计时？"<<endl<<"0:秒表 1:倒计时"<<endl;
	cin>>n;
	while(n!=0&&n!=1)
	{
		cout<<"不符合要求！请输入0或1！"<<endl;
		cin>>n;
	}
	int now,last;
	if(n==0){
		hour=0,minute=0,second=0,millis=0;
		system("cls");
		if(theme==0)printf("%02d:%02d:%02d.%02d\n",hour,minute,second,millis);
		else if(theme=1)ec(hour,minute,second,millis);
		last=clock()/10;
		while(1)
		{
			now=clock()/10;
			millis+=now-last;
			if(millis>99)second+=millis/100,millis%=100;
			if(second>59)minute++,second-=60;
			if(minute>59)hour++,minute-=60;
			system("cls");
			if(theme==0)printf("%02d:%02d:%02d.%02d\n",hour,minute,second,millis);
			else if(theme=1)ec(hour,minute,second,millis);
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
							if(millis>99)second+=millis/100,millis%=100;
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
		cout<<"请输入需计时的时、分、秒。（用空格或':'隔开）"<<endl;
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
		cout<<"请输入作为闹铃的音乐文件路径(最长300个字符，如C:\\Windows\\media\\Alarm01.wav）输入1即播放1000Hz3秒。"<<endl;
		char tr[305];
		gets(tr);gets(tr);
		system("cls");
		millis=0;
		if(theme==0)printf("%02d:%02d:%02d.%02d\n",hour,minute,second,millis);
		else if(theme=1)ec(hour,minute,second,millis);
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
			if(theme==0)printf("%02d:%02d:%02d.%02d\n",hour,minute,second,millis);
			else if(theme=1)ec(hour,minute,second,millis);
			if(ret==0){
				cout<<"按空格键记录，按其他键";
				if(RunTimeStop)cout<<"暂停";
				else cout<<"显示菜单";
			}
			else cout<<"编号\t时间\n";
			for(i=ret;i>0;i--)printf("%d\t%02d:%02d:%02d.%02d\n",i,record[i].hour,record[i].minu,record[i].sec,record[i].mil);
			for(i=1;i<=5;i++)
			{
				Sleep(refresh/5.0);
				if(kbhit()){
					if(getch()==' ')
						if(ret==100)MessageBox(NULL,"最多只能记录100次！","提示",MB_OK);
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
	cout<<"\nTime is over!\n";
	if(tr[0]=='1')Beep(1000,3000);
	else system(tr);
	}
	cout<<"想再来吗？(Y/N)";
	char c;
	cin>>c;
	if(c=='Y'||c=='y')goto reply;
	else exitt();
	return 0;
}
