#include "stdafx.h"
#include "query.h"

Query::Query(std::string mys)
{
	mysentence = mys;
}
std::string Query::getsentence()
{
	return mysentence;
}