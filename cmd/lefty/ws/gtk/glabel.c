/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      This software is part of the graphviz package      *
*                http://www.graphviz.org/                 *
*                                                         *
*            Copyright (c) 1994-2004 AT&T Corp.           *
*                and is licensed under the                *
*            Common Public License, Version 1.0           *
*                      by AT&T Corp.                      *
*                                                         *
*        Information and Software Systems Research        *
*              AT&T Research, Florham Park NJ             *
**********************************************************/


#include "common.h"
#include "g.h"
#include "gcommon.h"

#define WLU widget->u.l

int GLcreatewidget(Gwidget_t * parent, Gwidget_t * widget,
		   int attrn, Gwattr_t * attrp)
{
    PIXsize_t ps;
    int ai;
    GdkColor c;
    int color;

    if (!parent) {
	Gerr(POS, G_ERRNOPARENTWIDGET);
	return -1;
    }

    WLU->func = NULL;
    ps.x = ps.y = MINLWSIZE;

    for (ai = 0; ai < attrn; ai++) {
	switch (attrp[ai].id) {
	case G_ATTRSIZE:
	    GETSIZE(attrp[ai].u.s, ps, MINLWSIZE);
	    break;
	case G_ATTRBORDERWIDTH:
	    break;
	case G_ATTRTEXT:
	    break;
	case G_ATTRCOLOR:
	    color = attrp[ai].u.c.index;
	    if (color != 0 && color != 1) {
		Gerr(POS, G_ERRBADCOLORINDEX, color);
		return -1;
	    }

	    break;
	case G_ATTRWINDOWID:
	    Gerr(POS, G_ERRCANNOTSETATTR1, "windowid");
	    return -1;
	case G_ATTREVENTCB:
	    WLU->func = (Glabelcb) attrp[ai].u.func;
	    break;
	case G_ATTRUSERDATA:
	    widget->udata = attrp[ai].u.u;
	    break;
	default:
	    Gerr(POS, G_ERRBADATTRID, attrp[ai].id);
	    return -1;
	}
    }
    widget->w = gtk_label_new(NULL);

    return 0;
}


int GLsetwidgetattr(Gwidget_t * widget, int attrn, Gwattr_t * attrp)
{
    PIXsize_t ps;
    int ai;
    GdkColor c;
    int color;

    for (ai = 0; ai < attrn; ai++) {
	switch (attrp[ai].id) {
	case G_ATTRSIZE:
	    GETSIZE(attrp[ai].u.s, ps, MINLWSIZE);
	    break;
	case G_ATTRBORDERWIDTH:

	    break;
	case G_ATTRTEXT:

	    break;
	case G_ATTRCOLOR:
	    color = attrp[ai].u.c.index;
	    if (color != 0 && color != 1) {
		Gerr(POS, G_ERRBADCOLORINDEX, color);
		return -1;
	    }
	    break;
	case G_ATTRWINDOWID:
	    Gerr(POS, G_ERRCANNOTSETATTR2, "windowid");
	    return -1;
	case G_ATTREVENTCB:
	    WLU->func = (Glabelcb) attrp[ai].u.func;
	    break;
	case G_ATTRUSERDATA:
	    widget->udata = attrp[ai].u.u;
	    break;
	default:
	    Gerr(POS, G_ERRBADATTRID, attrp[ai].id);
	    return -1;
	}
    }

    return 0;
}


int GLgetwidgetattr(Gwidget_t * widget, int attrn, Gwattr_t * attrp)
{
    int width, height;
    char *s;
    int ai;

    for (ai = 0; ai < attrn; ai++) {
	switch (attrp[ai].id) {
	case G_ATTRSIZE:

	    break;
	case G_ATTRBORDERWIDTH:

	    break;
	case G_ATTRTEXT:

	    break;
	case G_ATTRWINDOWID:

	    break;
	case G_ATTREVENTCB:
	    attrp[ai].u.func = WLU->func;
	    break;
	case G_ATTRUSERDATA:
	    attrp[ai].u.u = widget->udata;
	    break;
	default:
	    Gerr(POS, G_ERRBADATTRID, attrp[ai].id);
	    return -1;
	}
    }

    return 0;
}


int GLdestroywidget(Gwidget_t * widget)
{
    gtk_widget_destroy(widget->w);
    return 0;
}
