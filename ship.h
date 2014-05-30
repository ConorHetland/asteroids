#include "entity.h"

#ifndef _SHIP
#define _SHIP

class ship : public entity {
	protected:
		float dx, dy, rotation;

		ship() {}

	public:
		ship(float, float);

		float getDx(void);
		float getDy(void);
		float getRotation(void);

		void setDx(float);
		void setDy(float);
		void setRotation(float);

		void rotate(float);
		void thrust(void);
		void update(float);
		void draw(void);
};

#endif