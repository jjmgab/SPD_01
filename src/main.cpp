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

	std::string names = "data/names.txt",	// nazwa listy nazw plikow
				output = "output.txt";		// nazwa pliku z danymi wyjsciowymi

	std::ifstream file_names;				// strumien wejsciowy do wczytywania nazw plikow

	std::filebuf file;						// plik z danymi wyjsciowymi
	file.open(output, std::ios::out);
	std::ostream loader(&file);				// strumien wyjsciowy, zamiast std::cout

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
		
		// wczytuje dane z pliku
		std::vector<t_job>* job_list_default = load_data("data/"+filename+".txt");

		// wykonywanie sie poszczegolnych algorytmow
		int time;

		std::cout << filename << std::endl;
		loader << filename << std::endl;

		time = measure_time(jobs_schrage, job_list_default, loader);
		loader << time << std::endl;

		/*
		// Rsort
		time = measure_time(jobs_Rsort, job_list_default, loader);
		loader << time << std::endl;

		// 2opt
		time = measure_time(jobs_2opt, job_list_default, loader);
		loader << time << std::endl;

		// Rsort, 2opt
		time = measure_time(jobs_Rsort_2opt, job_list_default, loader);
		loader << time << std::endl;
		*/

		delete job_list_default;
	}

	file_names.close();

	return 0;
}