#include "djui.h"

#include "src/pc/controller/controller_sdl.h"
#include "src/pc/controller/controller_mouse.h"

ALIGNED8 static u8 texture_hand_open[] = {
    0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xe7, 0x39, 0xf7, 0xbd, 0xef, 0x7b, 
	0xf7, 0xbd, 0xef, 0x7b, 0xd6, 0xb5, 0xbd, 0xee, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xef, 0x7b, 0xef, 0x7b, 0xf7, 0xbd, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 0xce, 0x73, 
	0xbd, 0xee, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xd6, 0xb5, 0xe7, 0x39, 0xd6, 0xb5, 0xe7, 0x39, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0x39, 
	0xa5, 0x29, 0xbd, 0xee, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xb5, 0xad, 0xc6, 0x31, 0xbd, 0xef, 0xd6, 0xb5, 
	0xef, 0x7b, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 
	0xd6, 0xb5, 0xce, 0x73, 0xef, 0x7b, 0xd6, 0xb5, 
	0xef, 0x7b, 0xce, 0x73, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0x94, 0xa5, 0x94, 0xa5, 0x9c, 0xe7, 
	0xd6, 0xb5, 0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 
	0xde, 0xf7, 0xad, 0x6b, 0xf7, 0xbd, 0xef, 0x7b, 
	0xbd, 0xef, 0xf7, 0xbd, 0xde, 0xf7, 0xbd, 0xee, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0x52, 0x95, 0x52, 0x95, 
	0xa5, 0x29, 0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 
	0xe7, 0x39, 0xbd, 0xef, 0xc6, 0x31, 0xde, 0xf7, 
	0xce, 0x73, 0xc6, 0x31, 0xc6, 0x31, 0xb5, 0xad, 
	0xbd, 0xef, 0xbd, 0xee, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xde, 0xf7, 0xf7, 0xbd, 0xff, 0xff, 
	0xef, 0x7b, 0xe7, 0x39, 0xe7, 0x39, 0xe7, 0x39, 
	0xde, 0xf7, 0xd6, 0xb5, 0xce, 0x73, 0xce, 0x73, 
	0xbd, 0xef, 0xad, 0x6b, 0xbd, 0xee, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xbd, 0xef, 0xef, 0x7b, 0xf7, 0xbd, 
	0xf7, 0xbd, 0xf7, 0xbd, 0xef, 0x7b, 0xef, 0x7b, 
	0xe7, 0x39, 0xde, 0xf7, 0xd6, 0xb5, 0xd6, 0xb5, 
	0xce, 0x73, 0xa5, 0x29, 0xad, 0x6b, 0xbd, 0xee, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xd6, 0xb5, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 0xf7, 0xbd, 
	0xe7, 0x39, 0xef, 0x7b, 0xce, 0x73, 0xa5, 0x29, 
	0xc6, 0x31, 0x29, 0x4b, 0x52, 0x95, 0xa5, 0x29, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xce, 0x73, 0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 
	0xf7, 0xbd, 0xef, 0x7b, 0xce, 0x73, 0x08, 0x43, 
	0x18, 0xc7, 0xad, 0x6b, 0x10, 0x85, 0xa5, 0x29, 
	0x42, 0x11, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xef, 0x7b, 0xf7, 0xbd, 
	0xe7, 0x39, 0xc6, 0x31, 0xbd, 0xee, 0xc6, 0x30, 
	0xd6, 0xb5, 0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xf7, 0xbd, 0xf7, 0xbd, 0xef, 0x7b, 0x84, 0x21, 
	0x10, 0x85, 0x8c, 0x63, 0xbd, 0xef, 0x6b, 0x5b, 
	0xad, 0x6b, 0x4a, 0x53, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xef, 0x7b, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xf7, 0xbd, 0xd6, 0xb5, 0xe7, 0x39, 
	0xce, 0x73, 0xef, 0x7b, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xf7, 0xbd, 0xef, 0x7b, 0xef, 0x7b, 
	0xbd, 0xef, 0x6b, 0x5b, 0xce, 0x73, 0xb5, 0xad, 
	0xbd, 0xef, 0xa5, 0x29, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xef, 0x7b, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xde, 0xf7, 0xde, 0xf7, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 0xef, 0x7b, 
	0xe7, 0x39, 0xde, 0xf7, 0xde, 0xf7, 0xce, 0x73, 
	0xc6, 0x31, 0xb5, 0xad, 0x94, 0xa5, 0xbd, 0xee, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xde, 0xf7, 0xef, 0x7b, 0xf7, 0xbd, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xce, 0x73, 0xe7, 0x39, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 0xf7, 0xbd, 
	0xe7, 0x39, 0xe7, 0x39, 0xde, 0xf7, 0xd6, 0xb5, 
	0xc6, 0x31, 0xa5, 0x29, 0xa5, 0x29, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xad, 0x6b, 0xce, 0x73, 0xd6, 0xb5, 
	0xe7, 0x39, 0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xe7, 0x39, 0xc6, 0x31, 0xe7, 0x39, 
	0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 
	0xef, 0x7b, 0xe7, 0x39, 0xde, 0xf7, 0xce, 0x73, 
	0xc6, 0x31, 0xad, 0x6b, 0xbd, 0xef, 0xc6, 0x31, 
	0xb5, 0xad, 0xa5, 0x29, 0xbd, 0xee, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0x84, 0x21, 0x9c, 0xe7, 
	0xb5, 0xad, 0xd6, 0xb5, 0xe7, 0x39, 0xef, 0x7b, 
	0xef, 0x7b, 0xd6, 0xb5, 0xce, 0x73, 0xc6, 0x31, 
	0xe7, 0x39, 0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 
	0xef, 0x7b, 0xde, 0xf7, 0xce, 0x73, 0xce, 0x73, 
	0xde, 0xf7, 0xe7, 0x39, 0xd6, 0xb5, 0xce, 0x73, 
	0xc6, 0x31, 0xb5, 0xad, 0x94, 0xa5, 0xbd, 0xee, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0x9c, 0xe7, 0xc6, 0x31, 0xbd, 0xef, 
	0xc6, 0x31, 0xbd, 0xef, 0xc6, 0x31, 0xa5, 0x29, 
	0xc6, 0x31, 0xde, 0xf7, 0xe7, 0x39, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 
	0xde, 0xf7, 0xd6, 0xb5, 0xe7, 0x39, 0xef, 0x7b, 
	0xef, 0x7b, 0xe7, 0x39, 0xde, 0xf7, 0xce, 0x73, 
	0xc6, 0x31, 0xad, 0x6b, 0x8c, 0x63, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0x84, 0x21, 0x7b, 0xdf, 
	0x7b, 0xdf, 0x84, 0x21, 0xa5, 0x29, 0xa5, 0x29, 
	0x9c, 0xe7, 0xb5, 0xad, 0xce, 0x73, 0xde, 0xf7, 
	0xef, 0x7b, 0xef, 0x7b, 0xe7, 0x39, 0xce, 0x73, 
	0xe7, 0x39, 0xf7, 0xbd, 0xff, 0xff, 0xf7, 0xbd, 
	0xef, 0x7b, 0xe7, 0x39, 0xd6, 0xb5, 0xc6, 0x31, 
	0xad, 0x6b, 0x9c, 0xe7, 0x84, 0x21, 0xbd, 0xee, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0x7b, 0xdf, 
	0x94, 0xa5, 0x84, 0x21, 0x9c, 0xe7, 0xbd, 0xef, 
	0xce, 0x73, 0xce, 0x73, 0xc6, 0x31, 0xe7, 0x39, 
	0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 
	0xe7, 0x39, 0xd6, 0xb5, 0xbd, 0xef, 0xad, 0x6b, 
	0x9c, 0xe7, 0x84, 0x21, 0x6b, 0x5b, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0x6b, 0x5b, 0x7b, 0xdf, 
	0x9c, 0xe7, 0xa5, 0x29, 0xde, 0xf7, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0x39, 
	0xce, 0x73, 0xb5, 0xad, 0xad, 0x6b, 0x94, 0xa5, 
	0x84, 0x21, 0x73, 0x9d, 0xbd, 0xee, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0x9c, 0xe7, 0xf7, 0xbd, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xde, 0xf7, 0xce, 0x73, 
	0xb5, 0xad, 0x9c, 0xe7, 0x94, 0xa5, 0x7b, 0xdf, 
	0x73, 0x9d, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xbd, 0xef, 0xe7, 0x39, 0xf7, 0xbd, 
	0xe7, 0x39, 0xd6, 0xb5, 0xbd, 0xef, 0xad, 0x6b, 
	0x9c, 0xe7, 0x84, 0x21, 0x7b, 0xdf, 0x6b, 0x5b, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xad, 0x6b, 0xce, 0x73, 0xce, 0x73, 
	0xbd, 0xef, 0xb5, 0xad, 0x9c, 0xe7, 0x94, 0xa5, 
	0x7b, 0xdf, 0x73, 0x9d, 0x63, 0x19, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0x9c, 0xe7, 0xa5, 0x29, 
	0x9c, 0xe7, 0x8c, 0x63, 0x84, 0x21, 0x73, 0x9d, 
	0x6b, 0x5b, 0xbd, 0xee, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0x73, 0x9d, 
	0x73, 0x9d, 0x6b, 0x5b, 0x6b, 0x5b, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
};

