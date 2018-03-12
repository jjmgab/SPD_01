#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>

#include "functions.hpp"
#include "t_job.hpp"




int main() {

	std::string names = "data/names.txt";
	std::ifstream file_names;

	// TODO - pomiar czasu???
	//clock_t clock = clock();

	int number_of_files = 0,
		i;

	file_names.open(names.c_str());
	if (file_names.is_open()) {
		file_names >> number_of_files;
	}
	else exit(-1);


	for (i = 0; i < number_of_files; i++) {

		std::string filename = "";
		file_names >> filename;
		std::cout << filename << std::endl;
		std::vector<t_job>* job_list_default = load_data("data/"+filename+".txt");

		int time;

		time = jobs_Rsort(*job_list_default);
		std::cout << filename + ": Czas wykonywania zadania dla alg. sort-R: " << time << std::endl;

		time = jobs_2opt(*job_list_default);
		std::cout << filename + ": Czas wykonywania zadania dla alg. 2-opt: " << time << std::endl;

		std::sort(job_list_default->begin(), job_list_default->end());
		time = jobs_2opt(*job_list_default);
		std::cout << filename + ": Czas wykonywania zadania dla alg. sortR+2-opt: " << time << std::endl;

		delete job_list_default;
	}

	file_names.close();

	return 0;
}