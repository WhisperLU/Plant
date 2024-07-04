#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#include <graphics.h>

class Scene
{
public:
	Scene() = default;
	~Scene() = default;

	virtual void on_enter() {};
	virtual void on_update(int delta) {};
	virtual void on_draw() {};
	virtual void on_input(const ExMessage& msg) {};
	virtual void on_exit() {};

private:

};

#endif // !__SCENE_H__