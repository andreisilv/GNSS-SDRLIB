#include "sdr.h"

int main(int argc, char* argv[])
{
	int    data_type		 = 1; // real
	double sampling_interval = 6.109482e-08;
	double frequency 		 = 4.0941e+06;
	double freq_phase_0 	 = 0.0f;
	double code_rate 	     = 1023000.0f;
	double code_phase_0  	 = 0.0f;
	int corrp[CORRN] 	     = {8}; // offset in samples (16 samples per chip)
	int corrn 				 = CORRN;
	int nsamp 				 = NSAMPLES;
	int nchips				 = NCHIPS;

	for(int i = 0; i < 1/*7*/; i ++) {
		printf("NSAMP: %d\n", nsamp >> i);

		correlator(data, data_type, sampling_interval, nsamp, frequency, freq_phase_0, code_rate, code_phase_0, corrp, corrn, corrI, corrQ, NULL, NULL, code, nchips);

		//  Results for "IN FILE 1 : SIGNAL : IF_GN3S.bin (sample)"
		//  EARLY                     PROMPT                     LATE
		//  II          QQ            II           QQ            II          QQ
		// {-0634.71875,-2331.09375} {-0913.59375, -4074.78125} {-0778.03125, -2345.09375}

		/* Results */
		for(int i = 0; i < 2*CORRN + 1; i++) {
			printf("{%+09.3lf, %+09.3lf}\t", corrI[i], corrQ[i]);
			if(!((i + 1) % 3)) printf("\n");
			else printf("\t");
		}
	}

	return 0;
}