#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std;

/* 
C++ solution for problem tagged as CHEFBEST.
Find problem description at https://www.codechef.com/problems/CHEFBEST
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
		//cout << "N = " << N << endl;
		swaps = 0;

		for(int i=0; i<N; i++){
			v.push_back(vin[2*i]);
			//cout << v[i] << " - ";
		}
		//cout << endl;
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
				/*for(int k=0; k<N; k++){
						v.push_back(v[k]);
						cout << v[k] << " - ";
				}cout << endl;*/
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

	/*for(int i=0;i<files.getNumberOfFiles();i++){
		cout << "File " << i+1 << " of " << files.getNumberOfFiles() << ": " << endl;
		for(int j=0;j<files.getFile(i).getNumberOfLines();j++){
			cout << files.getFile(i).getLine(j) << endl;
		}
		cout << endl;
	}*/

	FileContent input = files.getFile(0);

	int T;
	stringstream convert(input.getLine(0));
	if ( !(convert >> T) )//give the value to Result using the characters in the string
	    T = 0;//if that fails set Result to 0
		//Result now equal to 456 

	//cout << "T = " << T << endl;
	Row row;
	int n;

	for(int i=1; i<=T; i++){
		stringstream convert(input.getLine(2*i-1));
		if ( !(convert >> n) )//give the value to Result using the characters in the string
	    n = 0;//if that fails set Result to 0

		row = Row(n, input.getLine(2*i));
		row.orderRow();
		cout << row.getSwap() << endl;
	}

	return 0;
}