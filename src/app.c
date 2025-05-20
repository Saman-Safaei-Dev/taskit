#include "app.h"
#include <gtk/gtk.h>

struct _TaskitApp {
  GtkApplication parent;
};

G_DEFINE_TYPE(TaskitApp, taskit_app, GTK_TYPE_APPLICATION)

static void taskit_app_activate(GApplication *app) {
  GtkWidget *win = gtk_application_window_new(GTK_APPLICATION(app));
  gtk_window_set_title(GTK_WINDOW(win), "Taskit");
  gtk_window_set_default_size(GTK_WINDOW(win), 300, 300);
  gtk_window_present(GTK_WINDOW(win));
}

TaskitApp *taskit_app_new() {
  return g_object_new(TASKIT_TYPE_APP, "application-id", "ir.taskit.saman",
                      "flags", G_APPLICATION_DEFAULT_FLAGS, NULL);
}

static void taskit_app_init(TaskitApp *app) {}

static void taskit_app_class_init(TaskitAppClass *class) {
  G_APPLICATION_CLASS(class)->activate = taskit_app_activate;
}
