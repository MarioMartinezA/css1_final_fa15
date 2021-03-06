// Name Mario Martinez
// 12/17/15
// 
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void checkStat(ofstream& out, string S[][C]);

int main()
{
	string field[R][C];

	ifstream fin;
	ofstream fout;

	fin.open("northpole.txt");
	fout.open("status.txt");

	if(fin.fail() || fout.fail())
	{
		exit(1); //exit if text files are not found
	}
	
	fout << "Name Mario Martinez" << endl;

	fillArray(fin, field);

	checkStat(fout, field);

	fin.close();
	fout.close();
	
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	string stat;
	A_in >> stat;
	
	for(int ix = 0; ix < R; ix++)
	{
		for(int j = 0; j < C; j++)
		{
			S[ix][j] = stat;
			A_in >> stat;
		}
	}
	return;
	
}//end fillArray
//*****************************************
void checkStat(ofstream& out, string S[][C])
{
	int zombies = 0;
	for(int ix = 1; ix < R-1; ix++)
	{
		for(int j = 1; j < C-1; j++)
		{
			if(S[ix][j] == "@")
			{
				if(S[ix-1][j] == "!")
				{
					zombies++;				
				}
				if(S[ix+1][j] == "!")
				{
					zombies++;
				}
				if(S[ix][j-1] == "!")
				{
					zombies++;
				}
				if(S[ix][j+1] == "!")
				{
					zombies++;
				}

				if(zombies == 3)
				{
					out << "elf[" << ix << "][" << j << "]: Run!"<< endl;
				}
				if(zombies == 4)
				{
					out << "elf[" << ix << "][" << j << "]: Much!"<< endl;
				}

			}
			zombies = 0;
		}
	}

	return;
}




 
