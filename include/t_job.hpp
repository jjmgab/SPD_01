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

#endif //TJOB_H