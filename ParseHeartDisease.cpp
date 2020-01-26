// ParseHeartDisease.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	std::stringstream ss;
	string str, stri;
	int num, i;

	ifstream oldfile;
	ofstream newfile;
	oldfile.open("cleveland.data");
	newfile.open("newCleveland.txt");

	num = 0;
	i = 0;

	if (oldfile.is_open()) cout << "Opened old file.\n";
	if (newfile.is_open()) cout << "Opened new file.\n";

	while (oldfile >> str)
	{
		++i;
		if (i == 3 || i == 4 || i == 9 || i == 10 || i == 12 || i == 16 || i == 19 || i == 32 || i == 38 || i == 40 || i == 41 || i == 44 || i == 51)
		{
			if (i == 40) {
				float a = strtof((str).c_str(), 0);
				cout << a<<" ";
				a *= 10;
				ss << a;
				str =ss.str();
				ss.str(std::string());
			}
			stri += str + " ";
		}
		else if (i == 58)
		{
			if (str == "0") stri+= str;
			else stri += "1";
		}
		else if (str == "name")
		{
			newfile << "\n";
			++num;
			i = 0;
		}
		newfile << stri;
		stri.clear();
	}
	newfile << num;


	oldfile.close();
	newfile.close();
	return 0;
}

