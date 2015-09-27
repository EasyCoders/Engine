#ifndef __Window__
#define __Window__
#include <SDL.h>
#include <iostream>


class Window																		
{
public:

	Window();
	~Window();
	void init() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags); //создаёт окно по заданным параметрам: название, позиция по оси X, 
																						//позиция по Y, ширина, длина, флаг состояния окна
	void render();																	
	void update();
	void handleEvents();
	void clean();																		//удаляет окно
	bool running() { return m_bRunning; }												//возвращает состояния работы окна
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
};

#endif