ALIGNED8 static u8 texture_hand_closed[] = {
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xe7, 0x39, 0xde, 0xf7, 0xde, 0xf7, 0xbd, 0xee, 
	0xe7, 0x39, 0xef, 0x7b, 0xef, 0x7b, 0xd6, 0xb5, 
	0xef, 0x7b, 0xd6, 0xb5, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xe7, 0x39, 0xff, 0xff, 
	0xf7, 0xbd, 0xff, 0xff, 0xf7, 0xbd, 0xe7, 0x39, 
	0xc6, 0x31, 0xf7, 0xbd, 0xff, 0xff, 0xf7, 0xbd, 
	0xbd, 0xef, 0xf7, 0xbd, 0xd6, 0xb5, 0xbd, 0xee, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xef, 0x7b, 0xf7, 0xbd, 
	0xef, 0x7b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xd6, 0xb5, 0xce, 0x73, 0xe7, 0x39, 0xd6, 0xb5, 
	0xd6, 0xb5, 0xc6, 0x31, 0xc6, 0x31, 0xb5, 0xad, 
	0xbd, 0xef, 0xbd, 0xee, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x31, 0xde, 0xf7, 0xde, 0xf7, 
	0xde, 0xf7, 0xf7, 0xbd, 0xff, 0xff, 0xf7, 0xbd, 
	0xe7, 0x39, 0xef, 0x7b, 0xe7, 0x39, 0xe7, 0x39, 
	0xde, 0xf7, 0xd6, 0xb5, 0xce, 0x73, 0xce, 0x73, 
	0xb5, 0xad, 0xb5, 0xad, 0xbd, 0xee, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x31, 0xbd, 0xef, 0xbd, 0xef, 
	0xb5, 0xad, 0xe7, 0x39, 0xe7, 0x39, 0xf7, 0xbd, 
	0xf7, 0xbd, 0xf7, 0xbd, 0xef, 0x7b, 0xef, 0x7b, 
	0xe7, 0x39, 0xde, 0xf7, 0xde, 0xf7, 0xce, 0x73, 
	0xce, 0x73, 0xa5, 0x29, 0xad, 0x6b, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xe7, 0x39, 0xef, 0x7b, 0xb5, 0xad, 
	0x94, 0xa5, 0xde, 0xf7, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 0xef, 0x7b, 
	0xef, 0x7b, 0xe7, 0x39, 0xd6, 0xb5, 0x9c, 0xe7, 
	0xc6, 0x31, 0x31, 0x8d, 0x4a, 0x53, 0xad, 0x6b, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xe7, 0x39, 0xff, 0xff, 0xff, 0xff, 
	0xe7, 0x39, 0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 
	0xf7, 0xbd, 0xef, 0x7b, 0xc6, 0x31, 0x10, 0x85, 
	0x31, 0x8d, 0xb5, 0xad, 0x10, 0x85, 0x8c, 0x63, 
	0x31, 0x8d, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xd6, 0xb5, 0xef, 0x7b, 0xf7, 0xbd, 
	0xde, 0xf7, 0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xf7, 0xbd, 0xf7, 0xbd, 0xef, 0x7b, 0x94, 0xa5, 
	0x10, 0x85, 0x84, 0x21, 0xb5, 0xad, 0x73, 0x9d, 
	0xad, 0x6b, 0x4a, 0x53, 0xbd, 0xee, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xef, 0x7b, 0xef, 0x7b, 0xe7, 0x39, 
	0xce, 0x73, 0xef, 0x7b, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xf7, 0xbd, 0xef, 0x7b, 0xef, 0x7b, 
	0xc6, 0x31, 0x63, 0x19, 0xd6, 0xb5, 0xad, 0x6b, 
	0xbd, 0xef, 0xad, 0x6b, 0xbd, 0xee, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xd6, 0xb5, 0xef, 0x7b, 0xe7, 0x39, 0xef, 0x7b, 
	0xc6, 0x31, 0xde, 0xf7, 0xf7, 0xbd, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 0xef, 0x7b, 
	0xe7, 0x39, 0xde, 0xf7, 0xde, 0xf7, 0xce, 0x73, 
	0xc6, 0x31, 0xad, 0x6b, 0x9c, 0xe7, 0xbd, 0xee, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xce, 0x73, 0xef, 0x7b, 0xf7, 0xbd, 0xff, 0xff, 
	0xd6, 0xb5, 0xc6, 0x31, 0xe7, 0x39, 0xf7, 0xbd, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 0xf7, 0xbd, 
	0xe7, 0x39, 0xe7, 0x39, 0xde, 0xf7, 0xd6, 0xb5, 
	0xc6, 0x31, 0xad, 0x6b, 0xa5, 0x29, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x31, 0xd6, 0xb5, 0xef, 0x7b, 0xff, 0xff, 
	0xe7, 0x39, 0xd6, 0xb5, 0xce, 0x73, 0xe7, 0x39, 
	0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 
	0xe7, 0x39, 0xe7, 0x39, 0xde, 0xf7, 0xce, 0x73, 
	0xbd, 0xef, 0xbd, 0xef, 0xc6, 0x31, 0xbd, 0xef, 
	0xb5, 0xad, 0xa5, 0x29, 0xbd, 0xee, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x31, 0xde, 0xf7, 0xf7, 0xbd, 
	0xd6, 0xb5, 0xd6, 0xb5, 0xbd, 0xef, 0xc6, 0x31, 
	0xe7, 0x39, 0xf7, 0xbd, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 
	0xef, 0x7b, 0xde, 0xf7, 0xc6, 0x31, 0xd6, 0xb5, 
	0xde, 0xf7, 0xe7, 0x39, 0xd6, 0xb5, 0xce, 0x73, 
	0xc6, 0x31, 0xb5, 0xad, 0x8c, 0x63, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0x94, 0xa5, 0xc6, 0x31, 0xce, 0x73, 
	0xd6, 0xb5, 0xb5, 0xad, 0xc6, 0x31, 0xa5, 0x29, 
	0xc6, 0x31, 0xd6, 0xb5, 0xef, 0x7b, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 
	0xde, 0xf7, 0xd6, 0xb5, 0xe7, 0x39, 0xef, 0x7b, 
	0xef, 0x7b, 0xef, 0x7b, 0xde, 0xf7, 0xce, 0x73, 
	0xbd, 0xef, 0xad, 0x6b, 0x8c, 0x63, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0x8c, 0x63, 0x9c, 0xe7, 
	0x9c, 0xe7, 0x8c, 0x63, 0xa5, 0x29, 0xad, 0x6b, 
	0x94, 0xa5, 0xbd, 0xef, 0xce, 0x73, 0xde, 0xf7, 
	0xe7, 0x39, 0xef, 0x7b, 0xe7, 0x39, 0xd6, 0xb5, 
	0xde, 0xf7, 0xf7, 0xbd, 0xff, 0xff, 0xf7, 0xbd, 
	0xf7, 0xbd, 0xde, 0xf7, 0xd6, 0xb5, 0xc6, 0x31, 
	0xad, 0x6b, 0x9c, 0xe7, 0x84, 0x21, 0xbd, 0xee, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0x7b, 0xdf, 
	0x94, 0xa5, 0x8c, 0x63, 0x9c, 0xe7, 0xbd, 0xef, 
	0xce, 0x73, 0xce, 0x73, 0xc6, 0x31, 0xde, 0xf7, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbd, 
	0xe7, 0x39, 0xd6, 0xb5, 0xbd, 0xef, 0xad, 0x6b, 
	0x9c, 0xe7, 0x84, 0x21, 0x73, 0x9d, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0x73, 0x9d, 0x7b, 0xdf, 
	0x9c, 0xe7, 0xa5, 0x29, 0xde, 0xf7, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xde, 0xf7, 
	0xd6, 0xb5, 0xb5, 0xad, 0xad, 0x6b, 0x94, 0xa5, 
	0x84, 0x21, 0x73, 0x9d, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0x9c, 0xe7, 0xef, 0x7b, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xde, 0xf7, 0xce, 0x73, 
	0xad, 0x6b, 0xa5, 0x29, 0x94, 0xa5, 0x7b, 0xdf, 
	0x73, 0x9d, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xb5, 0xad, 0xef, 0x7b, 0xef, 0x7b, 
	0xef, 0x7b, 0xd6, 0xb5, 0xbd, 0xef, 0xad, 0x6b, 
	0x94, 0xa5, 0x8c, 0x63, 0x7b, 0xdf, 0x6b, 0x5b, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xa5, 0x29, 0xce, 0x73, 0xd6, 0xb5, 
	0xbd, 0xef, 0xb5, 0xad, 0x9c, 0xe7, 0x94, 0xa5, 
	0x7b, 0xdf, 0x73, 0x9d, 0x63, 0x19, 0xbd, 0xee, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0x9c, 0xe7, 0xa5, 0x29, 
	0x9c, 0xe7, 0x8c, 0x63, 0x84, 0x21, 0x73, 0x9d, 
	0x6b, 0x5b, 0xbd, 0xee, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0x7b, 0xdf, 
	0x73, 0x9d, 0x6b, 0x5b, 0x63, 0x19, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
	0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 0xc6, 0x30, 
};

