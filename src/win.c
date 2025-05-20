#include "win.h"
#include "app.h"
#include <gtk/gtk.h>

struct _TaskitWin {
  GtkApplicationWindow parent;
};

G_DEFINE_TYPE(TaskitWin, taskit_win, GTK_TYPE_APPLICATION_WINDOW)

TaskitWin *taskit_win_new(TaskitApp *app) {
  return g_object_new(TASKIT_TYPE_WIN, "application", app, NULL);
}

static void taskit_win_init(TaskitWin *win) {
  gtk_widget_init_template(GTK_WIDGET(win));
}

static void taskit_win_class_init(TaskitWinClass *class) {
  gtk_widget_class_set_template_from_resource(
      GTK_WIDGET_CLASS(class), "/ir/taskit/saman/assets/window.ui");
}
