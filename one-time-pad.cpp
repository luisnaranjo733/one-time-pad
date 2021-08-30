// one-time-pad.cpp : Defines the entry point for the application.
//

#include "one-time-pad.h"
#include "key.h"

using namespace std;

int calculateKeyLength(vector<string> &plaintexts)
{
	int keyLen = 0;
	for (string plaintext : plaintexts) {
		if (plaintext.length() > keyLen) {
			keyLen = plaintext.length();
		}
	}

	return keyLen;
}

vector<int> strToVec(string& str)
{
	vector<int> result = {};
	for (char const& c : str) {
		result.push_back(c);
	}
	return result;
}

string vecToString(vector<int>& str)
{
	vector<char> result;
	for (char c : str) {
		result.push_back(c);
	}
	string s(result.begin(), result.end());
	return s;
}

vector<vector<int>> encrypt(vector<vector<int>>& plaintexts, Key& key)
{
	vector<vector<int>> results = {};
	for (int i = 0; i < plaintexts.size(); i++) {
		vector<int> plaintext = plaintexts[i];
		vector<int> ciphertext = key. xor (plaintext);
		results.push_back(ciphertext);
	}
	return results;
}

vector<vector<int>> decrypt(vector<vector<int>>& ciphertexts, Key& key)
{
	vector<vector<int>> results = {};
	for (int i = 0; i < ciphertexts.size(); i++) {
		vector<int> ciphertext = ciphertexts[i];
		vector<int> plaintext = key. xor (ciphertext);
		results.push_back(plaintext);
	}
	return results;
}

int main()
{
	vector<string> plaintexts{ "Blue", "Red", "Orange" };
	vector<vector<int>> plaintextsInt = {};
	for (string plaintext : plaintexts) {
		plaintextsInt.push_back(strToVec(plaintext));
	}

	int keyLen = calculateKeyLength(plaintexts);
	Key key = Key(keyLen);
	vector<vector<int>> ciphertexts = encrypt(plaintextsInt, key);
	vector<vector<int>> decryptedPlaintexts = decrypt(ciphertexts, key);

	for (int i = 0; i < plaintexts.size(); i++) {
		string plaintext = plaintexts[i];
		string ciphertext = vecToString(ciphertexts[i]);
		string decryptedPlaintext = vecToString(decryptedPlaintexts[i]);
		cout << i << ": " << plaintext << " --> " << ciphertext << " --> " << decryptedPlaintext << endl;
	}
}
