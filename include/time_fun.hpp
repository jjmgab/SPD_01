#ifndef TIMEF_H
#define TIMEF_H

#include <iostream>
#include <vector>
#include <ctime>

#include "t_job.hpp"

/**
 * Mierzy i wyswietla czas wykonywania sie funkcji implementujacej
 * dany algorytm szeregowania zadan.
 * 
 * @param wskaznik na funkcje szeregujaca
 * @param wskaznik na wektor zadan
 * @return czas wykonywania sie szeregu zadan
 */
int measure_time(int(*f)(std::vector<t_job>&), std::vector<t_job>* jobs);

#endif // TIME_H