#define WINDOWS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Map.h"
#include "Vertex.h"
#include "Edge.h"

using namespace std;

Map makemap2(string filename);

Map makemap(string filename1, string filename2, string filename3, string filename4, string filename5, string filename6);


int main(int argc, char **argv)
{
	Map campus = makemap2("makemap2.txt");
	int opt = 0;
	char c = '\0';
	string place;
	string place1, place2;
	// Map campus = makemap("name.txt","info.txt","weight.txt","edgetype.txt","ver1.txt","ver2.txt");
	cout << "Map has been generated successfully." << endl;
	while(opt != 3){
		cout<< "\n1. Search for information of places\n2. Search for routes\n3. Quit\n4. Show all places.\n" << endl;
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
				cout << "From: " << '\t';
				cin >> place1;
				cout << "To: " << '\t';
				cin >> place2;

				double dist = 0.0;
				vector< int > path = campus.pathfinder(place1, place2, dist);
				cout << "Length of path found: " << dist << ". Passing " << path.size() << " sites." << endl;
				cout << "Path detail:" << endl;
				campus.pathprinter(path);
				break;
			}
			case 3:
				continue;
				break;
			case 4:
				campus.display();
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

Map makemap2(string filename) {
//------------------------------------------------------------------------------
// Pre: A file named "filename" with data written in designed manner exists.
//--- MAKEMAP will generate a Map object by data from the file.
// Post: An object of class Map was returned.
// Note: Returing a huge object by copying is completely doable, since most
//       modern compilers will optimize such operations.
//------------------------------------------------------------------------------
	ifstream in;
	in.open(filename.c_str());
	if(in.is_open()){
		cout << filename << " opened successfully." << endl;
	}else {
		cout << filename << " open failed." << endl;
	}

	Map made;
	int nofv = 0;
	int nofe = 0;
	in >> nofv;
	string names[nofv];
	string infos[nofv];
	for (int i=0; i<nofv; i++) {
		in >> names[i];
		in.ignore(999, '%');
		getline(in, infos[i]);
		made.addVertex(names[i], infos[i]);
	}

	in >> nofe;
	string v1[nofe], v2[nofe], edgetypes[nofe];
	double length[nofe];
	for (int i=0; i<nofe; i++) {
		in >> v1[i] >> length[i] >> v2[i] >> edgetypes[i];
		switch (made.addEdge(v1[i], v2[i], length[i], edgetypes[i])) {
			case MAP_SUCCESS:
			 	break;
			case VERTEX_NOT_FOUND:
				cerr << "Makemap2 - addEdge failed! : Vertex not found." << endl;
				break;
			case EDGE_NOT_FOUND:
			 	cerr << "Makemap2 - addEdge failed! : Edge not found." << endl;
				break;
			case MAP_UNDERFLOW:
			 	cerr << "Makemap2 - addEdge failed! : Map underflow." << endl;
				break;
			case MAP_OVERFLOW:
				cerr << "Makemap2 - addEdge failed! : Map overflow." << endl;
				break;
		}
	}

	return made;
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
	}else {
		cout << "file opening error" << endl;
	}

	string line;
	vector<string> name;
	while(getline(infile, line)) {
		name.push_back(line);
	}
	infile.close();

	infile.open(filename2.c_str());
	if(infile.is_open()) {
		cout << "file opened successfully" << endl;
	}else {
		cout << "file opening error" << endl;
	}

	vector<string> info;
	while(getline(infile, line)) {
		info.push_back(line);
	}
	infile.close();

	infile.open(filename3.c_str());
	if(infile.is_open()){
		cout << "file opened successfully" << endl;
	}else {
		cout << "file opening error" << endl;
	}
	double number;
	vector<double> weight;
	while(infile >> number)	{
		weight.push_back(number);
	}
	infile.close();

	infile.open(filename4.c_str());
	if(infile.is_open()) {
		cout << "file opened successfully" << endl;
	}else {
		cout << "file opening error" << endl;
	}

	vector<string> edgetype;
	string Line;
	while(infile >> Line) {
		edgetype.push_back(Line);
	}
	infile.close();

	infile.open(filename5.c_str());
	if(infile.is_open()) {
		cout << "file opened successfully" << endl;
	}else {
		cout << "file opening error" << endl;
	}
	vector<string> ver1;
	while(getline(infile,line))
	{
		ver1.push_back(line);
	}
	infile.close();
	infile.open(filename6.c_str());
	if(infile.is_open()){
		cout << "file opened successfully" << endl;
	}else {
		cout << "file opening error" << endl;
	}
	vector<string> ver2;
	while(getline(infile,line))	{
		ver2.push_back(line);
	}
	infile.close();

//----------- read-in sector ends ----------------------------------------------
// now we have 6 vectors, name, info, weight, edgetype, ver1, ver2.
// we can uses these to initiate our map
	Map campus;
	for(unsigned i=0; i<name.size(); i++)	{
		campus.addVertex(name[i], info[i]);
	}

	for(unsigned i=0; i<weight.size(); i++) {
		campus.addEdge(ver1[i],ver2[i],weight[i],edgetype[i]);
	}

	return campus;
}
