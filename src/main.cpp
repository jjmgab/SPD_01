#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <functional>

#include "functions.hpp"
#include "t_job.hpp"
#include "time_fun.hpp"


int main() {

	std::string names = "data/names.txt";	// lista nazw plikow
	std::ifstream file_names;				// strumien wejsciowy do wczytywania nazw plikow

	int number_of_files = 0,				// potrzebne przy wczytywaniu danych z plikow, l. plikow
		i;									// indeks do petli

	// otwarcie listy nazw plikow
	file_names.open(names.c_str());
	if (file_names.is_open()) {
		file_names >> number_of_files;
	}
	else exit(-1);


	// dla kazdego pliku na liscie
	for (i = 0; i < number_of_files; i++) {

		// wczytuje nazwe pliku
		std::string filename = "";
		file_names >> filename;
		std::cout << filename << std::endl;
		
		// wczytuje dane z pliku
		std::vector<t_job>* job_list_default = load_data("data/"+filename+".txt");

		// wykonywanie sie poszczegolnych algorytmow
		int time;

		time = measure_time(jobs_Rsort, job_list_default);
		std::cout << filename + ": Czas wykonywania zadania dla alg. sort-R: " << time << std::endl;

		// 2opt
		time = measure_time(jobs_2opt, job_list_default);
		std::cout << filename + ": Czas wykonywania zadania dla alg. 2-opt: " << time << std::endl;

		// Rsort, 2opt
		time = measure_time(jobs_Rsort_2opt, job_list_default);
		std::cout << filename + ": Czas wykonywania zadania dla alg. sortR+2-opt: " << time << std::endl;

		delete job_list_default;
	}

	file_names.close();

	return 0;
}