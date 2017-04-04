#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

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