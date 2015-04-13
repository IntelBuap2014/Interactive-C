//Para compilar:
//gcc `pkg-config --cflags gtk+-3.0` -o principal gtk-principal.c `pkg-config --libs gtk+-3.0`

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

  gtk_init (&argc, &argv);

  bind_text_domain_codeset("Interactive-C", "UTF-8");
  setlocate(LC_ALL, "");
  bindtextdomain("Interactive-C","idioma");

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "Principal.ui", NULL);

  /* Connect signal handlers to the constructed widgets. */
  window = gtk_builder_get_object (builder, "window");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  /*button = gtk_builder_get_object (builder, "button1");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "button2");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "button3");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "button4");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);*/

  gtk_main ();

  return 0;
}

