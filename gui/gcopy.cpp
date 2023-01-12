#include <iostream>
#include <gtkmm.h>
#include <gdkmm/pixbuf.h>

using namespace Glib;
using namespace Gtk;
using namespace std;

#define SCREEN_WIDTH 2400
#define SCREEN_HEIGHT 1800
#define WIDTH 400
#define HEIGHT 300
#define X0 10
#define Y0 10
#define WRATIO 0.3
#define HRATIO 0.35
#define PARATIO 0.7
#define PARATIO2 0.2
#define SPACE 10

class Form : public Window
{
private:
  VBox vbox;
  Fixed fixed;
  ScrolledWindow scrolledWindow;

  Image image;
  Grid mainGrid;

  Button button;
  Button buttonvtk;
  Label label;
  Label label1;

  Frame groupBox1;
  Frame groupBox2;
  Frame groupBox3;
  Frame groupBox4;
  Frame groupBox5;

  Scale trackBar {ORIENTATION_HORIZONTAL};
  ProgressBar progressBar;

  Scale trackBar2 {ORIENTATION_VERTICAL};
  ProgressBar progressBar2;

  MenuBar menuBar;
  MenuItem File;
  MenuItem View;
  MenuItem Segmentation;
  MenuItem Mesh;
  MenuItem Help;
  
  Menu subFile;
  Menu subView;
  Menu subSegmentation;
  Menu subMesh;
  Menu subHelp;

  MenuItem FileNew;
  MenuItem FileOpen;
  SeparatorMenuItem separator1;
  MenuItem FileSave;
  MenuItem FileSaveas;
  SeparatorMenuItem separator2;
  MenuItem FileExit;

  MenuItem ViewVertices;
  MenuItem ViewEdges;
  MenuItem ViewFaces;
  SeparatorMenuItem separator3;
  MenuItem ViewWireframe;

  MenuItem SegmentationManual;
  SeparatorMenuItem separator4;
  MenuItem SegmentationAutomatic;

  MenuItem MeshElementtype;
  MenuItem MeshElementSize;
  MenuItem MeshSmoothing;

