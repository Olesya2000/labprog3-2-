// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	ifstream fin("premier_league.csv");
	ofstream fout("result.csv");
	char s [3];
	fin >> s;
	int n = atoi(s);
	string line;
	getline(fin, line);
	string *name = new string[n];
	int *scopes = new int[n];
	for (int i = 0; i < n; i++) {
		getline(fin, line);
		int j = 0;
		int scope = 0;
		while (line[j] != ',')
		{
			name[i] += line[j];
			j++;
		}
		j++;
		while (j < line.length()) {
			if (line[j] > line[j + 2]) scope += 3; 
			else if (line[j] == line[j + 2]) scope += 1;
			j += 4;
		}
		scopes[i] = scope;
	}
	for (int k = 0; k < n; k++)
	{
		int scope = 0, j;
		for (int i = 0; i < n; i++)
		{
			if (scopes[i] > scope)
			{
				scope = scopes[i];
				j = i;
			}
		}
		fout << k + 1 << ". " << name[j] << ": " << scope << '.'<< endl;
		scopes[j] = -1;
	}
	return 0;
}

