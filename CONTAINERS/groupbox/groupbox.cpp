#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 900
#define WIDTH 200
#define HEIGHT 300

class Form : public Window {
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Frame groupBox1;
  Frame groupBox2;
  Frame groupBox3;
  Frame groupBox4;


public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    groupBox1.set_label("Axial");
    fixed.add(groupBox1);
    fixed.move(groupBox1, 300, 10);
    groupBox1.set_size_request(WIDTH, HEIGHT);
    
    groupBox2.set_label("Coronal");
    fixed.add(groupBox2);
    fixed.move(groupBox2, 550, 10);
    groupBox2.set_size_request(WIDTH, HEIGHT);


    groupBox3.set_label("3D");
    fixed.add(groupBox3);
    fixed.move(groupBox3, 300, 320);
    groupBox3.set_size_request(WIDTH, HEIGHT);
    
    groupBox4.set_label("Sagittal");
    fixed.add(groupBox4);
    fixed.move(groupBox4, 550, 320);
    groupBox4.set_size_request(WIDTH, HEIGHT);

    set_title("GUI");
    resize(SCREEN_WIDTH, SCREEN_HEIGHT);
    show_all();
  }
  
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
