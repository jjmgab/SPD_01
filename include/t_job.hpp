#ifndef TJOB_H
#define TJOB_H


/**
 * Klasa definiujaca zadanie. 
 */
class t_job {
public:
	int r,	// przygotowanie
		p,	// wykonywanie
		q;	// dostarczanie

	int C,	// czas zakonczenia wykonywania
		S;	// czas rozpoczecia wykonywania

	/**
	 * Operator porownania ze wzgledu na dlugosc
	 * czasu przygotowywania zadania.
	 * 
	 * @param referencja na zadanie
	 * @return czy zadanie jest wieksze
	 */
	bool operator>(const t_job &_job) {
		return this->r > _job.r;
	}

	/**
	 * Operator porownania ze wzgledu na dlugosc
	 * czasu przygotowywania zadania.
	 * 
	 * @param referencja na zadanie
	 * @return czy zadanie jest mniejsze
	 */
	bool operator<(const t_job &_job) {
		return this->r < _job.r;
	}

	/**
	 * Operator porownania ze wzgledu na dlugosc
	 * czasu przygotowywania zadania.
	 * 
	 * @param referencja na zadanie
	 * @return czy zadanie jest rowne
	 */
	bool operator==(const t_job &_job) {
		return this->r == _job.r;
	}
};



struct compare_jobs_r {

	bool operator()(const t_job& job1, const t_job& job2){
		if (job1.r > job2.r) return true;
		return false;
	}

};

struct compare_jobs_q {

	bool operator()(const t_job& job1, const t_job& job2){
		if (job1.q < job2.q) return true;
		return false;
	}

};

#endif //TJOB_H