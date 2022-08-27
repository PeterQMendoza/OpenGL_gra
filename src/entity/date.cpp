#include <chrono>
#include "date.hpp"

Date::Date(time_t t)
{
    this->m_date=t;

    // Inicializa vector de entero que 
    // representan los dias de cada mes
    // en=31, fe=28/29, m=31, a=30,
    // ma=31, jn=30, jl=31, ag=31,
    // se=30, oc=31, no=30, di=31
    this->m_daysMonth={};
    if (this->isYearBisiesto())
    {
        this->m_daysMonth={1,-1,1,0,1,0,1,1,0,1,0,1};
    }
    else
    {
        this->m_daysMonth={1,-2,1,0,1,0,1,1,0,1,0,1};
    }
}

Date::~Date()
{
}

bool Date::isYearBisiesto()
{
    tm* timeInfo=localtime(&m_date);
    int y=timeInfo->tm_year;
    // p:divisible entre 4
    bool p=(y%4==0)?true:false;
    // q: divisible entre 100
    bool q=(y%100==0)?true:false;
    // r: divisible entre 400
    bool r=(y%400==0)?true:false;

    bool resul=false;
    // Existe una diferencia en los operadores ~(NOT binario) y !(NOT logico)
    // Un anio en bisiesto si es divisible entre 4 y no es divisible entre 100
    // o es divisible entre 400.
    if(p&&((!q)||r))
    {
        resul=true;
    }
    delete timeInfo;
    return resul;
}
int Date::countDaysfromYear()
{
    int suma=0;
    for (auto &&i : m_daysMonth)
    {
        suma=suma+(i+30);
    }
    
    return suma;
}

std::string Date::dayBetweenDate()
{
    std::string delta;
    std::tm timeI{};
    std::tm timeII{};

    // 01-01-2022
    timeI.tm_year=122;
    timeI.tm_mon=0;
    timeI.tm_mday=1;
    timeI.tm_isdst=0;
    std::time_t after=std::mktime(&timeI);
    std::tm local1=*std::localtime(&after);

    // 12-2-2022
    timeII.tm_year=122;
    timeII.tm_mon=11;
    timeII.tm_mday=30;
    timeII.tm_isdst=0;
    std::time_t before=std::mktime(&timeII);
    std::tm local2=*std::localtime(&before);

    // Calculo de diferencia de fechas
    int meses[12]={1,-2,1,0,1,0,1,1,0,1,0,1};
    int difm=local2.tm_mon-local1.tm_mon;
    int difd=local2.tm_mday-local1.tm_mday;
    int dias=0;
    for (int i = 0; i < difm; i++)
    {
        dias=dias+meses[i]+30;
    }
    dias=dias+difd;
    
    dateInfo* di=new dateInfo();
    di->cdays=dias;

    // std::tm local=*std::localtime(&diffe);
    delta="Days:"+std::to_string(di->cdays);
    delete di;
    return delta;
}