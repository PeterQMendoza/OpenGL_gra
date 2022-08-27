#include <ctime>
#include <chrono>
#include <ratio>
#include <string>

class Unity
{
public:
    Unity();
    Unity(char s,char c);
    ~Unity();

    // Property
    void setYearOld(int,int,int);
    void setWeight(double);
    void setSex(char s);
    void setCategory(char c);

    double getWeight();
    char getSex();
    char getCategory();
    std::string getYearOld();

private:
    double      m_weight;
    char        m_sex;
    char        m_category;
    time_t      m_date_birth;
};