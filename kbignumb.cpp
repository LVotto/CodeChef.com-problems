#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

/*
	C++ solution for problem tagged as KBIGNUMB.
	Find problem description at https://www.codechef.com/problems/KBIGNUMB
*/

class FileContent{

private:
	int number_of_lines;
	vector<string> lines;

	void addLine(string line){
		lines.push_back(line);
		number_of_lines++;
	}

public:

	FileContent(){
		number_of_lines = 0;
	}

	FileContent(string filename){
		ifstream myfile(filename.c_str());
		string line;
		number_of_lines = 0;

		while(getline(myfile, line)) this->addLine(line);

		myfile.close();
	}


	int getNumberOfLines(){return number_of_lines;}

	vector<string> getLines(){return lines;}

	string getLine(int position){return lines[position];}


};

class ListOfFiles{

private:
	int number_of_files;
	vector<FileContent> files;

public:
	ListOfFiles(){
		number_of_files = 0;
	}

	ListOfFiles(int argc, char** argv){
		number_of_files = argc-1;
		for(int i=1; i< argc; i++){
			this->files.push_back(FileContent(argv[i]));
		}

	}

	FileContent getFile(int position){return files[position];}

	int getNumberOfFiles(){return number_of_files;}

};


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