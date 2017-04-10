//**************************************************************************************
//姓名:楊方寧
//學號:605415032
//E - mail : candy46410330@yahoo.com.tw
//作業環境 : Win10 64bit
//編譯器 : Visual Studio 2013
//**************************************************************************************
//指定作業功能:
//1.使用者介面：畫面左邊為畫布，畫面右邊為顯示圖片
//按鈕有point, line, triangles, quit, clear, draw六個鈕
//2.point, line, triangles三個鈕按了之後, 會分別在左邊的畫布隨機的位置顯示, 且顏色也隨機, 而draw鈕會顯示啟動
//clear鈕會將左邊畫布的資料都清除, 原本draw鈕及畫圖鈕都會回初始
//quit鈕會將整個exe檔和介面關掉
//3.畫面右邊是讀取bmp圖片

//額外bonus操作功能:
//1.由於point的點很小, 不容易看到, 因此在exe畫面有顯示"print"字, 確認有做這個動作
//而其他按鈕及顯示圖的時候也都會顯示字
//**************************************************************************************

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>
#include "Read_bmp.h"
#include "Draw_sharp.h"
#include "Bmp_print.h"

Fl_Window* Interface;
Fl_Button* mode_Draw;
Fl_Button* mode_Quit;
Fl_Button* mode_Clear;
Fl_Button* mode_Line;
Fl_Button* mode_Triangle;
Fl_Button* mode_Point;
Bmp_print *readimage1;
Draw_sharp* drawpicture;

void Click_Quit(Fl_Widget*, void*)
{
	mode_Quit->value(1);
	exit(0);
}

void Click_Clear(Fl_Widget*, void*)
{
	drawpicture->draw_number = 1;
	mode_Clear->value(1);
	mode_Draw->value(0);
	mode_Triangle->value(0);
	mode_Point->value(0);
	mode_Line->value(0);
	//printf("clear\n");
}

void Click_Draw(Fl_Widget *, void*)
{
	drawpicture->draw_number = 2;
	mode_Draw->value(1);
	mode_Clear->value(0);
	printf("draw\n");
}

void Click_Line(Fl_Widget *, void*)
{
	drawpicture->draw_number = 3;
	mode_Draw->value(1);
	mode_Line->value(1);
	mode_Clear->value(0);
	mode_Point->value(0);
	mode_Triangle->value(0);
}

void Click_Triangle(Fl_Widget *, void*)
{
	drawpicture->draw_number = 4;
	mode_Draw->value(1);
	mode_Triangle->value(1);
	mode_Clear->value(0);
	mode_Point->value(0);
	mode_Line->value(0);
}

void Click_Point(Fl_Widget *, void*)
{
	drawpicture->draw_number = 5;
	mode_Draw->value(1);
	mode_Point->value(1);
	mode_Clear->value(0);
	mode_Line->value(0);
	mode_Triangle->value(0);
}

int main(int argc, char **argv)
{
	Interface = new Fl_Window(900, 500, "HW01_605415032");
	
	mode_Quit = new Fl_Button(100, 450, 80, 30, "Quit");
	mode_Quit->callback((Fl_Callback*)Click_Quit); //(Fl_Callback*)有沒有好像沒差的感覺

	mode_Clear = new Fl_Button(300, 450, 80, 30, "Clear");
	mode_Clear->callback((Fl_Callback*)Click_Clear);

	mode_Draw = new Fl_Button(200, 450, 80, 30, "Draw");
	mode_Draw->callback((Fl_Callback*)Click_Draw);

	mode_Line = new Fl_Button(100, 400, 80, 30, "Line");
	mode_Line->callback((Fl_Callback*)Click_Line);

	mode_Triangle = new Fl_Button(200, 400, 80, 30, "Triangle");
	mode_Triangle->callback((Fl_Callback*)Click_Triangle);

	mode_Point = new Fl_Button(300, 400, 80, 30, "Point");
	mode_Point->callback((Fl_Callback*)Click_Point);

	int w, h;
	BYTE *img = (BYTE*)malloc(sizeof(BYTE*));
	BMP_Read("supermario.bmp", &img, w, h);//&img(殺回?)和*img(指標)到底差在哪 //為何不直接給w,h

	readimage1 = new Bmp_print(405, 10, 400, 350);
	readimage1->setImage(img, w, h);

	drawpicture = new Draw_sharp(10, 10, 380, 350); //drawpicture為何可以這樣用 Draw_sharp() why 

	Interface->end();
	Interface->show(argc, argv);
	//system("pause");
	return Fl::run();
		
}