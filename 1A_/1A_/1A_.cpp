// 1A_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

string contest(string word);

int main()
{
	bool fileInput = true;
	string firstLine = "", line = "";
	int testCases = -1;
	long int n = -1;
	string result;

	ifstream in("A-large.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());

	//ofstream out("output.txt");
	//streambuf *coutbuf = std::cout.rdbuf();
	//cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	if (!fileInput) {
		std::cin.rdbuf(cinbuf);  
		//std::cout.rdbuf(coutbuf);
	}

	getline(cin, firstLine);
	testCases = atoi(firstLine.c_str());

	//cout << "Number of tests: " << testCases << "\n";


	for (int t = 1; t <= testCases; t++) {

		getline(cin, line);
		result = contest(line);
		cout << "Case #" << t << ": " << result;

		if (t != testCases) cout << endl;

	}
	return 0;
}

string contest(string word) {

	int count = 0;
	string result = "";
	for (char& c : word) {
		
		if (count == 0) result += c;
		else {
			if ((int)c >= result.at(0))
				result = c + result;
			else result += c;

		}

		count++;
	}
	return result;


}

