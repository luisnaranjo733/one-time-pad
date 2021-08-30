#include "one-time-pad.h"

using namespace std;

class  Key
{
private:
    vector<int> key;

public:
    Key(int length);
    Key(vector<int> deterministicKey);
    vector<int> xoor (vector<int>& target);
    vector<int> get();
};

Key::Key(int length)
{
    // Seed randomness
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> distAscii(0, 127); // distribution in range of ascii values

    key = { };
    for (int i = 0; i < length; i++) {
        key.push_back(distAscii(rng));
    }
}

Key::Key(vector<int> deterministicKey)
{
    key = deterministicKey;
}

vector<int> Key :: xoor (vector<int>& target)
{
    vector<int> result = {};
    for (int i = 0; i < target.size(); i++)
    {
        int targetChar = target[i];
        int keyChar = key[i];
        result.push_back(targetChar ^ keyChar);
    }
    return result;
}

vector<int> Key::get()
{
    return key;
}