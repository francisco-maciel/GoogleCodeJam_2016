// B_RevengeOfThePancakes.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

static vector<string> history;

long int flipCakes(string pancake, int flips, int minFlips);
double rate(string pancake);
string flip(string pancake, unsigned int ammout);
string happyFace(string piece);
vector<string> getFlops(string pancake);

//bad breadth search implementation
int main()
{
	bool fileInput = true;
	string firstLine = "", pancake = "";
	int testCases = -1;

	ifstream in("B-large.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());

	ofstream out("output.txt");
	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	if (!fileInput) {
		//std::cin.rdbuf(cinbuf);  
		//std::cout.rdbuf(coutbuf);
	}

	getline(cin, firstLine);
	testCases = atoi(firstLine.c_str());

	//cout << "Number of tests: " << testCases << "\n";


	for (int t = 1; t <= testCases; t++) {

		getline(cin, pancake);

		cout << "Case #" << t << ": " << flipCakes(pancake, 0, INT_MAX);
		if (t != testCases) cout << endl;

	}



	return 0;
}


long int flipCakes(string pancake, int flips, int minFlips ) {
	

	if (rate(pancake) == 1) return flips;
	else {
		vector<string> startList;
		startList.push_back(pancake);

		while (true) {
			flips++;
			//cout << flips << endl;

			vector<string> list;

			for (int i = 0; i < startList.size(); i++) {
				vector<string> possibilites = getFlops(startList[i]);
				list.insert(list.end(), possibilites.begin(), possibilites.end());
			}
		

			for (int i = 0; i < list.size(); i++) {

				if (rate(list[i]) == 1) return flips;
				
			}

			sort(list.begin(), list.end());
			list.erase(unique(list.begin(), list.end()), list.end());

			startList = list;
		
		}
		


		return minFlips;

	}


	return minFlips;
}


vector<string> getFlops(string pancake) {
	vector<string> list;
	for (unsigned int i = 1; i <= pancake.length(); i++) {
		string flop = flip(pancake, i);

		list.push_back(flop);


	}
	return list;
}

double rate(string pancake) {
	double count = 0;

	for (char& c : pancake) {
		if (c == 43) count++;
	}
	return count / (double) pancake.length();
}

string flip(string pancake, unsigned int ammout) {

	string piece = pancake.substr(0, ammout);
	string remainder = pancake.substr(ammout, pancake.length());
	reverse(piece.begin(), piece.end());
	piece = happyFace(piece);

	return piece + remainder;
}

string happyFace(string piece) {
	for (char& c : piece) {
		if (c == 43) c = 45;
		else c = 43;
	}

	return piece;
}

