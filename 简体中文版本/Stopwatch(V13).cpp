//��ʹ�������м���Visual Studio Code����! 
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
short ret, hour, minute, second, yh = 0, ym = 0, ys = 0, refresh = 1000, millis, n, k = 2, jdtl = 10;
bool ynply, RunTimeStop = 1, theme = 0, jdt = 0;
struct a
{
	short hour, minu, sec, mil;
} record[101];
void exitt()
{
	for (int i = 3; i >= 1; i--)
	{
		system("cls");
		cout << "�ü�ʱ����zym����\n��ǰ�汾Version 12���ȶ��棩\n";
		cout << "����ʱ��:2020��11��28��18:22\n��Ȩ���У���Ȩ�ؾ�\n";
		cout << "\n��" << i << "����˳�";
		Sleep(1000);
	}
	exit(0);
}
void problem()
{
	int choi = MessageBox(NULL, "��ղ��������ַ����������֣����ִ���", "����", MB_ABORTRETRYIGNORE | MB_ICONERROR);
	if (choi == IDRETRY)
	{
		system("cls&&cd .&&start %cd%\\\"Stopwatch.exe\"");
		exit(0);
	}
	if (choi == IDABORT)
		exitt();
}
void file()
{
	cout << "\n1\t��������\n2\t�������ã�����ɫ�����ڴ�С��\n3\t��������\n��������ʱ�벻Ҫ����ԭ�������\n";
	char c = getch(), tr[303] = {' '};
	if (c == '1')
	{
		cout << "�������ļ�·����";
		while (strlen(tr) < 2)
			gets(tr);
	}
	if (c == '1')
	{
		int oldstdout = dup(STDOUT);
		freopen(tr, "w", stdout);
		SYSTEMTIME sys;
		GetLocalTime(&sys);
		printf("Save Time:%d��%d��%d��%dʱ%d��%d��%d����\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds);
		printf("Start Time:%02d:%02d:%02d\n", yh, ym, ys);
		printf("Now:%02d:%02d:%02d.%02d\n", hour, minute, second, millis);
		cout << "The number of data:" << ret;
		if (ret > 0)
		{
			cout << "\nrecord:\nnum.\ttime\n";
			for (short i = ret; i > 0; i--)
				printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
		}
		freopen("CON", "w", stdout);
		dup2(oldstdout, STDOUT);
	}
	/*if(c=='2'){
	ifstream fin(tr);
	string c;short a;char c2;
	fin>>c>>yh>>ym>>ys>>hour>>minute>>second>>millis>>c>>ret>>c>>c;
//	scanf("Start Time:%d:%d:%d\n",&yh,&ym,&ys);
//	scanf("Total Time:%d:%d:%d.%d\n",&hour,&minute,&second,&millis);
//	scanf("The number of data:%d\n",&ret);
	if(ret>0){
		fin>>tr;
		short a;
		for(short i=ret;i>0;i--)fin>>a>>record[i].hour>>record[i].minu>>record[i].sec>>record[i].mil;
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
			 << jdtl; /*save(tr);*/
		freopen("CON", "w", stdout);
		dup2(oldstdout, STDOUT);
	}
	if (c == '3')
	{
		ifstream fin("StopwatchData.db");
		//	freopen("StopwatchData.dll","r",stdin);
		fin >> ynply >> RunTimeStop >> refresh >> theme >> k >> jdt >> jdtl; /*load(tr);*/
		fin.close();
	}
	//	if(c=='2'||c=='4')freopen("CON","r",stdin);
}
void exterior()
{
	cout << "\n��\tѡ��\n1\t��ɫ\n2\t���ڴ�С\n3\t��ʱ����ʽ\n4\t�����������ý��Ե���ʱ�����ã�\n";
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
		cout << "�һ���������ѡ��\"Ĭ��ֵ\"��\"����\"����\"����\"ѡ��¸��ġ���\n";
		system("mode con /?");
		char c[35] = {' '};
		while (strlen(c) < 2)
			gets(c);
		system(c);
	}
	if (c == '3')
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
			theme = 1, k = -1;
			cout << "��С(�����5;���32767,�������ִ���)��";
			cin >> k;
			if(k == -1)
				problem();
			return;
		}
		if (c == '1' && theme)
			theme = 0;
	}
	if (c == '4')
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
			jdt = 1, jdtl = -1;
			cout << "����(�����120;���32767,�������ִ���)��";
			cin >> jdtl;
			if (jdtl == -1)
				problem();
			return;
		}
		if (c == '1' && jdt)
			jdt = 0;
	}
}
void settings()
{
	cout << "\n��\tѡ��\n1\t���\n2\tˢ��Ƶ��\n3\t��ʾ�˵�ʱ�Ƿ�ֹͣ��ʱ\n4\t��ռ�¼\n";
	char c = getch();
	if (c == '1')
		exterior();
	if (c == '2')
	{
		cout << "\n������ˢ��Ƶ�ʣ��Ժ���Ϊ��λ��1��=1000���룩��";
		refresh = -1;
		cin >> refresh;
		if (refresh == -1)
			problem(); 
	}
	if (c == '3')
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
	if (c == '4')
		ret = 0;
	if (c < '1' || c > '4')
		return;
	cout << "���óɹ���";
	Sleep(1000);
}
void pause()
{
	if (RunTimeStop)
		cout << "\n\n����ͣ...";
	else
		cout << "\n\n�˵�";
	cout << "\n��\tѡ��\n1\t��λ";
	printf("����ʼʱ����%02d:%02d:%02d.00��", yh, ym, ys);
	cout << "\n2\t���¿�ʼ\n3\t����\n4\t�ļ�\n5\t�����˳���\n6\t�˳�\n������\t����\n";
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
		exitt();
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
	cout << "��ӭʹ�ü�ʱ��\nVersion 12\n��zym����\n��Ȩ���У���Ȩ�ؾ�";
	MessageBox(NULL, "���������Ҫ�����룬�����\n���󣬿�����ͣ��5������", "��ʾ", MB_OK | MB_ICONASTERISK);
reply:
	ret = 0;
	system("cls");
	cout << "�����ʱ���ǵ���ʱ��" << endl
		 << "0:��� 1:����ʱ" << endl;
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
		cout << "������Ҫ��������0��1��" << endl; 
		goto nbux;
	}
	int now, last;
	if (n == 0)
	{
		hour = 0, minute = 0, second = 0, millis = 0;
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
			for (i = 1; i <= 5; i++)
			{
				Sleep(refresh / 5.0);
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
		cout << "���������ʱ��ʱ���֡��롣���ÿո��':'���������99:59:59��" << endl;
		hour = minute = second = -1;
		cin >> hour >> minute >> second;
		if (second == -1)
			problem();
		if (second > 59)
			minute += second / 60, second %= 60;
		if (minute > 59)
			hour += minute / 60, minute %= 60;
		while (hour < 0 || minute < 0 || second < 0 || hour > 99)
		{
			cout << "������Ҫ��������Ǹ������ɼ����ʱ��Ϊ99:59:59��" << endl;
			hour = minute = second = -1;
			cin >> hour >> minute >> second;
			if (second == -1)
				problem();
			if (second > 59)
				minute += second / 60, second %= 60;
			if (minute > 59)
				hour += minute / 60, minute %= 60;
		}
		yh = hour, ym = minute, ys = second;
		cout << "��������Ϊ����������ļ�·��(�300���ַ�����C:\\Windows\\media\\Alarm01.wav������1������1000Hz3�롣" << endl;
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
					if (i <= (double)(hour * 3600 + minute * 60 + second) / (yh * 3600 + ym * 60 + ys) * jdtl + 1)
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
			for (i = 1; i <= 5; i++)
			{
				Sleep(refresh / 5.0);
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
		system("cls");
		cout << "Time is over!\n";
		if (tr[0] == '1')
			Beep(1000, 3000);
		else
			system(tr);
	}
askagain:
	cout << "��������(Y/N)";
	char c = ' ';
	cin >> c;
	if (c == ' ')
		problem();
	if (c == 'Y' || c == 'y')
		goto reply;
	else if (c == 'N' || c == 'n')
		exitt();
	else
		goto askagain;
	return 0;
}
