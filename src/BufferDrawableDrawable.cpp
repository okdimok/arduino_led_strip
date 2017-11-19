#include "BufferDrawableDrawable.h"
#include "simple_arithmetics.h"

void BufferDrawableDrawable::update_and_draw(double time){
	for (int i = max(drawable->most_left_index(time), 0); i <= drawable->most_right_index(time) && i >=0 && i < (int)buffer->length; i++){
		Color color = drawable->get_color_at_position_at_time(i, time);
		buffer->buffer[i] = color_mixing->mix(buffer->buffer[i], color);
	}
}
