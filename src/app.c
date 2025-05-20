#include "app.h"
#include "win.h"
#include <gtk/gtk.h>

struct _TaskitApp {
  GtkApplication parent;
};

G_DEFINE_TYPE(TaskitApp, taskit_app, GTK_TYPE_APPLICATION)

static void taskit_app_activate(GApplication *app) {
  TaskitWin *win = taskit_win_new(TASKIT_APP(app));
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
