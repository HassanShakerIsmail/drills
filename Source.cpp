#include<GUI.h>
#include <Graph.h>
#include <Simple_window.h>
#include <FL/fl_draw.H>

//draws my intials (H.I) with each letter as a different color.

using namespace Graph_lib;

struct Arc_Class : Shape{
	Arc_Class(Point P, int w, int h, double a1, double a2)
		:x{ P.x }, y{ P.y }, height{ h }, ang1{ a1 }, ang2{ a2 }
	{
		fl_arc(x, y, h, ang1, ang2);
	}

private:
	int x;
	int y;
	int height;
	double ang2;
	double ang1;

};

void drawIntials() {
	Point t1{ 100,100 };
	Simple_window win{ t1,750,750,"Window" };
	Graph_lib::Rectangle hInitalLeft{ Point{0,0},10,100 };
	Graph_lib::Rectangle hIntialBridge{ Point{0,50},25,10 };
	Graph_lib::Rectangle hInitialRight{ Point{25,0},10,100 };

	hInitalLeft.set_fill_color(Color::black);
	hIntialBridge.set_fill_color(Color::black);
	hInitialRight.set_fill_color(Color::black);
	win.attach(hInitialRight);
	win.attach(hInitalLeft);
	win.attach(hIntialBridge);
	win.wait_for_button();

}

//creates a 3x3 tictactoe board of red and white squares (Wonder, better way to do this?)
void TicTacToeBoard() {
	Simple_window win{ Point{0,0},1200,1200,"TicTacToe" };
	Graph_lib::Rectangle square1{ Point{0,0},100,100 };
	Graph_lib::Rectangle square2{ Point{100,0},100,100 };
	Graph_lib::Rectangle square3{ Point{200,0},100,100 };
	Graph_lib::Rectangle square4{ Point{0,100},100,100 };
	Graph_lib::Rectangle square5{ Point{100,100},100,100 };
	Graph_lib::Rectangle square6{ Point{200,100},100,100 };
	Graph_lib::Rectangle square7{ Point{0,200},100,100 };
	Graph_lib::Rectangle square8{ Point{100,200},100,100 };
	Graph_lib::Rectangle square9{ Point{200,200},100,100 };

	square1.set_fill_color(Color::red);
	square2.set_fill_color(Color::white);
	square3.set_fill_color(Color::red);
	square4.set_fill_color(Color::white);
	square5.set_fill_color(Color::red);
	square6.set_fill_color(Color::white);
	square7.set_fill_color(Color::red);
	square8.set_fill_color(Color::white);
	square9.set_fill_color(Color::red);

	win.attach(square1);
	win.attach(square2);
	win.attach(square3);
	win.attach(square4);
	win.attach(square5);
	win.attach(square6);
	win.attach(square7);
	win.attach(square8);
	win.attach(square9);

	win.wait_for_button();
}

class Smiley : public Shape {


};
int main() {
	Simple_window test{ Point{0,0},1200,1200,"Main" };
	test.wait_for_button();

}

/*
Point t1{ 100,100 };
Simple_window win{ t1,600,400,"Canvas" };
Graph_lib::Rectangle r{ Point(200,100),100,200 };
r.set_fill_color(Color::black);
Graph_lib::Polygon rectng;
Text z1{ Point{500,250},"Howdy!" };
z1.set_color(Color::black);
rectng.add(Point{ 100,100 });
rectng.add(Point{ 0,100 });
rectng.add(Point{ 0,0 });
rectng.add(Point(100, 0));
rectng.set_fill_color(Color::blue);
win.attach(z1);
win.attach(rectng);
win.attach(r);
win.wait_for_button(); */