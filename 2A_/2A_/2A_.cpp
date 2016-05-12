// 2A_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
string find(vector<vector<int> > lists, int start);
string isAbove(vector<int> a, vector<int> b);

int main()
{
	bool fileInput = true;
	string firstLine = "", line = "";
	int testCases = -1;
	long int n = -1;
	string result;

	ifstream in("B-small-attempt0.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());

	ofstream out("output.txt");
	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	if (!fileInput) {
		std::cin.rdbuf(cinbuf);
		//std::cout.rdbuf(coutbuf);
	}

	getline(cin, firstLine);
	testCases = atoi(firstLine.c_str());

	//cout << "Number of tests: " << testCases << "\n";


	for (int t = 1; t <= testCases; t++) {
		getline(cin, line);
 		int size = atoi(line.c_str());

		vector<vector<int> > lists;

		for (int s = 1; s <= (2 * size) - 1; s++) {
			vector<int> soldiers;

			getline(cin, line);
			std::stringstream ss(line);

			for (int i = 0; i < size; i++) {
				int height;
				ss >> height;
				soldiers.push_back(height);
			
			}
			lists.push_back(soldiers);


		}

		string result = find(lists, 0);


		cout << "Case #" << t << ": " << result;

		if (t != testCases) cout << endl;

	}
	return 0;
}


string find(vector<vector<int> > lists, int start) {
	vector<vector<int> > matrix;

	int count = 0;
	int goal = lists[0].size();

	string missing = "";

	matrix.push_back(lists[start]);

	for (int i = 1; i < lists.size(); i++) {


		for (int j = 0; j < matrix.size(); j++) {

			string r = isAbove(lists[i], matrix[j]);
			if (r == "invalid") break;
			else if (r == "yes") {

				matrix.insert(matrix.begin() + j, lists[i]);
				break;
			}

			if (j == matrix.size() - 1 && r != "invalid") {
				matrix.push_back(lists[i]);
				break;
			}

		}

		if (matrix.size() == goal) break;

	}



	for (int i = 0; i < matrix.size(); i++) {
		vector <int> column;

		for (int j = 0; j < matrix.size(); j++) {
			column.push_back(matrix[j][i]);

		}

		//column ready

		bool found = false;
		for (int j = 0; j < lists.size(); j++) {
			bool equal = true;
			for (int k = 0; k < lists[j].size(); k++) {
				if (column[k] != lists[j][k]) {
					equal = false;
					break;
				}

			}

			if (equal) {
				found = true;
				break;
			}


		}

		if (!found) {

			for (int j = 0; j < column.size(); j++) {
				missing += std::to_string(column[j]);
				if (j != column.size() - 1) missing += " ";
			}
			
			break;
		}


	}
	if (missing == "") {
		return find(lists, start + 1);
	}

	return missing;

}



string isAbove(vector<int> a, vector<int> b) {

	int goal = a.size();
	int upper = 0;
	int down = 0;
	int error = 0;

	for (int i = 0; i < a.size(); i++) {

		if (a[i] > b[i]) upper++;
		else if (a[i] < b[i]) down++;
		else error++;
	}
	 
	if (error) return "invalid";
	else if (upper == goal) return "no";
	else if (down == goal) return "yes";
	else return "invalid";

}