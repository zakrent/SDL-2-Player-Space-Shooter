#ifndef OSIM_RENDERINST
#define OSIM_RENDERINST

#include "Types.h"
#include "Vector2D.h"

struct RenderInstruction{
	uint8 colR, colG, colB;
	Vector2D startPos;
	Vector2D endPos;	
	RenderInstruction(Vector2D _startPos, Vector2D _endPos, uint8 _colR, uint8 _colG, uint8 _colB)
	: colR(_colR), colG(_colG), colB(_colB), startPos(_startPos), endPos(_endPos){}
};

#endif
