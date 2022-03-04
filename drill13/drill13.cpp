/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill13.cpp `fltk-config --ldflags --use-images` -o a.out
*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){

	try {
		Point t1 {300,50};
		Simple_window win(t1,1000,800,"My window");
		win.wait_for_button();

		//rácsok létrehozása
		int x_size = 800;
		int y_size = 800;
		Lines grid;

		for (int i = 0; i <= 800; i+=100){

			grid.add(Point{i,0},Point{i,y_size});
			grid.add(Point{0,i},Point{x_size,i});
		}

		win.attach(grid);
		win.wait_for_button();

		//átlósan kitöltés 
		Rectangle r {Point{0,0},100,100};
			r.set_fill_color(Color::red);
			win.attach(r);

		Rectangle r1 {Point{100,100},100,100};
			r1.set_fill_color(Color::red);
			win.attach(r1);

		Rectangle r2 {Point{200,200},100,100};
			r2.set_fill_color(Color::red);
			win.attach(r2);

		Rectangle r3 {Point{300,300},100,100};
			r3.set_fill_color(Color::red);
			win.attach(r3);

		Rectangle r4 {Point{400,400},100,100};
			r4.set_fill_color(Color::red);
			win.attach(r4);

		Rectangle r5 {Point{500,500},100,100};
			r5.set_fill_color(Color::red);
			win.attach(r5);

		Rectangle r6 {Point{600,600},100,100};
			r6.set_fill_color(Color::red);
			win.attach(r6);

		Rectangle r7 {Point{700,700},100,100};
			r7.set_fill_color(Color::red);
			win.attach(r7);

		win.wait_for_button();

		//random 3 kép hozzáadása (200*200)
		Image img1 {Point{0,300},"GUI/cat.jpg"};
		Image img2 {Point{300,600},"GUI/cat.jpg"};
		Image img3 {Point{500,100},"GUI/cat.jpg"};

		img1.set_mask(Point{0,150},200,200);
		img2.set_mask(Point{100,200},200,200);
		img3.set_mask(Point{100,150},200,200);

		win.attach(img1);
		win.attach(img2);
		win.attach(img3);
		win.wait_for_button();

		//100*100 kép random mozgatása next-re nyomáskor

		while(true){
			
			int rand_x = rand() % 7 + 1;
			rand_x *= 100;
			int rand_y = rand() % 7 + 1;
			rand_y *= 100;
			Image img4 {Point{rand_x,rand_y},"GUI/cat.jpg"};
			img4.set_mask(Point(50,50),100,100);
			win.attach(img4);
			win.set_label("images");
			win.wait_for_button();
		}

		} catch (exception& e){
		cerr << "exception: " << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "error" << endl;
		return 2;
	}
}