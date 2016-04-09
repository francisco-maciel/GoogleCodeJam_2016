// C_CoinJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include<bitset>
#include <math.h>
#include <vector>

using namespace std;

string DecimalToBinaryString(int a, int digits);
double isPrime(double num);
double converToBaseX(string binary, int base);

int main()
{
	bool fileInput = true;
	string firstLine = "", line = "";
	int testCases = -1;
	long int n = -1, result = 0;

	ifstream in("input.txt");
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
	//cout << fixed;

	for (int t = 1; t <= testCases; t++) {
		cout << "Case #" << t << ":" << endl;
		int lenght, ammount, significant_length;
		cin >> lenght >> ammount;
		significant_length = lenght - 2;


		int count = 0;
		for (int i = 0; i < pow(2.0, significant_length); i++) {
			vector<int> divisors;

			string coin = "1" + DecimalToBinaryString(i, significant_length) + "1";
			//cout << coin << endl;
			//if (isPrime(i) == 0) cout << i << endl;

			bool primeFound = false;
			for (int base = 2; base <= 10; base++) {
				double converted = converToBaseX(coin, base);
				//cout << "base-" << base << " - " << converted << endl;
				double result = isPrime(converted);
				if (result == 0) {
					primeFound = true;
					break;
				}
				else {
					divisors.push_back(result);
				}

			}

			if (!primeFound) {
				count++;
				cout << coin;
				
				for (int d = 0; d < divisors.size(); d++) {
					cout << " " << divisors[d];
				}

				if (count == ammount) return 0;
				else cout << endl;

			}

		}
	

	}



	return 0;
}

string DecimalToBinaryString(int a, int digits)
{
	unsigned int b = (unsigned int)a;
	string binary = "";
	unsigned int mask = 0x80000000u;
	while (mask > 0)
	{
		binary += ((b & mask) == 0) ? '0' : '1';
		mask >>= 1;
	}
	//cout << binary << endl;
	return binary.substr(binary.length() - digits, binary.length());
}

// returns 0 if is not prime or first divisor

double isPrime(double num)
{
	if (num <= 1)
		return 0;
	else if (num == 2)
		return 0;
	else if ((long long unsigned int) num % 2 == 0)
		return 2;
	else
	{
		unsigned long long int prime = 0;
		unsigned long long int divisor = 3;
		long double num_d = static_cast<double>(num);
		unsigned long int upperLimit = static_cast<int>(sqrt(num_d) + 1);

		while (divisor <= upperLimit)
		{
			if ((long long unsigned int) num % divisor == 0)
			{
				prime = divisor;
				if (prime == num) return 0;
				return prime;

			}
			divisor += 2;
		}
		return prime;
	}
}

double converToBaseX(string binary, int base) {

	double n = 0;

	double power = 0;
	for (int i = binary.length() - 1; i >= 0; i--) {

		if ((unsigned long long int)(binary[i] - '0') == 1) {
			n += pow((double) base, power);
		}

		power++;
	}

	return n; 
}