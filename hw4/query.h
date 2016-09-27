#ifndef H_query
#define H_query

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <cstdlib>

class Query
{
public:
	Query(std::string mys);
	std::string getsentence();


private:
	std::string mysentence;


};

#endif