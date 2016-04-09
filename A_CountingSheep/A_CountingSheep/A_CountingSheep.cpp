// A_CountingSheep.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

long int countSheep(long int n);

int main()
{
	bool fileInput = true;
	string firstLine = "", line = "";
	int testCases = -1;
	long int n = -1, result = 0;

	ifstream in("A-large.in");
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

		getline(cin, line);
		n = atoi(line.c_str());
		result = countSheep(n);
		if (result == -1) cout << "Case #" << t << ": INSOMNIA";
		else cout << "Case #" << t << ": " << result;

		if (t != testCases) cout << endl;

	}



    return 0;
}


long int countSheep( long int n) {

	long int sheep = n;

	int finds[10] = { 0 };
	int findsCount = 0;
	long int count = 1;
	int store;
	long int digit;

	if(n == 0) return -1;
	else {

		do {

			sheep = count * n;
			store = sheep;
			do {
				digit = sheep % 10;
				
				if (finds[digit] == 0) {

					finds[digit] = 1;
					findsCount++;
					if (findsCount == 10) return store;
				}

				sheep /= 10;
			} while (sheep > 0);

			//cout << count << endl;
			count++;
		} while (true);

	return -1;
	}
}
