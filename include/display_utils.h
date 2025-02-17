
/**
 * @copyright  Copyright (C) 2025 Kaden Slater. All Rights Reserved.
 * @license    GNU General Public License version 2 or later; see LICENSE.txt
 */

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <gtk/gtk.h>


#ifndef INCLUDE_DISPLAY_UTILS_H_
#define INCLUDE_DISPLAY_UTILS_H_


void on_realize(GtkGLArea *);

gboolean render(GtkGLArea *, GdkGLContext *);


#endif  // INCLUDE_DISPLAY_UTILS_H_
