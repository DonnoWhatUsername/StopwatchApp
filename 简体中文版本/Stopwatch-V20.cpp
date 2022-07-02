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
string list[5][7] = {"秒表", "倒计时", "设置", "文件", "\0", "\0", "\0",
                     "继续", "复位", "重新开始", "设置", "文件", "重启此应用", "退出",
                     "继续", "返回", "外观", "屏幕刷新频率", "后台刷新频率", "显示菜单时是否停止计时", "清空记录",
                     "继续", "返回", "保存数据", "保存数据以供下次使用", "载入数据", "保存设置", "载入设置",
                     "继续", "返回", "颜色", "窗口大小", "计时器样式", "进度条（仅对倒计时起作用）", "\0"};
struct a
{
    short hour, minu, sec, mil;
} record[101];
void exitt(bool sffh)
{
    system("cls");
    cout << "该计时器由zym制作\nVersion 20（稳定版）\n";
    cout << "发行时间:2022年7月\n版权所有，侵权必究\n";
    if (sffh)
        cout << "\n按任意键返回";
    cout << "\n在 3 秒后退出\b\b\b\b\b\b\b\b\b";
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
            cout << "你没有记录\n";
        else
        {
            if (n == 2 || n == 3)
                cout << "你没有开始计时\n";
            else
            {
                cout << "编号\t时间\n";
                for (int i = 1; i <= ret; i++)
                    printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
            }
        }
        printf("%02d:%02d:%02d.%02d\n\n", hour, minute, second, millis);
    }
    cout << words;
    if (display)
        cout << "按 Ctrl+C 退出，按空格键或数字键确认，按\"w\",\"d\",↑,↓,←,→选择\n";
    for (int i = 0; i <= maxlist; i++)
        if (usrc == i)
            cout << "→" << i << '\t' << list[block][i] << endl;
        else
            cout << "　" << i << '\t' << list[block][i] << endl;
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
        c = choice(3, 7, 0, "已暂停...\n菜单 > 文件\n导入数据时请不要更改原输出数据\n");
    else
        c = choice(3, 7, 0, "菜单 > 文件\n导入数据时请不要更改原输出数据\n");
    if (c == 0)
        return;
    if (c == 1)
    {
        ynply = 1;
        return;
    }
    if (n == 3 && (c == 2 || c == 5))
    {
        cout << "没有开始计时，该选项暂时不可用。\n";
        system("pause");
        goto fileagain;
    }
