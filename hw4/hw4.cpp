
#include "stdafx.h"
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "query.h"



int main()
{
	std::string filename, sentence;
	std::ifstream myfile;
	std:: cout << "please enter your file name: ";
	std::cin >> filename;
	std::cout << "please enter your sentence: ";
	std::cin.ignore();
	std::getline(std::cin, sentence);

	myfile.open(filename.c_str());
	if (myfile.fail())
	{
		std::cout << "File open failed.\n";
		exit(1);
	}
	std::cout << std::fixed << std::showpoint;
	std::cout << std::setprecision(3);
	std::stringstream stream;
	std::stringstream stream2;
	std::string s[30000];
	std::string	s3[100];
	std::string s2;

	Query myquery(sentence);

	stream2 << myquery.getsentence();
	while (!myfile.eof())
	{
		getline(myfile, s2);
		stream << s2;
	}
	myfile.close();

	for (int i = 0; i < 30000; i++)
	{
		stream >> s[i];
		s[i].erase (remove_if(s[i].begin(), s[i].end(), ispunct),s[i].end());
		transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);

	}

	for (int i = 0; i < 100; i++)
	{
		stream2 >> s3[i];
		s3[i].erase(remove_if(s3[i].begin(), s3[i].end(), ispunct), s3[i].end());
		transform(s3[i].begin(), s3[i].end(), s3[i].begin(), ::tolower);

	}

	std::set<std::string> const w (s, s+30000);
	std::set<std::string> const w2 (s3, s3+100);
	std::vector<std::string> w3;
	std::set_intersection(w.begin(), w.end(),w2.begin(), w2.end(),back_inserter(w3));
	double a, b, c;
	a = w3.size()-1;//intersection
	b = w.size()-1; //number element set1
	c = w2.size()-1; //number element set2
	std::cout << "the similarity between set1 and set 2 is: ";
	std::cout << a / (sqrt(b)*sqrt(c)) << std::endl;
	std::cout << "the number of element set1 is : ";
	std::cout << b << std::endl;
	std::cout << "the number of element set2 is: ";
	std::cout << c << std::endl;
	std::cout << "the number of element intersection: ";
	std::cout << a << std::endl;

	return 0;
}
