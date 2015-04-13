//Compilación: gcc `pkg-config --cflags gtk+-3.0` -o gtk-crear-sesion gtk-crear-sesion.c `pkg-config --libs gtk+-3.0`

#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>
<<<<<<< HEAD
=======

#define _(cadena) gettext(cadena)
>>>>>>> 56b2b6b7b09f4ec0093e61146fc0dcdf8ae9d12b

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print (_("Hello World\n"));
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

  gtk_init (&argc, &argv);

  bind_textdomain_codeset("Interactive-C", "UTF-8");
  setlocale(LC_ALL, "");
  bindtextdomain("Interactive-C","idioma");
  textdomain("Interactive-C");

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "builder-crear-sesion.ui", NULL);

  /* Connect signal handlers to the constructed widgets. */
  window = gtk_builder_get_object (builder, "window");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  button = gtk_builder_get_object (builder, "hostButton");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_button_set_label(GTK_BUTTON(button),_("Host"));

  button = gtk_builder_get_object (builder, "cancelButton");
  g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);
  gtk_button_set_label(GTK_BUTTON(button),_("Cancelar"));

  label = gtk_builder_get_object (builder, "portLabel");
  gtk_label_set_text(GTK_LABEL(label),_("Puerto:"));
  label = gtk_builder_get_object (builder, "nameLabel");
  gtk_label_set_text(GTK_LABEL(label), _("Nombre:"));
  label = gtk_builder_get_object (builder, "colorLabel");
  gtk_label_set_text(GTK_LABEL(label), _("Color:"));
  label = gtk_builder_get_object (builder, "passLabel");
  gtk_label_set_text(GTK_LABEL(label), _("Contraseña:"));

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
