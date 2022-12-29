#include <conio.h>
#include<graphics.h>
#include <iostream>
#include"firework.h"
#include<vector>

int main()
{
	const int Max_Count{ 30 };
	int count{ 0 };
	int count_1{ 0 };
    initgraph(1280, 720);
	int x;
	int y;
	COLORREF colors[10]{BLUE,GREEN,CYAN,RED,YELLOW,LIGHTBLUE,LIGHTCYAN,LIGHTGREEN,LIGHTRED,WHITE};
	std::vector<FireWorkParticle> fireworks;
	while (!_kbhit())// 按任意键继续
	{
		if (count < Max_Count) {
			if (count_1 < 10) {
				count_1++;
			}
			else
			{
				count_1 = 0;
				x = rand() % 1280;
				y = rand() % 720;
				fireworks.push_back(FireWorkParticle(x, y, colors[count % 10]));
				fireworks[count].InitFireWork();
				count++;
			}
		}
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