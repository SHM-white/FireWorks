#include <conio.h>
#include<graphics.h>
#include <iostream>
#include"firework.h"
#include<vector>

int main()
{
	const int Max_Count{ 10 };
	int count{ 0 };
    initgraph(640, 480);
	int x;
	int y;
	COLORREF colors[10]{BLUE,GREEN,CYAN,RED,YELLOW,LIGHTBLUE,LIGHTCYAN,LIGHTGREEN,LIGHTRED,WHITE};
	std::vector<FireWorkParticle> fireworks;
	for (int i = 0; i < Max_Count; i++) {
		x = rand() % 640;
		y = rand() % 480;
		fireworks.push_back(FireWorkParticle(x, y, colors[i]));
	}
	for (auto& a : fireworks) {
		a.InitFireWork();
	}
	while (!_kbhit())// 按任意键继续
	{
		for (auto& a : fireworks) {
			
			for (int i = 0; i < a.Count; i++) {
				a.GetFireWork(i, x, y);
				putpixel(x, y, 0);
			}
			a.MoveFireWork();
			for (int i = 0; i < a.Count; i++) {
				a.GetFireWork(i, x, y);
				putpixel(x, y, a.mGetColor());
			}
		}
		Sleep(20);
	}
	closegraph();			// 关闭绘图窗口
	return 0;
}