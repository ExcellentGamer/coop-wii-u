#include <string.h>
#include "djui.h"

#include "src/pc/controller/controller_sdl.h"
#include "src/pc/controller/controller_mouse.h"

#ifndef TARGET_WII_U
struct DjuiBase* sHovered = NULL;
struct DjuiBase* sMouseDown = NULL;
#endif

static void djui_interactable_on_hover_begin(struct DjuiBase* base) {
    if (base                               == NULL) { return; }
    if (base->interactable                 == NULL) { return; }
    if (base->interactable->on_hover_begin == NULL) { return; }
    base->interactable->on_hover_begin(base);
}

void djui_interactable_on_hover_end(struct DjuiBase* base) {
    if (base                               == NULL) { return; }
    if (base->interactable                 == NULL) { return; }
    if (base->interactable->on_hover_begin == NULL) { return; }
    base->interactable->on_hover_end(base);
}

static void djui_interactable_on_mouse_down_begin(struct DjuiBase* base) {
    if (base                                    == NULL) { return; }
    if (base->interactable                      == NULL) { return; }
    if (base->interactable->on_mouse_down_begin == NULL) { return; }

#ifndef TARGET_WII_U
    if (sHovered != NULL) {
        djui_interactable_on_hover_end(sHovered);
        sHovered = NULL;
    }
#endif
    base->interactable->on_mouse_down_begin(base);
}

static void djui_interactable_on_mouse_down_end(struct DjuiBase* base) {
    if (base                                  == NULL) { return; }
    if (base->interactable                    == NULL) { return; }
    if (base->interactable->on_mouse_down_end == NULL) { return; }
    base->interactable->on_mouse_down_end(base);
}

static void djui_interactable_mouse_update_active(struct DjuiBase* base) {
    if (!base->visible) { return; }

    struct DjuiBaseRect* clip = &base->clip;
    if (mouse_window_x < clip->x) { return; }
    if (mouse_window_x > clip->x + clip->width) { return; }
    if (mouse_window_y < clip->y) { return; }
    if (mouse_window_y > clip->y + clip->height) { return; }

#ifndef TARGET_WII_U
    if (base->interactable != NULL) { sHovered = base; }
#endif

    // check all children
    struct DjuiBaseChild* child = base->child;
    while (child != NULL) {
        djui_interactable_mouse_update_active(child->base);
        child = child->next;
    }
}

void djui_interactable_update(void) {
#ifndef TARGET_WII_U
    if (mouse_window_buttons & 0b0001) {
        if (sHovered != NULL) {
            sMouseDown = sHovered;
            sHovered = NULL;
            djui_interactable_on_mouse_down_begin(sMouseDown);
        }
    } else {
        if (sMouseDown != NULL) {
            djui_interactable_on_mouse_down_end(sMouseDown);
            sMouseDown = NULL;
        }
        struct DjuiBase* lastHovered = sHovered;
        sHovered = NULL;
        djui_interactable_mouse_update_active(&gDjuiRoot->base);
        if (lastHovered != sHovered) {
            djui_interactable_on_hover_end(lastHovered);
        }
        djui_interactable_on_hover_begin(sHovered);
    }
#endif
}

void djui_interactable_create(struct DjuiBase* base,
    void (*on_hover_begin)(struct DjuiBase*),
    void (*on_hover_end)(struct DjuiBase*),
    void (*on_mouse_down_begin)(struct DjuiBase*),
    void (*on_mouse_down_end)(struct DjuiBase*)) {

    if (base->interactable != NULL) {
        free(base->interactable);
    }

    struct DjuiInteractable* interactable = malloc(sizeof(struct DjuiInteractable));
    interactable->on_hover_begin      = on_hover_begin;
    interactable->on_hover_end        = on_hover_end;
    interactable->on_mouse_down_begin = on_mouse_down_begin;
    interactable->on_mouse_down_end   = on_mouse_down_end;

    base->interactable = interactable;
}