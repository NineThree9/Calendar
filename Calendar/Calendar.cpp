#include "Calendar.h"
//判断某年某月某日是周几的函数93
int Calendar::CaculateWeekDay(int y, int m, int d)
{
    if (m == 1 || m == 2)
    {
        m += 12;
        y--;
    }
    int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    switch (iWeek)
    {
    case 0: return 1; break;
    case 1: return 2; break;
    case 2: return 3; break;
    case 3: return 4; break;
    case 4: return 5; break;
    case 5: return 6; break;
    case 6: return 7; break;
    }
}
//计算是否是闰年
bool Calendar::isLoopYaer(int year)
{
    return (((0 == (year % 4)) && (0 != (year % 100))) || (0 == (year % 400)));
}
//计算
int Calendar::getTotalMonthDays(int year, int month)
{
    int nDays = 0;
    int nLoopDay = isLoopYaer(year) ? 1 : 0;
    switch (month)
    {
    case  1: nDays = 0;            break;
    case  2: nDays = 31;            break;
    case  3: nDays = 59 + nLoopDay; break;
    case  4: nDays = 90 + nLoopDay; break;
    case  5: nDays = 120 + nLoopDay; break;
    case  6: nDays = 151 + nLoopDay; break;
    case  7: nDays = 181 + nLoopDay; break;
    case  8: nDays = 212 + nLoopDay; break;
    case  9: nDays = 243 + nLoopDay; break;
    case 10: nDays = 273 + nLoopDay; break;
    case 11: nDays = 304 + nLoopDay; break;
    case 12: nDays = 334 + nLoopDay; break;
    default: nDays = 0; break;
    }
    return nDays;
}
//计算某月一共有几天
int Calendar::getMonthDays(int year, int month)
{
    int nDays = 0;
    int nLoopDay = isLoopYaer(year) ? 1 : 0;
    switch (month) {
    case  1: nDays = 31;            break;
    case  2: nDays = 28 + nLoopDay; break;
    case  3: nDays = 31;            break;
    case  4: nDays = 30;            break;
    case  5: nDays = 31;            break;
    case  6: nDays = 30;            break;
    case  7: nDays = 31;            break;
    case  8: nDays = 31;            break;
    case  9: nDays = 30;            break;
    case 10: nDays = 31;            break;
    case 11: nDays = 30;            break;
    case 12: nDays = 31;            break;
    default: nDays = 30;            break;
    }

    return nDays;
}
//计算农历
int Calendar::LunarCalendar(int year, int month, int day)
{
    int Spring_NY, Sun_NY, StaticDayCount;
    int index, flag;
    //Spring_NY 记录春节离当年元旦的天数。  
    //Sun_NY 记录阳历日离当年元旦的天数。  
    if (((LunarCalendarTable[year - 1901] & 0x0060) >> 5) == 1)
        Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1;
    else
        Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1 + 31;
    Sun_NY = MonthAdd[month - 1] + day - 1;
    if ((!(year % 4)) && (month > 2))
        Sun_NY++;
    //StaticDayCount记录大小月的天数 29 或30  
    //index 记录从哪个月开始来计算。  
    //flag 是用来对闰月的特殊处理。  
    //判断阳历日在春节前还是春节后  
    if (Sun_NY >= Spring_NY)//阳历日在春节后（含春节那天）  
    {
        Sun_NY -= Spring_NY;
        month = 1;
        index = 1;
        flag = 0;
        if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
            StaticDayCount = 29;
        else
            StaticDayCount = 30;
        while (Sun_NY >= StaticDayCount)
        {
            Sun_NY -= StaticDayCount;
            index++;
            if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
            {
                flag = ~flag;
                if (flag == 0)
                    month++;
            }
            else
                month++;
            if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
                StaticDayCount = 29;
            else
                StaticDayCount = 30;
        }
        day = Sun_NY + 1;
    }
    else //阳历日在春节前  
    {
        Spring_NY -= Sun_NY;
        year--;
        month = 12;
        if (((LunarCalendarTable[year - 1901] & 0xF00000) >> 20) == 0)
            index = 12;
        else
            index = 13;
        flag = 0;
        if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
            StaticDayCount = 29;
        else
            StaticDayCount = 30;
        while (Spring_NY > StaticDayCount)
        {
            Spring_NY -= StaticDayCount;
            index--;
            if (flag == 0)
                month--;
            if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
                flag = ~flag;
            if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
                StaticDayCount = 29;
            else
                StaticDayCount = 30;
        }
        day = StaticDayCount - Spring_NY + 1;
    }
    LunarCalendarDay |= day;
    LunarCalendarDay |= (month << 6);
    if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
        return 1;
    else
        return 0;
}
//展示农历
char* Calendar::output(int year, int month, int day)
{     
    const char* ChDay[] = {"*  ","初一  ","初二  ","初三  ","初四  ","初五  ","初六  ","初七  ","初八  ","初九  ","初十  ", "十一  ","十二  ","十三  ","十四  ","十五  ","十六  ","十七  ","十八  ","十九  ","二十  ","廿一  ","廿二  ","廿三  ","廿四  ","廿五  ","廿六  ","廿七  ","廿八  ","廿九  ","三十  "};
    const char* ChMonth[] = { "*  ","正  ","二  ","三  ","四  ","五  ","六  ","七  ","八  ","九  ","十  ","十一  ","腊  " };
    memset(str, '\0', sizeof(str));
    memset(s, '\0', sizeof(s));
    if (LunarCalendar(year, month, day))
    {
        strcat_s(s, "闰");
        strcat_s(s, ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
    }
    else
        strcat_s(s, ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
    strcat_s(str, ChDay[LunarCalendarDay & 0x3F]);
    LunarCalendarDay = 0;
    return str;
}

Calendar::Calendar(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);
    this->resize(800, 600);
    int w = this->width();
    int h = this->height();
    //获取当前年月日
    current_year = QDate::currentDate().year();
    current_month = QDate::currentDate().month();
    current_day = QDate::currentDate().day();
    //初始化数组
    date = new MyLabel * [6];
    for (int i = 0; i < 6; i++)
    {
        date[i] = new MyLabel[7];
    }
    //将星期几打印在最上方
    headLine = new QLabel[7];
    for (int i = 0; i < 7; i++)
    {
        headLine[i].setParent(this);
        headLine[i].resize(w / 10, h / 10);
        headLine[i].move(15 * w / 100 + i * w / 10, 3*h / 10);
        headLine[i].setStyleSheet("QLabel{font-size:20px;}");
        headLine[i].setAlignment(Qt::AlignCenter);
    }
    headLine[1].setText(QString::fromLocal8Bit("周一"));
    headLine[2].setText(QString::fromLocal8Bit("周二"));
    headLine[3].setText(QString::fromLocal8Bit("周三"));
    headLine[4].setText(QString::fromLocal8Bit("周四"));
    headLine[5].setText(QString::fromLocal8Bit("周五"));
    headLine[6].setText(QString::fromLocal8Bit("周六"));
    headLine[0].setText(QString::fromLocal8Bit("周日"));
    bar = new QLabel;
    bar->setParent(this);
    bar->resize(4*w / 10, 15*h / 100);
    bar->move( 3*w / 10 , 15*h / 100);
    bar->setText(QString::number(current_year, 10)+ QString::fromLocal8Bit("年") + QString::number(current_month, 10) + QString::fromLocal8Bit("月"));
    bar->setStyleSheet("QLabel{font-size:20px;}");
    bar->setAlignment(Qt::AlignCenter);

    //将数组单元分配到界面上
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            date[i][j].setParent(this);
            date[i][j].resize(w / 10, h / 10);
            date[i][j].move(15 * w / 100 +  j* w / 10, 4*h / 10 + i * h / 10);
        }
    }
    QIcon  t1;
    t1.addFile(":/Calendar/icon.jpeg");
    this->setWindowIcon(t1);
    //分配按钮
    QPushButton* add = new QPushButton;
    QIcon  t2;
    t2.addFile(":/Calendar/add.jpg");
    add->setIcon(t2);
    add->setIconSize(QSize(w / 10, 15 * h / 100));
    add->resize(w /10, 15 * h / 100);
    add->setParent(this);
    add->move(7*w / 10, 15 * h / 100);
    //add->setFlat(true);
    QPushButton* sub = new QPushButton;
    QIcon  t3;
    t3.addFile(":/Calendar/sub.jpg");
    sub->setIcon(t3);
    sub->setIconSize(QSize(w / 10, 15 * h / 100));
    sub->resize(w /10, 15 * h / 100);
    sub->setParent(this);
    sub->move(2*w /10, 15 * h / 100);
    //sub->setFlat(true);
    connect(add, &QPushButton::clicked, this, &Calendar::addMonth);
    connect(sub, &QPushButton::clicked, this, &Calendar::subMonth);
    QFile  file1("saying.txt");
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << 1;
    }
    QFile  file2("word.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << 1;
    }
    for (int i = 0; i < 10; ++i) {
        char* b = new char[100];
        file1.readLine(b, 100);
        saying[i] = QString(b);
        file2.readLine(b, 100);
        word[i] = QString(b);
    }
    //ui.setupUi(this);
    QTime current = QTime::currentTime();
    srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    int b = rand() % 9;   //随机生成0到9的随机数
    text_saying = new QTextEdit;
    text_saying->resize(3*w/10,15*h/100);
    text_saying->move(0,0);
    text_saying->setParent(this);
    text_saying->insertPlainText(saying[b]);
    text_word = new QTextEdit;
    text_word->resize(3*w/10, 15*h/100);
    text_word->move(7*w/10,0);
    text_word->setParent(this);
    text_word->insertPlainText(word[b]);
    refreshdate = new QPushButton;
    refreshdate->resize(2*w/10,15*h/100);
    refreshdate->move(4*w/10,0);
    refreshdate->setParent(this);
    refreshdate->setText("refresh");
    connect(refreshdate, &QPushButton::clicked, this, [=] {this->UpdateSaying(); });
    //todolist
    Todo = new QPushButton;
    Todo->setText("todolist");
    Todo->resize(15*w/100,h/10);
    Todo->move(85*w/100,3*h/10);
    Todo->setParent(this);
    connect(Todo, &QPushButton::clicked, this, [=] {this->sx(); });
    //备忘录
    waiting = new QPushButton;
    waiting->setText("Froget");
    waiting->resize(15 * w / 100, h / 10);
    waiting->move(85 * w / 100, 4* h / 10);
    waiting->setParent(this);
    connect(waiting, &QPushButton::clicked, this, [=] {this->wit(); });
    //刷新日历数据
    initWidget();
}
Calendar::~Calendar()
{
    for (int i = 0; i < 6; i++)
    {
        delete[]date[i];
    }
    delete[]headLine;
    delete bar;
}
void  Calendar::initWidget()
{
    bar->setText(QString::number(current_year, 10) + QString::fromLocal8Bit("年") + QString::number(current_month, 10) + QString::fromLocal8Bit("月"));
    QString a;
    //计算该月的第一天是星期几
    int firweek = CaculateWeekDay(current_year, current_month, 1);
    int lastMonthDay;
    //计算上个月有几天
    if (current_month == 1)
    {
        lastMonthDay = getMonthDays(current_year - 1, 12);
    }
    else
    {
        lastMonthDay = getMonthDays(current_year, current_month - 1);
    }
    int currentMonthDay = getMonthDays(current_year, current_month);
    int total = 1;
    if (firweek == 1)
    {
        //显示上个月的天数
        for (int i = 6; i >= 0; i--)
        {
            if (current_month == 1)
            {
                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" + QString::fromLocal8Bit(output(current_year - 1, 12, lastMonthDay)));
            }
            else
            {
                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month - 1, lastMonthDay)));
            }

        }
        //显示当前月天数
        int i = 1; int j = 0;
        while (total <= currentMonthDay)
        {
            date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month - 1, total)));

            if (j == 7)
            {
                i++;
                j = 0;
            }

        }
        total = 1;
        //显示下一个月
        while (i < 6)
        {
            if (current_month == 12)
            {
                date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year + 1, 1, total)));
            }
            else
            {
                date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month+1, total)));
            }
            if (j == 7)
            {
                i++;
                j = 0;
            }

        }
    }
    else
    {
        for (int i = firweek - 1; i >= 0; i--)
        {
            if (current_month == 1)
            {
                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" + QString::fromLocal8Bit(output(current_year-1, 12, lastMonthDay)));
            }
            else
            {
                date[0][i].setText(QString::number(lastMonthDay--, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month - 1, lastMonthDay)));
            }
           
        }
        //显示当前月
        for (int i = firweek; i < 7; i++)
        {
            date[0][i].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month, total)));
            if (QDate::currentDate().day() == total)
            {
                date[0][i].setStyleSheet("QLabel{color:rgba(255, 0, 0, 255);font-size:30px;}");
            }
        }
        int i = 1; int j = 0;
        while (total <= currentMonthDay)
        {
            date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month, total)));
           
            if (j == 7)
            {
                i++;
                j = 0;
            }

        }
        total = 1;
        //显示下一个月
        while (i < 6)
        {
            if (current_month == 12)
            {
                date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year+1, 1, total)));
            }
            else
            {
                date[i][j++].setText(QString::number(total++, 10) + "\n" + QString::fromLocal8Bit(output(current_year, current_month+1, total)));
            }         
            if (j == 7)
            {
                i++;
                j = 0;
            }
        }
    }
}

void Calendar::addMonth()
{
    if (this->current_month == 12)
    {
        this->current_month = 1;
        this->current_year++;
        initWidget();
        return;
    }
    this->current_month++;
    initWidget();
}
void Calendar::subMonth()
{
    if (this->current_month == 1)
    {
        this->current_month = 12;
        this->current_year--;
        initWidget();
        return;
    }
    this->current_month--;
    initWidget();
}

void Calendar::UpdateSaying() {
    int b = rand() % 9;   //随机生成0到9的随机数
    text_saying->clear();
    text_word->clear();
    text_saying->insertPlainText(saying[b]);
    text_word->insertPlainText(word[b]);
}

void Calendar::ts()
{
    a->move(this->x() + this->frameGeometry().width(), this->y());
}
void Calendar::sx()
{
    a->show();
    connect(timer, &QTimer::timeout, this,[=]() {this->ts(); });
    timer->start(1);
}
void Calendar::wit() {
    
    w->show();
};
