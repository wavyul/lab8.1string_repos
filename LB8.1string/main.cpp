#include <iostream>
#include <string>

using namespace std;

string findStr(const string& str) {
    string foundValues = "";
    size_t pos = 0;

    while (true) {
        size_t pos1 = str.find("aa", pos);
        size_t pos2 = str.find("bb", pos);
        size_t pos3 = str.find("cc", pos);

        size_t nextPos = string::npos;
        if (pos1 != string::npos) nextPos = pos1;
        if (pos2 != string::npos && (nextPos == string::npos || pos2 < nextPos)) nextPos = pos2;
        if (pos3 != string::npos && (nextPos == string::npos || pos3 < nextPos)) nextPos = pos3;

        if (nextPos == string::npos) break;

        foundValues += str.substr(nextPos, 2) + " ";

        pos = nextPos + 2;
    }

    return foundValues.empty() ? "" : foundValues.substr(0, foundValues.size() - 1);
}


string Change(string& str)
{
    if (str.length() < 2)
    {
        cout << "Enter more characters";
        return str;
    }

    size_t pos;
    while (true) {
        size_t pos1 = str.find("aa");
        size_t pos2 = str.find("bb");
        size_t pos3 = str.find("cc");

        pos = string::npos;
        if (pos1 != string::npos) pos = pos1;
        if (pos2 != string::npos && (pos == string::npos || pos2 < pos)) pos = pos2;
        if (pos3 != string::npos && (pos == string::npos || pos3 < pos)) pos = pos3;

        if (pos == string::npos) break;

        str.replace(pos, 2, "***");
    }

    return str;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "Modified string (param) : " << str << endl;

    string foundStr = findStr(str);
    if (!foundStr.empty())
    {
        Change(str);
        cout << "'" << foundStr << "' found and will be changed" << endl;
        cout << "Modified string (result): " << str << endl;
    }
    else
    {
        cout << "'aa or bb or cc' not found" << endl;
    }

    return 0;
}
