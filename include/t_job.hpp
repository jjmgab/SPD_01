#ifndef TJOB_H
#define TJOB_H

class t_job {
public:
	int r,	// przygotowanie
		p,	// wykonywanie
		q;	// dostarczanie

	int C,	// czas zakonczenia wykonywania
		S;	// czas rozpoczecia wykonywania

	bool operator>(const t_job &_job) {
		return this->r > _job.r;
	}
	bool operator<(const t_job &_job) {
		return this->r < _job.r;
	}
	bool operator==(const t_job &_job) {
		return this->r == _job.r;
	}
};

#endif //TJOB_H