//��ʹ�������м���Visual Studio Code��ʱѡ��GB2312!!!
//Terrible experience: Choose GB2312 when opened this file in Visual Studio Code!!!
#include <iostream>
#include <cstdio>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <io.h>
#define STDOUT 1
#define ERRORCODE -30000
using namespace std;
short ret, hour, minute, second, yh = 0, ym = 0, ys = 0, millis, n, k = 2, jdtl = 10, zhouqi = 5;
bool ynply = 0, RunTimeStop = 1, theme = 0, jdt = 0;
int refresh = 1000;
string list[5][7] = {"���", "����ʱ", "\0", "\0", "\0", "\0", "\0",
					 "����", "��λ", "���¿�ʼ", "����", "�ļ�", "������Ӧ��", "�˳�",
					 "����", "����", "���", "��Ļˢ��Ƶ��", "��̨ˢ��Ƶ��", "��ʾ�˵�ʱ�Ƿ�ֹͣ��ʱ", "��ռ�¼",
					 "����", "����", "��������", "�������ã�����ɫ�����ڴ�С��", "��������", "\0", "\0",
					 "����", "����", "��ɫ", "���ڴ�С", "��ʱ����ʽ", "�����������ý��Ե���ʱ�����ã�"};
struct a
{
	short hour, minu, sec, mil;
} record[101];
void outputlist(int block, int maxlist, int usrc, bool display, string words)
{
	system("cls");
	if (n != -1)
	{
		printf("%02d:%02d:%02d.%02d\n", hour, minute, second, millis);
		if (ret == 0)
			cout << "��û�м�¼\n";
		else
		{
			cout << "���\tʱ��\n";
			for (int i = ret; i > 0; i--)
				printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
		}
		cout << '\n';
	}
	cout << words;
	if (display)
		cout << "���ո�������ּ�ȷ�ϣ���\"w\",\"d\",��,��,��,��ѡ��\n";
	for (int i = 0; i <= maxlist; i++)
		if (usrc == i)
			cout << "��" << i << '\t' << list[block][i] << endl;
		else
			cout << "��" << i << '\t' << list[block][i] << endl;
}
short choice(int block, int maxlist, bool display, string words)
{
	short usrc = 0;
	maxlist--;
	outputlist(block, maxlist, usrc, display, words);
	char c = '`';
	while (1)
	{
		if (c == 'w' || c == 72 || c == 77)
		{
			if (usrc > 0)
				usrc--;
			else
				usrc = maxlist;
		}
		else if (c == 's' || c == 75 || c == 80)
		{
			if (usrc < maxlist)
				usrc++;
			else
				usrc = 0;
		}
		else if (c >= '0' && c <= maxlist + '0')
			return c - '0';
		else goto getretry;
		outputlist(block, maxlist, usrc, display, words);
	getretry:
		c = getch();
		if (c == ' ' || c == 15)
			break;
	}
	return usrc;
}
int stringtochar(string str)
{
	int ans = 0;
	for (int i = 0; i < str.length(); i++)
		if (str[i] >= '0' && str[i] <= '9')
			ans = ans * 10 + str[i] - '0';
		else
			return ERRORCODE;
	return ans;
}
int rinput()
{
	string str;
	cin >> str;
	return stringtochar(str);
}
void exitt(bool sffh)
{
	system("cls");
	cout << "�ü�ʱ����zym����\n��ǰ�汾Version 16���ȶ��棩\n";
	cout << "����ʱ��:2021��6��30��\n��Ȩ���У���Ȩ�ؾ�\n";
	if (sffh)
		cout << "\n�����������";
	cout << "\n�� 3 ����˳�\b\b\b\b\b\b\b\b\b";
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
void file()
{
fileagain:
	short c;
	if (RunTimeStop)
		c = choice(3, 5, 0, "����ͣ...\n�˵� / �ļ�\n��������ʱ�벻Ҫ����ԭ�������\n");
	else
		c = choice(3, 5, 0, "�˵� / �ļ�\n��������ʱ�벻Ҫ����ԭ�������\n");
	if (c == 0)
		return;
	if (c == 1)
	{
		ynply = 1;
		return;
	}
	char tr[303] = {' '};
	if (c == 2)
	{
		cout << "�������ļ�·����";
		while (strlen(tr) < 2)
			gets(tr);
		cout << "����ɹ���";
		Sleep(1000);
	}
	if (c == 2)
	{
		int oldstdout = dup(STDOUT);
		freopen(tr, "w", stdout);
		SYSTEMTIME sys;
		GetLocalTime(&sys);
		//printf("Save Time: %d��%d��%d��%dʱ%d��%d��%d����\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds);
		printf("Start Time: %02d:%02d:%02d\n", yh, ym, ys);
		printf("Now: %02d:%02d:%02d.%02d\n", hour, minute, second, millis);
		cout << "The number of data: " << ret;
		if (ret > 0)
		{
			cout << "\n\nrecord:\n#\ttime\n";
			for (short i = ret; i > 0; i--)
				printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
		}
		freopen("CON", "w", stdout);
		dup2(oldstdout, STDOUT);
	}
	/*if (c == '5')
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
	if (c == 3)
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
		cout << "����ɹ���";
		Sleep(1000);
	}
	if (c == 4)
	{
	fileretry:
		ifstream fin("StopwatchData.db");
		//	freopen("StopwatchData.dll","r",stdin);
		if (!fin)
		{
			int cho = MessageBox(NULL, "�����ļ������ڣ�", "����ʧ��", MB_RETRYCANCEL | MB_ICONERROR);
			if (cho == IDRETRY)
				goto fileretry;
			return;
		}
		fin >> ynply >> RunTimeStop >> refresh >> theme >> k >> jdt >> jdtl >> zhouqi; /*load(tr);*/
		fin.close();
		cout << "����ɹ���";
		Sleep(1000);
	}
	//	if(c=='2'||c=='4')freopen("CON","r",stdin);
	goto fileagain;
}
void appearance()
{
appagain: 
	short c;
	if (RunTimeStop)
		c = choice(4, 6, 0, "����ͣ...\n�˵� / ���� / ���\n");
	else
		c = choice(4, 6, 0, "�˵� / ���� / ���\n");
	if (c == 0)
		return;
	if (c == 1)
	{
		ynply = 1;
		return;
	}
	if (c == 2)
	{
		system("color /?");
		char c[35] = {' '};
		while (strlen(c) < 2)
			gets(c);
		system(c);
	}
	if (c == 3)
	{
		cout << "�һ���������ѡ��\"Ĭ��ֵ\"��\"����\"����\"����\"ѡ��¸��ġ���\n";
		system("mode con /?");
		char c[35] = {' '};
		while (strlen(c) < 2)
			gets(c);
		system(c);
	}
	if (c == 4)
	{
		cout << "��ǰ��ʽ��";
		if (theme)
			cout << "��";
		cout << "������ʽ\n��1��ѡ\n";
		c = getch();
		int n;
		if (!theme && c == '1')
			n = MessageBox(NULL, "�ò�������ʽ���ܻ�������⣬ȷ��Ҫ����", "��ʾ", MB_YESNO | MB_ICONQUESTION);
		if (c == '1' && n == IDYES && !theme)
		{
			theme = 1;
			cout << "��С(�����5;���32767,�������ִ���)��";
		ka:
			k = (short)rinput();
			if (k <= 0)
			{
				cout << "���������룡��>0��\n";
				goto ka;
			}
			return;
		}
		if (c == '1' && theme)
			theme = 0;
	}
	if (c == 5)
	{
		cout << "��1";
		if (jdt)
			cout << "����";
		else
			cout << "��ʾ";
		cout << "������\n";
		int choi;
		c = getch();
		if (!jdt && c == '1')
			choi = MessageBox(NULL, "ʹ�ý��������ܻ�������⣬ȷ��Ҫ����", "��ʾ", MB_OKCANCEL | MB_ICONQUESTION);
		if (c == '1' && choi == IDOK && !jdt)
		{
			jdt = 1;
			cout << "����(�����120;���32767,�������ִ���)��";
		jdtla:
			jdtl = (short)rinput();
			if (jdtl <= 0)
			{
				cout << "���������룡��>0��\n";
				goto jdtla;
			}
			goto appagain;
		}
		if (c == '1' && jdt)
			jdt = 0;
	}
	goto appagain;
}
void settings()
{
setagain:
	short c;
	if (RunTimeStop)
		c = choice(2, 7, 0, "����ͣ...\n�˵� / ����\n");
	else
		c = choice(2, 7, 0, "�˵� / ����\n");
	if (c == 0)
		return;
	if (c == 1)
	{
		ynply = 1;
		return;
	}
	if (c == 2)
	{
		appearance();
		if (ynply)
		{
			ynply = 0;
			goto setagain;
		}
		else
			return;
	}
	if (c == 3)
	{
		cout << "\n��������Ļˢ��Ƶ�ʣ��Ժ���Ϊ��λ��1��=1000���룩��";
	refresha:
		refresh = rinput();
		if (refresh < 0)
		{
			cout << "���������룡��>=0��\n";
			goto refresha;
		}
	}
	if (c == 4)
	{
		cout << "\n�������̨ˢ��Ƶ��(��λ:��/ÿ����,>0):";
	zqzl:
		zhouqi = rinput();
		if (zhouqi <= 0)
		{
			cout << "���������룡��>0��\n";
			goto zqzl;
		}
	}
	if (c == 5)
	{
		cout << '\n';
		if (RunTimeStop)
			cout << "��";
		else
			cout << "  ";
		cout << "��ʾ�˵�ʱֹͣ��ʱ\n��1��ѡ";
		c = getch();
		if (c == '1')
			RunTimeStop = !RunTimeStop;
		cout << '\n';
	}
	if (c == 6)
		ret = 0;
	if (c <= 1)
		return;
	cout << "���óɹ���";
	Sleep(1000);
	goto setagain;
}
void pause()
{
pagain:
	short c;
	if (RunTimeStop)
		c = choice(1, 7, 0, "����ͣ...\n�˵�\n");
	else
		c = choice(1, 7, 0, "�˵�\n");
	if (c == 0)
		return;
	if (c == 1)
	{
		hour = yh, minute = ym, second = ys, millis = 0, ret = 0;
		return;
	}
	if (c == 2)
	{
		ynply = 1;
		return;
	}
	if (c == 3)
	{
		settings();
		if (ynply)
		{
			ynply = 0;
			goto pagain;
		}
		else
			return;
	}
	if (c == 4)
	{
		file();
		if (ynply)
		{
			ynply = 0;
			goto pagain;
		}
		else
			return;
	}
	if (c == 5)
	{
		system("cls&&cd .&&start %cd%\\\"Stopwatch(V16).exe\"");
		exit(0);
	}
	if (c == 6)
		exitt(1);
	goto pagain;
}
void ec(short a, short b, short c, short d)
{
	char s[30];
	string m[10] = {"-|| ||-", "  |  | ", "- |-| -", "- |- |-", " ||- | ", "-| - |-", "-| -||-", "- |  | ", "-||-||-", "-||- |-"};
	//	itoa(a,s,10);
	s[0] = '0' + a / 100;
	s[1] = '0' + a / 10 % 10;
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
	system("title ��ʱ�� by ZYM");
	cout << "��ӭʹ�ü�ʱ��\nVersion 16\n��zym����\n��Ȩ���У���Ȩ�ؾ�";
	system("timeout /t 3");
reply:
	ret = 0, n = -1;
	system("title ��ʱ�� by ZYM");
	n = choice(0, 2, 1, "�����ʱ���ǵ���ʱ��\n");
	int now, last;
	if (n == 0)
	{
		system("title Stopwatch");
		hour = minute = second = millis = yh = ym = ys = 0;
		//	system("cls");
		//	if (theme == 0)
		//		printf("%02d:%02d:%02d.%02d\n", hour, minute, second, millis);
		//	else if (theme = 1)
		//		ec(hour, minute, second, millis);
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
				cout << "���ո����¼����������";
				if (RunTimeStop)
					cout << "��ͣ";
				else
					cout << "��ʾ�˵�";
			}
			else
				cout << "���\tʱ��\n";
			for (i = ret; i > 0; i--)
				printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
			for (i = 1; i <= zhouqi; i++)
			{
				Sleep(refresh / (double)zhouqi);
				if (kbhit())
				{
					if (getch() == ' ')
						if (ret == 100)
							MessageBox(NULL, "���ֻ�ܼ�¼100�Σ�", "��ʾ", MB_OK | MB_ICONWARNING);
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
					{
						pause();
						if (ynply)
						{
							ynply = 0;
							goto reply;
						}
					}
					if (RunTimeStop)
						last = clock() / 10;
				}
			}
		}
	}
	else
	{
		system("title Timer && cls");
		cout << "���������ʱ��ʱ���֡��롣���ÿո��':'���������999:59:59��" << endl;
	bhyq1:
		hour = (short)rinput(), minute = (short)rinput(), second = (short)rinput();
		if (second > 59)
			minute += second / 60, second %= 60;
		if (minute > 59)
			hour += minute / 60, minute %= 60;
		if (hour < 0 || minute < 0 || second < 0 || hour > 999)
		{
			cout << "������Ҫ��������Ǹ������ɼ����ʱ��Ϊ999:59:59��" << endl;
			goto bhyq1;
		}
		yh = hour, ym = minute, ys = second;
		cout << "��������Ϊ����������ļ�·��(�300���ַ�)������:\n";
		cout << "����\t����\n"
			 << "0\t1000Hz3��\n"
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
				cout << "���ո����¼����������";
				if (RunTimeStop)
					cout << "��ͣ";
				else
					cout << "��ʾ�˵�";
			}
			else
				cout << "���\tʱ��\n";
			for (i = ret; i > 0; i--)
				printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
			for (i = 1; i <= zhouqi; i++)
			{
				Sleep(refresh / (double)zhouqi);
				if (kbhit())
				{
					if (getch() == ' ')
						if (ret == 100)
							MessageBox(NULL, "���ֻ�ܼ�¼100�Σ�", "��ʾ", MB_OK | MB_ICONWARNING);
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
		cout << "\nTime is over!";
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
	cout << "\n��������(Y/N)";
	char c = getch();
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
