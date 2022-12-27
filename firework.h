#pragma once
#include <stdlib.h>
#include<math.h>
class Step
{
public:
	double x{ 0 };
	double y{ 0 };
};
class FireWork {
public:
	FireWork() {};
	FireWork(double ix, double iy, Step istep)
		:x{ ix }, y{ iy }, step{ istep } {};
	void mSetFireWork(double ix, double iy, Step istep){
		x = ix;
		y = iy;
		step = istep;
	};
	int mMoveFireWork();
	int mGetXY(int& ix, int& iy);
private:
	double x{ 0 };
	double y{ 0 };
	Step step;
};
class FireWorkParticle
{
public:
	FireWorkParticle(int x, int y,COLORREF icolor)
		:CenterX{ x }, CenterY{ y }, color{icolor} {};
	void InitFireWork();
	void MoveFireWork();
	void GetFireWork(int i,int& ix,int& iy);
	static const int Count{ 500 };
	COLORREF mGetColor();
private:
	int CenterX;
	int CenterY;
	FireWork fireworks[Count];
	Step step;
	int count{ 0 };
	COLORREF color;
	const int max_count{ 50 };
};
void FireWorkParticle::InitFireWork()
{
	int op = 1;
	double resize;
	for (int i = 0; i < Count; i++) {
		if (i % 2) {
			step.x = (rand() % 1000) / 100.0 - 5.0;
			step.y = sqrt(25.0 - pow(step.x, 2)) * (op);
			op = op * (-1);
		}
		else {
			step.y = (rand() % 1000) / 100.0 - 5.0;
			step.x = sqrt(25.0 - pow(step.y, 2)) * (op);
		}
		resize = (rand() % 100) / 100.0;
		step.x *= resize;
		step.y *= resize;
		fireworks[i].mSetFireWork(CenterX, CenterY, step);
	}
}
void FireWorkParticle::MoveFireWork()
{
	
	for (int i = 0; i < Count; i++) {
		fireworks[i].mMoveFireWork();
	}
	count += 1;
	if (count > max_count){ 
		InitFireWork(); 
		count = 0;
		CenterX = rand() % 640;
		CenterY = rand() % 480;
	}
		
}
int FireWork::mMoveFireWork()
{
	
	x += step.x;
	y += step.y;	
	return 0;
}
int FireWork::mGetXY(int& ix, int& iy)
{
	ix = (int)x;
	iy = (int)y;
	return 0;
}
void FireWorkParticle::GetFireWork(int i, int& ix, int& iy)
{
	if (i < Count) {
		fireworks[i].mGetXY(ix, iy);
	}
	else {
		ix = iy = 0;
	}
}
inline COLORREF FireWorkParticle::mGetColor()
{
	double r = GetRValue(color);
	double g = GetGValue(color);
	double b = GetBValue(color);
	r *= ((double)(max_count - count) / (double)max_count);
	g *= ((double)(max_count - count) / (double)max_count);
	b *= ((double)(max_count - count) / (double)max_count);
	return RGB((int)r, (int)g, (int)b);
}