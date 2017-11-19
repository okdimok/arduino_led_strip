#ifndef BufferDrawableDrawable_h
#define BufferDrawableDrawable_h

#include "StripBuffer.h"
#include "ColorMixing.h"
#include "Drawable.h"
#include "BufferDrawable.h"

class BufferDrawableDrawable : public BufferDrawable {
protected:
	Drawable* drawable;
	void update_and_draw(double time);
public:
	BufferDrawableDrawable() : BufferDrawable() {}
	BufferDrawableDrawable (Drawable* drawable_, StripBuffer* buffer_, ColorMixing* color_mixing_) : BufferDrawable(buffer_, color_mixing_), drawable(drawable_) {}

	int check_update_and_draw(double time){
		if (buffer && color_mixing && drawable) {
			if (time > drawable->start_time() && (drawable->end_time() < 0 || time < drawable->end_time()) ){
				update_and_draw(time);
			}
			return true;
		}
		return false;
	}
};

#endif