fileretry:
    char tr[303] = {' '};
    cout << "\n请输入文件名称路径(包括拓展名)：";
    while (strlen(tr) < 2)
        gets(tr);
    if (c == 2)
    {
        int oldstdout = dup(STDOUT);
        freopen(tr, "w", stdout);
        SYSTEMTIME sys;
        GetLocalTime(&sys);
        printf("记录保存时间: %d年%d月%d日%d时%d分%d秒%d毫秒\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds);
        printf("计时开始时间: %02d:%02d:%02d\n", yh, ym, ys);
        if (n == 1)
            cout << "剩余时间";
        else
            cout << "计时时间";
        printf(": %02d:%02d:%02d.%02d\n", hour, minute, second, millis);
        cout << "共记录 " << ret << " 组数据";
        if (ret > 0)
        {
            cout << "\n\n编号\t时间\n";
            for (short i = ret; i > 0; i--)
                printf("%d\t%02d:%02d:%02d.%02d\n", i, record[i].hour, record[i].minu, record[i].sec, record[i].mil);
        }
        freopen("CON", "w", stdout);
        dup2(oldstdout, STDOUT);
        cout << "保存成功！";
        Sleep(1000);
    }
    if (c == 3)
    {
        int oldstdout = dup(STDOUT);
        freopen(tr, "w", stdout);
        SYSTEMTIME sys;
        GetLocalTime(&sys);                                                                                                        //获取系统时间
        printf("%d %d %d %d %d %d %d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds); //保存时间
        printf("%02d %02d %02d\n", yh, ym, ys);                                                                                    //开始计时时间
        cout << n;                                                                                                                 //模式
        printf("\n%02d %02d %02d %02d\n", hour, minute, second, millis);                                                           //已经计时时间
        cout << ret << endl;                                                                                                       //记录数据组数
        if (ret > 0)
            for (short i = ret; i > 0; i--)
                printf("%02d %02d %02d %02d\n", record[i].hour, record[i].minu, record[i].sec, record[i].mil); //保存的记录
        freopen("CON", "w", stdout);
        dup2(oldstdout, STDOUT);
        cout << "保存成功！";
        Sleep(1000);
    }
    if (c == 4)
    {
        cout << "\n只能读取以“保存数据以供下次使用”的文件。”\n";
        ifstream fin(tr);
        //	freopen("StopwatchData.dll","r",stdin);
        if (!fin)
        {
            int cho = MessageBox(NULL, "数据文件不存在！", "载入失败", MB_RETRYCANCEL | MB_ICONERROR);
            if (cho == IDRETRY)
                goto fileretry;
            return;
        }
        yh = 0;
        fin >> yh;
        if (yh == 0)
        {
            cout << "读取失败！";
            goto fileretry;
        }
        for (int i = 2; i <= 7; i++)
            fin >> yh;
        fin >> yh >> ym >> ys >> n >> hour >> minute >> second >> millis >> ret;
        for (short i = ret; i >= 0; i--)
            fin >> record[i].hour >> record[i].minu >> record[i].sec >> record[i].mil;
        fin.close();
        filerestart = 1;
        cout << "导入成功！";
        Sleep(1000);
    }
    if (c == 5)
    {
        ifstream fin(tr);
        if (fin)
        {
            printf("已存在 %s，是否继续？(Y/N) ", tr);
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
        cout << "保存成功！";
        Sleep(1000);
    }
    if (c == 6)
    {
        cout << "若想启动时自动读取设置，请将设置保存到 Stopwatch.ini\n";
        ifstream fin(tr);
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
        cout << "导入成功！";
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
        c = choice(4, 6, 0, "已暂停...\n菜单 > 设置 > 外观\n");
    else
        c = choice(4, 6, 0, "菜单 > 设置 > 外观\n");
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
        cout << "右击标题栏，选择\"默认值\"或\"属性\"，在\"布局\"选项卡下更改。或\n";
        system("mode con /?");
        char c[35] = {' '};
        while (strlen(c) < 2)
            gets(c);
        system(c);
    }
    if (c == 4)
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
            theme = 1;
            cout << "大小(建议≤5;最大32767,否则会出现错误)：";
            int katot = 0;
        ka:
            k = (short)rinput();
            if (k <= 0)
            {
                cout << "请重新输入！数>0！\n";
                katot++;
                if (katot > 100)
                {
                    cout << "你可能输入了 Ctrl-Z, 将结束该应用。";
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
            jdt = 1;
            cout << "长度(建议≤120;最大32767,否则会出现错误)：";
            int jdtot = 0;
        jdtla:
            jdtl = (short)rinput();
            if (jdtl <= 0)
            {
                cout << "请重新输入！数>0！\n";
                jdtot++;
                if (jdtot > 100)
                {
                    cout << "你可能输入了 Ctrl-Z, 将结束该应用。";
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
        c = choice(2, 7, 0, "已暂停...\n菜单 > 设置\n");
    else
        c = choice(2, 7, 0, "菜单 > 设置\n");
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
        cout << "\n请输入屏幕刷新频率（以毫秒为单位，1秒=1000毫秒）：";
        int rftot = 0;
    refresha:
        refresh = rinput();
        if (refresh < 0)
        {
            cout << "请重新输入！数>=0！\n";
            rftot++;
            if (rftot > 100)
            {
                cout << "你可能输入了 Ctrl-Z, 将结束该应用。";
                system("timeout /t 3");
                exitt(0);
                rftot = 0;
            }
            goto refresha;
        }
    }
    if (c == 4)
    {
        cout << "\n请输入后台刷新频率(单位:次/每周期,>0):";
        int zqtot = 0;
    zqzl:
        zhouqi = rinput();
        if (zhouqi <= 0)
        {
            cout << "请重新输入！数>0！\n";
            zqtot++;
            if (zqtot > 100)
            {
                cout << "你可能输入了 Ctrl-Z, 将结束该应用。";
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
            cout << "√";
        else
            cout << "  ";
        cout << "显示菜单时停止计时\n按1反选";
        c = getch();
        if (c == '1')
            RunTimeStop = !RunTimeStop;
        cout << '\n';
    }
    if (c == 6)
        ret = 0;
    if (c <= 1)
        return;
    cout << "设置成功！";
    Sleep(1000);
    goto setagain;
}
void pause()
{
pagain:
    short c;
    if (RunTimeStop)
        c = choice(1, 7, 0, "已暂停...\n菜单\n");
    else
        c = choice(1, 7, 0, "菜单\n");
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
    system("title 计时器 by ZYM");
    cout << "欢迎使用计时器\nVersion 20\n由zym制作\n版权所有，侵权必究\n正在载入设置\b\b\b\b\b\b\b\b\b\b\b\b";
    char tr[305] = {'S', 't', 'o', 'p', 'w', 'a', 't', 'c', 'h', '.', 'i', 'n', 'i'};
    ifstream fin(tr);
    if (fin)
    {
        fin >> ynply >> RunTimeStop >> refresh >> theme >> k >> jdt >> jdtl >> zhouqi;
        cout << "设置载入成功\n";
    }
    else
        cout << "找不到设置文件，请确保当前目录下有 Stopwatch.ini 文件\n";
    fin.close();
    system("timeout /t 3");
reply:
    hour = minute = second = millis = yh = ym = ys = 0;
    ret = 0, n = -1;
    system("title 计时器 by ZYM");
    n = choice(0, 4, 1, "按空格键记录，按其他键暂停或显示菜单\n你想做什么？\n");
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
                cout << "编号\t时间\n";
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
                            MessageBox(NULL, "最多只能记录100次！", "提示", MB_OK | MB_ICONWARNING);
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
        cout << "请输入需计时的时、分、秒。（用空格或':'隔开，最大999:59:59）" << endl;
    bhyq1:
        hour = (short)rinput(), minute = (short)rinput(), second = (short)rinput();
        if (second > 59)
            minute += second / 60, second %= 60;
        if (minute > 59)
            hour += minute / 60, minute %= 60;
        if (hour < 0 || minute < 0 || second < 0 || hour > 999)
        {
            cout << "不符合要求，请输入非负数！可计最大时间为999:59:59！" << endl;
            goto bhyq1;
        }
        yh = hour, ym = minute, ys = second;
        cout << "请输入作为闹铃的音乐文件路径(最长300个字符)。例如:\n";
        cout << "输入\t播放\n"
             << "0\t1000Hz 3 秒\n"
             << "0<x<10\tC:\\Windows\\media\\Alarmx.wav\n"
             << "10\t错误提示音 10 次\n"
             << "\"C:\\Program Files (x86)\\163music\\cache\\1.mp3\"\n请确保声音最大。\n";
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
                cout << "编号\t时间\n";
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
                            MessageBox(NULL, "最多只能记录100次！", "提示", MB_OK | MB_ICONWARNING);
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
            cout << "按任意键停止。\n";
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
    cout << "想再来吗？(Y/N)";
    char c = getch();
    cout << c << endl;
    if (c == 'Y' || c == 'y')
        goto reply;
    else if (c == 'N' || c == 'n')
        exitt(1);
    goto endask;
    return 0;
}
