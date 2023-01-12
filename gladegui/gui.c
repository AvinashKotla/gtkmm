#include <stdio.h>
#include <gtk-3.0/gtk/gtk.h>
#include <gtk-3.0/gtk/gtkx.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *fixed;
    GtkWidget *radio;
    GtkWidget *button1;
    GtkWidget *label1;
    GtkBuilder *builder;

    builder = gtk_builder_new_from_file("part2.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder,"window"));
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_builder_connect_signals(builder,NULL);

    fixed = GTK_WIDGET(gtk_builder_get_object(builder,"fixed"));
    radio = GTK_WIDGET(gtk_builder_get_object(builder,"radio"));
    button1 = GTK_WIDGET(gtk_builder_get_object(builder,"button"));

    gtk_widget_show(window);

    gtk_main();

    return EXIT_SUCCESS;
}

/*
void on_button_clicked (GtkButton *b)
{
    gtk_label_set_text (GTK_LABEL(label1), (const gchar*), "Hello World");
}
*/