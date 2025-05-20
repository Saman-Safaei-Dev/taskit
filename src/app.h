#include <gtk/gtk.h>

#ifndef TASKIT_APP_H_
#define TASKIT_APP_H_

#define TASKIT_TYPE_APP taskit_app_get_type()
G_DECLARE_FINAL_TYPE(TaskitApp, taskit_app, TASKIT, APP, GtkApplication)

TaskitApp *taskit_app_new();

#endif
