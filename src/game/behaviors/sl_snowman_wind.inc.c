// sl_snowman_wind.c.inc

u8 bhv_sl_snowman_wind_loop_continue_dialog(void) { return o->oSubAction == SL_SNOWMAN_WIND_ACT_TALKING; }

void bhv_sl_snowman_wind_loop(void) {
    if (!network_sync_object_initialized(o)) {
        network_init_object(o, SYNC_DISTANCE_ONLY_EVENTS);
        network_init_object_field(o, &o->oAction);
        network_init_object_field(o, &o->oPrevAction);
        network_init_object_field(o, &o->oTimer);
        network_init_object_field(o, &o->oSubAction);
    }

    struct Object* player = nearest_player_to_object(o);
    int distanceToPlayer = dist_between_objects(o, player);
    int angleToPlayer = obj_angle_to_object(o, player);

    UNUSED s32 unusedVar = 0;
    s16 marioAngleFromWindSource;
    Vec3f tempPos;
    
    if (o->oTimer == 0)
        o->oSLSnowmanWindOriginalYaw = o->oMoveAngleYaw;
    
    // Waiting for Mario to approach.
    if (o->oSubAction == SL_SNOWMAN_WIND_ACT_IDLE) {
        o->oDistanceToMario = 0;
        
        // Check if Mario is within 1000 units of the center of the bridge, and ready to speak.
        vec3f_copy_2(tempPos, &o->oPosX);
        obj_set_pos(o, 1100, 3328, 1164); // Position is in the middle of the ice bridge
        if (cur_obj_can_mario_activate_textbox(&gMarioStates[0], 1000.0f, 30.0f, 0x7FFF))
            o->oSubAction++;
        vec3f_copy_2(&o->oPosX, tempPos);
        
    // Mario has come close, begin dialog.
    } else if (o->oSubAction == SL_SNOWMAN_WIND_ACT_TALKING) {
        if (cur_obj_update_dialog(&gMarioStates[0], 2, 2, DIALOG_153, 0, bhv_sl_snowman_wind_loop_continue_dialog)) {
            o->oSubAction++;
            network_send_object(o);
        }
        
    // Blowing, spawn wind particles (SL_SNOWMAN_WIND_ACT_BLOWING)
    } else if (distanceToPlayer < 1500.0f && absf(player->oPosY - o->oHomeY) < 500.0f) {
        // Point towards Mario, but only within 0x1500 angle units of the original angle.
        if ((marioAngleFromWindSource = angleToPlayer - o->oSLSnowmanWindOriginalYaw) > 0) {
            if (marioAngleFromWindSource < 0x1500)
                o->oMoveAngleYaw = angleToPlayer;
            else
                o->oMoveAngleYaw = o->oSLSnowmanWindOriginalYaw + 0x1500;
        } else {
            if (marioAngleFromWindSource > -0x1500)
                o->oMoveAngleYaw = angleToPlayer;
            else
                o->oMoveAngleYaw = o->oSLSnowmanWindOriginalYaw - 0x1500;
        }
        // Spawn wind and play wind sound
        cur_obj_spawn_strong_wind_particles(12, 3.0f, 0, 0, 0);
        cur_obj_play_sound_1(SOUND_AIR_BLOW_WIND);
    }
}