static struct DjuiImage* sMouseCursor = NULL;
static bool sCursorMouseControlled = false;
static struct DjuiBase* sInputControlledBase = NULL;

static f32 sSavedMouseX = 0;
static f32 sSavedMouseY = 0;
static f32 sCursorX = 0;
static f32 sCursorY = 0;

bool djui_cursor_inside_base(struct DjuiBase* base) {
    struct DjuiBaseRect* clip = &base->elem;
    if (sCursorX < clip->x)                { return false; }
    if (sCursorX > clip->x + clip->width)  { return false; }
    if (sCursorY < clip->y)                { return false; }
    if (sCursorY > clip->y + clip->height) { return false; }
    return true;
}

static void djui_cursor_base_hover_location(struct DjuiBase* base, f32* x, f32* y) {
    *x = (base->elem.x + base->elem.width  * 3.0f / 4.0f);
    *y = (base->elem.y + base->elem.height * 3.0f / 4.0f);
}

void djui_cursor_input_controlled_center(struct DjuiBase* base) {
    if (!sCursorMouseControlled) {
        sInputControlledBase = base;
        if (sMouseCursor != NULL) {
            djui_base_set_visible(&sMouseCursor->base, (base != NULL));
        }
        sSavedMouseX = mouse_window_x;
        sSavedMouseY = mouse_window_y;
    }
}

