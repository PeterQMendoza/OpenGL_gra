#include "unity.hpp"

Unity::Unity(char s,char c)
{
    this->m_sex=s;
    this->m_category=c;
    this->m_weight=0;

    // Almacenar la fecha de nacimiento
    std::chrono::system_clock::time_point today=std::chrono::system_clock::now();
    this->m_date_birth=std::chrono::system_clock::to_time_t(today);
}

Unity::~Unity()
{
}

// Set property
void Unity::setYearOld(int d, int m,int y)
{
    struct tm* timeinfo;
    timeinfo->tm_year=y;
    timeinfo->tm_mon=m;
    timeinfo->tm_mday=d;
    
    this->m_date_birth=mktime(timeinfo);
}

void Unity::setWeight(double nw)
{
    this->m_weight=nw;
}

void Unity::setSex(char s)
{
    this->m_sex=s;
}

void Unity::setCategory(char c)
{
    this->m_category=c;
}

// Get property
double Unity::getWeight()
{
    return this->m_weight;
}

char Unity::getSex()
{
    return this->m_sex;
}

char Unity::getCategory()
{
    return this->m_category;
}

std::string Unity::getYearOld()
{
    // Agregar cantidad de dias
    std::chrono::duration<int,std::ratio<60*60*24>> one_day(1);
    std::chrono::system_clock::time_point today=std::chrono::system_clock::now();
    time_t now=std::chrono::system_clock::to_time_t(today);
    tm* ltm=localtime(&now);
    std::string msg;
    msg="Años: "+std::to_string((1900+ltm->tm_year))+"\n";
    msg=msg+"Meses: "+std::to_string((1+ltm->tm_mon))+"\n";
    msg=msg+"Dias: "+std::to_string(ltm->tm_yday);
    return msg;
}