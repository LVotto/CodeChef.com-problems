#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "oofilereader.hpp"
using namespace std;

/* 
C++ solution for problem tagged as CHEFBEST.
Find problem description at https://www.codechef.com/problems/CHEFBEST
*/

class Row{
private:
	int N;
	vector<char> v;
	int swaps;

public:
	Row(){
		this->N = 0;
		this->swaps = 0;
	}

	Row(int N, string vin){
		this->N = N;
		swaps = 0;

		for(int i=0; i<N; i++){
			v.push_back(vin[2*i]);
		}
	}

	void orderRow(){
		for(int i=0; i<N; i++){
			int flag = 0;
			vector<char> vnext = v;
			for(int j=i; j<N-1; j++){
				
				if(v[j]=='0' && v[j+1]=='1'){
					vnext[j+1]='0'; vnext[j]='1';
					flag++;
				}
			}
			if(flag){
				v = vnext;
				swaps++;
			}
		}
	}

	int getSwap(){
		return swaps;
	}
};

/* 	Header of a multiple file reading program, where lines stores each 
	line of the input text files. */

int main(int argc, char** argv){
	ListOfFiles files = ListOfFiles(argc, argv);
	FileContent input = files.getFile(0);

	int T;
	stringstream convert(input.getLine(0));
	if ( !(convert >> T) )
	    T = 0;

	//cout << "T = " << T << endl;
	Row row;
	int n;

	for(int i=1; i<=T; i++){
		stringstream convert(input.getLine(2*i-1));
		if ( !(convert >> n) )
	    n = 0;

		row = Row(n, input.getLine(2*i));
		row.orderRow();
		cout << row.getSwap() << endl;
	}

	return 0;
}