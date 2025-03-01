#pragma once

#include "raylib.h"

extern Camera2D SCREEN_CAMERA;

/**
 * @brief Update camera for screen resizing. 
 * 
 * @param camera 
 */
void UpdateScreenCamera(Camera2D &camera);