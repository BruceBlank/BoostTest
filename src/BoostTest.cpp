//============================================================================
// Name        : BoostTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

#include <boost/assign/list_inserter.hpp> // for 'insert()'
#include <boost/foreach.hpp>

// main class (singleton)
class CBoostTest{
private:
	// no direct instantiation
	CBoostTest(){}
	// no direct copy
	CBoostTest(const CBoostTest &);

public:
	// return an instance
	static CBoostTest &instance(){
		static CBoostTest instance;
		return instance;
	}
	// do it using boost features
	void doit_boost();
	// do it using C++11 features
	void doit_cpp11();
};

void CBoostTest::doit_boost()
{
	cout << "Fill and loop through map using boost feature:" << endl;
	cout << "----------------------------------------------" << endl;
	typedef map<string,int> MonthMap;
	MonthMap days_per_month;
	// fill map using boost feature
	boost::assign::insert(days_per_month)( "january",   31 )( "february", 28 )
                ( "march",     31 )( "april",    30 )
                ( "may",       31 )( "june",     30 )
                ( "july",      31 )( "august",   31 )
                ( "september", 30 )( "october",  31 )
                ( "november",  30 )( "december", 31 );
	// output map using boost foreach
	BOOST_FOREACH(MonthMap::value_type val, days_per_month){
		cout << val.first << ": " << val.second << endl;
	}
	cout << endl;
}

void CBoostTest::doit_cpp11()
{
	cout << "Fill and loop through map using C++11 feature:" << endl;
	cout << "----------------------------------------------" << endl;
	typedef map<string,int> MonthMap;
	// fill map using boost feature
	MonthMap days_per_month = {
			{ "january",   31 },{ "february", 28 },
            { "march",     31 },{ "april",    30 },
            { "may",       31 },{ "june",     30 },
            { "july",      31 },{ "august",   31 },
            { "september", 30 },{ "october",  31 },
            { "november",  30 },{ "december", 31 }
	};
	// output map using C++11 foreach
	for(MonthMap::value_type &val : days_per_month){
		cout << val.first << ": " << val.second << endl;
	}
	cout << endl;
}


int main() {
	CBoostTest &main = CBoostTest::instance();
	main.doit_boost();
	main.doit_cpp11();
}
