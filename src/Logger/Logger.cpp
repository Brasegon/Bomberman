/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Debian]
** File description:
** Log
*/

#include "Logger.hpp"

Logger::Logger()
{
}

void Logger::printInfo(std::string message)
{
    time_t tmm = time(0);
    tm *ltm = localtime(&tmm);
    int annee = 1900 + ltm->tm_year;
    int mois = ltm->tm_mon;
    int jour = ltm->tm_mday;
    int heure = ltm->tm_hour;
    int min = ltm->tm_min;
    int sec = ltm->tm_sec;


    std::cout << "[" << jour << "/" << mois << "/" << annee << " " << heure << ":" << min << ":" << sec << "] ";
    std::cout << " [INFO] " << message << std::endl;
}

Logger::~Logger()
{
}
