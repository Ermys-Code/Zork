#include "GlobalFunctions.h"

string ToLower(string stringToLower)
{
    string result = stringToLower;
    for (char& c : result) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return result;
}
