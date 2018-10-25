#include "stdafx.h"
#include "Edge.h"

Edge::Edge(int nodeIndexA, int nodeIndexB, int weightValue)
{
	this->m_iNodeIndexA = nodeIndexA;
	this->m_iNodeIndexB = nodeIndexB;
	this->m_iWeightValue = weightValue;
	this->m_bSelected = false;
}
