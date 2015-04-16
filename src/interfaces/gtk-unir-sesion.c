//Compilación: gcc `pkg-config --cflags gtk+-3.0` -o gtk-unir-sesion gtk-unir-sesion.c `pkg-config --libs gtk+-3.0`


#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>

#define _(cadena) gettext(cadena)


static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

int
main (int   argc,
      char *argv[])
{
  GtkBuilder *builder;
  GObject *window;
  GObject *button;
  GObject *entry;
  GObject *label;

  bind_textdomain_codeset ("gtk-interfaces", "UTF-8");
  setlocale(LC_ALL, "");
  bindtextdomain("gtk-interfaces", "idioma");
  textdomain("gtk-interfaces");

  gtk_init (&argc, &argv);

  bind_textdomain_codeset("Interactive-C", "UTF-8");
  setlocale(LC_ALL, "");
  bindtextdomain("Interactive-C","idioma");
  textdomain("Interactive-C");

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "builder-unir-sesion.ui", NULL);

  /* Connect signal handlers to the constructed widgets. */
  window = gtk_builder_get_object (builder, "window");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  button = gtk_builder_get_object (builder, "acceptButton");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "cancelButton");
  g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

  label = gtk_builder_get_object (builder, "hostLabel");
  label = gtk_builder_get_object (builder, "portLabel");
  label = gtk_builder_get_object (builder, "nameLabel");
  label = gtk_builder_get_object (builder, "colorLabel");
  label = gtk_builder_get_object (builder, "passLabel");

  entry = gtk_builder_get_object (builder, "hostEntry");
  g_signal_connect(entry, "activate", G_CALLBACK(print_hello), NULL);

  entry = gtk_builder_get_object (builder, "portEntry");
  g_signal_connect(entry, "activate", G_CALLBACK(print_hello), NULL);
 
  entry = gtk_builder_get_object (builder, "nameEntry");
  g_signal_connect(entry, "activate", G_CALLBACK(print_hello), NULL);

  entry = gtk_builder_get_object (builder, "colorEntry");
//g_signal_connect(entry, "activate", G_CALLBACK(print_hello), NULL);

  entry = gtk_builder_get_object (builder, "passEntry");
  g_signal_connect(entry, "activate", G_CALLBACK(print_hello), NULL);

  gtk_main ();

  return 0;
}
