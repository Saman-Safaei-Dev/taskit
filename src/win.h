#include "app.h"
#include <gtk/gtk.h>

#ifndef TASKIT_WIN_H_
#define TASKIT_WIN_H_

#define TASKIT_TYPE_WIN taskit_win_get_type()
G_DECLARE_FINAL_TYPE(TaskitWin, taskit_win, TASKIT, WIN, GtkApplicationWindow)

TaskitWin *taskit_win_new(TaskitApp *app);

#endif
