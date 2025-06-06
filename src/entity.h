#ifndef LLGLGD_ENTITY_H
#define LLGLGD_ENTITY_H

#include <linux/fb.h>
#include "gmdefs.h"

#define EN_NUM_ENTITY_MAX 15
#define EN_HUD_ID 0
#define EN_GAMER_ID 1

/* DEV: if you change the HUD LEN you must also change the HUD DAMAGE accordingly */

#define EN_GAMER_LEN 128
#define EN_ENEMY_LEN 64
#define EN_HUD_LEN 200
#define EN_HUD_WIDTH EN_HUD_LEN
#define EN_HUD_HEIGHT 32

#define EN_HUD_XPOS (EN_HUD_HEIGHT + (EN_HUD_WIDTH  >> 1))
#define EN_HUD_YPOS (EN_HUD_HEIGHT + (EN_HUD_HEIGHT >> 1))

#define EN_GAMER_VEL 16
#define EN_GAMER_XVEL EN_GAMER_VEL
#define EN_GAMER_YVEL (EN_GAMER_VEL << 1)
#define EN_ENEMY_MINVEL 8
#define EN_ENEMY_MAXVEL 16
#define EN_ENEMY_VEL EN_ENEMY_MAXVEL

#define EN_HUD_ALPHA 0
#define EN_HUD_BLUE 0
#define EN_HUD_GREEN 128
#define EN_HUD_RED 0

#define EN_GAMER_ALPHA 0
#define EN_GAMER_BLUE 255
#define EN_GAMER_GREEN 0
#define EN_GAMER_RED 0

#define EN_ENEMY_ALPHA 0
#define EN_ENEMY_BLUE 0
#define EN_ENEMY_GREEN 0
#define EN_ENEMY_RED 255

#define EN_GAMER_DAMAGED_ALPHA 0
#define EN_GAMER_DAMAGED_BLUE 128
#define EN_GAMER_DAMAGED_GREEN 128
#define EN_GAMER_DAMAGED_RED 128

#define EN_HUD_HP 100
#define EN_ENEMY_HP 20
#define EN_GAMER_HP 100

/* DEV: if you change the collision damage you must adjust the settings for the HUD */

#define EN_HUD_DAMAGE 40
#define EN_COLLISION_DAMAGE 20
#define EN_COLLISION_IGNORE ((int) (4.0 * GAME_FRAMERATE_HZ))

enum entag {
	EN_HUD,
	EN_GAMER,
	EN_ENEMY,
	EN_NTAGS
};

struct entity {
	enum entag tag;
	int invisibility;
	int ticks;
	int xpos;
	int ypos;
	int xvel;
	int yvel;
	int xmin;
	int ymin;
	int xmax;
	int ymax;
	int blue;
	int green;
	int red;
	int alpha;
	int len;
	int width;
	int height;
	int hp;
};

void en_init(
		struct entity * const entities,
		struct fb_var_screeninfo const * const fvsp,
		int num_entities
);

void en_update(
		struct entity * const entities,
		int num_entities
);

void en_handle_collisions(
		struct entity * const entities,
		int const num_entities
);

#endif

/*

gnu-linux-gaming-dev                                 May 20, 2025

author: @misael-diaz
source: src/entity.h

Copyright (C) 2025 Misael Diaz-Maldonado

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2 only of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/
