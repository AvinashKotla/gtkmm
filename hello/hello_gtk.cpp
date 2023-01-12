// To compile a single file:
// g++ filename.cpp -o m `pkg-config gtkmm-3.0 --libs --cflags`
// g++ simple.cc -o simple `pkg-config gtkmm-4.0 --cflags --libs`

// To compile, link and execute a header and a .cc file:
// g++ -c -Wall  helloworld.cc -o helloworld.o `pkg-config gtkmm-3.0 --cflags`
// g++ -c -Wall  main.cc -o main.o `pkg-config gtkmm-3.0 --cflags`
// g++ helloworld.o main.o -o helloworld `pkg-config gtkmm-3.0 --libs`

/*
// https://www.ubuntubuzz.com/2018/11/setup-cpp-gtkmm-programming-tools-on-ubuntu-for-beginners.html
Makefile:
# thanks to Dorku, I modified his Makefile from https://stackoverflow.com/a/26995650
CC=g++
CFLAGS=-c -Wall 
SOURCES=helloworld.cc main.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=helloworld

all: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS) 
 $(CC) $(OBJECTS) -o $@ `pkg-config gtkmm-3.0 --libs`

.cc.o:
 $(CC) $(CFLAGS) $< -o $@ `pkg-config gtkmm-3.0 --cflags`

clean:
 rm -rf *.o helloworld
*/


// To compile, link and execute any typical header and main file:
// g++ -g -c headerfile.cpp
// g++ -g -c mainfile.cpp
// two .o files are generated now
// g++ -g -o executablefile headerfile.o mainfile.o
// ./executablefile
// (or) 
// g++ -g -o executablefile mainfile.cpp headerfile.cpp
// ./executablefile


/*
// https://developer-old.gnome.org/gtkmm-tutorial/stable/sec-basics-simple-example.html.en
#include <gtkmm.h>

class MyWindow : public Gtk::Window
{
public:
  MyWindow();
};

MyWindow::MyWindow()
{
  set_title("Basic application");
  set_default_size(200, 200);
}

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.examples.base");

  return app->make_window_and_run<MyWindow>(argc, argv);
}

*/


/*
// https://docs.huihoo.com/gtkmm/programming-with-gtkmm-3/3.4.1/en/sec-basics-simple-example.html
#include <gtkmm.h>

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create(argc, argv,
      "org.gtkmm.examples.base");

  Gtk::ApplicationWindow window;

  return app->run(window);
}
*/


//#include <gtkmm-3.0/gtkmm.h> // this also works
#include <gtkmm.h>
#include <iostream>

using namespace std;


void click_message()
{
  static int i=0;
  cout << "Button clicks: " << ++i << endl;
  //cout << "Button clicked: " << i++ << endl;
}


int main ()
{
  
  //Gtk::Main kit(argc,argv);   // This line replaces the two lines 
  Glib::RefPtr<Gtk::Application> app;
  app = Gtk::Application::create();


  Gtk::ApplicationWindow window;
  Gtk::Button button("Click here");
  
  window.set_default_size(600,400);
  window.set_position(Gtk::WIN_POS_CENTER);
  window.set_border_width(10);
  window.add(button);
  button.show();

  button.signal_clicked().connect(sigc::ptr_fun(&click_message)); // displays message when button is clicked

  //return Gtk::Main::run(window); // if kit() is used
  return app-> run(window);
  
}



