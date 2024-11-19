#include "Main.h"
#include <cstring>
#include <vector>

using namespace std;

void GetKey(const string &Data, const string &Mask, vector<int> &key)
{
	for (char ch : Data) {
		for (size_t i = 0; i < Mask.length(); i++) {
			if (ch == Mask[i]) {
				key.push_back(i);
				break;
			}
		}
	}
}

void Decoder(const string &Mask, const vector<int> &key)
{
	string encoded;
	for (int index : key) {
		encoded += Mask[index];
	}
	cout << encoded << endl;
}

int main()
{
	string Data = "Hello! How are you";
	string Mask = "He would remember that honesty is the best policy!";
	vector<int> Key = {};
	GetKey(Data, Mask, Key);
	Decoder(Mask, Key);
	return 0;
}
