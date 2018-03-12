#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>

#include "t_job.hpp"

int jobs_time(std::vector<t_job>& jobs);
std::vector<t_job>* load_data(const std::string& filename);
int jobs_Rsort(std::vector<t_job>& jobs);
int jobs_2opt(std::vector<t_job>& jobs);

#endif //FUNCTIONS_H