static f32 djui_cursor_base_distance(struct DjuiBase* base) {
    f32 x, y;
    djui_cursor_base_hover_location(base, &x, &y);
    x -= sCursorX;
    y -= sCursorY;
    return sqrtf((x * x) + (y * y));
}

static void djui_cursor_move_check(s8 xDir, s8 yDir, struct DjuiBase** pick, struct DjuiBase* base) {
    if (!base->visible) { return; }
    if (!base->enabled) { return; }

    if (base->interactable != NULL) {
        f32 xH, yH;
        djui_cursor_base_hover_location(base, &xH, &yH);
        bool valid = true;
        if (xDir > 0 && sCursorX >= xH) { valid = false; }
        if (xDir < 0 && sCursorX <= xH) { valid = false; }
        if (yDir > 0 && sCursorY >= yH) { valid = false; }
        if (yDir < 0 && sCursorY <= yH) { valid = false; }
        if (valid) {
            if (*pick == NULL) {
                *pick = base;
            } else {
                f32 pickDist = djui_cursor_base_distance(*pick);
                f32 baseDist = djui_cursor_base_distance(base);
                if (baseDist < pickDist) {
                    *pick = base;
                }
            }
        }
    }

    // check all children
    struct DjuiBaseChild* child = base->child;
    while (child != NULL) {
        djui_cursor_move_check(xDir, yDir, pick, child->base);
        child = child->next;
    }
}

