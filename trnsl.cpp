#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
unsigned int index = 0;
bool state = 0;
unsigned int a = 1;
unsigned int i = 1;
unsigned int j = 0;
unsigned int sublength = 0;
string print;
string subtitle;
string translated;
vector<unsigned int> timestamps;
int main(int argc, char* argv[]){
	ifstream file;
	unsigned int chunksize = stoi(argv[2]);
	file.open(argv[1]);
	if(file.fail()){
		cout << "ERROR: Cannot open file, please see if there's a typo somewhere";
		return 1;
	}
	stringstream buffer;
	buffer << file.rdbuf();
	subtitle = buffer.str();
	cout << "Length of subtitle: " << subtitle.length() << '\n';
	while(subtitle[i] != '\n'){
		i++;
	}
	while(true){
		cout << "\n\033[31mBlock #" << a << "\033[0m\n";
		sublength=i+chunksize;
		state = 0;
		if(sublength > subtitle.length()){
			state = 1;
			sublength = subtitle.length();
		}
		while(i < sublength){
			if((subtitle[i] == '\n')&&(subtitle[i+1]  == '\n')){
				i=i+2;
				timestamps.push_back(i);
				while(subtitle[i] != '\n'){
					i++;
				}
				cout << '\n';
				if((sublength + 24) < subtitle.length()){
					sublength = sublength + 24;
				}else{
					sublength = subtitle.length();
				}
			}
			cout << subtitle[i];
			i++;
		}
		i--;
		while((subtitle[i]!=' ')&&(subtitle[i]!='\n')){
			cout << "\b \b";
			i--;
		}
		i++;
		if(state){
			break;
		}
		cout << '\n';
		a++;
	}
	string line;
	cout << "\nWhere's the file with the translated version: \n";
	getline(cin, line);
	ifstream newFile;
	newFile.open(line);
	if(newFile.fail()){
		cout << "ERROR: Cannot open file, please see if there's a typo somewhere";
		return 1;
	}
	stringstream secndbuffer;
	secndbuffer << newFile.rdbuf();
	translated = secndbuffer.str();
	a=0;
	i=0;
	j=1;
	translated.insert(0,1,'\n');
	while(subtitle[j]!='\n'){
		translated.insert(i,1,subtitle[j]);
		i++;
		j++;
	}
	translated.insert(i,1,'\n');
	i++;
	while(i < translated.length()){
		if((translated[i] == '\n')&&(translated[i+1] == '\n')){
			i=i+2;
			j=timestamps[a];
			while(subtitle[j]!='\n'){
				translated.insert(i,1,subtitle[j]);
				i++;
				j++;
			}
			translated.insert(i,1,'\n');
			a++;
		}
		i++;
	}
	cout << "\nType the name of the file which will contain the translated captions and the right timestamps: \n";
	getline(cin, line);	
	ofstream output(line);
	output << translated;
	output.close();
	file.close();
	newFile.close();
}