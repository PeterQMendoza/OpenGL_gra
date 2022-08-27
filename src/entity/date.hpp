#include <time.h>
#include <vector>
#include <iomanip>
#include <string>

struct dateInfo
{
    int year;
    int month;
    int week;
    int day;
    int cdays;

    dateInfo()
    {
        year=0;
        month=0;
        week=0;
        day=0;
        cdays=0;
    }
};

class Date
{
public:
    Date(time_t t);
    ~Date();

    bool isYearBisiesto();
    int countDaysfromYear();
    std::string dayBetweenDate();
private:
    time_t m_date;
    std::vector<int> m_daysMonth;
};