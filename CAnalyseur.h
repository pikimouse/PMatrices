#pragma once
#include "CMatrice.h"
#include <iostream>
#include <string>

using namespace std;

class CAnalyseur : public CMatrice
{
private:
	string fANAFichier;
	string cANAContenue;

public :
	void ANALireFichier();
	void ANAChargerMatrice();
	CAnalyseur();
	CAnalyseur(CAnalyseur &ANAParam);
	~CAnalyseur();

};

