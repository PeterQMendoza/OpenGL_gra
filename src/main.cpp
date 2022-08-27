#include <iostream>
#include <ratio>
#include <chrono>

#include "entity/unity.hpp"
#include "entity/date.hpp"

int main(int argc, char** argv)
{
    // Contar la cantidad de dias que tiene el a;os
    std::chrono::system_clock::time_point today=std::chrono::system_clock::now();
    time_t now=std::chrono::system_clock::to_time_t(today);
    Date* date=new Date(now);
    // std::cout<<"The date:"<<ctime(&now)<<std::endl;
    // std::cout<<"and it's have "<<date->countDaysfromYear()<<" days"<<std::endl;
    std::cout<<"have between: "<<date->dayBetweenDate()<<std::endl;

    delete date;

    return EXIT_SUCCESS;
}