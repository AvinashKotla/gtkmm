#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>

// The class mainwindow inherits from Gtk::Window
class mainwindow : public Gtk::Window
{
	// Constructor and destructor
public:    
	mainwindow();
	virtual             ~mainwindow();

protected:
	//Signal handlers (run when the button are clicked)
	void                  on_button();

	//Member widgets:
	Gtk::Button           buttonQuit;
	Gtk::Grid             mainGrid;
};


#endif // MAINWINDOW_H