void djui_cursor_move(s8 xDir, s8 yDir) {
    if (xDir == 0 && yDir == 0) { return; }

    struct DjuiBase* pick = NULL;
    djui_cursor_move_check(xDir, yDir, &pick, &gDjuiRoot->base);
    if (pick != NULL) {
        sCursorMouseControlled = false;
        djui_cursor_input_controlled_center(pick);
    }
}

void djui_cursor_update(void) {
#if defined(CAPI_SDL2) || defined(CAPI_SDL1)
    controller_sdl_read_mouse_window();

    // adjust mouse cursor
    if (sCursorMouseControlled) {
        sCursorX = mouse_window_x;
        sCursorY = mouse_window_y;
    } else {
        if (sInputControlledBase != NULL) {
            djui_cursor_base_hover_location(sInputControlledBase, &sCursorX, &sCursorY);
        }
        f32 dist = sqrtf(powf(mouse_window_x - sSavedMouseX, 2) + powf(mouse_window_y - sSavedMouseY, 2));
        if (dist > 5) {
            sCursorMouseControlled = true;
            djui_base_set_visible(&sMouseCursor->base, true);
        }
    }

    djui_base_set_location(&sMouseCursor->base, sCursorX - 13, sCursorY - 13);

    if (mouse_window_buttons & 0b0001) {
        djui_image_set_image(sMouseCursor, texture_hand_closed, 32, 32, 16);
    }
    else {
        djui_image_set_image(sMouseCursor, texture_hand_open, 32, 32, 16);
    }
#else
    if (sInputControlledBase != NULL) {
        djui_cursor_base_hover_location(sInputControlledBase, &sCursorX, &sCursorY);
    }

    djui_base_set_location(&sMouseCursor->base, sCursorX - 13, sCursorY - 13);
    djui_image_set_image(sMouseCursor, texture_hand_open, 32, 32, 16);
#endif
    djui_base_render(&sMouseCursor->base);
}

void djui_cursor_create(void) {
    sMouseCursor = djui_image_create(NULL, texture_hand_open, 32, 32, 16);
    djui_base_set_location(&sMouseCursor->base, 0, 0);
    djui_base_set_size(&sMouseCursor->base, 64, 64);
}