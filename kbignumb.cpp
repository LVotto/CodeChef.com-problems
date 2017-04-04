#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include "oofilereader.hpp"
using namespace std;

/*
	C++ solution for problem tagged as KBIGNUMB.
	Find problem description at https://www.codechef.com/problems/KBIGNUMB
*/

int stringToInt(string s){

	int I;
	stringstream convert(s);
	if ( !(convert >> I) )
	    return 0;
	return I;
}

long int appending(int A, int N){
	long int X=0;
	for(int i=0; i<N; i++){
		X += ceil(pow(10,i*ceil(log10(A)))*A);
		//cout << "X[" << i << "] = "  << X << endl;
	}
	return X;
}

int main(int argc, char** argv){
	
	ListOfFiles files = ListOfFiles(argc, argv);
	FileContent input = files.getFile(0);

	int T = stringToInt(input.getLine(0));

	for(int i=1; i<=T; i++){
		int j = 0;
		string sA;
		string sN;
		string sM;
		while(input.getLine(i)[j]!=' '){
			sA.push_back(input.getLine(i)[j]);
			//cout << "A " << input.getLine(i)[j] << endl;
			j++;
		}j++;while(input.getLine(i)[j]!=' '){
			sN.push_back(input.getLine(i)[j]);
			//cout << "N " << input.getLine(i)[j] << endl;
			j++;
		}j++;while(input.getLine(i)[j]!=' '){
			sM.push_back(input.getLine(i)[j]);

			j++;
		}

		int N = stringToInt(sN);
		int A = stringToInt(sA);
		int M = stringToInt(sM);

		long int X = appending(A,N);

		int result = X%M;

		//cout << "X = " << X << endl;
		cout << result << endl;
	}

	return 0;
}