#include "entity.h"

#ifndef _BULLET
#define _BULLET

class bullet : public entity {
	protected:
		float rotation;

		bullet() {}

	public:
		bullet(float, float, float);

		void update(float);
		void draw(void);
};

#endif