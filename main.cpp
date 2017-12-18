#define WINDOWS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Map.h"
#include "Vertex.h"
#include "Edge.h"

using namespace std;

Map makemap(string filename1, string filename2, string filename3, string filename4, string filename5, string filename6);


int main(int argc, char **argv)
{
	int opt = 0;
	char c = '\0';
	string place;
	string place1, place2;
//	cout << "function test: makemap" << endl;
	Map campus = makemap("name.txt","info.txt","weight.txt","edgetype.txt","ver1.txt","ver2.txt");
	//debug
	//-----------------
	/*cout << "\n\n \t DEBUG" << endl;
	campus.display();
	cout << endl << endl;
	//debug
	//-------------------------------
	cout << "place1: " << campus.info("place1") << endl;
	cout << "place2: " << campus.info("place2") << endl;
	cout << "place3: " << campus.info("place3") << endl;
	cout << "place4: " << campus.info("place4") << endl;
	cout << "place5: " << campus.info("place5") << endl;*/
	//--------------------------------
	//-----------------
	cout << "Map has been generated successfully." << endl;
	while(opt != 3){
		cout<< "\n1. Search for information of places\n2. Search for routes\n3. Quit" << endl;
		cin >> opt;

		switch(opt) {
			case 1: {
				string information;
				cout << "Search for place: ";
				cin >> place;
				information = campus.getInfo(place);
				cout << "\nIntroduction of "<< place <<" :" << endl;
				cout << '\t' << information << endl;
				break;
			}
			case 2: {
				cout << "From: " << endl;
				cin >> place1;
				cout << "To: " << endl;
				cin >> place2;
				//TODO
				break;
			}
			case 3:
				continue;
				break;
			default:
				cout << "Invalid input." << endl;
				break;
		}
		cout << "\n\nPress any key to continue..." << endl;
		cin >> c;
		#ifdef WINDOWS
			system("cls");
		#endif //WINDOWS
	}

	return 0;
}

Map makemap(string filename1, string filename2, string filename3, string filename4, string filename5, string filename6) {
	//------------------------------------------------------------------------------
	// Pre: A file named "filename" with data written in designed manner exists.
	//--- MAKEMAP will generate a Map object by data from the file.
	// Post: An object of class Map was returned.
	// Note: Returing a huge object by copying is completely doable, since most
	//       modern compilers will optimize such operations.
	//------------------------------------------------------------------------------
	// Method begins here
	// reading in sector
	//------------------------------------------------------------------------------
	ifstream infile;
	// read in names of spots
	infile.open(filename1.c_str());
	if(infile.is_open()){
		cout << "file opened successfully" << endl;
	}
	else
	{
		cout << "file opening error" << endl;
	}

	string line;
	vector<string> name;
	while(getline(infile, line))
	{
		name.push_back(line);
	}
	infile.close();

	infile.open(filename2.c_str());
	if(infile.is_open()){
		cout << "file opened successfully" << endl;
	}
	else
	{
		cout << "file opening error" << endl;
	}

	vector<string> info;
	while(getline(infile, line))
	{
		info.push_back(line);
	}
	infile.close();

	infile.open(filename3.c_str());
	if(infile.is_open()){
		cout << "file opened successfully" << endl;
	}
	else
	{
		cout << "file opening error" << endl;
	}
	double number;
	vector<double> weight;
	while(infile >> number)
	{
		weight.push_back(number);
	}
	infile.close();

	infile.open(filename4.c_str());
	if(infile.is_open()){
		cout << "file opened successfully" << endl;
	}
	else
	{
		cout << "file opening error" << endl;
	}

	vector<string> edgetype;
	string Line;
	while(infile >> Line)
	{
		edgetype.push_back(Line);
	}
	infile.close();

	infile.open(filename5.c_str());
	if(infile.is_open()){
		cout << "file opened successfully" << endl;
	}
	else
	{
		cout << "file opening error" << endl;
	}
	vector<string> ver1;
	while(getline(infile,line))
	{
		ver1.push_back(line);
	}
	infile.close();
	// check
	/*for(int i = 0; i < ver1.size(); i++)
	{
	cout <<"ver1 = " << ver1[i] << endl;
}*/
// read in the other end of edges
infile.open(filename6.c_str());
if(infile.is_open()){
	cout << "file opened successfully" << endl;
}
else
{
	cout << "file opening error" << endl;
}
vector<string> ver2;
while(getline(infile,line))
{
	ver2.push_back(line);
}
infile.close();

//----------- read-in sector ends ---------------------------
// now we have 6 vectors, name, info, weight, edgetype, ver1, ver2.
// we can uses these to initiate our map
Map campus;
for(unsigned i=0; i<name.size(); i++)
{
	campus.addVertex(name[i], info[i]);
}

for(unsigned i=0; i<weight.size(); i++)
{
	campus.addEdge(ver1[i],ver2[i],weight[i],edgetype[i]);
}

return campus;
}
