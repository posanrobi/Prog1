/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill12.cpp `fltk-config --ldflags --use-images` -o a.out
*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){

	try {

		Point t1 {100,100};

		Simple_window win {t1,600,400,"My window"};
		win.wait_for_button();

		Axis xa {Axis::x,Point{30,300},280,20,"x axis"};
		win.attach(xa);
		win.set_label("x axis");
		win.wait_for_button();

		Axis ya {Axis::y,Point{30,300},280,20,"y axis"};
		ya.set_color(Color::dark_cyan);
		ya.label.set_color(Color::dark_red);
		win.attach(ya);
		win.set_label("y axis");
		win.wait_for_button();

		Function sine {sin,0,100,Point{30,170},1200,50,50};
		win.attach(sine);
		win.set_label("sine");
		win.wait_for_button();

		Polygon poly;
		poly.add(Point{300,200});
		poly.add(Point{350,100});
		poly.add(Point{400,200});
		poly.set_color(Color::red);
		poly.set_style(Line_style::dashdot);
		win.attach(poly);
		win.set_label("polygon");
		win.wait_for_button();

		Rectangle r {Point{200,200},100,50};
		win.attach(r);
		win.set_label("rectangle");
		win.wait_for_button();

		Closed_polyline poly_rect;
		poly_rect.add(Point{100,50});
		poly_rect.add(Point{200,50});
		poly_rect.add(Point{200,100});
		poly_rect.add(Point{100,100});
		poly_rect.add(Point{50,75});
		win.attach(poly_rect);

		r.set_fill_color(Color::blue);
		poly.set_style(Line_style(Line_style::dash,4));
		poly_rect.set_style(Line_style(Line_style::dashdot,2));
		poly_rect.set_fill_color(Color::green);
		win.set_label("fill");
		win.wait_for_button();

		Text t {Point{150,150},"Hello, graphical world!"};
		win.attach(t);
		win.set_label("text");
		win.wait_for_button();

		t.set_font(Font::times_italic);
		t.set_font_size(30);
		win.set_label("font");
		win.wait_for_button();

		Image ii {Point{100,50},"GUI/badge.jpg"};
		win.attach(ii);
		win.set_label("image");
		win.wait_for_button();

		ii.move(120,200);
		win.set_label("moved image");
		win.wait_for_button();

		Circle c {Point{100,200},70};
		Ellipse e {Point{100,200},85,30};
		e.set_color(Color::dark_magenta);
		Mark m {Point{100,200},'O'};

		ostringstream oss;
		oss << "screen size: " << x_max() << "*" << y_max()
			<< "; window size: " << win.x_max() << "*" << win.y_max();
		Text sizes {Point{100,20},oss.str()};

		Image cal {Point{225,225},"GUI/badge.jpg"};
		cal.set_mask(Point{40,40},200,150);

		win.attach(c);
		win.attach(m);
		win.attach(e);

		win.attach(sizes);
		win.attach(cal);
		win.set_label("Last window");
		win.wait_for_button();


	} catch (exception& e){
		cerr << "exception: " << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "error" << endl;
		return 2;
	}
}