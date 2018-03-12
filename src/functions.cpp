#include "functions.hpp"

int jobs_time(std::vector<t_job>& jobs) {
	int max_C=0;
	int i;
	int n = jobs.size();

	// wyznaczanie czasow C i S
	jobs.at(0).S = jobs.at(0).r;
	jobs.at(0).C = jobs.at(0).S + jobs.at(0).p;

	for (i = 1; i < n; i++) {
		jobs.at(i).S = std::max(jobs.at(i).r, jobs.at(i - 1).C);
		jobs.at(i).C = jobs.at(i).S + jobs.at(i).p;
		//std::cout << "S: " << jobs.at(i).S << " C: " << jobs.at(i).C << std::endl;
	}

	// wyznaczanie maksymalnego czasu - czasu wykonania uszeregowanych zadan
	for (i = 0; i < n; i++) {
		//std::cout << "max_C = " << max_C << " job = " << jobs.at(i).C + jobs.at(i).q << std::endl;
		max_C = std::max(max_C, jobs.at(i).C + jobs.at(i).q);
	}

	return max_C;
}

std::vector<t_job>* load_data(const std::string& filename) {
	int n, v;
	
	std::ifstream file;				// plik z danymi
	std::vector<t_job>* job_list_default = new std::vector<t_job>();

	// ladowanie danych z pliku
	file.open(filename.c_str(), std::ios::in);
	if (file.is_open()) {
		file >> n;
		file >> v;

		for (int i = 0; i < n; i++) {
			t_job new_job;
			file >> new_job.r >> new_job.p >> new_job.q;
			job_list_default->push_back(new_job);
		}
	}
	else exit(-2);
	file.close();

	return job_list_default;
}

int jobs_Rsort(std::vector<t_job>& jobs) {
	std::sort(jobs.begin(), jobs.end());
	return jobs_time(jobs);
}

int jobs_2opt(std::vector<t_job>& jobs) {
	// algorytm 2-opt
	int temp_overall_time = 0,
		overall_time = 0;

	int i, j,
		n = jobs.size();

	std::vector<t_job> job_list2(jobs);
	overall_time = jobs_time(job_list2);

	for (i = 0; i < n - 1; i++) {

		for (j = i + 1; j < n; j++) {
			std::swap(job_list2.at(i), job_list2.at(j));
			temp_overall_time = jobs_time(job_list2);

			if (temp_overall_time < overall_time) {
				overall_time = temp_overall_time;
				i = 0; // (i > 0 ? 0 : i);
				j = 1;
			}
			else {
				std::swap(job_list2.at(i), job_list2.at(j));
			}
		}
	}

	return overall_time;
}