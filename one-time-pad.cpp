// one-time-pad.cpp : Defines the entry point for the application.
//

#include "one-time-pad.h"

#include <vector>
#include <array>
#include <random>
#include <iostream>

using namespace std;

int calculateKeyLength(vector<string> &plaintexts)
{
	int keyLen = 0;
	for (string plaintext : plaintexts) {
		if (plaintext.length() > keyLen) {
			keyLen = plaintext.length();
		}
		cout << plaintext << endl;
	}

	return keyLen;
}

vector<int> generateKey(int keyLen, uniform_int_distribution<mt19937::result_type> &dist, mt19937 &rng)
{
	vector<int> key{ };
	for (int i = 0; i < keyLen; i++) {
		key.push_back(dist(rng));
	}
	return key;
}

int main()
{
	vector<string> plaintexts{ "Blue", "Red", "Orange" };

	int keyLen = calculateKeyLength(plaintexts);

	// Seed randomness
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> distAscii(0, 127); // distribution in range of ascii values

	// Generate key
	vector<int> key = generateKey(keyLen, distAscii, rng);

	for (int c : key) {
		cout << c << endl;
	}

	return 0;
}
