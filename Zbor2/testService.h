#pragma once
#include "Service.h"
using namespace std;

class TestService {
private:
	Service s;
	void test1();	
	void test2();
	void test3();
public:
	TestService();
	void runTests();
	~TestService();
	};


