//惨痛经历：切忌用Visual Studio Code保存!
//Bad experience: Don't save in Visual Studio Code!
#include <iostream>
#include <cstdio>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <io.h>
#define STDOUT 1
using namespace std;
short ret, hour, minute, second, yh = 0, ym = 0, ys = 0, millis, n, k = 2, jdtl = 10, zhouqi = 5;
bool ynply, RunTimeStop = 1, theme = 0, jdt = 0;
int refresh = 1000;
struct a
{
	short hour, minu, sec, mil;
} record[101];
void exitt(bool sffh)
{
	system("cls");
	cout << "该计时器由zym制作\n当前版本Version 13（稳定版）\n";
	cout << "发行时间:2021年2月10日\n版权所有，侵权必究\n";
	if (sffh)
		cout << "\n按任意键返回";
	cout << "\n在 3 秒后退出\b\b\b\b\b\b\b\b\b";
	for (int i = 3; i >= 1; i--)
	{
		cout << "\b" << i;
		Sleep(1000);
		if (sffh && kbhit())
		{
			system("cls");
			return;
		}
	}
	exit(0);
}
void problem()
{
	int choi = MessageBox(NULL, "你刚才输入了字符或过大/小的数字，出现错误。", "警告", MB_ABORTRETRYIGNORE | MB_ICONERROR);
	if (choi == IDRETRY)
	{
		system("cls&&cd .&&start %cd%\\\"Stopwatch.exe\"");
		exit(0);
	}
	if (choi == IDABORT)
		exitt(0);
}
void file()
{
	cout << "\n1\t保存数据\n2\t保存设置（除颜色及窗口大小）\n3\t载入设置\nTip:导入数据时请不要更改原输出数据\n";
	char c = getch(), tr[303] = {' '};
	if (c == '1')
	{
		cout << "请输入文件路径：";
		while (strlen(tr) < 2)
			gets(tr);
	}
	if (c == '1')
	{
		int oldstdout = dup(STDOUT);
		freopen(tr, "w", stdout);
		SYSTEMTIME sys;
		GetLocalTime(&sys);
		//printf("Save Time:%d年%d月%d日%d时%d分%d秒%d毫秒\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds);
		printf("Start Time:%02d:%02d:%02d\n", yh, ym, ys);
		printf("Now:%02d:%02d:%02d.%02d\n", hour, minute, second, millis);
		cout << "The number of data:" << ret;
		if (ret > 0)
		{
			cout << "\nrecord:\tnum.\ttime\n";
			for (short i = ret; i > 0; i--)
				printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
		}
		freopen("CON", "w", stdout);
		dup2(oldstdout, STDOUT);
	}
	/*if (c == '4')
	{
		ifstream fin(tr);
		string c;
		short a,i;
		char c2;
		for (i = 1;i<=11;i++)fin>>c2;
		fin >> yh >> c2 >> ym >> c2 >> ys;
		for (i = 1;i<=4;i++)fin>>c2;
		fin >> hour >>c2>> minute >>c2>> second >>c2>> millis;
		for (i = 1;i<=18;i++)fin>>c2;
		fin >> ret;
		if (ret > 0)
		{
			fin>>tr;
			short a;
			for(short i=ret;i>0;i--)fin>>a>>record[i].hour>>c2>>record[i].minu>>c2>>record[i].sec>>c2>>record[i].mil;
		}
	}*/
	if (c == '2')
	{
		int oldstdout = dup(STDOUT);
		freopen("StopwatchData.db", "w", stdout);
		cout << ynply << endl
			 << RunTimeStop << endl
			 << refresh << endl
			 << theme << endl
			 << k << endl
			 << jdt << endl
			 << jdtl << endl
			 << zhouqi << endl; /*save(tr);*/
		freopen("CON", "w", stdout);
		dup2(oldstdout, STDOUT);
	}
	if (c == '3')
	{
	fileretry:
		ifstream fin("StopwatchData.db");
		//	freopen("StopwatchData.dll","r",stdin);
		if (!fin)
		{
			int cho = MessageBox(NULL, "设置文件不存在！", "载入失败", MB_RETRYCANCEL | MB_ICONERROR);
			if (cho == IDRETRY)
				goto fileretry;
			return;
		}
		fin >> ynply >> RunTimeStop >> refresh >> theme >> k >> jdt >> jdtl >> zhouqi; /*load(tr);*/
		fin.close();
	}
	//	if(c=='2'||c=='4')freopen("CON","r",stdin);
}
void exterior()
{
	cout << "\n按\t选项\n1\t颜色\n2\t窗口大小\n3\t计时器样式\n4\t进度条（设置仅对倒计时起作用）\n";
	char c = getch();
	if (c == '1')
	{
		system("color /?");
		char c[15] = {' '};
		while (strlen(c) < 2)
			gets(c);
		system(c);
	}
	if (c == '2')
	{
		cout << "右击标题栏，选择\"默认值\"或\"属性\"，在\"布局\"选项卡下更改。或\n";
		system("mode con /?");
		char c[35] = {' '};
		while (strlen(c) < 2)
			gets(c);
		system(c);
	}
	if (c == '3')
	{
		cout << "当前样式：";
		if (theme)
			cout << "不";
		cout << "正常样式\n按1反选\n";
		c = getch();
		int n;
		if (!theme && c == '1')
			n = MessageBox(NULL, "用不正常样式可能会出现问题，确定要用吗？", "提示", MB_YESNO | MB_ICONQUESTION);
		if (c == '1' && n == IDYES && !theme)
		{
			theme = 1, k = -1;
			cout << "大小(建议≤5;最大32767,否则会出现错误)：";
			cin >> k;
			if (k == -1)
			{
				problem();
				k = 2;
			}
			return;
		}
		if (c == '1' && theme)
			theme = 0;
	}
	if (c == '4')
	{
		cout << "按1";
		if (jdt)
			cout << "隐藏";
		else
			cout << "显示";
		cout << "进度条\n";
		int choi;
		c = getch();
		if (!jdt && c == '1')
			choi = MessageBox(NULL, "使用进度条可能会出现问题，确定要用吗？", "提示", MB_OKCANCEL | MB_ICONQUESTION);
		if (c == '1' && choi == IDOK && !jdt)
		{
			jdt = 1, jdtl = -1;
			cout << "长度(建议≤120;最大32767,否则会出现错误)：";
			cin >> jdtl;
			if (jdtl == -1)
			{
				problem();
				jdtl = 60;
			}
			return;
		}
		if (c == '1' && jdt)
			jdt = 0;
	}
}
void settings()
{
	cout << "\n按\t选项\n1\t外观\n2\t屏幕刷新频率\n3\t后台刷新频率\n4\t显示菜单时是否停止计时\n5\t清空记录\n";
	char c = getch();
	if (c == '1')
		exterior();
	if (c == '2')
	{
		cout << "\n请输入屏幕刷新频率（以毫秒为单位，1秒=1000毫秒）：";
		refresh = -1;
		cin >> refresh;
		if (refresh == -1)
		{
			problem();
			refresh = 1000;
		}
	}
	if (c == '3')
	{
		cout << "\n请输入后台刷新频率(单位:次/每周期,>0):";
	zqzl:
		zhouqi = -1;
		cin >> zhouqi;
		if (zhouqi == -1)
		{
			problem();
			zhouqi = 5;
		}
		if (zhouqi <= 0)
		{
			cout << "请重新输入！数>0！\n";
			goto zqzl;
		}
	}
	if (c == '4')
	{
		cout << '\n';
		if (RunTimeStop)
			cout << "√";
		else
			cout << "  ";
		cout << "显示菜单时停止计时\n按1反选";
		c = getch();
		if (c == '1')
			RunTimeStop = !RunTimeStop;
		cout << '\n';
	}
	if (c == '5')
		ret = 0;
	if (c < '1' || c > '5')
		return;
	cout << "设置成功！";
	Sleep(1000);
}
void pause()
{
	if (RunTimeStop)
		cout << "\n\n已暂停...";
	else
		cout << "\n\n菜单";
	cout << "\n按\t选项\n1\t复位";
	printf("（开始时间是%02d:%02d:%02d.00）", yh, ym, ys);
	cout << "\n2\t重新开始\n3\t设置\n4\t文件\n5\t重启此程序\n6\t退出\n其他键\t继续\n";
	char c = getch();
	if (c == '1')
		hour = yh, minute = ym, second = ys, millis = 0, ret = 0;
	if (c == '2')
		ynply = 1;
	if (c == '3')
		settings();
	if (c == '4')
		file();
	if (c == '5')
	{
		system("cls&&cd .&&start %cd%\\\"Stopwatch.exe\"");
		exit(0);
	}
	if (c == '6')
		exitt(1);
	return;
}
void ec(short a, short b, short c, short d)
{
	char s[30];
	string m[10] = {"-|| ||-", "  |  | ", "- |-| -", "- |- |-", " ||- | ", "-| - |-", "-| -||-", "- |  | ", "-||-||-", "-||- |-"};
	//	itoa(a,s,10);
	s[0] = '0' + a / 100;
	s[1] = '0' + a / 10;
	s[2] = '0' + a % 10;
	s[3] = '0' + b / 10;
	s[4] = '0' + b % 10;
	s[5] = '0' + c / 10;
	s[6] = '0' + c % 10;
	s[7] = '0' + d / 10;
	s[8] = '0' + d % 10;
	for (int p = 0; p < 7; p++)
	{
		if (p == 2 || p == 5)
			continue;
		if (p % 3 == 0)
		{
			for (int i = 0; i < 9; i++)
			{
				cout << ' ';
				for (int j = 0; j < k; j++)
					cout << m[s[i] - '0'][p];
				cout << "  ";
			}
			cout << endl;
		}
		else
			for (int q = 0; q < k; q++)
			{
				for (int i = 0; i < 9; i++)
				{
					cout << m[s[i] - '0'][p];
					for (int j = 0; j < k; j++)
						cout << ' ';
					cout << m[s[i] - '0'][p + 1] << ' ';
				}
				cout << endl;
			}
	}
}
int main()
{
	short i;
	system("title Stopwatch");
	cout << "欢迎使用计时器\nVersion 13\n由zym制作\n版权所有，侵权必究";
	MessageBox(NULL, "如果不按照要求输入，会出现\n错误，可以暂停后按5重启。", "提示", MB_OK | MB_ICONASTERISK);
reply:
	ret = 0;
	system("cls");
	cout << "你想计时还是倒计时？" << endl
		 << "0:秒表 1:倒计时" << endl;
nbux:
	n = -1;
	cin >> n;
	if (n == -1)
	{
		problem();
		n = 0;
	}
	if (n != 0 && n != 1)
	{
		cout << "不符合要求！请输入0或1！" << endl;
		goto nbux;
	}
	int now, last;
	if (n == 0)
	{
		hour = minute = second = millis = yh = ym = ys = 0;
		system("cls");
		if (theme == 0)
			printf("%02d:%02d:%02d.%02d\n", hour, minute, second, millis);
		else if (theme = 1)
			ec(hour, minute, second, millis);
		last = clock() / 10;
		while (1)
		{
			now = clock() / 10;
			millis += now - last;
			if (millis > 99)
				second += millis / 100, millis %= 100;
			if (second > 59)
				minute++, second -= 60;
			if (minute > 59)
				hour++, minute -= 60;
			last = now;
			system("cls");
			if (theme == 0)
				printf("%02d:%02d:%02d.%02d\n", hour, minute, second, millis);
			else if (theme = 1)
				ec(hour, minute, second, millis);
			if (ret == 0)
			{
				cout << "按空格键记录，按其他键";
				if (RunTimeStop)
					cout << "暂停";
				else
					cout << "显示菜单";
			}
			else
				cout << "编号\t时间\n";
			for (i = ret; i > 0; i--)
				printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
			for (i = 1; i <= zhouqi; i++)
			{
				Sleep(refresh / (double)zhouqi);
				if (kbhit())
				{
					if (getch() == ' ')
						if (ret == 100)
							MessageBox(NULL, "最多只能记录100次！", "提示", MB_OK | MB_ICONWARNING);
						else
						{
							now = clock() / 10;
							millis += now - last;
							if (millis > 99)
								second += millis / 100, millis %= 100;
							if (second > 59)
								minute++, second -= 60;
							if (minute > 59)
								hour++, minute -= 60;
							record[++ret].hour = hour, record[ret].minu = minute, record[ret].sec = second, record[ret].mil = millis;
						}
					else
						pause();
					if (ynply)
					{
						ynply = 0;
						goto reply;
					}
					if (RunTimeStop)
						last = clock() / 10;
				}
			}
		}
	}
	else
	{
		cout << "请输入需计时的时、分、秒。（用空格或':'隔开，最大99:59:59）" << endl;
	bhyq1:
		hour = minute = second = -1;
		cin >> hour >> minute >> second;
		if (second == -1)
		{
			problem();
			hour = minute = second = 0;
		}
		if (second > 59)
			minute += second / 60, second %= 60;
		if (minute > 59)
			hour += minute / 60, minute %= 60;
		if (hour < 0 || minute < 0 || second < 0 || hour > 99)
		{
			cout << "不符合要求，请输入非负数！可计最大时间为99:59:59！" << endl;
			goto bhyq1;
		}
		yh = hour, ym = minute, ys = second;
		cout << "请输入作为闹铃的音乐文件路径(最长300个字符)。例如:\n";
		cout << "输入\t播放\n"
			 << "0\t1000Hz3秒\n"
			 << "0<x<10\tC:\\Windows\\media\\Alarmx.wav\n"
			 << "\"C:\\Program Files (x86)\\163music\\cache\\1.mp3\"\n";
		char tr[305];
		gets(tr);
		gets(tr);
		system("cls");
		millis = 0;
		if (theme == 0)
			printf("%02d:%02d:%02d.%02d\n", hour, minute, second, millis);
		else if (theme = 1)
			ec(hour, minute, second, millis);
		last = clock() / 10;
		while (1)
		{
			now = clock() / 10;
			millis -= now - last;
			if (millis < 0)
				second += millis / 100 - 1, millis = 100 + millis % 100;
			if (millis == 100)
				millis = 0;
			if (second < 0)
				minute--, second += 60;
			if (minute < 0)
				hour--, minute += 60;
			if (hour < 0)
				break;
			last = now;
			system("cls");
			if (jdt)
			{
				cout << ' ';
				for (i = 1; i <= jdtl; i++)
					cout << '-';
				cout << '\n';
				cout << '|';
				for (i = 1; i <= jdtl; i++)
					if (i <= (double)(hour * 3600 + minute * 60 + second) / (yh * 3600 + ym * 60 + ys) * jdtl /* + 1*/)
						cout << '#';
					else
						cout << ' ';
				printf("|%lf%%\n ", (double)(hour * 3600 + minute * 60 + second) / (yh * 3600 + ym * 60 + ys) * 100);
				for (i = 1; i <= jdtl; i++)
					cout << '-';
				cout << " \n";
			}
			if (theme == 0)
				printf("%02d:%02d:%02d.%02d\n", hour, minute, second, millis);
			else if (theme = 1)
				ec(hour, minute, second, millis);
			if (ret == 0)
			{
				cout << "按空格键记录，按其他键";
				if (RunTimeStop)
					cout << "暂停";
				else
					cout << "显示菜单";
			}
			else
				cout << "编号\t时间\n";
			for (i = ret; i > 0; i--)
				printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
			for (i = 1; i <= zhouqi; i++)
			{
				Sleep(refresh / (double)zhouqi);
				if (kbhit())
				{
					if (getch() == ' ')
						if (ret == 100)
							MessageBox(NULL, "最多只能记录100次！", "提示", MB_OK | MB_ICONWARNING);
						else
						{
							now = clock() / 10;
							millis -= now - last;
							if (millis < 0)
								second += millis / 100 - 1, millis = 100 + millis % 100;
							if (second < 0)
								minute--, second += 60;
							if (minute < 0)
								hour--, minute += 60;
							record[++ret].hour = hour, record[ret].minu = minute, record[ret].sec = second, record[ret].mil = millis;
						}
					else
						pause();
					if (ynply)
					{
						ynply = 0;
						goto reply;
					}
					if (RunTimeStop)
						last = clock() / 10;
				}
			}
		}
		cout << "\nTime is over!\n";
		if (tr[0] == '0')
			Beep(1000, 3000);
		else if (tr[0] >= '1' && tr[0] <= '9')
		{
			char zx[] = {'C', ':', '\\', 'W', 'i', 'n', 'd', 'o', 'w', 's', '\\', 'm', 'e', 'd', 'i', 'a', '\\', 'A', 'l', 'a', 'r', 'm', '0', tr[0], '.', 'w', 'a', 'v'};
			system(zx);
		}
		else
			system(tr);
	}
askagain:
	cout << "想再来吗？(Y/N)";
	char c = ' ';
	cin >> c;
	if (c == ' ')
		problem();
	if (c == 'Y' || c == 'y')
		goto reply;
	else if (c == 'N' || c == 'n')
	{
		exitt(1);
		getch();
		goto askagain;
	}
	else
		goto askagain;
	return 0;
}
