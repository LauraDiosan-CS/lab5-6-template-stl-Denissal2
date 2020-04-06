#pragma once
#include "RepoFile.h"
class TestRepoFile
{
private:
	RepoFile<Rezervare> repo;
public:
	TestRepoFile();
	void testLoadFromFile();
	~TestRepoFile();
	
};

