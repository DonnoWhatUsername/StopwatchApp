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
bool ynply = 0, RunTimeStop = 1, theme = 0, jdt = 0, filerestart = 0;
int refresh = 1000;
string list[5][7] = {"���", "����ʱ", "����", "�ļ�", "\0", "\0", "\0",
                     "����", "��λ", "���¿�ʼ", "����", "�ļ�", "������Ӧ��", "�˳�",
                     "����", "����", "���", "��Ļˢ��Ƶ��", "��̨ˢ��Ƶ��", "��ʾ�˵�ʱ�Ƿ�ֹͣ��ʱ", "��ռ�¼",
                     "����", "����", "��������", "���������Թ��´�ʹ��", "��������", "��������", "��������",
                     "����", "����", "��ɫ", "���ڴ�С", "��ʱ����ʽ", "�����������Ե���ʱ�����ã�", "\0"};
struct a
{
    short hour, minu, sec, mil;
} record[101];
void exitt(bool sffh)
{
    system("cls");
    cout << "�ü�ʱ����zym����\nVersion 20���ȶ��棩\n";
    cout << "����ʱ��:2022��7��\n��Ȩ���У���Ȩ�ؾ�\n";
    if (sffh)
        cout << "\n�����������";
    cout << "\n�� 3 ����˳�\b\b\b\b\b\b\b\b\b";
    for (int i = 3; i >= 1; i--)
    {
        cout << "\b" << i;
        Sleep(1000);
        if (sffh && kbhit())
        {
            getch();
            system("cls");
            return;
        }
    }
    exit(0);
}
void outputlist(int block, int maxlist, int usrc, bool display, string words)
{
    system("cls");
    if (n != -1)
    {
        if (ret == 0 && n != 2 && n != 3)
            cout << "��û�м�¼\n";
        else
        {
            if (n == 2 || n == 3)
                cout << "��û�п�ʼ��ʱ\n";
            else
            {
                cout << "���\tʱ��\n";
                for (int i = 1; i <= ret; i++)
                    printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
            }
        }
        printf("%02d:%02d:%02d.%02d\n\n", hour, minute, second, millis);
    }
    cout << words;
    if (display)
        cout << "�� Ctrl+C �˳������ո�������ּ�ȷ�ϣ���\"w\",\"d\",��,��,��,��ѡ��\n";
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
        if (c == 'w' || c == 72 || c == 75)
        {
            if (usrc > 0)
                usrc--;
            else
                usrc = maxlist;
        }
        else if (c == 's' || c == 77 || c == 80)
        {
            if (usrc < maxlist)
                usrc++;
            else
                usrc = 0;
        }
        else if (c >= '0' && c <= maxlist + '0')
            return c - '0';
        else
            goto getretry;
        outputlist(block, maxlist, usrc, display, words);
    getretry:
        c = getch();
        if (c == '')
        {
            exitt(0);
            outputlist(block, maxlist, usrc, display, words);
            goto getretry;
        }
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
void file()
{
fileagain:
    short c;
    if (RunTimeStop)
        c = choice(3, 7, 0, "����ͣ...\n�˵� > �ļ�\n��������ʱ�벻Ҫ����ԭ�������\n");
    else
        c = choice(3, 7, 0, "�˵� > �ļ�\n��������ʱ�벻Ҫ����ԭ�������\n");
    if (c == 0)
        return;
    if (c == 1)
    {
        ynply = 1;
        return;
    }
    if (n == 3 && (c == 2 || c == 5))
    {
        cout << "û�п�ʼ��ʱ����ѡ����ʱ�����á�\n";
        system("pause");
        goto fileagain;
    }
fileretry:
    char tr[303] = {' '};
    cout << "\n�������ļ�����·��(������չ��)��";
    while (strlen(tr) < 2)
        gets(tr);
    if (c == 2)
    {
        int oldstdout = dup(STDOUT);
        freopen(tr, "w", stdout);
        SYSTEMTIME sys;
        GetLocalTime(&sys);
        printf("��¼����ʱ��: %d��%d��%d��%dʱ%d��%d��%d����\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds);
        printf("��ʱ��ʼʱ��: %02d:%02d:%02d\n", yh, ym, ys);
        if (n == 1)
            cout << "ʣ��ʱ��";
        else
            cout << "��ʱʱ��";
        printf(": %02d:%02d:%02d.%02d\n", hour, minute, second, millis);
        cout << "����¼ " << ret << " ������";
        if (ret > 0)
        {
            cout << "\n\n���\tʱ��\n";
            for (short i = ret; i > 0; i--)
                printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
        }
        freopen("CON", "w", stdout);
        dup2(oldstdout, STDOUT);
        cout << "����ɹ���";
        Sleep(1000);
    }
    if (c == 3)
    {
        int oldstdout = dup(STDOUT);
        freopen(tr, "w", stdout);
        SYSTEMTIME sys;
        GetLocalTime(&sys);                                                                                                        //��ȡϵͳʱ��
        printf("%d %d %d %d %d %d %d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds); //����ʱ��
        printf("%02d %02d %02d\n", yh, ym, ys);                                                                                    //��ʼ��ʱʱ��
        cout << n;                                                                                                                 //ģʽ
        printf("\n%02d %02d %02d %02d\n", hour, minute, second, millis);                                                           //�Ѿ���ʱʱ��
        cout << ret << endl;                                                                                                       //��¼��������
        if (ret > 0)
            for (short i = ret; i > 0; i--)
                printf("%02d %02d %02d %02d\n", record[i].hour, record[i].minu, record[i].sec, record[i].mil); //����ļ�¼
        freopen("CON", "w", stdout);
        dup2(oldstdout, STDOUT);
        cout << "����ɹ���";
        Sleep(1000);
    }
    if (c == 4)
    {
        cout << "\nֻ�ܶ�ȡ�ԡ����������Թ��´�ʹ�á����ļ�����\n";
        ifstream fin(tr);
        //	freopen("StopwatchData.dll","r",stdin);
        if (!fin)
        {
            int cho = MessageBox(NULL, "�����ļ������ڣ�", "����ʧ��", MB_RETRYCANCEL | MB_ICONERROR);
            if (cho == IDRETRY)
                goto fileretry;
            return;
        }
        yh = 0;
        fin >> yh;
        if (yh == 0)
        {
            cout << "��ȡʧ�ܣ�";
            goto fileretry;
        }
        for (int i = 2; i <= 7; i++)
            fin >> yh;
        fin >> yh >> ym >> ys >> n >> hour >> minute >> second >> millis >> ret;
        for (short i = ret; i >= 0; i--)
            fin >> record[i].hour >> record[i].minu >> record[i].sec >> record[i].mil;
        fin.close();
        filerestart = 1;
        cout << "����ɹ���";
        Sleep(1000);
    }
    if (c == 5)
    {
        ifstream fin(tr);
        if (fin)
        {
            printf("�Ѵ��� %s���Ƿ������(Y/N) ", tr);
            fin.close();
            char c3;
            scanf("%c", &c3);
            if (c3 == 'N' || c3 == 'n')
                goto fileagain;
        }
        else
            fin.close();
        int oldstdout = dup(STDOUT);
        freopen(tr, "w", stdout);
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
    if (c == 6)
    {
        cout << "��������ʱ�Զ���ȡ���ã��뽫���ñ��浽 Stopwatch.ini\n";
        ifstream fin(tr);
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
    if (RunTimeStop && n != 2)
        c = choice(4, 6, 0, "����ͣ...\n�˵� > ���� > ���\n");
    else
        c = choice(4, 6, 0, "�˵� > ���� > ���\n");
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
            int katot = 0;
        ka:
            k = (short)rinput();
            if (k <= 0)
            {
                cout << "���������룡��>0��\n";
                katot++;
                if (katot > 100)
                {
                    cout << "����������� Ctrl-Z, ��������Ӧ�á�";
                    system("timeout /t 3");
                    exitt(0);
                    katot = 0;
                }
                goto ka;
            }
            goto appagain;
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
            int jdtot = 0;
        jdtla:
            jdtl = (short)rinput();
            if (jdtl <= 0)
            {
                cout << "���������룡��>0��\n";
                jdtot++;
                if (jdtot > 100)
                {
                    cout << "����������� Ctrl-Z, ��������Ӧ�á�";
                    system("timeout /t 3");
                    exitt(0);
                    jdtot = 0;
                }
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
    if (RunTimeStop && n != 2)
        c = choice(2, 7, 0, "����ͣ...\n�˵� > ����\n");
    else
        c = choice(2, 7, 0, "�˵� > ����\n");
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
        int rftot = 0;
    refresha:
        refresh = rinput();
        if (refresh < 0)
        {
            cout << "���������룡��>=0��\n";
            rftot++;
            if (rftot > 100)
            {
                cout << "����������� Ctrl-Z, ��������Ӧ�á�";
                system("timeout /t 3");
                exitt(0);
                rftot = 0;
            }
            goto refresha;
        }
    }
    if (c == 4)
    {
        cout << "\n�������̨ˢ��Ƶ��(��λ:��/ÿ����,>0):";
        int zqtot = 0;
    zqzl:
        zhouqi = rinput();
        if (zhouqi <= 0)
        {
            cout << "���������룡��>0��\n";
            zqtot++;
            if (zqtot > 100)
            {
                cout << "����������� Ctrl-Z, ��������Ӧ�á�";
                system("timeout /t 3");
                exitt(0);
                zqtot = 0;
            }
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
        system("cls&&cd .&&start %cd%\\\"Stopwatch-V19.exe\"");
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
    cout << "��ӭʹ�ü�ʱ��\nVersion 20\n��zym����\n��Ȩ���У���Ȩ�ؾ�\n������������\b\b\b\b\b\b\b\b\b\b\b\b";
    char tr[305] = {'S', 't', 'o', 'p', 'w', 'a', 't', 'c', 'h', '.', 'i', 'n', 'i'};
    ifstream fin(tr);
    if (fin)
    {
        fin >> ynply >> RunTimeStop >> refresh >> theme >> k >> jdt >> jdtl >> zhouqi;
        cout << "��������ɹ�\n";
    }
    else
        cout << "�Ҳ��������ļ�����ȷ����ǰĿ¼���� Stopwatch.ini �ļ�\n";
    fin.close();
    system("timeout /t 3");
reply:
    hour = minute = second = millis = yh = ym = ys = 0;
    ret = 0, n = -1;
    system("title ��ʱ�� by ZYM");
    n = choice(0, 4, 1, "���ո����¼������������ͣ����ʾ�˵�\n������ʲô��\n");
    if (n == 2)
    {
        settings();
        ynply = 0;
        goto reply;
    }
    if (n == 3)
    {
        file();
        ynply = 0;
        goto reply;
    }
    int now, last;
fileres:
    if (n == 0)
    {
        system("title Stopwatch");
        //	system("cls");
        //	if (theme == 0)
        //		printf("%02d:%02d:%02d.%02d", hour, minute, second, millis);
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
                minute += second / 60, second %= 60;
            if (minute > 59)
                hour += minute / 60, minute %= 60;
            last = now;
            system("cls");
            if (ret != 0)
                cout << "���\tʱ��\n";
            for (i = 1; i <= ret; i++)
                printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
            if (theme == 0)
                printf("%02d:%02d:%02d.%02d", hour, minute, second, millis);
            else if (theme = 1)
                ec(hour, minute, second, millis);
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
                                minute += second / 60, second %= 60;
                            if (minute > 59)
                                hour += second / 60, minute %= 60;
                            record[++ret].hour = hour, record[ret].minu = minute, record[ret].sec = second, record[ret].mil = millis;
                        }
                    else
                    {
                        pause();
                        if (filerestart)
                        {
                            filerestart = 0;
                            goto fileres;
                        }
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
             << "0\t1000Hz 3 ��\n"
             << "0<x<10\tC:\\Windows\\media\\Alarmx.wav\n"
             << "10\t������ʾ�� 10 ��\n"
             << "\"C:\\Program Files (x86)\\163music\\cache\\1.mp3\"\n��ȷ���������\n";
        gets(tr);
        gets(tr);
        system("cls");
        millis = 0;
        if (theme == 0)
            printf("%02d:%02d:%02d.%02d", hour, minute, second, millis);
        else if (theme = 1)
            ec(hour, minute, second, millis);
        last = clock() / 10;
        while (1)
        {
            now = clock() / 10;
            millis -= now - last;
            while (millis < 0)
                second += millis / 100 - 1, millis = 100 + millis % 100;
            if (millis == 100)
                millis = 0;
            while (second < 0)
                minute--, second += 60;
            while (minute < 0)
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
            if (ret != 0)
                cout << "���\tʱ��\n";
            for (i = 1; i <= ret; i++)
                printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
            if (theme == 0)
                printf("%02d:%02d:%02d.%02d", hour, minute, second, millis);
            else if (theme = 1)
                ec(hour, minute, second, millis);
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
                            while (millis < 0)
                                second += millis / 100 - 1, millis = 100 + millis % 100;
                            while (second < 0)
                                minute--, second += 60;
                            while (minute < 0)
                                hour--, minute += 60;
                            record[++ret].hour = hour, record[ret].minu = minute, record[ret].sec = second, record[ret].mil = millis;
                        }
                    else
                    {
                        pause();
                        if (filerestart)
                        {
                            filerestart = 0;
                            goto fileres;
                        }
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
        cout << "\nTime is over!\n";
        if (tr[0] == '0')
            Beep(1000, 3000);
        else if (tr[0] == '1' && tr[1] == '0')
        {
            cout << "�������ֹͣ��\n";
            for (i = 1; i <= 10; i++)
            {
                system("echo ");
                Sleep(3000);
                if (kbhit())
                {
                    getch();
                    break;
                }
            }
        }
        else if (tr[0] >= '1' && tr[0] <= '9')
        {
            char zx[] = {'C', ':', '\\', 'W', 'i', 'n', 'd', 'o', 'w', 's', '\\', 'm', 'e', 'd', 'i', 'a', '\\', 'A', 'l', 'a', 'r', 'm', '0', tr[0], '.', 'w', 'a', 'v'};
            system(zx);
        }
        else
            system(tr);
    }
endask:
    cout << "��������(Y/N)";
    char c = getch();
    cout << c << endl;
    if (c == 'Y' || c == 'y')
        goto reply;
    else if (c == 'N' || c == 'n')
        exitt(1);
    goto endask;
    return 0;
}
