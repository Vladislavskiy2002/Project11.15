//									   - - - - - - - - - - - - - - -  The task   - - - - - - - - - - - - - - -   
//			 - - - - - - - - - - - - - - -		 Write a program that reads a text file and writes			- - - - - - - - - - - - - - -  
//			 - - - - - - - - - - - - - - -   the number of characters of each category to another file		- - - - - - - - - - - - - - -



#include "../std_lib_facilities.h"
#include <locale>
#include "windows.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string file_name = "file.txt";
	ifstream ifs{ file_name };
	if (!ifs)
	{
		cerr << "file " << file_name << " is not found" << endl;
		return 3;
	}

	string temp_str;
	double s_num = 0.0;
	bool zapyataya = false;
	vector <double>vec_num;
	while (ifs >> temp_str)
	{
		zapyataya = false;
		char ch;
		for (int i = 0; i < temp_str.size(); i++)
		{
			if (isdigit(temp_str[i]))
			{
				if (i + 1 == temp_str.size())
				{
					stringstream sw{ temp_str };
					sw >> s_num;
					vec_num.push_back(s_num);
					break;
				}
			}
			else if (temp_str[i] == '.' || temp_str[i] == ',')
			{
				if (zapyataya == true)
				{
					break;
				}
				zapyataya = true;
			}
			else
				break;
		}
	}
	ofstream ofs{ "gupsy.txt" };
	if (!ofs)
	{
		cerr << "fileout ERROR" << endl;
		return 3;
	}
	int prov = 3;
	ofs << scientific << setprecision(8);
	cout << scientific << setprecision(8);
	for (int i = 0; i < vec_num.size(); i++)
	{
		/*cout << defaultfloat << setprecision(8) << setw(nock) << vec_num[i];
		ofs << defaultfloat << setprecision(8) << setw(nock) << vec_num[i];*/
		cout << setw(20) << vec_num[i];
		ofs << setw(20) << vec_num[i];
		if (i == prov)
		{
			cout << endl;
			ofs << endl;
			prov += 4;
		}
	}
	/*ofs << "counting alphanumeric characters: " << isaln_num << endl;
	ofs << "counting alphabetic characters: " << isalp_num << endl;
	ofs << "number of capital letters: " << isup_num << endl;
	ofs << "number of lowercase letters: " << islow_num << endl;
	ofs << "numeric character counting: " << isdig_num << endl;
	ofs << "whitespace counting: " << isspa_num << endl;
	ofs << "counting unknown characters: " << nonchar_num << endl;*/
	cout << endl << "bye" << endl;
	cin.get();
	cin.get();
	return 0;
}