#include "djui.h"
#include "../debuglog.h"

#include "src/pc/controller/controller_sdl.h"
#include "src/pc/controller/controller_mouse.h"

ALIGNED8 static u8 texture_hand_open[] = {
#include "textures/intro_raw/hand_open.rgba16.inc.c"
};

ALIGNED8 static u8 texture_hand_closed[] = {
#include "textures/intro_raw/hand_closed.rgba16.inc.c"
};

ALIGNED8 static u8 texture_title[] = {
#include "textures/segment2/custom_title.rgba16.inc.c"
};

static Gfx* sSavedDisplayListHead = NULL;

struct DjuiRoot* gDjuiRoot = NULL;

#ifndef TARGET_WII_U
static struct DjuiImage* sMouseCursor = NULL;
#endif

struct DjuiFlowLayout* buttonContainer;

static void djui_init(void) {
    gDjuiRoot = djui_root_create();

#ifndef TARGET_WII_U
    sMouseCursor = djui_image_create(NULL, texture_hand_open, 32, 32, 16);
    djui_base_set_location(&sMouseCursor->base, 0, 0);
    djui_base_set_size(&sMouseCursor->base, 64, 64);
#endif

    djui_panel_main_create();
}

static void djui_debug_update(void) {
    /*static struct DjuiImage* sDjuiImage = NULL;
    static struct DjuiRect* sDjuiRect = NULL;;
    static struct DjuiRect* sDjuiRect2 = NULL;;
    static struct DjuiText* sDjuiText = NULL;;
    if (sDjuiImage == NULL) {
        struct DjuiRect* imageContainer = djui_rect_create(&gDjuiRoot->base);
        djui_base_set_location(&imageContainer->base, 32, 32);
        djui_base_set_size(&imageContainer->base, 128, 128);
        djui_base_set_padding(&imageContainer->base, 48, 48, 48, 48);

        sDjuiImage = djui_image_create(&imageContainer->base, texture16x16, 16, 16, 16);
        djui_base_set_location(&sDjuiImage->base, 0, 0);
        djui_base_set_size(&sDjuiImage->base, 32, 32);
        djui_base_set_size_type(&sDjuiImage->base, DJUI_SVT_RELATIVE, DJUI_SVT_RELATIVE);
        djui_base_set_size(&sDjuiImage->base, 1.0f, 1.0f);

        sDjuiRect = djui_rect_create(&gDjuiRoot->base);
        djui_base_set_location(&sDjuiRect->base, 64, 64);
        djui_base_set_size(&sDjuiRect->base, 188, 64);
        djui_base_set_color(&sDjuiRect->base, 255, 255, 255, 200);
        djui_base_set_alignment(&sDjuiRect->base, DJUI_HALIGN_LEFT, DJUI_VALIGN_BOTTOM);

        sDjuiRect2 = djui_rect_create(&sDjuiRect->base);
        djui_base_set_location(&sDjuiRect2->base, 0, 0);
        djui_base_set_size(&sDjuiRect2->base, 188 - 8, 64 - 8);
        djui_base_set_alignment(&sDjuiRect2->base, DJUI_HALIGN_CENTER, DJUI_VALIGN_CENTER);

        sDjuiText = djui_text_create(&sDjuiRect2->base, "Host");
        djui_base_set_location(&sDjuiText->base, 0, 0);
        djui_base_set_size(&sDjuiText->base, 188 - 8, 64 - 8);
        djui_base_set_color(&sDjuiText->base, 111, 111, 111, 255);
        djui_text_set_font_size(sDjuiText, 2);
        djui_text_set_alignment(sDjuiText, DJUI_HALIGN_CENTER, DJUI_VALIGN_CENTER);
    }*/
    static u32 sTimer = 0;
    sTimer++;
    /*djui_base_set_size(&buttonContainer->base,
        512.0f + cos((sTimer) / 20.0f) * 256.0f,
        buttonContainer->base.height.value);*/
    /*djui_base_set_location(&sDjuiImage->base,
        0.0f + cos((sTimer) / 30.0f) * 128.0f,
        0.0f + fabs(sin((sTimer) / 30.0f)) * 128.0f);*/

    /*djui_base_set_color(&sDjuiImage->base,
        127.0f + sin((sTimer) / 13.0f) * 127.0f,
        127.0f + sin((sTimer) / 17.0f) * 127.0f,
        127.0f + sin((sTimer) / 23.0f) * 127.0f,
        255);

    djui_base_set_location(&sDjuiRect2->base,
        32.0f + cos((sTimer) / 10.0f) * 64.0f,
        32.0f + sin((sTimer) / 31.0f) * 64.0f);*/
}

static void djui_mouse_update(void) {
#if defined(CAPI_SDL2) || defined(CAPI_SDL1)
#ifndef TARGET_WII_U
    controller_sdl_read_mouse_window();
    djui_interactable_update();

    // adjust mouse cursor (if on pc ofc)
    djui_base_set_location(&sMouseCursor->base, mouse_window_x - 13, mouse_window_y - 13);

    if (mouse_window_buttons & 0b0001) {
        djui_image_set_image(sMouseCursor, texture_hand_closed, 32, 32, 16);
    } else {
        djui_image_set_image(sMouseCursor, texture_hand_open, 32, 32, 16);
    }
#endif
#endif
}

void djui_render_patch(void) {
    // reset the head and re-render DJUI
    if (sSavedDisplayListHead == NULL) { return; }
    gDisplayListHead = sSavedDisplayListHead;
    djui_render();
    gDPFullSync(gDisplayListHead++);
    gSPEndDisplayList(gDisplayListHead++);
}

void djui_render(void) {
    if (gDjuiRoot == NULL) { djui_init(); }
    sSavedDisplayListHead = gDisplayListHead;
    create_dl_ortho_matrix();

#ifndef TARGET_WII_U
    djui_mouse_update();
#endif

    djui_debug_update();

    djui_base_render(&gDjuiRoot->base);
#ifndef TARGET_WII_U
    djui_base_render(&sMouseCursor->base);
#endif
}
