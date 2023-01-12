#include "mainwindow.h"
#include <gtkmm.h>


// Constructor of the main Window (build ui interface).
mainwindow::mainwindow()
{
	// Initialize the main window and hide the title bar
	this->set_border_width(0);
	this->set_decorated(false);

	// Add the Quit button
	buttonQuit.add_label("Quit");
	buttonQuit.set_size_request(200,100);
	buttonQuit.signal_enter().connect(sigc::mem_fun(*this,&mainwindow::on_button));
	buttonQuit.signal_pressed().connect(sigc::mem_fun(*this,&mainwindow::close));
	mainGrid.attach(buttonQuit,0,1,3,1);

	// Display the main grid in the main window
	mainGrid.set_column_spacing(10);
	mainGrid.set_row_spacing(10);
	mainGrid.show_all();

	// Insert the grid in the main window
	add(mainGrid);
}


// Destructor of the class
mainwindow::~mainwindow()
{}


// Call when the button is clicked
void mainwindow::on_button()
{
	// Get screen dimensions
	Glib::RefPtr screen = Gdk::Screen::get_default();
	// Move window at a new random position
	this->move(rand()%screen->get_width(),rand()%screen->get_height());
}