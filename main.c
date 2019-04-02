#include <stdio.h>
#include <turboc.h>
#include <windows.h>

void cursor(int n) // 커서 보이기 & 숨기기
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
 
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 
    ConsoleCursor.bVisible = n;
    ConsoleCursor.dwSize = 1;
 
    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}



int main() 
{
	system("mode con: cols=93 lines=39");
	POINT pt;
	cursor(0);
	int x, y, mx, my, fx, fy, a, b, cx, cy, csx, csy;
	fx = GetSystemMetrics(SM_CXSCREEN) / 2;
	fy = GetSystemMetrics(SM_CYSCREEN) / 2;


	
	cx = 45, cy = 18;

	SetCursorPos(fx,fy);
	gotoxy(cx, cy);
	printf("■");
	while(1){ 
		
		

		GetCursorPos(&pt);
		
		x = pt.x;
		y = pt.y;
		if(x != fx || y != fy){
			clrscr();
			mx = fx - x;
			my = fy - y;
			a = mx;
			b = my;
			if(mx < 0)
				a = -mx;
			if(my < 0)
				b = -my;
			if(a > b){
				if(mx < 0){
					
					cx = cx + 1;
				}
				else{ 
					
					cx = cx - 1;
				}
			}
			else if(a == b){
				if(mx > 0 && my < 0){
					cx = cx - 1;
					cy = cy + 1;
				}
				else if(mx < 0 && my > 0){
					cx = cx + 1;
					cy = cy - 1;
				}
				else if(mx > 0 && my > 0){
					cx = cx - 1;
					cy = cy - 1;
				}
				else if(mx < 0 && my < 0){
					cx = cx + 1;
					cy = cy + 1;
				}
			}
			else{
				if(my < 0){
					
					cy = cy + 1;
				}
				else{
					
					cy = cy - 1;
				}
			}
			
			
			gotoxy(cx, cy);
			printf("■");
			SetCursorPos(fx,fy);
			if(cy < 0 || cy > 38 || cx < 0 || cx > 91){
				clrscr();
				break;
				
			}
			


			
			Sleep(100);
		}

		
	
		
		
		
		
		
		gotoxy(0, 0);
		
	}
}