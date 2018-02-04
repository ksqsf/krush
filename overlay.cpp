
#include "overlay.h"

static bool within(int left /* x */, int top /* y */, Object *obj)
{
	int x = obj->x, y = obj->y, w = obj->width, h = obj->height;
	return x <= left && left <= x+w && y <= top && top <= y+h;
}

OverlayHandler::OverlayHandler(std::function<void(Object*, Object*)> cb)
	: m_callback(cb)
{
}

void OverlayHandler::add_object(Object *obj)
{
	m_objectList.push_back(obj);
}

void OverlayHandler::operator()(SDL_Event e)
{
	for (int i = 0; i < m_objectList.size(); ++i) {
		int x = m_objectList[i]->x;
		int y = m_objectList[i]->y;
		int w = m_objectList[i]->width;
		int h = m_objectList[i]->height;
		for (int j = i+1; j < m_objectList.size(); ++j) {
			Object *o = m_objectList[j];
			if (within(x, y, o) || within(x+w, y, o) || within(x, y+h, o) || within(x+w, y+h, o)) {
				m_callback(m_objectList[i], o);
			}
		}
	}
}