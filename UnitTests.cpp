#include <iostream>
#include "LinkedList.h"
#include "boost\test\unit_test.hpp"
#define BOOST_TEST_MODULE MyTest


BOOST_AUTO_TEST_CASE(TestinsElem)
{
	LinkedList testList;
	
	BOOST_CHECK(true == testList.insElem('a'));
	BOOST_CHECK(true == testList.insElem('b'));
	BOOST_CHECK(true == testList.insElem('c'));
	BOOST_CHECK(true == testList.insElem('d'));

	BOOST_CHECK(false == testList.insElem('d'));

	BOOST_CHECK(true == testList.insElem('e'));
	BOOST_CHECK(true == testList.insElem('g'));
	BOOST_CHECK(true == testList.insElem('h'));
	BOOST_CHECK(true == testList.insElem('f'));
	
	std::vector<std::pair<char, int>> elemente = testList.getElemets();
	for (unsigned int i = 0; i < elemente.size(); i++)
	{
		BOOST_CHECK_EQUAL(i, elemente.at(i).second);
	}
	


}