  MenuItem HelpDocumentation;

public:
  Form() 
  {
    add(vbox);
    vbox.pack_start(menuBar, PACK_SHRINK);
    vbox.pack_end(scrolledWindow);
    scrolledWindow.add(fixed);
   
    File.set_label("File");
    menuBar.append(File);
    
    View.set_label("View");
    menuBar.append(View);

    Segmentation.set_label("Segmentation");
    menuBar.append(Segmentation);
    
    Mesh.set_label("Mesh");
    menuBar.append(Mesh);
    
    Help.set_label("Help");
    menuBar.append(Help);

    File.set_submenu(subFile);
    View.set_submenu(subView);
    Segmentation.set_submenu(subSegmentation);
    Mesh.set_submenu(subMesh);
    Help.set_submenu(subHelp);
    
    subFile.append(FileNew);
    subFile.append(FileOpen);
    subFile.append(separator1);
    subFile.append(FileSave);
    subFile.append(FileSaveas);
    subFile.append(separator2);
    subFile.append(FileExit);

    subView.append(ViewVertices);
    subView.append(ViewEdges);
    subView.append(ViewFaces);
    subView.append(separator3);
    subView.append(ViewWireframe);

    subSegmentation.append(SegmentationManual);
    subSegmentation.append(SegmentationAutomatic);

    subMesh.append(MeshElementtype);
    subMesh.append(MeshElementSize);
    subMesh.append(MeshSmoothing);

    subHelp.append(HelpDocumentation);

    FileNew.set_label("New");
    FileNew.set_use_underline(true);
    FileNew.Gtk::Widget::add_accelerator("New", get_accel_group(), 'n', Gdk::CONTROL_MASK, Gtk::ACCEL_VISIBLE);
    FileNew.signal_activate().connect([&]() 
    {
      cout << "MainMenu/File/New" << endl;

    });

    FileOpen.set_label("Open");
    FileOpen.set_use_underline(true);
    FileOpen.signal_activate().connect([&]() 
    {
      cout << "MainMenu/File/Open" << endl;
    });

    FileSave.set_label("Save");
    FileSave.set_use_underline(true);
    FileSave.signal_activate().connect([&]()
    {
      cout << "MainMenu/File/Save" << endl;
    });

    FileSaveas.set_label("Save as");
    FileSaveas.set_use_underline(true);
    FileSaveas.signal_activate().connect([&]() 
    {
      cout << "MainMenu/File/Save as" << endl;
    });

    
    FileExit.set_label("Exit");
    FileExit.set_use_underline(true);
    FileExit.signal_activate().connect([&]() 
    {
      cout << "MainMenu/File/Exit" << endl;
    });

    ViewVertices.set_label("Vertices");
    ViewVertices.set_use_underline(true);
    ViewVertices.signal_activate().connect([&]()
    {
      cout << "Mainmenu/View/Vertices" << endl;
    });

    ViewEdges.set_label("Edges");
    ViewEdges.set_use_underline(true);
    ViewEdges.signal_activate().connect([&]()
    {
      cout << "Mainmenu/View/Edges" << endl;
    });

    ViewFaces.set_label("Faces");
    ViewFaces.set_use_underline(true);
    ViewFaces.signal_activate().connect([&]()
    {
      cout << "Mainmenu/View/Faces" << endl;
    });

    ViewWireframe.set_label("Wireframe");
    ViewWireframe.set_use_underline(true);
    ViewWireframe.signal_activate().connect([&]()
    {
      cout << "Mainmenu/View/Wireframe" << endl;
    });

    SegmentationManual.set_label("Manual");
    SegmentationManual.set_use_underline(true);
    SegmentationManual.signal_activate().connect([&]() 
    {
      cout << "MainMenu/Segmentation/Manual" << endl;
    });
    
    SegmentationAutomatic.set_label("Automatic");
    SegmentationAutomatic.set_use_underline(true);
    SegmentationAutomatic.signal_activate().connect([&]() 
    {
      cout << "MainMenu/Segmentation/Automatic" << endl;
    });

    MeshElementtype.set_label("Element type");
    MeshElementtype.set_use_underline(true);
    MeshElementtype.signal_activate().connect([&]() 
    {
      cout << "MainMenu/Mesh/Elementtype" << endl;
    });

    MeshElementSize.set_label("Element size");
    MeshElementSize.set_use_underline(true);
    MeshElementSize.signal_activate().connect([&]() 
    {
      cout << "MainMenu/Mesh/Elementsize" << endl;
    });

    MeshSmoothing.set_label("Smoothing");
    MeshSmoothing.set_use_underline(true);
    MeshSmoothing.signal_activate().connect([&]() 
    {
      cout << "MainMenu/Mesh/Smoothing" << endl;
    });

    HelpDocumentation.set_label("Documentation");
    HelpDocumentation.set_use_underline(true);
    HelpDocumentation.signal_activate().connect([&]()
      {
        cout << "MainMenu/Help/Documentation" << endl;
      });

// three views and 3D

    groupBox1.set_label("SidePanel");
    fixed.add(groupBox1);
    fixed.move(groupBox1, X0, Y0);
    groupBox1.set_size_request(SCREEN_WIDTH*PARATIO2, SCREEN_HEIGHT*PARATIO);

    groupBox2.set_label("Axial");
    fixed.add(groupBox2);
    fixed.move(groupBox2, X0+SCREEN_WIDTH*PARATIO2+SPACE, Y0);
    groupBox2.set_size_request(SCREEN_WIDTH*WRATIO, SCREEN_HEIGHT*HRATIO);
   
    fixed.add(trackBar);
    fixed.move(trackBar, (X0+SCREEN_WIDTH*PARATIO2+SCREEN_WIDTH*WRATIO+SPACE)*0.6, Y0-10);
    trackBar.set_size_request(200, 10);
    trackBar.set_range(0.0, 100);
    trackBar.set_draw_value(true);
    trackBar.signal_value_changed().connect([&] {
      progressBar.set_fraction(trackBar.get_value() / 100);
      label.set_text(ustring::compose("%1", (int)trackBar.get_value()));
    });
    trackBar.set_value(100);

    groupBox3.set_label("Coronal");
    fixed.add(groupBox3);
    fixed.move(groupBox3, X0+SCREEN_WIDTH*PARATIO2+SPACE+SCREEN_WIDTH*WRATIO+SPACE, Y0);
    groupBox3.set_size_request(SCREEN_WIDTH*WRATIO, SCREEN_HEIGHT*HRATIO);

    
    fixed.add(trackBar2);
    fixed.move(trackBar2, (X0+SCREEN_WIDTH*PARATIO2+SPACE+SCREEN_WIDTH*WRATIO+SPACE)*1.55, Y0+SCREEN_WIDTH*PARATIO2/2);
    trackBar2.set_size_request(10,200);
    trackBar2.set_range(0.0, 100);
    trackBar2.set_draw_value(true);
    trackBar2.signal_value_changed().connect([&] {
      progressBar2.set_fraction(trackBar2.get_value() / 100);
      label.set_text(ustring::compose("%1", (int)trackBar2.get_value()));
    });
    trackBar2.set_value(100);
    

    groupBox4.set_label("3D");
    fixed.add(groupBox4);
    fixed.move(groupBox4, X0+SCREEN_WIDTH*PARATIO2+SPACE, Y0+SCREEN_HEIGHT*HRATIO+SPACE);
    groupBox4.set_size_request(SCREEN_WIDTH*WRATIO, SCREEN_HEIGHT*HRATIO);
    
    groupBox5.set_label("Sagittal");
    fixed.add(groupBox5);
    fixed.move(groupBox5, X0+SCREEN_WIDTH*PARATIO2+SPACE+SCREEN_WIDTH*WRATIO+SPACE, Y0+SCREEN_HEIGHT*HRATIO+SPACE);
    groupBox5.set_size_request(SCREEN_WIDTH*WRATIO, SCREEN_HEIGHT*HRATIO);

    mainGrid.show_all();
    add(mainGrid);
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
