#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>

#include <queue>

#include "t_job.hpp"

/**
 * Zwraca czas wykonania zadan.
 * 
 * @param wektor zadan
 * @return czas wykonywania zadan
 */
int jobs_time(std::vector<t_job>& jobs);

/**
 * Wczytuje dane z podanego pliku do zaalokowanego wektora zadan,
 * na ktory wskaznik nastepnie zwraca.
 * 
 * @param nazwa pliku
 * @return wskaznik na wektor zadan
 */
std::vector<t_job>* load_data(const std::string& filename);

/**
 * Wykonuje algorytm szeregowania zadan R-sort.
 * 
 * @param referencja na wektor zadan
 * @return czas wykonywania uszeregowanych zadan
 */
int jobs_Rsort(std::vector<t_job>& jobs);

/**
 * Wykonuje algorytm szeregowania zadan 2opt.
 * 
 * @param referencja na wektor zadan
 * @return czas wykonywania uszeregowanych zadan
 */
int jobs_2opt(std::vector<t_job>& jobs);

/**
 * Wykonuje algorytm szeregowania zadan Rsort+2opt. 
 * Najpierw wykonuje Rsort, nastepnie 2opt.
 * 
 * @param referencja na wektor zadan
 * @return czas wykonywania uszeregowanych zadan
 */

int jobs_Rsort_2opt(std::vector<t_job>& jobs);

/**
 * Wykonuje algorytm szeregowania zadan Schrage.
 * 
 * @param referencja na wektor zadan
 * @return czas wykonywania uszeregowanych zadan
 */
int jobs_schrage(std::vector<t_job>& jobs);

#endif //FUNCTIONS_H