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

void encrypt(vector<string> &plaintexts, Key &key)
{
	for (int i = 0; i < plaintexts.size(); i++) {
		string plaintext = plaintexts[i];
		vector<int> ciphertext = key. xor (strToVec(plaintext));
		vector<int> decryptedPlaintext = key. xor (ciphertext);
		cout << i << ": " << plaintext << " --> " << vecToString(ciphertext) << " --> " << vecToString(decryptedPlaintext) << endl;
	}
}

int main()
{
	vector<string> plaintexts{ "Blue", "Red", "Orange" };
	int keyLen = calculateKeyLength(plaintexts);
	Key key = Key(keyLen);
	encrypt(plaintexts, key);
}
