#include <gtkmm.h>
#include "mainwindow.h"


int main(int argc, char* argv[])
{
	// Initialize gtkmm
	Gtk::Main app(argc, argv);
	// Create the window
	mainwindow w;
	// Start main loop
	Gtk::Main::run(w);
	return 0;
}